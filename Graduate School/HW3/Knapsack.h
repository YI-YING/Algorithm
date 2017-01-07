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
    TButton *btAddItems;
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
    TLabel *lblUserInput;
    TLabel *lblItemWeight;
    TEdit *edItemWeight;
    TLabel *lblItemProfit;
    TEdit *edItemProfit;
    TButton *btAddItem;
    TButton *btClearAll;
    void __fastcall edItemNumChange(TObject *Sender);
    void __fastcall edItemNumExit(TObject *Sender);
    void __fastcall btAddItemsClick(TObject *Sender);
    void __fastcall btAddItemClick(TObject *Sender);
    void __fastcall btClearAllClick(TObject *Sender);
    void __fastcall btBranchAndBoundClick(TObject *Sender);
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

//declare Total Item Num
int iTotalNum = 0;

//---------------------------------------------------------------------------
#endif
