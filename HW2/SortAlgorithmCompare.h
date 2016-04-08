//---------------------------------------------------------------------------

#ifndef SortAlgorithmCompareH
#define SortAlgorithmCompareH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    TButton *btBubble;
    TButton *btHeap;
    TButton *btInorder;
    TButton *btInorderNR;
    TButton *btInsertion;
    TButton *btQuick;
    TButton *btRandom;
    TButton *btSelection;
    TCheckBox *cbShowData;
    TCheckBox *cbShowResult;
    TEdit *edNum;
    TEdit *edRange;
    TLabel *Label4;
    TLabel *lblCPUTime;
    TLabel *lblNum;
    TLabel *lblRange;
    TMemo *Memo1;
    TMemo *Memo2;
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
unsigned int i,j,k;
unsigned int uiNum, uiRange;

// Array input & result
int* iRandomData, *iResultData;

// Array heap
int *iHeap;
//---------------------------------------------------------------------------
//宣告執行緒類別
class TMyThread:public TThread
{
public:
    __fastcall TMyThread(void);
private:
    void __fastcall Execute(void);
};
//---------------------------------------------------------------------------
#endif
