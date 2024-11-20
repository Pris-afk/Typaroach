//---------------------------------------------------------------------------

#ifndef FrmPlayLevelsH
#define FrmPlayLevelsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CPP2DWinAnimation.h"
#include <Vcl.ExtCtrls.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TFrmPlayLevel : public TForm
{
__published:	// IDE-managed Components
	TImage *ImgScr;
	TProgressBar *HPBarUser;
	TProgressBar *ProgressBar1;
	TADOConnection *KoneksiDB;
	TADOQuery *QueryWord;
	TLabel *Label1;
	TADOTable *TblUserWord;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
	tDisplay RoachImg[3][21];
	tDisplay NewsImg[10], Letters[2][26];
	char **WordsDB, WordInput[15], WordOutput[15];

	bool WordIsMoving;
	int PoseNo, lWordInput, WordCount, xWord, yWord, LetterWidth, LetterHeight;
	int rand, HurufKe;
	int RoachWidth[3][21], RoachHeight[3][21], SprNo, xRoach, yRoach, TickCount;
	//int RoachAtkW[21], RoachAtkH[21], RASprNo, xRoachAtk, yRoachAtk, RATickCount;
	int NewsWidth[10], NewsHeight[10], NSprNo, xNews, yNews, NTickCount;
	bool Hit, Atk, Hurt;

	Graphics::TBitmap *BM;
	TLocateOptions LO;

public:		// User declarations
	void PrepareImages();
	__fastcall TFrmPlayLevel(TComponent* Owner);
	void __fastcall MainLoop(TObject *Sender, bool &Done);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmPlayLevel *FrmPlayLevel;
//---------------------------------------------------------------------------
#endif
