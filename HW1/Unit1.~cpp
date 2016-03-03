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

struct BTreeNode *btrnRoot = NULL;
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
//define function
void BSTInsert(struct BTreeNode *node, int insertData)
{
    if (insertData == node->iData)
        return;
    if (insertData > node->iData)
        {
        if (node->btrnRightChild == NULL)
            {
            node->btrnRightChild = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
            node->btrnRightChild->iData = insertData;
            node->btrnRightChild->btrnLeftChild = NULL;
            node->btrnRightChild->btrnRightChild = NULL;
            }
        else
            BSTInsert(node->btrnRightChild, insertData);
        }
    if (insertData < node->iData)
        {
        if (node->btrnLeftChild == NULL)
            {
            node->btrnLeftChild = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
            node->btrnLeftChild->iData = insertData;
            node->btrnLeftChild->btrnLeftChild = NULL;
            node->btrnLeftChild->btrnRightChild = NULL;
            }
        else
            BSTInsert(node->btrnLeftChild, insertData);
        }
}
void BSTInorderTraversal(struct BTreeNode *node, AnsiString &answer)
{
    if (node != NULL)
        {
        BSTInorderTraversal(node->btrnLeftChild, answer);
        answer = answer + AnsiString(node->iData) + AnsiString(">>");
        BSTInorderTraversal(node->btrnRightChild, answer);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btInsertIntoBSTClick(TObject *Sender)
{
    if (btrnRoot == NULL)
        {
        btrnRoot = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
        btrnRoot->iData = StrToInt(edInsertIntoBST->Text);
        btrnRoot->btrnLeftChild = NULL;
        btrnRoot->btrnRightChild = NULL;
        }
    else
        BSTInsert(btrnRoot, StrToInt(edInsertIntoBST->Text));

    AnsiString answer;
    BSTInorderTraversal(btrnRoot, answer);

    Memo1->Lines->Add(answer);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::edInsertIntoBSTKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_RETURN)
        {
        if (btrnRoot == NULL)
            {
            btrnRoot = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
            btrnRoot->iData = StrToInt(edInsertIntoBST->Text);
            btrnRoot->btrnLeftChild = NULL;
            btrnRoot->btrnRightChild = NULL;
            }
        else
            BSTInsert(btrnRoot, StrToInt(edInsertIntoBST->Text));

        AnsiString answer;
        BSTInorderTraversal(btrnRoot, answer);

        Memo1->Lines->Add(answer);
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::edInsertIntoBSTKeyPress(TObject *Sender, char &Key)
{
    if ((Key<48 || Key>57) && Key!=8)
        Key=0;
}
//---------------------------------------------------------------------------

