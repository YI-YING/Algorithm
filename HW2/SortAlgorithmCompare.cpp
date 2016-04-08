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
void DataClear(unsigned int **data)
{
    unsigned int *uiOld = *data;
    *data = NULL;
    free(uiOld);
}
//---------------------------------------------------------------------------
void AddRandomData(unsigned int **array)
{
    unsigned int *uiNew = new unsigned int[uiNum];
    for (i = 0; i < uiNum; i++)
        uiNew[i] = rand() % uiRange + 1;

    *array = uiNew;
}
//---------------------------------------------------------------------------
// define function ShowRandomData
void ShowRandomData()
{
    Form1->Memo1->Lines->Clear();
    if (Form1->cbShowData->Checked)
        {
        for (i = 0; i < uiNum; i++)
            Form1->Memo1->Lines->Add(IntToStr(i+1)+":\t"+StrToInt(uiRandomData[i]));
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btRandomClick(TObject *Sender)
{
    uiNum = StrToInt(edNum->Text);
    uiRange = StrToInt(edRange->Text);

    if (uiRandomData != NULL)
        DataClear(&uiRandomData);
    AddRandomData(&uiRandomData);

    ShowRandomData();

}
//---------------------------------------------------------------------------
//define function InsertHeap, DeleteHeap
unsigned int uiHeapNum = 0;
void InsertHeap(unsigned int x)
{
    uiHeapNum++;
    unsigned int i = uiHeapNum;

    while (i > 1 && x < uiHeap[i/2])
        {
        uiHeap[i] = uiHeap[i/2];
        i/=2;
        }
    uiHeap[i] = x;
}
//---------------------------------------------------------------------------
unsigned int DeleteHeap()
{
    unsigned int i,j,x;

    x = uiHeap[1];
    uiHeap[1] = uiHeap[uiHeapNum];
    uiHeapNum--;
    i = 1;

    while (i <= uiHeapNum/2)
        {
        j = uiHeap[2*i] < uiHeap[2*i +1] ? 2*i : 2*i +1;

        if (uiHeap[i] < uiHeap[j]) break;
        swap(uiHeap[i], uiHeap[j]);
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
            Form1->Memo2->Lines->Add(IntToStr(i+1)+":\t"+StrToInt(uiResultData[i]));
        }
}
//---------------------------------------------------------------------------
//implementation Heap Thread Constructor & Method
__fastcall THeapThread::THeapThread(void):TThread(true)
{
    FreeOnTerminate=true;
    Resume();
}
//---------------------------------------------------------------------------
//define function ButtonEnable
void ButtonEnable(bool state)
{
    Form1->btRandom->Enabled = state;
    Form1->btHeap->Enabled = state;
    Form1->btInorder->Enabled = state;
    Form1->btInorderNR->Enabled = state;
    Form1->btSelection->Enabled = state;
    Form1->btInsertion->Enabled = state;
    Form1->btBubble->Enabled = state;
    Form1->btQuick->Enabled = state;
}
//---------------------------------------------------------------------------
void __fastcall THeapThread::Execute()
{
    clock_t ckStart = clock();

    for (i = 0; i < uiNum; i++)
        InsertHeap(uiRandomData[i]);
    for (i = 0; i < uiNum; i++)
        uiResultData[i] = DeleteHeap();

    clock_t ckEnd = clock();
    float fCostTime = float(ckEnd - ckStart)/CLK_TCK;

    DataClear(&uiHeap);

    ShowResult();
    DataClear(&uiResultData);

    Form1->lblCPUTime->Caption = "CPU Time(s) = " + FloatToStr(fCostTime);
    ButtonEnable(true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btHeapClick(TObject *Sender)
{
    ButtonEnable(false);

    uiHeap = new unsigned int[uiNum+1];

    uiResultData = new unsigned int[uiNum];

    lblCPUTime->Caption = "CPU Time(s) = Sorting ...";

    THeapThread *HeapThread;
    HeapThread = new THeapThread();
}
//---------------------------------------------------------------------------
//define struct BTreeNode
struct BTreeNode
    {
    struct BTreeNode *btrnLeftChild;
    unsigned int uiData;
    struct BTreeNode *btrnRightChild;
    };
struct BTreeNode *btrnRoot;
//---------------------------------------------------------------------------
//define function NewNode,AddNode
struct BTreeNode *NewNode(unsigned int x)
{
    struct BTreeNode *btrnNew = new struct BTreeNode;
    btrnNew->btrnLeftChild = NULL;
    btrnNew->uiData = x;
    btrnNew->btrnRightChild = NULL;

    return btrnNew;
}
//---------------------------------------------------------------------------
struct BTreeNode *AddNode(struct BTreeNode *node, unsigned int x)
{
    if (node == NULL)
        return NewNode(x);
    if (x < node->uiData)
        node->btrnLeftChild = AddNode(node->btrnLeftChild, x);
    else
        node->btrnRightChild = AddNode(node->btrnRightChild, x);
    return node;
}
//---------------------------------------------------------------------------
//define function InorderTraversl,DeleteNode,NodeClear
void InorderTraversal(struct BTreeNode *node)
{
    if (node != NULL)
        {
        InorderTraversal(node->btrnLeftChild);
        uiResultData[i++] = node->uiData;
        InorderTraversal(node->btrnRightChild);
        }
}
//---------------------------------------------------------------------------
struct BTreeNode *DeleteNode(struct BTreeNode *node)
{
    struct BTreeNode *Old = node;
    node = NULL;

    free(Old);
    return node;
}
//---------------------------------------------------------------------------
struct BTreeNode *NodeClear(struct BTreeNode *node)
{
    if (node != NULL)
        {
        node->btrnLeftChild = NodeClear(node->btrnLeftChild);
        node->btrnRightChild = NodeClear(node->btrnRightChild);

        node = DeleteNode(node);
        }

    return node;
}
//---------------------------------------------------------------------------
//implementation Inorder Thread Constructor & Method
__fastcall TInorderThread::TInorderThread(void):TThread(true)
{
    FreeOnTerminate=true;
    Resume();
}
//---------------------------------------------------------------------------
void __fastcall TInorderThread::Execute()
{
    clock_t ckStart = clock();

    for (i = 0; i < uiNum; i++)
        btrnRoot = AddNode(btrnRoot,uiRandomData[i]);
    i = 0;
    InorderTraversal(btrnRoot);

    clock_t ckEnd = clock();
    float fCostTime = float(ckEnd - ckStart)/CLK_TCK;

    btrnRoot = NodeClear(btrnRoot);

    ShowResult();
    DataClear(&uiResultData);

    Form1->lblCPUTime->Caption = "CPU Time(s) = " + FloatToStr(fCostTime);
    ButtonEnable(true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btInorderClick(TObject *Sender)
{
    ButtonEnable(false);

    uiResultData = new unsigned int[uiNum];

    lblCPUTime->Caption = "CPU Time(s) = Sorting ...";

    TInorderThread *InorderThread;
    InorderThread = new TInorderThread();
}
//---------------------------------------------------------------------------
//define struct StackNode
struct StackNode
    {
    struct StackNode *snNext;
    struct BTreeNode *btrnTreeNode;
    };
struct StackNode *snTop;
//---------------------------------------------------------------------------
//define function PushNode,PopNode
void PushNode(struct BTreeNode *node)
{
    struct StackNode *snOld = snTop;

    snTop = new struct StackNode;
    snTop->snNext = snOld;
    snTop->btrnTreeNode = node;
}
//---------------------------------------------------------------------------
struct BTreeNode *PopNode()
{
    if (snTop == NULL)
        return NULL;
    struct BTreeNode *btrn = snTop->btrnTreeNode;
    struct StackNode *snOld = snTop;

    snTop = snTop->snNext;
    free(snOld);

    return btrn;
}
//---------------------------------------------------------------------------
//define function InorderTraversalNR, AddNodeNR
void InorderTraversalNR(struct BTreeNode *node)
{
    do
        {
        while (node != NULL)
            {
            PushNode(node);
            node = node->btrnLeftChild;
            }
        if (snTop != NULL)
            {
            node = PopNode();
            uiResultData[i++] = node->uiData;
            node = node->btrnRightChild;
            }
        }
    while (snTop != NULL || node != NULL);
}
//---------------------------------------------------------------------------
void AddNode(unsigned int x)
{
    struct BTreeNode *btrnTemp,*btrnParent;
    btrnTemp = btrnRoot; btrnParent = NULL;

    while (btrnTemp != NULL)
        {
        btrnParent = btrnTemp;

        btrnTemp = x < btrnTemp->uiData ?
            btrnTemp->btrnLeftChild : btrnTemp->btrnRightChild;
        }
    btrnTemp = NewNode(x);

    if (btrnParent == NULL)
        {
        btrnRoot = btrnTemp;
        return ;
        }

    if (x < btrnParent->uiData)
        btrnParent->btrnLeftChild = btrnTemp;
    else
        btrnParent->btrnRightChild = btrnTemp;
}
//---------------------------------------------------------------------------
//define struct QueueNode, function AddQueue,DeleteQueue
struct QueueNode
    {
    struct QueueNode *qnNext;
    struct BTreeNode *btrnTreeNode;
    };
//---------------------------------------------------------------------------
//implementation InorderNR Thread Constructor & Method
__fastcall TInorderNRThread::TInorderNRThread(void):TThread(true)
{
    FreeOnTerminate = true;
    Resume();
}
//---------------------------------------------------------------------------
void __fastcall TInorderNRThread::Execute(void)
{
    clock_t ckStart = clock();

    for (i = 0; i < uiNum; i++)
        AddNode(uiRandomData[i]);
    i = 0;
    InorderTraversalNR(btrnRoot);

    clock_t ckEnd = clock();
    float fCostTime = float(ckEnd - ckStart)/CLK_TCK;

    btrnRoot = NodeClear(btrnRoot);

    ShowResult();
    DataClear(&uiResultData);

    Form1->lblCPUTime->Caption = "CPU Time(s) = " + FloatToStr(fCostTime);
    ButtonEnable(true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btInorderNRClick(TObject *Sender)
{
    ButtonEnable(false);

    uiResultData = new unsigned int[uiNum];

    lblCPUTime->Caption = "CPU Time(s) = Sorting ...";

    TInorderNRThread *InorderNRThread;
    InorderNRThread = new TInorderNRThread();
}
//---------------------------------------------------------------------------
//implementation Selection Thread Constructor & Method
__fastcall TSelectionThread::TSelectionThread(void):TThread(true)
{
    FreeOnTerminate = true;
    Resume();
}
//---------------------------------------------------------------------------
void __fastcall TSelectionThread::Execute(void)
{
    clock_t ckStart = clock();

    for (i = 0; i < uiNum; i++)
        uiResultData[i] = uiRandomData[i];

    unsigned int uiMax;
    for (i = 0; i < uiNum; i++)
        {
        uiMax = i;
        for (j = i+1; j < uiNum; j++)
            if (uiResultData[j] < uiResultData[uiMax])
                uiMax = j;
        if ( i != uiMax)
            swap(uiResultData[i], uiResultData[uiMax]);
        }

    clock_t ckEnd = clock();
    float fCostTime = float(ckEnd - ckStart)/CLK_TCK;

    ShowResult();
    DataClear(&uiResultData);

    Form1->lblCPUTime->Caption = "CPU Time(s) = " + FloatToStr(fCostTime);
    ButtonEnable(true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btSelectionClick(TObject *Sender)
{
    ButtonEnable(false);

    uiResultData = new unsigned int[uiNum];

    lblCPUTime->Caption = "CPU Time(s) = Sorting ...";

    TSelectionThread *SelectionThread;
    SelectionThread = new TSelectionThread();
}
//---------------------------------------------------------------------------
//implementation Insertion Thread Constructor & Method
__fastcall TInsertionThread::TInsertionThread(void):TThread(true)
{
    FreeOnTerminate = true;
    Resume();
}
//---------------------------------------------------------------------------
void __fastcall TInsertionThread::Execute(void)
{
    clock_t ckStart = clock();

    for (i = 0; i < uiNum; i++)
        uiResultData[i] = uiRandomData[i];

    unsigned int uiTemp;
    for (i = 1; i < uiNum; i++)
        {
        uiTemp = uiResultData[i];
        for (j = i; j > 0 && uiTemp < uiResultData[j-1]; j--)
            uiResultData[j] = uiResultData[j-1];
        uiResultData[j] = uiTemp;
        }

    clock_t ckEnd = clock();
    float fCostTime = float(ckEnd - ckStart)/CLK_TCK;

    ShowResult();
    DataClear(&uiResultData);

    Form1->lblCPUTime->Caption = "CPU Time(s) = " + FloatToStr(fCostTime);
    ButtonEnable(true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btInsertionClick(TObject *Sender)
{
    ButtonEnable(false);

    uiResultData = new unsigned int[uiNum];

    lblCPUTime->Caption = "CPU Time(s) = Sorting ...";

    TInsertionThread *InsertionThread;
    InsertionThread = new TInsertionThread();
}
//---------------------------------------------------------------------------

