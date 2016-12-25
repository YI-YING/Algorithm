//---------------------------------------------------------------------------

#ifndef KnapsackH
#define KnapsackH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfKnapsack : public TForm
{
__published:	// IDE-managed Components
    TPanel *PLeft;
    TPanel *PRight;
    TSplitter *Splitter1;
    TPageControl *PageControl1;
    TTabSheet *tsSolution;
    TTabSheet *tsItems;
    TMemo *memSolution;
    TStringGrid *sgItems;
    TLabel *Label1;
    TButton *btGenerate;
    TLabel *lblItemNum;
    TLabel *lblWeightRange;
    TEdit *edItemNum;
    TEdit *edWeightRange;
    TLabel *lblBagCapacity;
    TEdit *edBagCapacity;
    TCheckBox *cbPrintItems;
    TLabel *Label5;
    TButton *btBranchAndBound;
    TEdit *edProfitRange;
    TLabel *lblProfitRange;
    void __fastcall edItemNumChange(TObject *Sender);
    void __fastcall edItemNumExit(TObject *Sender);
    void __fastcall btGenerateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfKnapsack(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfKnapsack *fKnapsack;
/***************************************************************************
 *宣告全域變數
 ***************************************************************************/
//declare input
int iItemNum, iWeightRange, iProfitRange, iBagCapacity;

//declare dynamic Weights, Profits Array
int **iItems;
//---------------------------------------------------------------------------
#endif
