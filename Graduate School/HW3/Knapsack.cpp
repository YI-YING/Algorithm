//---------------------------------------------------------------------------

#include <vcl.h>
#include <climits>
#include <algorithm.h>
#pragma hdrstop

#include "Knapsack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfKnapsack *fKnapsack;
//---------------------------------------------------------------------------
//Set Edit Style Center, Number
void SetCenter(TEdit *edTemp) {

    //unsigned long 暫存變數
    DWord fstyle;

    //取得輸入框的初始設定資訊
    fstyle = GetWindowLong(edTemp->Handle, GWL_STYLE);

    //設定只能輸入數字以及文字要置中
    SetWindowLong(edTemp->Handle, GWL_STYLE, fstyle | ES_NUMBER | ES_CENTER);

}
//---------------------------------------------------------------------------
__fastcall TfKnapsack::TfKnapsack(TComponent* Owner)
    : TForm(Owner)
{
    SetCenter(edItemNum);
    SetCenter(edWeightRange);
    SetCenter(edProfitRange);
    SetCenter(edBagCapacity);
    SetCenter(edItemWeight);
    SetCenter(edItemProfit);

}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::edItemNumChange(TObject *Sender)
{
    TEdit *edTemp = (TEdit*)Sender;

    if (edTemp->Text == "")
        return ;

    //限制數字在 65535 中
    if (StrToInt(edTemp->Text) > 65535)
        edTemp->Text = "65535";

}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::edItemNumExit(TObject *Sender)
{
    TEdit *edTemp = (TEdit*)Sender;

    if (edTemp->Text != "" && StrToInt(edTemp->Text) != 0)
        return ;

    //如果是空字串或數值為零則設定初始值
    switch (edTemp->Tag) {
        case 0:
            edTemp->Text = "5";
            break;

        case 1:
            edTemp->Text = "20";
            break;

        case 2:
            edTemp->Text = "10";
            break;

        case 3:
            edTemp->Text = "34";
            break;

        case 4:
            edTemp->Text = "10";
            break;

        default:
            edTemp->Text = "5";
    }

}
/****************************************************************************
 *宣告 struct Item
 ***************************************************************************/
typedef struct Item {

    int iWeight;    //重量
    int iProfit;    //價值
    float fRatio;   //比值

    Item *itmLeft;  //左邊節點
    Item *itmRight; //右邊節點
} Item;

Item *itmRoot;    //根節點
//---------------------------------------------------------------------------
//新的節點
Item* NewItem(int iWeight, int iProfit) {

    Item *item = new Item;

    item->iWeight = iWeight;
    item->iProfit = iProfit;
    item->fRatio = float(iProfit) / iWeight;
    item->itmLeft = NULL;
    item->itmRight = NULL;

    return item;
}
//---------------------------------------------------------------------------
//新 Item
Item* AddItem(Item *node, int iWeight, int iProfit) {

    if (node == NULL)
        return NewItem(iWeight, iProfit);

    if ((float)iProfit / iWeight > node->fRatio)
        node->itmRight = AddItem(node->itmRight, iWeight, iProfit);
    else
        node->itmLeft = AddItem(node->itmLeft, iWeight, iProfit);

    return node;
}
//---------------------------------------------------------------------------
//Add Items
void AddItems() {

    for (int i = 0; i < iItemNum; i++)
        itmRoot = AddItem(itmRoot, rand() % iWeightRange + 1, rand() % iProfitRange + 1);

}
//---------------------------------------------------------------------------
//用來將 Item* 封裝
typedef struct Wrap {

    Item *itm;
} Wrap;

