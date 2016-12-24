//---------------------------------------------------------------------------

#ifndef SortingAlgorithmH
#define SortingAlgorithmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>
#include <ComCtrls.hpp>
#include <Chart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
//---------------------------------------------------------------------------
class TfSortingAlgorithm : public TForm
{
__published:	// IDE-managed Components
    TPanel *pControl;
    TPanel *pShowResult;
    TGroupBox *gbInput;
    TGroupBox *gbSorting;
    TGroupBox *gbCheck;
    TCheckListBox *clbAlgorithms;
    TLabel *lblTimes;
    TLabel *lblNum;
    TLabel *lblRange;
    TEdit *edTimes;
    TEdit *edNum;
    TEdit *edRange;
    TCheckBox *cbSeeData;
    TButton *btDrawDiagram;
    TPageControl *pcShowData;
    TTabSheet *tsDiagram;
    TTabSheet *tsData;
    TMemo *memCheck;
    TChart *chDiagram;
    TLineSeries *Series1;
    TMemo *memData;
    void __fastcall btDrawDiagramClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfSortingAlgorithm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfSortingAlgorithm *fSortingAlgorithm;
//---------------------------------------------------------------------------
//办跑计
int iTimes, iNum, iRange;   //璶磅︽碭Ω计睹计絛瞅
//---------------------------------------------------------------------------
#endif
