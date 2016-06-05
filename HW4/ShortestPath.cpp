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
 *GenerateG button 會使用到的 Function
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

//  無向圖相鄰矩陣
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

//  有向圖相鄰矩陣
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

//  如果已經有一相鄰矩陣，將其歸還系統
    if (iGraphArray != NULL)
        {
        DeleteGraph();
        iGraphArray = NULL;
        }

//  讀取使用者輸入
    iVertexNum = StrToInt(edVertexNum->Text);
    iRange = StrToInt(edRange->Text);
    iWeightLimit = StrToInt(edWeightLimit->Text);
    iWeightMax = StrToInt(edWeightMax->Text);


//  產生相鄰矩陣
    GenerateGraph();

//  印出相鄰矩陣
    if (cbPrintG->Checked)
        PrintGraph();

}
//---------------------------------------------------------------------------
void __fastcall TfShowtestPath::btSingleSourceClick(TObject *Sender)
{
//  讀取使用者輸入
    iSource = StrToInt(edSource->Text);

//  常用區域變數
    int i,j,k;

//  儲存距離的矩陣
    int **iDistance = new int* [iVertexNum];
    for (i = 0; i < iVertexNum; i++)
        iDistance[i] = new int [iVertexNum];

//  設定行標題
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

//  設定列標題以及找出起點到其他點的距離
    for (j = 0; j < iVertexNum; j++)
        {
        //找出起點到其他點的距離
        iDistance[j][0] = (j != iSource)? iGraphArray[iSource][j] : 0;
        //sgSSADTables->Cells[1][j +1] = iDistance[j][0];

        //設定列標題
        sgSSADTables->Cells[0][j +1] = j;

        if ((iGraphArray[iSource][j] != iWeightMax) || (j == iSource))
            sgSSADTables->Cells[iVertexNum +1][j +1] = iSource;
        }

//  產生一布林陣列 用以紀錄是否找到最小路徑
    bool *bFound = new bool[iVertexNum];
    for (i = 0; i < iVertexNum; i++)
        bFound[i] = (i != iSource) ? false : true;

//  開始尋找起點至其他點最短路徑
    i = 0;
    while (i < iVertexNum -1)
        {
        //先找出尚未找到最小路徑的點
        for (j = 0; j < iVertexNum; j++)
            {
            if (bFound[j] == false)
                {
                k = j;
                break;
                }
            }
        //由尚未找到最小路徑的點中找路徑最小的點
        for (j = 0; j < iVertexNum; j++)
            {
            if ((bFound[j] == false) &&
                (iDistance[j][i] < iDistance[k][i]))
                    k = j;
            }
        bFound[k] = true;

        //更新路徑距離
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

//  記憶體管理
    for (i = 0; i < iVertexNum; i++)
        delete[] iDistance[i];
    delete[] iDistance;
    delete[] bFound;
}
//---------------------------------------------------------------------------


