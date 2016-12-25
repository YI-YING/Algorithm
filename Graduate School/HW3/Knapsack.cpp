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

}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::edItemNumChange(TObject *Sender)
{
    TEdit *edTemp = (TEdit*)Sender;

    if (edTemp->Text == "")
        return ;

    if (StrToInt(edTemp->Text) > 65535)
        edTemp->Text = "65535";

}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::edItemNumExit(TObject *Sender)
{
    TEdit *edTemp = (TEdit*)Sender;

    if (edTemp->Text != "")
        return ;

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

        default:
            edTemp->Text = "34";
    }

}
//---------------------------------------------------------------------------
//Generate Items
void GenerateItems() {

    iItems = new int* [2];
    for (int i = 0; i < 2; i++)
        iItems[i] = new int [iItemNum];

    for (int i = 0; i < iItemNum; i++) {
        iItems[0][i] = rand() % iWeightRange + 1;
        iItems[1][i] = rand() % iProfitRange + 1;
    }

}
//---------------------------------------------------------------------------
//Print Items
void  PrintItems() {

    TStringGrid *sgItems = fKnapsack->sgItems;

    sgItems->CleanupInstance();
    sgItems->RowCount = 3;
    sgItems->ColCount = iItemNum + 1;

    sgItems->Cells[0][0] = "i";
    sgItems->Cells[0][1] = "Weight";
    sgItems->Cells[0][2] = "Profit";

    for (int i = 1; i <= iItemNum; i++) {
        sgItems->Cells[i][0] = i;
        sgItems->Cells[i][1] = iItems[0][i];
        sgItems->Cells[i][2] = iItems[1][i];
    }

}
//---------------------------------------------------------------------------
void __fastcall TfKnapsack::btGenerateClick(TObject *Sender)
{
    if (iItems) {
        for (int i = 0; i < 2; i++)
            delete[] iItems[i];
        delete[] iItems;

        iItems = NULL;
    }

    //讀取使用者輸入
    iItemNum = StrToInt(edItemNum->Text);
    iWeightRange = StrToInt(edWeightRange->Text);
    iProfitRange = StrToInt(edProfitRange->Text);
    iBagCapacity = StrToInt(edBagCapacity->Text);

    //產生 Items 的重量以及價值
    GenerateItems();

    if (cbPrintItems->Checked)
        PrintItems();

}
//---------------------------------------------------------------------------


