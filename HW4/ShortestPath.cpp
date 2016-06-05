//---------------------------------------------------------------------------

#include <vcl.h>
#include <Algorithm.h>
#pragma hdrstop

#include "ShortestPath.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfShortestPath *fShortestPath;
//---------------------------------------------------------------------------
__fastcall TfShortestPath::TfShortestPath(TComponent* Owner)
    : TForm(Owner)
{
}
/****************************************************************************
 *GenerateG button �|�ϥΨ쪺 Function
 ****************************************************************************/
void DeleteGraph()
{
    for (int i=0; i < iVertexNum; i++)
        delete[] iGraphArray[i];
    delete[] iGraphArray;
}
//---------------------------------------------------------------------------
void GenerateGraph()
{
    iGraphArray = new int* [iVertexNum];
    for (int i = 0; i < iVertexNum; i++)
        iGraphArray[i] = new int [iVertexNum];

//  �L�V�Ϭ۾F�x�}
    int k;
    randomize();
    if (fShortestPath->cbUndirectedG->Checked)
        {
        for (int i = 0; i < iVertexNum; i++)
            for (int j = 0; j < iVertexNum; j++)
                {
                k = rand() % iRange + 1;
                iGraphArray[i][j] = (k > iWeightLimit)? iWeightMax: k;

                if (i == j)
                    iGraphArray[i][j] = iWeightMax;
                iGraphArray[j][i] = iGraphArray[i][j];
                }
        }

//  ���V�Ϭ۾F�x�}
    else
        {
        for (int i = 0; i < iVertexNum; i++)
            for (int j = 0; j < iVertexNum; j++)
                {
                k = rand() % iRange + 1;
                iGraphArray[i][j] = (k > iWeightLimit)? iWeightMax: k;

                if (i == j)
                    iGraphArray[i][j] = iWeightMax;
                }
        }
}
//---------------------------------------------------------------------------
void PrintGraph()
{
    fShortestPath->sgAjacentMatrix->CleanupInstance();
    fShortestPath->sgAjacentMatrix->ColCount = iVertexNum +1;
    fShortestPath->sgAjacentMatrix->RowCount = iVertexNum +1;

    for (int i = 0; i < iVertexNum +1; i++)
        for (int j = 0; j < iVertexNum +1; j++)
            {
            if (i == 0 && j ==0) continue;
            
            if (i == 0)
                fShortestPath->sgAjacentMatrix->Cells[j][i] = j -1;
            else if (j == 0)
                fShortestPath->sgAjacentMatrix->Cells[j][i] = i -1;
            else
                fShortestPath->sgAjacentMatrix->Cells[j][i] = iGraphArray[i-1][j-1];
            }
}
//---------------------------------------------------------------------------
void __fastcall TfShortestPath::btGenerateGClick(TObject *Sender)
{

//  �p�G�w�g���@�۾F�x�}�A�N���k�٨t��
    if (iGraphArray != NULL)
        {
        DeleteGraph();
        iGraphArray = NULL;
        }

//  Ū���ϥΪ̿�J
    iVertexNum = StrToInt(edVertexNum->Text);
    iRange = StrToInt(edRange->Text);
    iWeightLimit = StrToInt(edWeightLimit->Text);
    iWeightMax = StrToInt(edWeightMax->Text);


//  ���ͬ۾F�x�}
    GenerateGraph();

//  �L�X�۾F�x�}
    if (cbPrintG->Checked)
        PrintGraph();

}
/****************************************************************************
 *Single Source button �|�ϥΨ쪺 Function
 ****************************************************************************/
