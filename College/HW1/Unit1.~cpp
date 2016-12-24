//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "math.h"
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
//define struct BTreeNode_Char
struct BTreeNode_Char
    {
    struct BTreeNode_Char *btrn_cLeftChild;
    char cData;
    struct BTreeNode_Char *btrn_cRightChild;
    };
struct BTreeNode_Char *btrn_cRoot;
//---------------------------------------------------------------------------
//define struct StackNode_Char function Push_Node_Char,Pop_Node_Char
struct StackNode_Char
    {
    struct BTreeNode_Char *btrn_cTreeNode;
    struct StackNode_Char *sn_cNext;
    };
struct StackNode_Char *sn_cOperand,*sn_cOperator;
//---------------------------------------------------------------------------
void Push_Node_Char(struct BTreeNode_Char *node, struct StackNode_Char **stack)
{
    struct StackNode_Char *sn_cOld = *stack;
    struct StackNode_Char *sn_cNew = (struct StackNode_Char *)malloc(sizeof(struct StackNode_Char));
    sn_cNew->btrn_cTreeNode = node;
    sn_cNew->sn_cNext = sn_cOld;
    *stack = sn_cNew;
}
//---------------------------------------------------------------------------
struct BTreeNode_Char *Pop_Node_Char(struct StackNode_Char **stack)
{
    if (*stack == NULL)
        return NULL;
    struct StackNode_Char *sn_cOld = *stack;
    struct BTreeNode_Char *btrn_c = sn_cOld->btrn_cTreeNode;

    *stack = (struct StackNode_Char *)(*stack)->sn_cNext;
    free(sn_cOld);
    return btrn_c;
}
//---------------------------------------------------------------------------
//define function NewNode_Char,InsertNode_Char, Priority1,Priority2
int iElementNum = 0;
struct BTreeNode_Char *NewNode_Char(char cData)
{
    if (cData != '(')
        iElementNum++;
    
    struct BTreeNode_Char *btrn_c = (struct BTreeNode_Char *)malloc(sizeof(struct BTreeNode_Char));
    btrn_c->btrn_cLeftChild = NULL;
    btrn_c->btrn_cRightChild = NULL;
    btrn_c->cData = cData;

    return btrn_c;
}
//---------------------------------------------------------------------------
int Priority1(char cData)
{
    switch (cData)
        {
        case '+':
        case '-': return 6;
        case '*':
        case '/': return 7;
        case '%':
        case '(': return 8;
        case '&&': return 5;
        case '||': return 4;
        }
}
//---------------------------------------------------------------------------
int Priority2(struct StackNode_Char *node)
{
    if (node == NULL)
        return 1;
    switch (node->btrn_cTreeNode->cData)
        {
        case '+':
        case '-': return 6;
        case '*':
        case '/': return 7;
        case '%':
        case '(': return 1;
        case '&&': return 5;
        case '||': return 4;
        }
}
//---------------------------------------------------------------------------
struct BTreeNode_Char *InsertNode_Char(struct BTreeNode_Char *node, String s)
{
    struct BTreeNode_Char *btrn_c;

