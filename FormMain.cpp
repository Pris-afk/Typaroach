//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"

#include "CPP2DWinAnimation.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmMain *FrmMain;

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
void __fastcall TFrmMain::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	switch (Key) {
	   case 27:
       int result = Application->MessageBox(L"Do you want to close the application?", L"Exit", MB_ICONQUESTION|MB_YESNO);


        if (result == IDYES) {
		// User clicked Yes
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

			if(FrmLevels->Visible){ //utk cek formny open / g (visible itu true/false)
				FrmLevels->Close();
			}

			if(FrmTampilanLevelAwal->Visible){ //utk cek formny open / g (visible itu true/false)
				FrmTampilanLevelAwal->Close();
			}

			if(FrmPlayLevel->Visible){ //utk cek formny open / g (visible itu true/false)
				FrmPlayLevel->Close();
			}

		}
		if(result==IDNO)
			Key=0;



	   break;
	   /*case '1':
			Application->OnIdle = MainLoop; break;           */
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::MainLoop(TObject *Sender, bool &Done){
   /*	CopyScreen(Back, Process, ScreenWidth, ScreenHeight);
	PutImage(RoachImg[SprNo], RoachWidth[SprNo], RoachHeight[SprNo], 990, 450, Process);
	CopyScreenToBitmap(Process, BM, ScreenWidth, ScreenHeight);
	ImgScr->Picture->Bitmap = BM;
	if (TickCount %25 == 0) {
		SprNo = (SprNo+1) % 6;
	}

	Done = false;
	TickCount++;         */


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


