//---------------------------------------------------------------------------

#ifndef FormMainH
#define FormMainH
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

//---------------------------------------------------------------------------
class TFrmMain : public TForm
{
__published:	// IDE-managed Components
	TImage *ImgScr;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall PlayImgClick(TObject *Sender);
private:	// User declarations
	tDisplay RoachImg[2][21];
	tDisplay NewsImg[9];

    int PoseNo;
	int RoachWidth[2][21], RoachHeight[2][21], SprNo, xRoach, yRoach, TickCount;
	//int RoachAtkW[21], RoachAtkH[21], RASprNo, xRoachAtk, yRoachAtk, RATickCount;
	int NewsWidth[9], NewsHeight[9], NSprNo, xNews, yNews, NTickCount;
    bool Hit, Atk;

	Graphics::TBitmap *BM;

	void __fastcall KecoaIdleLoop(TObject *Sender, bool &Done);

public:		// User declarations
	__fastcall TFrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMain *FrmMain;
//---------------------------------------------------------------------------
#endif