Wrap *wrItems;
//---------------------------------------------------------------------------
//Print Items
void  PrintItems() {

    TStringGrid *sgItems = fKnapsack->sgItems;

    sgItems->CleanupInstance();
    sgItems->RowCount = 4;

    sgItems->ColCount = iTotalNum + 1;

    sgItems->Cells[0][0] = "i";
    sgItems->Cells[0][1] = "Weight";
    sgItems->Cells[0][2] = "Profit";
    sgItems->Cells[0][3] = "P / W";

    for (int i = 1; i <= iTotalNum; i++) {
        sgItems->Cells[i][0] = i;
        sgItems->Cells[i][1] = wrItems[i -1].itm->iWeight;
        sgItems->Cells[i][2] = wrItems[i -1].itm->iProfit;
        sgItems->Cells[i][3] = FloatToStrF(wrItems[i -1].itm->fRatio,ffFixed,8,3);
    }

}
//---------------------------------------------------------------------------
//中序走訪樹並將結果存在 wrItems 陣列
void InorderTraversal(Item *node, Wrap *answer,int &i) {

    if (node != NULL) {
        InorderTraversal(node->itmRight, answer, i);
        answer[i++].itm = node;
        InorderTraversal(node->itmLeft, answer, i);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::btAddItemsClick(TObject *Sender)
{
    //如果已存在陣列 wrItems 將之清除
    if (wrItems) {
        delete[] wrItems;
        wrItems = NULL;
    }

    //讀取使用者輸入
    iItemNum = StrToInt(edItemNum->Text);
    iWeightRange = StrToInt(edWeightRange->Text);
    iProfitRange = StrToInt(edProfitRange->Text);

    //亂數產生 Items 的重量以及價值
    //並加入 itmRoot
    AddItems();

    //產生新的 wrItems 陣列
    iTotalNum += iItemNum;    //用來計算現在總共有多少資料
    wrItems = new Wrap [iTotalNum];

    //用中序走訪樹並將結果存到 wrItems
    InorderTraversal(itmRoot, wrItems, 0);

    //顯示所有資料，由 CP 值高到低顯示
    if (cbPrintItems->Checked)
        PrintItems();

    memSolution->Lines->Add(edItemNum->Text + " 筆亂數資料新增完成");

}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::btAddItemClick(TObject *Sender)
{
    //如果已存在陣列 wrItems 將之清除
    if (wrItems) {
        delete[] wrItems;
        wrItems = NULL;
    }

    //讀取使用者輸入
    int iItemWeight = StrToInt(edItemWeight->Text);
    int iItemProfit = StrToInt(edItemProfit->Text);

    itmRoot = AddItem(itmRoot, iItemWeight, iItemProfit);

    //產生新的 wrItems 陣列
    iTotalNum += 1;    //用來計算現在總共有多少資料
    wrItems = new Wrap [iTotalNum];

    //用中序走訪樹並將結果存到 wrItems
    InorderTraversal(itmRoot, wrItems, 0);

    //顯示所有資料，由 CP 值高到低顯示
    if (cbPrintItems->Checked)
        PrintItems();

    memSolution->Lines->Add("1 筆資料新增完成");

}
//---------------------------------------------------------------------------
//遞迴刪除資料
Item* ClearAll(Item *node) {

    if (node != NULL) {
        node->itmLeft = ClearAll(node->itmLeft);
        node->itmRight = ClearAll(node->itmRight);

        Item *itm = node;
        node = NULL;
        free(itm);

        iTotalNum--;
    }
    return node;
}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::btClearAllClick(TObject *Sender)
{
    //如果有資料就刪除
    if (itmRoot) {
        delete[] wrItems;
        wrItems = NULL;

        itmRoot = ClearAll(itmRoot);
    }

    PrintItems();
    memSolution->Lines->Add("資料已清空");

}
//---------------------------------------------------------------------------
//宣告 Heap Array 需要的 Node
typedef struct Node {

    int iLevel;
    int iUpperBound;
    int iLowerBound;
    int iNowProfit;
    int iNowWeight;

} Node;

Node *ndHeapArray;
int iHeapCount;
//---------------------------------------------------------------------------
void InsertHeap(Node u) {

    iHeapCount++;
    int i = iHeapCount;

    while ((i > 1) && u.iUpperBound > ndHeapArray[i/2].iUpperBound) {
        ndHeapArray[i] = ndHeapArray[i/2];
        i /= 2;
    }

    ndHeapArray[i] = u;
}
//---------------------------------------------------------------------------
Node DeleteHeap() {

    Node x = ndHeapArray[1];
    ndHeapArray[1] = ndHeapArray[iHeapCount];
    iHeapCount--;

    int i = 1, j;

    while (i <= iHeapCount/2) {
        j = (ndHeapArray[2*i].iUpperBound > ndHeapArray[2*i +1].iUpperBound)
            ? 2*i : 2*i +1;

        if (ndHeapArray[i].iUpperBound > ndHeapArray[j].iUpperBound)
            break;

        swap(ndHeapArray[i], ndHeapArray[j]);

        i = j;
    }

    return x;

}
//---------------------------------------------------------------------------
//找出 Upper Bound 與 LowerBound
int UpperBound(Node u) {

    int i = u.iLevel +1;
    Item *itm;

    while (i < iTotalNum) {
        itm = wrItems[i].itm;

        if (u.iNowWeight + itm->iWeight > iBagCapacity)
            break;

        u.iNowProfit += itm->iProfit;
        u.iNowWeight += itm->iWeight;
        i++;

    }

    return -u.iNowProfit;
}
//---------------------------------------------------------------------------
int LowerBound(Node u) {

    int i = u.iLevel +1;
    Item *itm;

    while (i < iTotalNum) {
        itm = wrItems[i].itm;

        if (u.iNowWeight + itm->iWeight > iBagCapacity) {
            float fTemp = float(iBagCapacity - u.iNowWeight) / itm->iWeight * itm->iProfit;
            u.iNowProfit += fTemp;


            break;
        }

        u.iNowProfit += itm->iProfit;
        u.iNowWeight += itm->iWeight;
        i++;

    }

    return -u.iNowProfit;
}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::btBranchAndBoundClick(TObject *Sender)
{
    //如果已存在 ndHeapArray 先清除
    if (ndHeapArray) {
        delete[] ndHeapArray;
        ndHeapArray = NULL;
    }

    //讀入背包限制
    iBagCapacity = StrToInt(edBagCapacity->Text);

    //產生 Heap 陣列
    iHeapCount = 0;
    ndHeapArray = new Node[iTotalNum +1];

    //產生 Heap 的第一個節點
    Node u, v;
    u.iLevel = -1;
    u.iNowProfit = 0;
    u.iNowWeight = 0;
    u.iUpperBound = UpperBound(u);
    u.iLowerBound = LowerBound(u);

    InsertHeap(u);

    Item *itm;
    int iNowUpper = INT_MAX;

    while (iHeapCount > 0) {
        u = DeleteHeap();

        if (u.iLevel == iTotalNum-1)
            continue;

        v.iLevel = u.iLevel +1;
        itm = wrItems[v.iLevel].itm;

        //現在的重量加下一個 Item 的重量沒超過限重
        //才去計算 UpperBound 與 LowerBound
        if (u.iNowWeight + itm->iWeight <= iBagCapacity) {

            //拿這個東西
            v.iNowProfit = u.iNowProfit + itm->iProfit;
            v.iNowWeight = u.iNowWeight + itm->iWeight;
            v.iUpperBound = UpperBound(v);
            v.iLowerBound = LowerBound(v);


            if (v.iUpperBound > v.iLowerBound && v.iLowerBound < iNowUpper)
                InsertHeap(v);

            if (v.iUpperBound < iNowUpper)
                iNowUpper = v.iUpperBound;

        }

        //不拿這個東西
        v.iNowProfit = u.iNowProfit;
        v.iNowWeight = u.iNowWeight;
        v.iUpperBound = UpperBound(v);
        v.iLowerBound = LowerBound(v);

        if (v.iUpperBound > v.iLowerBound && v.iLowerBound < iNowUpper)
            InsertHeap(v);

        if (v.iUpperBound < iNowUpper)
            iNowUpper = v.iUpperBound;

    }

    memSolution->Lines->Add("----------------------------------------------");
    memSolution->Lines->Add("Maximum possible profit:");
    memSolution->Lines->Add(-iNowUpper);

}
//---------------------------------------------------------------------------

