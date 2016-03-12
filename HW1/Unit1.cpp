//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
//define struct
struct BTreeNode
    {
    struct BTreeNode *btrnLeftChild;
    int iData;
    struct BTreeNode *btrnRightChild;
    };

struct BTreeNode *btrnRoot;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::trbNumOfIntegerChange(TObject *Sender)
{
    edNumOfInteger->Text = trbNumOfInteger->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::trbRangeChange(TObject *Sender)
{
    edRange->Text = trbRange->Position;
}
//---------------------------------------------------------------------------
//define function NewBSTNode,BSTInsert,BSTInorderTraversal
struct BTreeNode *NewBSTNode(int insertData)
{
    struct BTreeNode *btreenode = new struct BTreeNode;
    btreenode->btrnLeftChild = NULL;
    btreenode->iData = insertData;
    btreenode->btrnRightChild = NULL;

    return btreenode;
}
//---------------------------------------------------------------------------
struct BTreeNode *BSTInsert(struct BTreeNode *node, int insertData)
{
    if (node == NULL)
        return NewBSTNode(insertData);

    if (insertData > node->iData)
        node->btrnRightChild = BSTInsert(node->btrnRightChild, insertData);
    else
        node->btrnLeftChild = BSTInsert(node->btrnLeftChild, insertData);

