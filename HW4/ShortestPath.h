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
class TfShowtestPath : public TForm
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
private:	// User declarations
public:		// User declarations
    __fastcall TfShowtestPath(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfShowtestPath *fShowtestPath;
//---------------------------------------------------------------------------
#endif
