//---------------------------------------------------------------------------

#ifndef MST_KruscalAndPrimH
#define MST_KruscalAndPrimH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfMST : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *gpbGraphic;
    TGroupBox *gpbMSTAlgorithm;
    TPageControl *pcOutput;
    TTabSheet *tsMSTFound;
    TLabel *lblVertex;
    TLabel *lblWeightRange;
    TLabel *lblWeightLimit;
    TLabel *lblWeightMax;
    TButton *btGenerateG;
    TEdit *edVertexNum;
    TEdit *edWeightRange;
    TEdit *edWeightLimit;
    TEdit *edWeightMax;
    TCheckBox *cbPrintG;
    TButton *btKruscal;
    TButton *btPrim;
    TCheckBox *cbPrintEdges;
    TMemo *Memo1;
    TTabSheet *tbAjacentMatrix;
    TStringGrid *sgAjacentMatrix;
    TTabSheet *tbEdgesMatrix;
    TStringGrid *sgEdgesMatrix;
    void __fastcall btGenerateGClick(TObject *Sender);
    void __fastcall btKruscalClick(TObject *Sender);
    void __fastcall btPrimClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfMST(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMST *fMST;
//---------------------------------------------------------------------------
//declare user input
int iVertexNum,iWeightRange,iWeightLimit,iWeightMax;

//declare dynamic Graph Array, Edges Array;
int **iGraphicArray, **iEdgesArray;

//declare Heap Count,Array
int iHeapCount;
int *iHeapArray;
//---------------------------------------------------------------------------
//declare 統計資料
int iEdges;
int iCycleNum;
//---------------------------------------------------------------------------
#endif
