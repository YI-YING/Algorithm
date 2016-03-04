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
    int iInsertData;
    try
        {
        iInsertData = StrToInt(edInsertIntoBST->Text);
        }
    catch (...)
        {
        ShowMessage("Please enter an integer !");
        return ;
        }
    btrnRoot = BSTInsert(btrnRoot, iInsertData);

    String answer;
    BSTInorderTraversal(btrnRoot, answer);

    Memo1->Lines->Add(answer);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::edInsertIntoBSTKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_RETURN)
        {
        int iInsertData;
        try
            {
            iInsertData = StrToInt(edInsertIntoBST->Text);
            }
        catch (...)
            {
            ShowMessage("Please enter an integer !");
            return ;
            }
        btrnRoot = BSTInsert(btrnRoot, iInsertData);

        String answer;
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
    int iDeleteData;
    try
        {
        iDeleteData = StrToInt(edDeleteFromBST->Text);
        }
    catch (...)
        {
        ShowMessage("Please enter an integer !");
        return ;
        }
    btrnRoot = BSTDelete(btrnRoot, iDeleteData);

    String answer;
    BSTInorderTraversal(btrnRoot, answer);
    if (answer == "")
        answer = "All data have been cleared !";

    Memo1->Lines->Add(answer);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::edDeleteFromBSTKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_RETURN)
        {
        int iDeleteData;
        try
            {
            iDeleteData = StrToInt(edDeleteFromBST->Text);
            }
        catch (...)
            {
            ShowMessage("Please enter an integer !");
            return ;
            }
        btrnRoot = BSTDelete(btrnRoot, iDeleteData);

        String answer;
        BSTInorderTraversal(btrnRoot, answer);
        if (answer == "")
            answer = "All data have been cleared !";

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

