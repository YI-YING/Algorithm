//---------------------------------------------------------------------------

#include <vcl.h>
#include <time.h>
#include <Algorithm.h>
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
//define function DataClear, AddRandomData
void DataClear(int **data)
{
    int *iOld = *data;
    *data = NULL;
    free(iOld);
}
//---------------------------------------------------------------------------
void AddRandomData(int **array)
{
    int *iNew = new int[uiNum];
    for (i = 0; i < uiNum; i++)
        iNew[i] = rand() % uiRange + 1;

    *array = iNew;
}
//---------------------------------------------------------------------------
// define function ShowRandomData
void ShowRandomData()
{
    Form1->Memo1->Lines->Clear();
    if (Form1->cbShowData->Checked)
        {
        for (i = 0; i < uiNum; i++)
            Form1->Memo1->Lines->Add(IntToStr(i+1)+":\t"+StrToInt(iRandomData[i]));
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btRandomClick(TObject *Sender)
{
    uiNum = StrToInt(edNum->Text);
    uiRange = StrToInt(edRange->Text);

    if (iRandomData != NULL)
        DataClear(&iRandomData);
    AddRandomData(&iRandomData);

    ShowRandomData();

}
//---------------------------------------------------------------------------
//define function InsertHeap, DeleteHeap
int iHeapNum = 0;
void InsertHeap(int x)
{
    iHeapNum++;
    int i = iHeapNum;

    while (i > 1 && x < iHeap[i/2])
        {
        iHeap[i] = iHeap[i/2];
        i/=2;
        }
    iHeap[i] = x;
}
//---------------------------------------------------------------------------
int DeleteHeap()
{
    int i,j,x;

    x = iHeap[1];
    iHeap[1] = iHeap[iHeapNum];
    iHeapNum--;
    i = 1;

    while (i <= iHeapNum/2)
        {
        j = iHeap[2*i] < iHeap[2*i +1] ? 2*i : 2*i +1;

        if (iHeap[i] < iHeap[j]) break;
        swap(iHeap[i], iHeap[j]);
        i = j;
        }
    return x;
}
//---------------------------------------------------------------------------
//define function ShowResult
void ShowResult()
{
    Form1->Memo2->Lines->Clear();
    if (Form1->cbShowResult->Checked)
        {
        for (i = 0; i < uiNum; i++)
            Form1->Memo2->Lines->Add(IntToStr(i+1)+":\t"+StrToInt(iResultData[i]));
        }
}
//---------------------------------------------------------------------------
//implementation Thread Method
_fastcall TMyThread::TMyThread(void):TThread(true)
{
    FreeOnTerminate=true;
    Resume();
}
//---------------------------------------------------------------------------
void __fastcall TMyThread::Execute()//°õ¦æºü function
{
    clock_t ckStart = clock();

    for (i = 0; i < uiNum; i++)
        InsertHeap(iRandomData[i]);
    for (i = 0; i < uiNum; i++)
        iResultData[i] = DeleteHeap();

    clock_t ckEnd = clock();
    float fCostTime = float(ckEnd - ckStart)/CLK_TCK;
    Form1->lblCPUTime->Caption = "CPU Time(s) = " + FloatToStr(fCostTime);

    ShowResult();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btHeapClick(TObject *Sender)
{
    if (iHeap != NULL)
        DataClear(&iHeap);
    iHeap = new int[uiNum+1];

    if (iResultData != NULL)
        DataClear(&iResultData);
    iResultData = new int[uiNum];

    lblCPUTime->Caption = "CPU Time(s) = Sorting ...";

    TMyThread *MyThread;
    MyThread = new TMyThread();
}
//---------------------------------------------------------------------------