    return node;
}
//---------------------------------------------------------------------------
void BSTInorderTraversal(struct BTreeNode *node, String &answer)
{
    if (node != NULL)
        {
        BSTInorderTraversal(node->btrnLeftChild, answer);
        answer = answer + IntToStr(node->iData) + ">>";
        BSTInorderTraversal(node->btrnRightChild, answer);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btInsertIntoBSTClick(TObject *Sender)
{
    if (edInsertIntoBST->Text == "")
        {
        ShowMessage("Please enter an integer !");
        return ;
        }
    btrnRoot = BSTInsert(btrnRoot, StrToInt(edInsertIntoBST->Text));

    String answer;
    BSTInorderTraversal(btrnRoot, answer);

    String s = edInsertIntoBST->Text + " successfully adds to tree";
    Memo1->Lines->Add(s);
    Memo1->Lines->Add(answer);

    edInsertIntoBST->Text = StrToInt(edInsertIntoBST->Text) + 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::edInsertIntoBSTKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_RETURN)
        {
        if (edInsertIntoBST->Text == "")
            {
            ShowMessage("Please enter an integer !");
            return ;
            }
        btrnRoot = BSTInsert(btrnRoot, StrToInt(edInsertIntoBST->Text));

        String answer;
        BSTInorderTraversal(btrnRoot, answer);

        String s = edInsertIntoBST->Text + " successfully adds to tree";
        Memo1->Lines->Add(s);
        Memo1->Lines->Add(answer);

        edInsertIntoBST->Text = StrToInt(edInsertIntoBST->Text) + 10;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::edInsertIntoBSTKeyPress(TObject *Sender, char &Key)
{
    if ((Key<48 || Key>57) && Key!=8)
        Key=0;
}
//---------------------------------------------------------------------------
//define function BSTFindSucc,BSTDelete
struct BTreeNode *BSTFindSucc(struct BTreeNode *node)
{
    while (node->btrnLeftChild != NULL)
        node = node->btrnLeftChild;
    return node;
}
//---------------------------------------------------------------------------
struct BTreeNode *BSTDelete(struct BTreeNode *node, int deleteData)
{
    struct BTreeNode *temp;

    if (node == NULL)
        return node;
    else if (deleteData > node->iData)
        node->btrnRightChild = BSTDelete(node->btrnRightChild, deleteData);
    else if (deleteData < node->iData)
        node->btrnLeftChild = BSTDelete(node->btrnLeftChild, deleteData);
    else
        {
        if (node->btrnLeftChild == NULL || node->btrnRightChild == NULL)
            {
            temp = node->btrnLeftChild ? node->btrnLeftChild : node->btrnRightChild;
            if (temp == NULL)
                {
                temp = node;
                node = NULL;
                }
            else
                *node = *temp;
            free(temp);
            }
        else
            {
            temp = BSTFindSucc(node->btrnRightChild);
            node->iData = temp->iData;
            node->btrnRightChild = BSTDelete(node->btrnRightChild, temp->iData);
            }
        }
    return node;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btDeletefromBSTClick(TObject *Sender)
{
    if (edDeleteFromBST->Text == "")
        {
        ShowMessage("Please enter an integer !");
        return ;
        }
    btrnRoot = BSTDelete(btrnRoot, StrToInt(edDeleteFromBST->Text));

    String answer;
    BSTInorderTraversal(btrnRoot, answer);
    if (answer == "")
        answer = "All data have been cleared !";
    else
        {
        String s = edDeleteFromBST->Text + " has been deleted !";
        Memo1->Lines->Add(s);
        edDeleteFromBST->Text = StrToInt(edDeleteFromBST->Text) + 10;
        }
    Memo1->Lines->Add(answer);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::edDeleteFromBSTKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_RETURN)
        {
        if (edDeleteFromBST->Text == "")
            {
            ShowMessage("Please enter an integer !");
            return ;
            }
        btrnRoot = BSTDelete(btrnRoot, StrToInt(edDeleteFromBST->Text));

        String answer;
        BSTInorderTraversal(btrnRoot, answer);
        if (answer == "")
            answer = "All data have been cleared !";
        else
            {
            String s = edDeleteFromBST->Text + " has been deleted !";
            Memo1->Lines->Add(s);
            edDeleteFromBST->Text = StrToInt(edDeleteFromBST->Text) + 10;
            }
        Memo1->Lines->Add(answer);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::edDeleteFromBSTKeyPress(TObject *Sender, char &Key)
{
    if ((Key<48 || Key>57) && Key!=8)
        Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btRandomClick(TObject *Sender)
{
    int iNumOfInteger = StrToInt(edNumOfInteger->Text);
    int iRange = StrToInt(edRange->Text);

    int iInsertData;

    for (int i = 0; i < iNumOfInteger; i++)
        {
        iInsertData = rand()%iRange;
        btrnRoot = BSTInsert(btrnRoot, iInsertData);
        }

    String answer;
    BSTInorderTraversal(btrnRoot, answer);

    Memo1->Lines->Add(answer);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::edNumOfIntegerChange(TObject *Sender)
{
    if (edNumOfInteger->Text == "")
        edNumOfInteger->Text = "5";
    if (StrToInt(edNumOfInteger->Text) > 100)
        edNumOfInteger->Text = "100";
    trbNumOfInteger->Position = StrToInt(edNumOfInteger->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::edNumOfIntegerKeyPress(TObject *Sender, char &Key)
{
    if ((Key<48 || Key>57) && Key!=8)
        Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::edRangeChange(TObject *Sender)
{
    if (edRange->Text == "" || StrToInt(edRange->Text) < 100)
        edRange->Text = "100";
    if (StrToInt(edRange->Text) > 10000)
        edRange->Text = "10000";
    trbRange->Position = StrToInt(edRange->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::edRangeKeyPress(TObject *Sender, char &Key)
{
    if ((Key<48 || Key>57) && Key!=8)
        Key=0;
}
//---------------------------------------------------------------------------
//define Preorder function
void BSTPreorderTraversal(struct BTreeNode *node, String &answer)
{
    if (node != NULL)
        {
        answer = answer + IntToStr(node->iData) + ">>";
        BSTPreorderTraversal(node->btrnLeftChild, answer);
        BSTPreorderTraversal(node->btrnRightChild, answer);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btPreorderClick(TObject *Sender)
{
    String answer;
    BSTPreorderTraversal(btrnRoot, answer);

    if (answer == "")
        {
        Memo1->Lines->Add("There is no data in tree");
        return ;
        }
    Memo1->Lines->Add("Preorder output:");
    Memo1->Lines->Add(answer);
}
//---------------------------------------------------------------------------
//define Postorder function
void BSTPostorderTraversal(struct BTreeNode *node, String &answer)
{
    if (node != NULL)
        {
        BSTPostorderTraversal(node->btrnLeftChild, answer);
        BSTPostorderTraversal(node->btrnRightChild, answer);
        answer = answer + IntToStr(node->iData) + ">>";
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btPostOrderClick(TObject *Sender)
{
    String answer;
    BSTPostorderTraversal(btrnRoot, answer);

    if (answer == "")
        {
        Memo1->Lines->Add("There is no data in tree");
        return ;
        }
    Memo1->Lines->Add("Postorder output:");
    Memo1->Lines->Add(answer);
}
//---------------------------------------------------------------------------
//define struct Queue Node and function AddQueue,DeleteQueue
struct QueueNode
    {
    struct BTreeNode *btrnTreeNode;
    struct QueueNode *qnNext;
    };
struct QueueNode *qnFront, *qnRear;
//---------------------------------------------------------------------------
void AddQueue(struct BTreeNode *node)
{
    struct QueueNode *qn = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    qn->btrnTreeNode = node;
    qn->qnNext = NULL;

    if (qnFront == NULL)
        qnFront = qn;
    else
        qnRear->qnNext = qn;
    qnRear = qn;
}
//---------------------------------------------------------------------------
struct BTreeNode *DeleteQueue()
{
    if (qnRear == NULL)
        return NULL;

    struct BTreeNode *btrn = qnFront->btrnTreeNode;
    struct QueueNode *qnOld = qnFront;

    qnFront = qnFront->qnNext;
    free(qnOld);

    return btrn;
}
//---------------------------------------------------------------------------
//define function LevelOrder Traveral
void LevelOrder(struct BTreeNode *node)
{
    struct BTreeNode *btrn;
    String sAnswer = "";
    AddQueue(node);

    while(qnFront != NULL)
        {
        btrn = DeleteQueue();
        sAnswer = sAnswer + btrn->iData + ">>";

        if (btrn->btrnLeftChild != NULL)
            AddQueue(btrn->btrnLeftChild);
        if (btrn->btrnRightChild != NULL)
            AddQueue(btrn->btrnRightChild);
        }
    Form1->Memo1->Lines->Add(sAnswer);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btLevelOrderClick(TObject *Sender)
{
    if (btrnRoot == NULL)
        {
        Memo1->Lines->Add("There is no data in tree");
        return ;
        }
    Memo1->Lines->Add("Level Order :");
    LevelOrder(btrnRoot);
}
//---------------------------------------------------------------------------
//define struct StackNode and function Push_Node,Pop_Node
struct StackNode
    {
    struct BTreeNode *btrnTreeNode;
    struct StackNode *snNext;
    };
struct StackNode *snTop;
//---------------------------------------------------------------------------
void Push_Node(struct BTreeNode *node)
{
    struct StackNode *snOld = snTop;
    snTop = (struct StackNode *)malloc(sizeof(struct StackNode));
    snTop->btrnTreeNode = node;
    snTop->snNext = snOld;
}
//---------------------------------------------------------------------------
struct BTreeNode *Pop_Node()
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
//define function Prefix_Stack
void Prefix_Stack(struct BTreeNode *node)
{
    String answer = "";
    do
        {
        while (node != NULL)
            {
            answer = answer + node->iData + ">>";
            Push_Node(node);
            node = node->btrnLeftChild;
            }
        if (snTop != NULL)
            {
            node = Pop_Node();
            node = node->btrnRightChild;
            }
        }
    while (snTop != NULL || node != NULL);

    if (answer == "")
        {
        Form1->Memo1->Lines->Add("There is no data in tree");
        return ;
        }
    Form1->Memo1->Lines->Add("None recursive Prefix output :");
    Form1->Memo1->Lines->Add(answer);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btPrefixClick(TObject *Sender)
{
    Prefix_Stack(btrnRoot);
}
//---------------------------------------------------------------------------
//define function Infix_Stack
void Infix_Stack(struct BTreeNode *node)
{
    String answer = "";
    do
        {
        while (node != NULL)
            {
            Push_Node(node);
            node = node->btrnLeftChild;
            }
        if (snTop != NULL)
            {
            node = Pop_Node();
            answer = answer + node->iData + ">>";
            node = node->btrnRightChild;
            }
        }
    while (snTop != NULL || node != NULL);

    if (answer == "")
        {
        Form1->Memo1->Lines->Add("There is no data in tree");
        return ;
        }
    Form1->Memo1->Lines->Add("None recursive Infix output :");
    Form1->Memo1->Lines->Add(answer);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btInfixClick(TObject *Sender)
{
    Infix_Stack(btrnRoot);
}
//---------------------------------------------------------------------------
//define function Postfix_Stack
void Postfix_Stack(struct BTreeNode *node)
{
    String answer = "";
    do
        {
        while (node != NULL)
            {
            answer = IntToStr(node->iData) + ">>" + answer;
            Push_Node(node);
            node = node->btrnRightChild;
            }
        if (snTop != NULL)
            {
            node = Pop_Node();
            node = node->btrnLeftChild;
            }
        }
    while (snTop != NULL || node != NULL);

    if (answer == "")
        {
        Form1->Memo1->Lines->Add("There is no data in tree");
        return ;
        }
    Form1->Memo1->Lines->Add("None recursive Postfix output :");
    Form1->Memo1->Lines->Add(answer);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btPostfixClick(TObject *Sender)
{
    Postfix_Stack(btrnRoot);
}
//---------------------------------------------------------------------------