void FindDistance(int **iDistance)
{
    for (int j = 0; j < iVertexNum; j++)
        {
        iDistance[j][0] = (j != iSource)? iGraphArray[iSource][j] : 0;

        if ((iGraphArray[iSource][j] != iWeightMax) || (j == iSource))
            iDistance[j][iVertexNum] = iSource;
        }
}
//---------------------------------------------------------------------------
void PrintSSADTables(int **iDistance)
{
    int i,j;
    String s;

//  �L�X Solutions
    for (i = 0; i < iVertexNum; i++)
        {
        if (i == iSource)continue;
        j = i;
        s = "";
        do
            {
            s = "--["+ IntToStr(iGraphArray[iDistance[j][iVertexNum]][j]) +
                "]-->" + IntToStr(j) +s;
            j = iDistance[j][iVertexNum];
            }
        while (j != iSource);

        s = IntToStr(iSource) +s;
        fShortestPath->memSolutions->Lines->Add("The Shortest distance from " +
            IntToStr(iSource) + " to " + IntToStr(i) + " is " + IntToStr(iDistance[i][iVertexNum -1]) +" with path " +s);
        }

//  �L�X SSADTables
    fShortestPath->sgSSADTables->CleanupInstance();
    fShortestPath->sgSSADTables->ColCount = iVertexNum +2;
    fShortestPath->sgSSADTables->RowCount = iVertexNum +1;

    for (i = 1; i < iVertexNum +2; i++)
        {
        //�]�w����D
        if (i != iVertexNum +1)
            fShortestPath->sgSSADTables->Cells[i][0] = i -1;
        else
            fShortestPath->sgSSADTables->Cells[i][0] = "from";

        //�]�w�C���D
        if (i < iVertexNum +1)
            fShortestPath->sgSSADTables->Cells[0][i] = i -1;
        }
    for (j = 0; j < iVertexNum; j++)
        for (i = 0; i < iVertexNum +1; i++)
            fShortestPath->sgSSADTables->Cells[i +1][j +1] = iDistance[j][i];
}
//---------------------------------------------------------------------------
void FindSSADSolution(bool *bFound, int **iDistance)
{
    int i,j,k;

    i = 0;
    while (i < iVertexNum -1)
        {
        //����X�|�����̤p���|���I
        for (j = 0; j < iVertexNum; j++)
            {
            if (bFound[j] == false)
                {
                k = j;
                break;
                }
            }
        //�ѩ|�����̤p���|���I������|�̤p���I
        for (j = 0; j < iVertexNum; j++)
            {
            if ((bFound[j] == false) &&
                (iDistance[j][i] < iDistance[k][i]))
                    k = j;
            }
        bFound[k] = true;

        if (fShortestPath->cbPrintResult->Checked)
            fShortestPath->memSolutions->Lines->Add("min = " +IntToStr(k));

        //��s���|�Z��
        for (j = 0; j < iVertexNum; j++)
            {
            if (!bFound[j])
                {
                if ((iDistance[k][i] + iGraphArray[k][j]) < iDistance[j][i])
                    iDistance[j][iVertexNum] = k;

                iDistance[j][i +1] = min(iDistance[j][i],
                    iDistance[k][i] + iGraphArray[k][j]);
                }
            else
                iDistance[j][i +1] = iDistance[j][i];
            }
        i++;
        }
}
//---------------------------------------------------------------------------
void __fastcall TfShortestPath::btSingleSourceClick(TObject *Sender)
{
//  Ū���ϥΪ̿�J
    iSource = StrToInt(edSource->Text);

//  �`�ΰϰ��ܼ�
    int i,j;

//  �x�s�Z�����x�}
    int **iDistance = new int* [iVertexNum];
    for (i = 0; i < iVertexNum; i++)
        iDistance[i] = new int [iVertexNum +1];

//  ��X�_�I���L�I���Z��
    FindDistance(iDistance);

//  ���ͤ@���L�}�C �ΥH�����O�_���̤p���|
    bool *bFound = new bool[iVertexNum];
    for (i = 0; i < iVertexNum; i++)
        bFound[i] = (i != iSource) ? false : true;

//  �}�l�M��_�I�ܨ�L�I�̵u���|
    FindSSADSolution(bFound, iDistance);

//  Print SSADTables
    if (cbPrintResult->Checked)
        {
        PrintSSADTables(iDistance);
        }

//  �O����޲z
    for (i = 0; i < iVertexNum; i++)
        delete[] iDistance[i];
    delete[] iDistance;
    delete[] bFound;
}
//---------------------------------------------------------------------------