    for (int i = 1; i <= s.Length(); i++)
        {
        if (s[i] == '(' || s[i] == '+' ||
            s[i] == '-' || s[i] == '*' ||
            s[i] == '/' || s[i] == '%' ||
            s[i] == '&&' || s[i] == '||' ||
            s[i] == ')')
            {
            if (s[i] == ')')
                {
                while ((btrn_c = Pop_Node_Char(&sn_cOperator))->cData != '(')
                    {
                    btrn_c->btrn_cRightChild = Pop_Node_Char(&sn_cOperand);
                    btrn_c->btrn_cLeftChild = Pop_Node_Char(&sn_cOperand);
                    Push_Node_Char(btrn_c, &sn_cOperand);
                    }
                }
            else if (sn_cOperator == NULL)
                {
                btrn_c = NewNode_Char(s[i]);
                Push_Node_Char(btrn_c, &sn_cOperator);
                }
            else
                {
                while (Priority1(s[i]) <= Priority2(sn_cOperator))
                    {
                    btrn_c = Pop_Node_Char(&sn_cOperator);
                    btrn_c->btrn_cRightChild = Pop_Node_Char(&sn_cOperand);
                    btrn_c->btrn_cLeftChild = Pop_Node_Char(&sn_cOperand);
                    Push_Node_Char(btrn_c, &sn_cOperand);
                    }
                btrn_c = NewNode_Char(s[i]);
                Push_Node_Char(btrn_c, &sn_cOperator);
                }
            }
        else
            {
            btrn_c = NewNode_Char(s[i]);
            Push_Node_Char(btrn_c, &sn_cOperand);
            }
        }
    while (sn_cOperator != NULL)
        {
        btrn_c = Pop_Node_Char(&sn_cOperator);
        btrn_c->btrn_cRightChild = Pop_Node_Char(&sn_cOperand);
        btrn_c->btrn_cLeftChild = Pop_Node_Char(&sn_cOperand);
        Push_Node_Char(btrn_c, &sn_cOperand);
        }
    btrn_c = Pop_Node_Char(&sn_cOperand);
    return btrn_c;
}
//---------------------------------------------------------------------------
//define function Inorder_Traversal Clear_tree
void Inorder_Traversal(struct BTreeNode_Char *node, String &sAnswer)
{
    if (node != NULL)
        {
        Inorder_Traversal(node->btrn_cLeftChild, sAnswer);
        sAnswer += String(node->cData);
        Inorder_Traversal(node->btrn_cRightChild, sAnswer);
        }
}
//---------------------------------------------------------------------------
void Clear_tree(struct BTreeNode_Char **node)
{
    if (*node != NULL)
        {
        Clear_tree(&((*node)->btrn_cLeftChild));
        Clear_tree(&((*node)->btrn_cRightChild));

        struct BTreeNode_Char *btrn_c = *node;
        *node = NULL;
        free(btrn_c);
        iElementNum--;
        }
}
//---------------------------------------------------------------------------
//define function TreeHeight
int TreeHeight(struct BTreeNode_Char *node)
{
    if (node == NULL)
        return 0;
    int iLeftHeight = TreeHeight(node->btrn_cLeftChild);
    int iRightHeight = TreeHeight(node->btrn_cRightChild);

    int iTreeHeight = iLeftHeight > iRightHeight ? iLeftHeight : iRightHeight;

    return iTreeHeight + 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btInsertClick(TObject *Sender)
{
    if (btrn_cRoot != NULL)
        Clear_tree(&btrn_cRoot);

    btrn_cRoot = InsertNode_Char(btrn_cRoot, edInsert->Text);
    String sAnswer = "";
    Inorder_Traversal(btrn_cRoot, sAnswer);

    Memo2->Lines->Add("Add data successfully");
    Memo2->Lines->Add(sAnswer);

    lblElementNum->Caption = "Element Num :" + IntToStr(iElementNum);
    lblStatus->Caption = "Status : Insert successfully";
    lblLevelHeight->Caption = "Level Height :" + IntToStr(TreeHeight(btrn_cRoot));
}
//---------------------------------------------------------------------------
//define function Preorder_Traversal,Postorder_Traversal
void Preorder_Traversal(struct BTreeNode_Char *node, String &sAnswer)
{
    if (node != NULL)
        {
        sAnswer += String(node->cData);
        Preorder_Traversal(node->btrn_cLeftChild, sAnswer);
        Preorder_Traversal(node->btrn_cRightChild, sAnswer);
        }
}
//---------------------------------------------------------------------------
void Postorder_Traversal(struct BTreeNode_Char *node, String &sAnswer)
{
    if (node != NULL)
        {
        Postorder_Traversal(node->btrn_cLeftChild, sAnswer);
        Postorder_Traversal(node->btrn_cRightChild, sAnswer);
        sAnswer += String(node->cData);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btTreeTraversalClick(TObject *Sender)
{
    String sAnswer = "";
    switch (cbTreeTraversal->ItemIndex)
        {
        case 1:
            {
            Inorder_Traversal(btrn_cRoot, sAnswer);

            if (sAnswer == "")
                {
                Memo2->Lines->Add("There is no data in tree");
                return ;
                }
            Memo2->Lines->Add("Inorder traversal :");
            }
            break;
        case 2:
            {
            Postorder_Traversal(btrn_cRoot, sAnswer);

            if (sAnswer == "")
                {
                Memo2->Lines->Add("There is no data in tree");
                return ;
                }
            Memo2->Lines->Add("Postorder traversal :");
            }
            break;
        default:
            {
            Preorder_Traversal(btrn_cRoot, sAnswer);

            if (sAnswer == "")
                {
                Memo2->Lines->Add("There is no data in tree");
                return ;
                }
            Memo2->Lines->Add("Preorder traversal :");
            }
        }
    Memo2->Lines->Add(sAnswer);
    lblStatus->Caption = "Status : Tree Traversal";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btResetTreeClick(TObject *Sender)
{
    Clear_tree(&btrn_cRoot);
    Memo2->Lines->Add("Tree has been cleared !");

    lblElementNum->Caption = "Element Num :" + IntToStr(iElementNum);
    lblStatus->Caption = "Status : Reset successfully";
    lblLevelHeight->Caption = "Level Height :" + IntToStr(TreeHeight(btrn_cRoot));
}
//---------------------------------------------------------------------------
//define struct DrawTreeNode, function CopyBTN_CToDTN
struct DrawTreeNode
    {
    struct DrawTreeNode *dtnLeftChild;
    struct DrawTreeNode *dtnRightChild;
    int iData;
    char cData;
    int iX;
    int iY;
    int iIndex;
    };
//---------------------------------------------------------------------------
struct DrawTreeNode *CopyBTN_CToDTN(struct BTreeNode_Char *node, int index, int depth)
{
    if (node == NULL)
        return NULL;
    struct DrawTreeNode *dtn = (struct DrawTreeNode *)malloc(sizeof(struct DrawTreeNode));
    dtn->cData = node->cData;
    dtn->iIndex = index;
    dtn->iY = ceil(log(index+1)/log(2.0));
    dtn->iX = pow(2,depth - dtn->iY) + pow(2,depth - dtn->iY +1)*(index-(pow(2,dtn->iY-1) -1) -1);

    dtn->dtnLeftChild = CopyBTN_CToDTN(node->btrn_cLeftChild, index*2, depth);
    dtn->dtnRightChild = CopyBTN_CToDTN(node->btrn_cRightChild, index *2 +1, depth);

    return dtn;
}
//---------------------------------------------------------------------------
//define function Draw_BT_C
void Draw_BT_C(struct DrawTreeNode *node, int detW, int detH, int radius)
{
    if (node != NULL)
        {
        Form1->imDrawTree->Canvas->Pen->Color = RGB(0,0,255);

        if (node->dtnLeftChild != NULL)
            {
            Form1->imDrawTree->Canvas->MoveTo(node->iX * detW,
                node->iY * detH);
            Form1->imDrawTree->Canvas->LineTo(node->dtnLeftChild->iX * detW,
                node->dtnLeftChild->iY * detH);
            }
        if (node->dtnRightChild != NULL)
            {
            Form1->imDrawTree->Canvas->MoveTo(node->iX * detW,
                node->iY * detH);
            Form1->imDrawTree->Canvas->LineTo(node->dtnRightChild->iX * detW,
                node->dtnRightChild->iY * detH);
            }
        Form1->imDrawTree->Canvas->Ellipse(node->iX * detW - radius,
            node->iY * detH - radius,
            node->iX * detW + radius,
            node->iY * detH + radius);
        Form1->imDrawTree->Canvas->TextOutA(node->iX * detW -3,
            node->iY * detH - 5,
            node->cData);

        Draw_BT_C(node->dtnLeftChild, detW, detH, radius);
        Draw_BT_C(node->dtnRightChild, detW, detH, radius);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btDraw_BT_CClick(TObject *Sender)
{
    imDrawTree->Picture->Assign(NULL);
    int iHeight = TabSheet3->Height;
    int iWidth = TabSheet3->Width;

    int iDepth = TreeHeight(btrn_cRoot);
    int iTotalNode = pow(2,iDepth) -1;
    int iDetW = iWidth/(iTotalNode +1);
    int iDetH = iHeight/(iDepth +1);
    int iRadius = iDetW/2;

    imDrawTree->Left = 0;
    imDrawTree->Top = 0;
    imDrawTree->Height = iHeight;
    imDrawTree->Width = iWidth;

    struct DrawTreeNode *dtnRoot = CopyBTN_CToDTN(btrn_cRoot, 1, iDepth);
    Draw_BT_C(dtnRoot, iDetW, iDetH, iRadius);
}
//---------------------------------------------------------------------------




