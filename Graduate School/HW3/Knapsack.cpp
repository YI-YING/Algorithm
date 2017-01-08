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

    //unsigned long �Ȧs�ܼ�
    DWord fstyle;

    //���o��J�ت���l�]�w��T
    fstyle = GetWindowLong(edTemp->Handle, GWL_STYLE);

    //�]�w�u���J�Ʀr�H�Τ�r�n�m��
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

    //����Ʀr�b 65535 ��
    if (StrToInt(edTemp->Text) > 65535)
        edTemp->Text = "65535";

}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::edItemNumExit(TObject *Sender)
{
    TEdit *edTemp = (TEdit*)Sender;

    if (edTemp->Text != "" && StrToInt(edTemp->Text) != 0)
        return ;

    //�p�G�O�Ŧr��μƭȬ��s�h�]�w��l��
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
 *�ŧi struct Item
 ***************************************************************************/
typedef struct Item {

    int iWeight;    //���q
    int iProfit;    //����
    float fRatio;   //���

    Item *itmLeft;  //����`�I
    Item *itmRight; //�k��`�I
} Item;

Item *itmRoot;    //�ڸ`�I
//---------------------------------------------------------------------------
//�s���`�I
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
//�s Item
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
//�ΨӱN Item* �ʸ�
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
//���Ǩ��X��ñN���G�s�b wrItems �}�C
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
    //�p�G�w�s�b�}�C wrItems �N���M��
    if (wrItems) {
        delete[] wrItems;
        wrItems = NULL;
    }

    //Ū���ϥΪ̿�J
    iItemNum = StrToInt(edItemNum->Text);
    iWeightRange = StrToInt(edWeightRange->Text);
    iProfitRange = StrToInt(edProfitRange->Text);

    //�üƲ��� Items �����q�H�λ���
    //�å[�J itmRoot
    AddItems();

    //���ͷs�� wrItems �}�C
    iTotalNum += iItemNum;    //�Ψӭp��{�b�`�@���h�ָ��
    wrItems = new Wrap [iTotalNum];

    //�Τ��Ǩ��X��ñN���G�s�� wrItems
    InorderTraversal(itmRoot, wrItems, 0);

    //��ܩҦ���ơA�� CP �Ȱ���C���
    if (cbPrintItems->Checked)
        PrintItems();

    memSolution->Lines->Add(edItemNum->Text + " ���üƸ�Ʒs�W����");

}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::btAddItemClick(TObject *Sender)
{
    //�p�G�w�s�b�}�C wrItems �N���M��
    if (wrItems) {
        delete[] wrItems;
        wrItems = NULL;
    }

    //Ū���ϥΪ̿�J
    int iItemWeight = StrToInt(edItemWeight->Text);
    int iItemProfit = StrToInt(edItemProfit->Text);

    itmRoot = AddItem(itmRoot, iItemWeight, iItemProfit);

    //���ͷs�� wrItems �}�C
    iTotalNum += 1;    //�Ψӭp��{�b�`�@���h�ָ��
    wrItems = new Wrap [iTotalNum];

    //�Τ��Ǩ��X��ñN���G�s�� wrItems
    InorderTraversal(itmRoot, wrItems, 0);

    //��ܩҦ���ơA�� CP �Ȱ���C���
    if (cbPrintItems->Checked)
        PrintItems();

    memSolution->Lines->Add("1 ����Ʒs�W����");

}
//---------------------------------------------------------------------------
//���j�R�����
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
    //�p�G����ƴN�R��
    if (itmRoot) {
        delete[] wrItems;
        wrItems = NULL;

        itmRoot = ClearAll(itmRoot);
    }

    PrintItems();
    memSolution->Lines->Add("��Ƥw�M��");

}
//---------------------------------------------------------------------------
//�ŧi Heap Array �ݭn�� Node
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
//��X Upper Bound �P LowerBound
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
    //�p�G�w�s�b ndHeapArray ���M��
    if (ndHeapArray) {
        delete[] ndHeapArray;
        ndHeapArray = NULL;
    }

    //Ū�J�I�]����
    iBagCapacity = StrToInt(edBagCapacity->Text);

    //���� Heap �}�C
    iHeapCount = 0;
    ndHeapArray = new Node[iTotalNum +1];

    //���� Heap ���Ĥ@�Ӹ`�I
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

        //�{�b�����q�[�U�@�� Item �����q�S�W�L����
        //�~�h�p�� UpperBound �P LowerBound
        if (u.iNowWeight + itm->iWeight <= iBagCapacity) {

            //���o�ӪF��
            v.iNowProfit = u.iNowProfit + itm->iProfit;
            v.iNowWeight = u.iNowWeight + itm->iWeight;
            v.iUpperBound = UpperBound(v);
            v.iLowerBound = LowerBound(v);


            if (v.iUpperBound > v.iLowerBound && v.iLowerBound < iNowUpper)
                InsertHeap(v);

            if (v.iUpperBound < iNowUpper)
                iNowUpper = v.iUpperBound;

        }

        //�����o�ӪF��
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

