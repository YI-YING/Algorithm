//---------------------------------------------------------------------------

#include <vcl.h>
#include <Algorithm.h>
#pragma hdrstop

#include "SortingAlgorithm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfSortingAlgorithm *fSortingAlgorithm;
//---------------------------------------------------------------------------
__fastcall TfSortingAlgorithm::TfSortingAlgorithm(TComponent* Owner)
        : TForm(Owner)
{
}
/****************************************************************************
 *演算法
 ****************************************************************************/
void SelectionSort(int *iData)
{
    int i,j;
    int iMin;

    for (i = 0; i < iNum -1; i++)
        {
        iMin = i;
        for (j = i +1; j < iNum; j++)
            if (iData[j] < iData[iMin])
                iMin = j;
        swap(iData[i],iData[iMin]);
        }
}
//---------------------------------------------------------------------------
void InsertSort(int *iData)
{
    int i,j;
    int iTarget;

    for (i = 1; i < iNum; i++)
        {
        iTarget = iData[i];
        j = i;

        while (iData[j -1] > iTarget && j > 0)
            {
            iData[j] = iData[j -1];
            j--;
            }
        iData[j] = iTarget;
        }
}
//---------------------------------------------------------------------------
void BubleSort(int *iData)
{
    int i,j;

    for (i = 0; i < iNum; i++)
        for (j = 1; j < iNum - i; j++)
            if (iData[j -1] > iData[j])
                swap(iData[j -1], iData[j]);
}
//---------------------------------------------------------------------------
void QuickSort(int *iData, int iLeft, int iRight)
{
    int i,j;
    int iTarget;

    if (iLeft < iRight)
        {
        i = iLeft +1;
        j = iRight;
        iTarget = iData[iLeft];

        do
            {
            while (iData[i] < iTarget && i <= j) i++;
            while (iData[j] >= iTarget && i <= j) j--;

            if (i < j) swap(iData[i],iData[j]);
            }
        while (i < j);

        if (iLeft < j) swap(iData[iLeft], iData[j]);

        QuickSort(iData, iLeft, j -1);
        QuickSort(iData, j +1, iRight);
        }
}
//---------------------------------------------------------------------------
void restore(int *iData, int s, int t)
{
    int i = s, j;
    while (i <= t/2)
        {
        j = (iData[2*i] < iData[2*i +1])? 2*i: 2*i +1;

        if (iData[i] < iData[j]) break;

        swap(iData[i], iData[j]);
        i = j;
        }
}
//---------------------------------------------------------------------------
void HeapSort(int *iData)
{
    int *iTemp = new int [iNum +1];
    int i;

    for (i = 1; i < iNum +1; i++)
        iTemp[i] = iData[i -1];

    for (i = iNum/2; i >= 1; i--)
        restore(iTemp, i, iNum);

    for (i = iNum; i > 1; i--)
        {
        iData[iNum -i] = iTemp[1];

        iTemp[1] = iTemp[i];

        restore(iTemp, 1, i -1);
        }

    delete[] iTemp;
}
//---------------------------------------------------------------------------
void Merge(int C[], int k, int A[], int i, int m,
     int B[], int j, int n)
{
    while ((i <= m) && (j <= n))
        {

        if (A[i] <= B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
        }
    while (i <= m) C[k++] = A[i++];
    while (j <= n) C[k++] = B[j++];
}
//---------------------------------------------------------------------------
void MergeSort(int A[], int iLeft, int iRight)
{
    String s = "";

    for (int i = iLeft; i < iRight; i++)
        s += IntToStr(A[i]) + " ";
    ShowMessage(s);

    int m;
    if (iLeft < iRight)
        {
        m = (iLeft + iRight) / 2;

        MergeSort(A, iLeft, m);
        MergeSort(A, m +1, iRight);

        Merge(A, iLeft, A, iLeft, m, A, m +1, iRight);
        }
}
//---------------------------------------------------------------------------
void __fastcall TfSortingAlgorithm::btDrawDiagramClick(TObject *Sender)
{
//  取得使用者設定
    iTimes = StrToInt(edTimes->Text);
    iNum = StrToInt(edNum->Text);
    iRange = StrToInt(edRange->Text);

    int i,j,k;              //區域變數
    int *iData, *iOrder;    //亂數資料、排序好後的資料
    String sData, sOrder;   //用來輸出結果的字串

//  開始執行演算法
    memData->Clear();
    for (i = 0; i < iTimes; i++)
        {
        iData = new int[iNum];
        for (k = 0; k < iNum; k++)
            iData[k] = rand()%iRange;

        for (j = 0; j < clbAlgorithms->Items->Count; j++)
            {
            if (!clbAlgorithms->Checked[j])
                continue;

            iOrder = new int [iNum];
            for (k = 0; k < iNum; k++)
                iOrder[k] = iData[k];

            switch (j)
                {
                case 0:
                    {
                    SelectionSort(iOrder);

                    if (cbSeeData->Checked)
                        memData->Lines->Add("Selection Sort :");
                    }
                    break;
                case 1:
                    {
                    InsertSort(iOrder);

                    if (cbSeeData->Checked)
                        memData->Lines->Add("Insert Sort :");
                    }
                    break;
                case 2:
                    {
                    BubleSort(iOrder);
                    if (cbSeeData->Checked)
                        memData->Lines->Add("Bubble Sort :");
                    }
                    break;
                case 3:
                    {
                    QuickSort(iOrder, 0, iNum);

                    if (cbSeeData->Checked)
                        memData->Lines->Add("Quick Sort :");
                    }
                    break;
                case 4:
                    {
                    HeapSort(iOrder);

                    if (cbSeeData->Checked)
                        memData->Lines->Add("Heap Sort :");
                    }
                    break;
                case 5:
                    {
                    MergeSort(iOrder, 0, iNum -1);

                    if (cbSeeData->Checked)
                        memData->Lines->Add("Merge Sort :");
                    }
                    break;
                case 6:
                    {

                    if (cbSeeData->Checked)
                        memData->Lines->Add("Radix Sort :");
                    }
                    break;
                }
            if (cbSeeData->Checked)
                {
                sData = sOrder = "";

                for (k = 0; k < iNum; k++)
                    {
                    sData += IntToStr(iData[k]) + "_";
                    sOrder += IntToStr(iOrder[k]) + "_";
                    }
                memData->Lines->Add("Init data : " + sData);
                memData->Lines->Add("Order data : " + sOrder);
                }

            delete[] iOrder;
            }
        delete[] iData;
        }

    memCheck->Clear();
    for (i = 0; i < clbAlgorithms->Items->Count; i++)
        if (clbAlgorithms->Checked[i])
            {
            switch (i)
                {
                case 0:
                    memCheck->Lines->Add("----Selection Sort complete----");
                    break;

                case 1:
                    memCheck->Lines->Add("----Insert Sort complete----");
                    break;

                case 2:
                    memCheck->Lines->Add("----Buble Sort complete----");
                    break;

                case 3:
                    memCheck->Lines->Add("----Quick Sort complete----");
                    break;

                case 4:
                    memCheck->Lines->Add("----Heap Sort complete----");
                    break;

                case 5:
                    memCheck->Lines->Add("----Merge Sort complete----");
                    break;

                case 6:
                    memCheck->Lines->Add("----Radix Sort complete----");
                    break;
                }
            }

}
//---------------------------------------------------------------------------

