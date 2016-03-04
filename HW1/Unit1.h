//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
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
        TEdit *edInsertIntoBST;
        TButton *btInsertIntoBST;
        TEdit *edDeleteFromBST;
        TButton *btDeletefromBST;
        TLabel *Label1;
    TTrackBar *trbNumOfInteger;
    TEdit *edNumOfInteger;
        TLabel *Label2;
    TTrackBar *trbRange;
    TEdit *edRange;
    TButton *btRandom;
    TMemo *Memo1;
    void __fastcall trbNumOfIntegerChange(TObject *Sender);
    void __fastcall trbRangeChange(TObject *Sender);
    void __fastcall btInsertIntoBSTClick(TObject *Sender);
    void __fastcall edInsertIntoBSTKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edInsertIntoBSTKeyPress(TObject *Sender, char &Key);
    void __fastcall btDeletefromBSTClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
//public variable
//---------------------------------------------------------------------------
#endif
