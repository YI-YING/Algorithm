//---------------------------------------------------------------------------

#include <vcl.h>
#include <algorithm.h>
#pragma hdrstop

#include "MST_KruscalAndPrim.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMST *fMST;
//---------------------------------------------------------------------------
__fastcall TfMST::TfMST(TComponent* Owner)
        : TForm(Owner)
{
}
/****************************************************************************
 *declare function which button GenerateG will use
 ****************************************************************************/
void DeleteGraph()
{
    for (int i = 0; i < iVertexNum; i++)
        delete[] iGraphicArray[i];
    delete[] iGraphicArray;
}
//---------------------------------------------------------------------------
void DeleteEdges()
{
    for (int i = 1; i < iEdges+1; i++)
        delete[] iEdgesArray[i];
    delete[] iEdgesArray;
}
//---------------------------------------------------------------------------
void GenerateGraph()
{
    iGraphicArray = new int* [iVertexNum];
    for (int i = 0; i < iVertexNum; i++)
        iGraphicArray[i] = new int [iVertexNum];

    iEdges = 0;
    int k;
    for (int i = 0; i < iVertexNum; i++)
        for (int j = i; j < iVertexNum; j++)
            {
            k = rand()%100 +1;

            iGraphicArray[i][j] = (k > iWeightLimit)? iWeightMax : k;

            if (i == j)
                iGraphicArray[i][j] =  iWeightMax;
            iGraphicArray[j][i] = iGraphicArray[i][j];

            if (iGraphicArray[i][j] != iWeightMax)
                iEdges++;
            }
}
//---------------------------------------------------------------------------
void PrintGraph()
{
    fMST->sgAjacentMatrix->RowCount = iVertexNum;
    fMST->sgAjacentMatrix->ColCount = iVertexNum;
    for (int i = 0; i < iVertexNum; i++)
        for (int j = 0; j < iVertexNum; j++)
            fMST->sgAjacentMatrix->Cells[j][i] = iGraphicArray[i][j];
}
//---------------------------------------------------------------------------
void __fastcall TfMST::btGenerateGClick(TObject *Sender)
{
//  �p�G�w�s�b�@�۾F�x�}�A���N���k�٨t��
    if (iGraphicArray != NULL)
        {
        DeleteGraph();
        iGraphicArray = NULL;
        }

//  �p�G�w�s�b�@ Edges �x�}�A���N���k�٨t��
    if (iEdgesArray != NULL)
        {
        DeleteEdges();
        iEdgesArray = NULL;
        }

//  Ū���ϥΪ̿�J
    iVertexNum = StrToInt(edVertexNum->Text);
    iWeightRange = StrToInt(edWeightRange->Text);
    iWeightLimit = StrToInt(edWeightLimit->Text);
    iWeightMax = StrToInt(edWeightMax->Text);

//  ���ͬ۾F�x�}
    GenerateGraph();

//  ��ܬ۾F�x�}
    if (cbPrintG->Checked)
        {
        PrintGraph();
        }

}
/****************************************************************************
 *declare function which button Kruscal will use
 ****************************************************************************/
void InsertHeap(int x)
{
    iHeapCount++;
    int i = iHeapCount;

    while ((i >1) && (iEdgesArray[x][2] < iEdgesArray[iHeapArray[i/2]][2]))
        {
        iHeapArray[i] = iHeapArray[i/2];
        i/=2;
        }
    iHeapArray[i] = x;
}
//---------------------------------------------------------------------------
int DeleteHeap()
{
    int x = iHeapArray[1];
    iHeapArray[1] = iHeapArray[iHeapCount];
    iHeapCount--;
    int i = 1,j;

    while (i <= iHeapCount/2)
        {
        j = (iEdgesArray[iHeapArray[2*i]][2]
            < iEdgesArray[iHeapArray[2*i+1]][2]) ? 2*i : 2*i +1;
        if (iEdgesArray[iHeapArray[i]][2] < iEdgesArray[iHeapArray[j]][2])
            break;
        swap(iHeapArray[i],iHeapArray[j]);
        i = j;
        }
    return x;
}
//---------------------------------------------------------------------------
void GraphToEdges()
{
    iEdgesArray = new int* [iEdges +1];
    for (int i = 1; i < iEdges+1; i++)
        iEdgesArray[i] = new int [3];

    int k = 1;
    for (int i = 0; i < iVertexNum; i++)
        for (int j = i+1; j < iVertexNum; j++)
            {
            if (iGraphicArray[i][j] != iWeightMax)
                {
                iEdgesArray[k][0] = i;
                iEdgesArray[k][1] = j;
                iEdgesArray[k][2] = iGraphicArray[i][j];
                k++;
                }
            }
}
//---------------------------------------------------------------------------
void PrintEdges()
{
    fMST->sgEdgesMatrix->RowCount = iEdges;
    fMST->sgEdgesMatrix->ColCount = 3;
    for (int i = 0; i < iEdges; i++)
        for (int j = 0; j < 3; j++)
            fMST->sgEdgesMatrix->Cells[j][i] = iEdgesArray[i+1][j];
}
//---------------------------------------------------------------------------
void __fastcall TfMST::btKruscalClick(TObject *Sender)
{
//  �p�G�w�s�b�@ Edges �x�}�A���N���k�٨t��
    if (iEdgesArray != NULL)
        {
        DeleteEdges();
        iEdgesArray = NULL;
        }

//  �N�۾F�x�}�ഫ�� E x 3 �x�}
    GraphToEdges();

//  �L�X Edges �x�}
    PrintEdges();

//  �p�G�w�s�b�@ Heap �x�}�A���N���k�٨t��
    if (iHeapArray != NULL)
        {
        delete[] iHeapArray;
        iHeapArray = NULL;
        }

//  ���ͤ@ Heap �x�}
    iHeapCount = 0;
    iHeapArray = new int [iEdges +1];

    for (int j = 1; j < iEdges+1; j++)
        InsertHeap(j);
}
//---------------------------------------------------------------------------

