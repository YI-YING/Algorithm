//---------------------------------------------------------------------------

#include <vcl.h>
#include <Algorithm.h>
#pragma hdrstop

#include "ShortestPath.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfShowtestPath *fShowtestPath;
//---------------------------------------------------------------------------
__fastcall TfShowtestPath::TfShowtestPath(TComponent* Owner)
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
    if (fShowtestPath->cbUndirectedG->Checked)
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
    fShowtestPath->sgAjacentMatrix->CleanupInstance();
    fShowtestPath->sgAjacentMatrix->ColCount = iVertexNum +1;
    fShowtestPath->sgAjacentMatrix->RowCount = iVertexNum +1;

    for (int i = 0; i < iVertexNum +1; i++)
        for (int j = 0; j < iVertexNum +1; j++)
            {
            if (i == 0 && j ==0) continue;
            
            if (i == 0)
                fShowtestPath->sgAjacentMatrix->Cells[j][i] = j -1;
            else if (j == 0)
                fShowtestPath->sgAjacentMatrix->Cells[j][i] = i -1;
            else
                fShowtestPath->sgAjacentMatrix->Cells[j][i] = iGraphArray[i-1][j-1];
            }
}
//---------------------------------------------------------------------------
void __fastcall TfShowtestPath::btGenerateGClick(TObject *Sender)
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
//---------------------------------------------------------------------------
void __fastcall TfShowtestPath::btSingleSourceClick(TObject *Sender)
{
//  Ū���ϥΪ̿�J
    iSource = StrToInt(edSource->Text);

//  �`�ΰϰ��ܼ�
    int i,j,k;

//  �x�s�Z�����x�}
    int **iDistance = new int* [iVertexNum];
    for (i = 0; i < iVertexNum; i++)
        iDistance[i] = new int [iVertexNum];

//  �]�w����D
    sgSSADTables->CleanupInstance();
    sgSSADTables->ColCount = iVertexNum +2;
    sgSSADTables->RowCount = iVertexNum +1;
    for (i = 1; i < iVertexNum +2; i++)
        {
        if (i != iVertexNum +1)
            sgSSADTables->Cells[i][0] = i -1;
        else
            sgSSADTables->Cells[i][0] = "from";
        }

//  �]�w�C���D�H�Χ�X�_�I���L�I���Z��
    for (j = 0; j < iVertexNum; j++)
        {
        //��X�_�I���L�I���Z��
        iDistance[j][0] = (j != iSource)? iGraphArray[iSource][j] : 0;
        //sgSSADTables->Cells[1][j +1] = iDistance[j][0];

        //�]�w�C���D
        sgSSADTables->Cells[0][j +1] = j;

        if ((iGraphArray[iSource][j] != iWeightMax) || (j == iSource))
            sgSSADTables->Cells[iVertexNum +1][j +1] = iSource;
        }

//  ���ͤ@���L�}�C �ΥH�����O�_���̤p���|
    bool *bFound = new bool[iVertexNum];
    for (i = 0; i < iVertexNum; i++)
        bFound[i] = (i != iSource) ? false : true;

//  �}�l�M��_�I�ܨ�L�I�̵u���|
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

        //��s���|�Z��
        for (j = 0; j < iVertexNum; j++)
            {
            if (!bFound[j])
                {
                if ((iDistance[k][i] + iGraphArray[k][j]) < iDistance[j][i])
                    sgSSADTables->Cells[iVertexNum +1][j +1] = k;

                iDistance[j][i +1] = min(iDistance[j][i],
                    iDistance[k][i] + iGraphArray[k][j]);
                }
            else
                iDistance[j][i +1] = iDistance[j][i];
            }
        i++;
        }

//  Print SSADTables
    if (cbPrintResult->Checked)
        {
        for (j = 0; j < iVertexNum; j++)
            for (i = 0; i < iVertexNum; i++)
                sgSSADTables->Cells[i +1][j +1] = iDistance[j][i];
        }

//  �O����޲z
    for (i = 0; i < iVertexNum; i++)
        delete[] iDistance[i];
    delete[] iDistance;
    delete[] bFound;
}
//---------------------------------------------------------------------------


