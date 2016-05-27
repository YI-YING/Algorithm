//---------------------------------------------------------------------------

#include <vcl.h>
#include <ctime.h>
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
            k = rand()%iWeightRange +1;

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
//define function ButtonEnable
void ButtonEnable(bool state)
{
    fMST->btGenerateG->Enabled = state;
    fMST->btKruscal->Enabled = state;
    fMST->btPrim->Enabled = state;
}
//---------------------------------------------------------------------------
__fastcall TGenerateGThread::TGenerateGThread(void):TThread(true)
{
    FreeOnTerminate = true;
    Resume();
}
//---------------------------------------------------------------------------
void __fastcall TGenerateGThread::Execute()
{
//  如果已存在一相鄰矩陣，先將其歸還系統
    if (iGraphicArray != NULL)
        {
        DeleteGraph();
        iGraphicArray = NULL;
        }

//  如果已存在一 Edgea 矩陣，先將其歸還系統
    if (iEdgesArray != NULL)
        {
        DeleteEdges();
        iEdgesArray = NULL;
        }

//  讀取使用者輸入
    iVertexNum = StrToInt(fMST->edVertexNum->Text);
    iWeightRange = StrToInt(fMST->edWeightRange->Text);
    iWeightLimit = StrToInt(fMST->edWeightLimit->Text);
    iWeightMax = StrToInt(fMST->edWeightMax->Text);

//  產生相鄰矩陣
    GenerateGraph();

//  顯示相鄰矩陣
    if (fMST->cbPrintG->Checked)
        {
        PrintGraph();
        }
    ButtonEnable(true);
}
//---------------------------------------------------------------------------
void __fastcall TfMST::btGenerateGClick(TObject *Sender)
{
    ButtonEnable(false);

    TGenerateGThread *GenerateThread = new TGenerateGThread();
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
/****************************************************************************
 *implementation Kruscal Thread Constructor & Method
 ****************************************************************************/
__fastcall TKruscalThread::TKruscalThread(void):TThread(true)
{
    FreeOnTerminate=true;
    Resume();
}
//---------------------------------------------------------------------------
void __fastcall TKruscalThread::Execute()
{

//  如果已存在一 Edgea 矩陣，先將其歸還系統
    if (iEdgesArray != NULL)
        {
        DeleteEdges();
        iEdgesArray = NULL;
        }

    clock_t ckStart = clock();

//  將相鄰矩陣轉換成 E x 3 矩陣
    GraphToEdges();

//  印出 Edges 矩陣
    if (fMST->cbPrintEdgesMatrix->Checked)
        PrintEdges();

//  如果已存在一 Heap 矩陣，先將其歸還系統
    if (iHeapArray != NULL)
        {
        delete[] iHeapArray;
        iHeapArray = NULL;
        }

//  產生一 Heap 矩陣
    iHeapCount = 0;
    iHeapArray = new int [iEdges +1];

    for (int j = 1; j < iEdges+1; j++)
        InsertHeap(j);

//  產生一陣列用來儲存 MST
    int *iMSTArray = new int [iVertexNum -1];
    int iMSTEdges = 0;

//  產生用來判斷是否會造成迴圈的 Node 陣列
    struct Dsnode *dVertex = new struct Dsnode [iVertexNum];
    for (int i = 0; i < iVertexNum; i++)
        {
        dVertex[i].iData = i;
        MakeSet(&dVertex[i]);
        }

    iCycleNum = 0;
    int iMin;       //最小邊
    int iU;         //最小邊起始
    int iV;         //最小邊終點

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

    clock_t ckEnd = clock();

//  印出 MST
    if (fMST->cbPrintEdges->Checked)
        {
        if (iMSTEdges < iVertexNum -1)
            fMST->Memo1->Lines->Add("無延展樹");
        else
            {
            for (int i = 0; i < iVertexNum -1; i++)
                {
                iU = iEdgesArray[iMSTArray[i]][0];
                iV = iEdgesArray[iMSTArray[i]][1];
                fMST->Memo1->Lines->Add("edge "+ IntToStr(i) + ": (" + IntToStr(iU)
                    + "," + IntToStr(iV) + ") [" + IntToStr(iMSTArray[i]) + "]");
                }
            }
        fMST->Memo1->Lines->Add("# edges incurring cycles : " + IntToStr(iCycleNum));
        }

    float fCostTime = float(ckEnd - ckStart)/CLK_TCK;

    fMST->Memo1->Lines->Add("Kruscal Algorithm used " + FloatToStr(fCostTime) +" (sec)");

//  記憶體管理
    delete[] iMSTArray, dVertex;

//  將按鈕狀態恢復
    ButtonEnable(true);
}
//---------------------------------------------------------------------------
void __fastcall TfMST::btKruscalClick(TObject *Sender)
{
    ButtonEnable(false);

    TKruscalThread *KruscalThread;
    KruscalThread = new TKruscalThread();
}
//---------------------------------------------------------------------------
__fastcall TPrimThread::TPrimThread(void):TThread(true)
{
    FreeOnTerminate = true;
    Resume();
}
//---------------------------------------------------------------------------
void __fastcall TPrimThread::Execute()
{
    clock_t ckStart = clock();

    int *iC1 = new int [iVertexNum];        //記錄由誰連出
    int *iC2 = new int [iVertexNum];        //紀錄 X 到 i 目前最短距離
    int **iMSTArray = new int* [iVertexNum];//存放 MST Edges
    int *iXSet = new int [iVertexNum];      //紀錄 X 已經有哪些點
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

    clock_t ckEnd = clock();

//  印出 MST
    if (fMST->cbPrintEdges->Checked)
        {
        if (iXNum < iVertexNum)
            fMST->Memo1->Lines->Add("無延展樹");
        else
            for (i = 0; i < iVertexNum -1; i++)
                fMST->Memo1->Lines->Add("edge "+ IntToStr(i) + ": (" + IntToStr(iMSTArray[i][0])
                + "," + IntToStr(iMSTArray[i][1]) + ")");
        }

    float fCostTime = float(ckEnd - ckStart)/CLK_TCK;

    fMST->Memo1->Lines->Add("Prim Algorithm used " + FloatToStr(fCostTime) + " (sec)");

//  記憶體管理
    for (i = 0; i < iVertexNum; i++)
        delete[] iMSTArray[i];
    delete[] iC1,iC2,iXSet,iMSTArray;

//  將按鈕狀態恢復
    ButtonEnable(true);
}
//---------------------------------------------------------------------------
void __fastcall TfMST::btPrimClick(TObject *Sender)
{
    ButtonEnable(false);

    TPrimThread *PrimThread = new TPrimThread();
}
//---------------------------------------------------------------------------

