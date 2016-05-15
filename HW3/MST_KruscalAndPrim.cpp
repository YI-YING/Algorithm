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

//  �p�G�w�s�b�@ Edgea �x�}�A���N���k�٨t��
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
/****************************************************************************
 *declare Node
 ****************************************************************************/
 struct Dsnode
    {
    int iData;
    struct Dsnode *dnParent;
    };
//---------------------------------------------------------------------------
void MakeSet(struct Dsnode *node)
{
    node->dnParent = node;
}
//---------------------------------------------------------------------------
struct Dsnode *Find(struct Dsnode *node)
{
    if (node->dnParent == node)
        return node;
    node->dnParent = Find(node->dnParent);
    return node->dnParent;
}
//---------------------------------------------------------------------------
void Union(struct Dsnode *x, struct Dsnode *y)
{
    struct Dsnode *xParent = Find(x);
    struct Dsnode *yParent = Find(y);

    xParent->dnParent = yParent;
}
//---------------------------------------------------------------------------
void __fastcall TfMST::btKruscalClick(TObject *Sender)
{
//  �p�G�w�s�b�@ Edgea �x�}�A���N���k�٨t��
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

//  ���ͤ@�}�C�Ψ��x�s MST
    int *iMSTArray = new int [iVertexNum -1];
    int iMSTEdges = 0;

//  ���ͥΨӧP�_�O�_�|�y���j�骺 Node �}�C
    struct Dsnode *dVertex = new struct Dsnode [iVertexNum];
    for (int i = 0; i < iVertexNum; i++)
        {
        dVertex[i].iData = i;
        MakeSet(&dVertex[i]);
        }

    iCycleNum = 0;
    int iMin;       //�̤p��
    int iU;         //�̤p��_�l
    int iV;         //�̤p����I

//  Kruscal Algorithm
    while ((iMSTEdges < iVertexNum -1) && iHeapCount > 0)
        {
        iMin = DeleteHeap();
        iU = iEdgesArray[iMin][0];
        iV = iEdgesArray[iMin][1];
        if (Find(&dVertex[iU]) != Find(&dVertex[iV]))
            {
            iMSTArray[iMSTEdges++] = iMin;
            Union(&dVertex[iU], &dVertex[iV]);
            }
        else
            iCycleNum++;
        }

//  �L�X MST
    if (cbPrintEdges->Checked)
        {
        if (iMSTEdges < iVertexNum -1)
            Memo1->Lines->Add("�L���i��");
        else
            {
            for (int i = 0; i < iVertexNum -1; i++)
                {
                iU = iEdgesArray[iMSTArray[i]][0];
                iV = iEdgesArray[iMSTArray[i]][1];
                Memo1->Lines->Add("edge "+ IntToStr(i) + ": (" + IntToStr(iU)
                    + "," + IntToStr(iV) + ") [" + IntToStr(iMSTArray[i]) + "]");
                }
            }
        Memo1->Lines->Add("# edges incurring cycles : " + IntToStr(iCycleNum));
        }

    delete[] iMSTArray, dVertex;
}
//---------------------------------------------------------------------------
void __fastcall TfMST::btPrimClick(TObject *Sender)
{
    int *iC1 = new int [iVertexNum];        //�O���ѽֳs�X
    int *iC2 = new int [iVertexNum];        //���� X �� i �ثe�̵u�Z��
    int **iMSTArray = new int* [iVertexNum];//�s�� MST Edges
    int *iXSet = new int [iVertexNum];      //���� X �w�g�������I
    int iX = 0;
    int iXNum = 1;
    int i;

    for (i = 0; i < iVertexNum; i++)
        {
        iC1[i] = iX; iC2[i] = iWeightMax;
        iXSet[i] = (i == 0)? 1: 0;
        iMSTArray[i] = new int [2];
        }

//  Prim Algorithm
    int iY;
    while (iXNum < iVertexNum)
        {
        for (i = 0; i < iVertexNum; i++)
            {
            if (iXSet[i] == 1) continue;
            if (iGraphicArray[iX][i] < iC2[i])
                {
                iC1[i] = iX; iC2[i] = iGraphicArray[iX][i];
                }
            }
        iY = 0;
        for (i = 0; i < iVertexNum; i++)
            {
            if (iXSet[i] == 1) continue;
            if (iC2[i] < iC2[iY])
                iY = i;
            }
        if (iC2[iY] == iWeightMax)
            break;
        iC2[iY] = iWeightMax;
        iMSTArray[iXNum -1][0] = iC1[iY];
        iMSTArray[iXNum -1][1] = iY;
        iXSet[iY] = 1;
        iX = iY; iXNum++;
        }

//  �L�X MST
    if (iXNum < iVertexNum)
        Memo1->Lines->Add("�L���i��");
    else
        {
        for (i = 0; i < iVertexNum -1; i++)
            Memo1->Lines->Add("edge "+ IntToStr(i) + ": (" + IntToStr(iMSTArray[i][0])
                + "," + IntToStr(iMSTArray[i][1]) + ")");
        }

//  �O����޲z
    for (i = 0; i < iVertexNum; i++)
        delete[] iMSTArray[i];
    delete[] iC1,iC2,iXSet,iMSTArray;
}
//---------------------------------------------------------------------------

