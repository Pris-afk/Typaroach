//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"
#include "FrmLogin.h"
#include "FrmShopcpp.h"
#include "FrmShop2.h"
#include "FrmShop3.h"
#include "FrmWord.h"
#include "FrmLevel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmMain *FrmMain;
TLogin *Login;
TForm1 *Form1; //FrmShopcpp
TForm2 *Form2; //FrmShop2
TForm3 *Form3; //FrmShop3
TFrmWords *FrmWords;
TFrmLevels *FrmLevels;
//---------------------------------------------------------------------------
__fastcall TFrmMain::TFrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TLogin::TLogin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::FormCreate(TObject *Sender)
{

	//get OldScreenResolution
	OldScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	OldScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	//Label1->Caption = OldScreenHeight;
	SetScreenResolution(1366, 768);
	//Prepare form
	//BorderStyle = bsNone;
	WindowState = wsNormal;

	//Prepare Screen
	BackWidth = 1366;
	BackHeight = 768;
	ScreenWidth = 1366;
	ScreenHeight = 768;
	CurrentBytePerPixel = 3;
	CurrentBitPerPixel = 24;
	CurrentPixelFormat = pf24bit;

	ImgScr->Left = 0;
	ImgScr->Width = ScreenWidth;
	ImgScr->Height = ScreenHeight;


	BM = new Graphics::TBitmap;
	//Back = AllocateObjectMemory(Back, BackWidth * BackHeight * CurrentBytePerPixel);
	Process = AllocateObjectMemory(Process, ScreenWidth * ScreenHeight * CurrentBytePerPixel);

	//Loading Img assets
	Back = LoadImageFromBitmap(Back, &BackWidth, &BackHeight, "BG2.bmp");
	RoachImg[0] = LoadImageFromBitmap(RoachImg[0], &RoachWidth[0], &RoachHeight[0], "KecoaIdle1.bmp");
	RoachImg[1] = LoadImageFromBitmap(RoachImg[1], &RoachWidth[1], &RoachHeight[1], "KecoaIdle2.bmp");
	RoachImg[2] = LoadImageFromBitmap(RoachImg[2], &RoachWidth[2], &RoachHeight[2], "KecoaIdle3.bmp");
	RoachImg[3] = LoadImageFromBitmap(RoachImg[3], &RoachWidth[3], &RoachHeight[3], "KecoaIdle4.bmp");
	RoachImg[4] = LoadImageFromBitmap(RoachImg[4], &RoachWidth[4], &RoachHeight[4], "KecoaIdle3.bmp");
	RoachImg[5] = LoadImageFromBitmap(RoachImg[5], &RoachWidth[5], &RoachHeight[5], "KecoaIdle2.bmp");
	//RoachImg[6] = LoadImageFromBitmap(RoachImg[6], &RoachWidth[6], &RoachHeight[6], "KecoaIdle1.bmp");
	//RoachImg[7] = LoadImageFromBitmap(RoachImg[7], &RoachWidth[7], &RoachHeight[7], "KecoaIdle4.bmp");

	SprNo = 0;
	TickCount = 0;
	BM->Width=ScreenWidth;
	BM->Height=ScreenHeight;

	CopyScreen(Back, Process, ScreenWidth, ScreenHeight);
	CopyScreenToBitmap(Process, BM, ScreenWidth, ScreenHeight);
	ImgScr->Picture->Bitmap = BM;
	//Application->OnIdle = MainLoop;

}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	switch (Key) {
	   case 27:
		if(FrmMain->Visible){
			FrmMain->Close();
		}

		if(Form1->Visible){ //utk cek formny open / g (visible itu true/false)
			Form1->Close();
		}

		if(Form2->Visible){ //utk cek formny open / g (visible itu true/false)
			Form2->Close();
		}

		if(Form3->Visible){ //utk cek formny open / g (visible itu true/false)
			Form3->Close();
		}

		if(FrmWords->Visible){ //utk cek formny open / g (visible itu true/false)
			FrmWords->Close();
		}

	   break;
	   case '1':
			Application->OnIdle = MainLoop; break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::MainLoop(TObject *Sender, bool &Done){
	CopyScreen(Back, Process, ScreenWidth, ScreenHeight);
	PutImage(RoachImg[SprNo], RoachWidth[SprNo], RoachHeight[SprNo], 990, 450, Process);
	CopyScreenToBitmap(Process, BM, ScreenWidth, ScreenHeight);
	ImgScr->Picture->Bitmap = BM;
	if (TickCount %25 == 0) {
		SprNo = (SprNo+1) % 6;
	}

	Done = false;
	TickCount++;


}
void __fastcall TFrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	SetScreenResolution(OldScreenWidth, OldScreenHeight);
}
//---------------------------------------------------------------------------


//NI GJD

void __fastcall TFrmMain::PlayImgClick(TObject *Sender)
{
	/*PressedPlay = Buttons->GetImageHandle(1);
	PlayImg->Picture = PressedPlay;    */
	FrmLevels->Show();  //FrmShopcpp
	FrmMain->SendToBack();
}
//---------------------------------------------------------------------------


void __fastcall TFrmMain::ShopImgClick(TObject *Sender)
{
	Form1->Show();  //FrmShopcpp
	FrmMain->SendToBack();
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::WordsImgClick(TObject *Sender)
{
	FrmWords->Show();
	FrmMain->SendToBack();
}
//---------------------------------------------------------------------------
