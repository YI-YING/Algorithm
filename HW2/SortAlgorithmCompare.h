//---------------------------------------------------------------------------

#ifndef SortAlgorithmCompareH
#define SortAlgorithmCompareH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *lblCPUTime;
    TLabel *lblNum;
    TLabel *lblRange;
    TEdit *edNum;
    TEdit *edRange;
    TMemo *Memo1;
    TMemo *Memo2;
    TLabel *Label4;
    TCheckBox *cbShowData;
    TCheckBox *cbShowResult;
    TButton *btHeap;
    TButton *btInorder;
    TButton *btInorderNR;
    TButton *btSelection;
    TButton *btInsertion;
    TButton *btBubble;
    TButton *btQuick;
    TButton *btRandom;
    TLabel *lblRunLoop;
    TEdit *edRunLoop;
    void __fastcall edNumKeyPress(TObject *Sender, char &Key);
    void __fastcall edRangeKeyPress(TObject *Sender, char &Key);
    void __fastcall btRandomClick(TObject *Sender);
    void __fastcall btHeapClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
//define global variation
int i,j,k;
int iNum;

// Array input & result
int* iRandomData, iResultData;

// Array heap
int *iHeap;
//---------------------------------------------------------------------------
#endif
