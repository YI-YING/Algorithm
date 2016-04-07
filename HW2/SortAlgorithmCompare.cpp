//---------------------------------------------------------------------------

#include <vcl.h>
#include <time.h>
#pragma hdrstop

#include "SortAlgorithmCompare.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::edNumKeyPress(TObject *Sender, char &Key)
{
    //limit only input number
    if ((Key<48 || Key>57) && Key!=8)
        {
        Key=0;
        ShowMessage("Please enter integer !");
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::edRangeKeyPress(TObject *Sender, char &Key)
{
    //limit only input number
    if ((Key<48 || Key>57) && Key!=8)
        {
        Key=0;
        ShowMessage("Please enter integer !");
        }
}
//---------------------------------------------------------------------------
//define function DataClear
void DataClear(int **data)
{
    int *iOld = *data;
    *data = NULL;
    free(iOld);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btRandomClick(TObject *Sender)
{
    iNum = StrToInt(edNum->Text);
    int iRange = StrToInt(edRange->Text);

    if (iRandomData != NULL)
        DataClear(&iRandomData);
    iRandomData = new int[iNum];
    for (i = 0; i < iNum; i++)
        iRandomData[i] = rand() % iRange + 1;

    clock_t start = clock();
    if (cbShowData->Checked)
        {
        Memo1->Lines->Clear();
        for (i = 0; i < iNum; i++)
            Memo1->Lines->Add(IntToStr(i+1)+":\t"+StrToInt(iRandomData[i]));
        }
    clock_t end = clock();
    float costtime = (float)(end - start)/CLK_TCK;
    lblCPUTime->Caption = "CPU Time(s) = " + FloatToStr(costtime);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btHeapClick(TObject *Sender)
{
    int temp;
}
//---------------------------------------------------------------------------

