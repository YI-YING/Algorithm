//---------------------------------------------------------------------------

#include <vcl.h>
#include <climits>
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

    //���� Items �����q�H�λ���
    AddItems();

    //���ͷs�� wrItems �}�C
    iTotalNum += iItemNum;    //�Ψӭp��{�b�`�@���h�ָ��
    wrItems = new Wrap [iTotalNum];

    //�Τ��Ǩ��X��ñN���G�s�� wrItems
    InorderTraversal(itmRoot, wrItems, 0);

    //��ܩҦ���ơA�� CP �Ȱ���C���
    if (cbPrintItems->Checked)
        PrintItems();

}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::btBranchAndBoundClick(TObject *Sender)
{

    //Ū�J�I�]����
    iBagCapacity = StrToInt(edBagCapacity->Text);

}
//---------------------------------------------------------------------------

