//---------------------------------------------------------------------------

#ifndef ShortestPathH
#define ShortestPathH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfShortestPath : public TForm
{
__published:	// IDE-managed Components
    TPanel *panlControl;
    TGroupBox *gbInputGroup;
    TGroupBox *gbOutputGroup;
    TPageControl *pcOutput;
    TTabSheet *tsSolutions;
    TTabSheet *tsAjacentMatrix;
    TTabSheet *tsShortestPaths;
    TTabSheet *tsTransitiveClosure;
    TLabel *lblVertexNum;
    TLabel *lblRange;
    TLabel *lblSource;
    TEdit *edVertexNum;
    TEdit *edRange;
    TEdit *edWeightLimit;
    TEdit *edWeightMax;
    TLabel *lblWeightLimit;
    TLabel *lblWeightMax;
    TEdit *edSource;
    TButton *btGenerateG;
    TCheckBox *cbUndirectedG;
    TCheckBox *cbPrintG;
    TButton *btSingleSource;
    TButton *btAllPairs;
    TButton *btTransitiveClosure;
    TCheckBox *cbPrintResult;
    TMemo *memSolutions;
    TStringGrid *sgAjacentMatrix;
    TStringGrid *sgShortestPaths;
    TStringGrid *sgTransitiveClosure;
    TTabSheet *TabSheet2;
    TStringGrid *sgSSADTables;
    void __fastcall btGenerateGClick(TObject *Sender);
    void __fastcall btSingleSourceClick(TObject *Sender);
    void __fastcall btAllPairsClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfShortestPath(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfShortestPath *fShortestPath;
/****************************************************************************
 *办跑计
 ****************************************************************************/
//竊翴计ヘ舦絛瞅舦舦程癬﹍翴
int iVertexNum,iRange,iWeightLimit,iWeightMax,iSource;

//綟痻皚
int **iGraphArray;
//---------------------------------------------------------------------------
#endif
