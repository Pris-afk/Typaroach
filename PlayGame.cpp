//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmPlayLevels.h"
#include "CPP2DWinAnimation.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmPlayLevel *FrmPlayLevel;

void AnsiToCStr(AnsiString AS, char CStr[])
{
 int i, l=AS.Length();
 for(i=0; i<l; i++)
  CStr[i]=AS[i+1];
 CStr[i]=0;
}

void TFrmPlayLevel::PrepareImages()
{
	int i;
	//get OldScreenResolution
	//OldScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	//OldScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	//Label1->Caption = OldScreenHeight;
	//SetScreenResolution(1366, 768);
	//Prepare form
	//BorderStyle = bsNone;
	WindowState = wsNormal;

	strcpy(WordOutput, "aaa");

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
	RoachImg[0][0] = LoadImageFromBitmap(RoachImg[0][0], &RoachWidth[0][0], &RoachHeight[0][0], "KecoaIdle1.bmp");
	RoachImg[0][1] = LoadImageFromBitmap(RoachImg[0][1], &RoachWidth[0][1], &RoachHeight[0][1], "KecoaIdle2.bmp");
	RoachImg[0][2] = LoadImageFromBitmap(RoachImg[0][2], &RoachWidth[0][2], &RoachHeight[0][2], "KecoaIdle3.bmp");
	RoachImg[0][3] = LoadImageFromBitmap(RoachImg[0][3], &RoachWidth[0][3], &RoachHeight[0][3], "KecoaIdle4.bmp");
	RoachImg[0][4] = LoadImageFromBitmap(RoachImg[0][4], &RoachWidth[0][4], &RoachHeight[0][4], "KecoaIdle3.bmp");
	RoachImg[0][5] = LoadImageFromBitmap(RoachImg[0][5], &RoachWidth[0][5], &RoachHeight[0][5], "KecoaIdle2.bmp");

	//Kecoa Attack
	RoachImg[1][0] = LoadImageFromBitmap(RoachImg[1][0], &RoachWidth[1][0], &RoachHeight[1][0], "KecoaAtk1.bmp");
	RoachImg[1][1] = LoadImageFromBitmap(RoachImg[1][1], &RoachWidth[1][1], &RoachHeight[1][1], "KecoaAtk2.bmp");
	RoachImg[1][2] = LoadImageFromBitmap(RoachImg[1][2], &RoachWidth[1][2], &RoachHeight[1][2], "KecoaAtk3.bmp");
	RoachImg[1][3] = LoadImageFromBitmap(RoachImg[1][3], &RoachWidth[1][3], &RoachHeight[1][3], "KecoaAtk4.bmp");
	RoachImg[1][4] = LoadImageFromBitmap(RoachImg[1][4], &RoachWidth[1][4], &RoachHeight[1][4], "KecoaAtk5.bmp");
	RoachImg[1][5] = LoadImageFromBitmap(RoachImg[1][5], &RoachWidth[1][5], &RoachHeight[1][5], "KecoaAtk6.bmp");
	RoachImg[1][6] = LoadImageFromBitmap(RoachImg[1][6], &RoachWidth[1][6], &RoachHeight[1][6], "KecoaAtk7.bmp");
	RoachImg[1][7] = LoadImageFromBitmap(RoachImg[1][7], &RoachWidth[1][7], &RoachHeight[1][7], "KecoaAtk8.bmp");
	RoachImg[1][8] = LoadImageFromBitmap(RoachImg[1][8], &RoachWidth[1][8], &RoachHeight[1][8], "KecoaAtk9.bmp");
	RoachImg[1][9] = LoadImageFromBitmap(RoachImg[1][9], &RoachWidth[1][9], &RoachHeight[1][9], "KecoaAtk10.bmp");
	RoachImg[1][10] = LoadImageFromBitmap(RoachImg[1][10], &RoachWidth[1][10], &RoachHeight[1][10], "KecoaAtk11.bmp");
	RoachImg[1][11] = LoadImageFromBitmap(RoachImg[1][11], &RoachWidth[1][11], &RoachHeight[1][11], "KecoaAtk12.bmp");
	RoachImg[1][12] = LoadImageFromBitmap(RoachImg[1][12], &RoachWidth[1][12], &RoachHeight[1][12], "KecoaAtk13.bmp");
	RoachImg[1][13] = LoadImageFromBitmap(RoachImg[1][13], &RoachWidth[1][13], &RoachHeight[1][13], "KecoaAtk14.bmp");
	RoachImg[1][14] = LoadImageFromBitmap(RoachImg[1][14], &RoachWidth[1][14], &RoachHeight[1][14], "KecoaAtk15.bmp");
	RoachImg[1][15] = LoadImageFromBitmap(RoachImg[1][15], &RoachWidth[1][15], &RoachHeight[1][15], "KecoaAtk16.bmp");
	RoachImg[1][16] = LoadImageFromBitmap(RoachImg[1][16], &RoachWidth[1][16], &RoachHeight[1][16], "KecoaAtk17.bmp");
	RoachImg[1][17] = LoadImageFromBitmap(RoachImg[1][17], &RoachWidth[1][17], &RoachHeight[1][17], "KecoaAtk18.bmp");
	RoachImg[1][18] = LoadImageFromBitmap(RoachImg[1][18], &RoachWidth[1][18], &RoachHeight[1][18], "KecoaAtk19.bmp");
	RoachImg[1][19] = LoadImageFromBitmap(RoachImg[1][19], &RoachWidth[1][19], &RoachHeight[1][19], "KecoaAtk20.bmp");
	RoachImg[1][20] = LoadImageFromBitmap(RoachImg[1][20], &RoachWidth[1][20], &RoachHeight[1][20], "KecoaAtk21.bmp");

	//Kecoa Dizzy
	RoachImg[2][0] = LoadImageFromBitmap(RoachImg[2][0], &RoachWidth[2][0], &RoachHeight[2][0], "KecoaDizzy1.bmp");
	RoachImg[2][1] = LoadImageFromBitmap(RoachImg[2][1], &RoachWidth[2][1], &RoachHeight[2][1], "KecoaDizzy2.bmp");
	RoachImg[2][2] = LoadImageFromBitmap(RoachImg[2][2], &RoachWidth[2][2], &RoachHeight[2][2], "KecoaDizzy3.bmp");
	RoachImg[2][3] = LoadImageFromBitmap(RoachImg[2][3], &RoachWidth[2][3], &RoachHeight[2][3], "KecoaDizzy4.bmp");
	RoachImg[2][4] = LoadImageFromBitmap(RoachImg[2][4], &RoachWidth[2][4], &RoachHeight[2][4], "KecoaDizzy5.bmp");
	RoachImg[2][5] = LoadImageFromBitmap(RoachImg[2][5], &RoachWidth[2][5], &RoachHeight[2][5], "KecoaDizzy6.bmp");
	RoachImg[2][6] = LoadImageFromBitmap(RoachImg[2][6], &RoachWidth[2][6], &RoachHeight[2][6], "KecoaDizzy5.bmp");
	RoachImg[2][7] = LoadImageFromBitmap(RoachImg[2][7], &RoachWidth[2][7], &RoachHeight[2][7], "KecoaDizzy4.bmp");
	//RoachImg[2][8] = LoadImageFromBitmap(RoachImg[2][8], &RoachWidth[2][8], &RoachHeight[2][8], "KecoaDizzy3.bmp");
	//RoachImg[2][9] = LoadImageFromBitmap(RoachImg[2][9], &RoachWidth[2][9], &RoachHeight[2][9], "KecoaDizzy2.bmp");

	//Newspaper hand
	NewsImg[0] = LoadImageFromBitmap(NewsImg[0], &NewsWidth[0], &NewsHeight[0], "news1.bmp");
	NewsImg[1] = LoadImageFromBitmap(NewsImg[1], &NewsWidth[1], &NewsHeight[1], "news2.bmp");
	NewsImg[2] = LoadImageFromBitmap(NewsImg[2], &NewsWidth[2], &NewsHeight[2], "news3.bmp");
	NewsImg[3] = LoadImageFromBitmap(NewsImg[3], &NewsWidth[3], &NewsHeight[3], "news4.bmp");
	NewsImg[4] = LoadImageFromBitmap(NewsImg[4], &NewsWidth[4], &NewsHeight[4], "news5.bmp");
	NewsImg[5] = LoadImageFromBitmap(NewsImg[5], &NewsWidth[5], &NewsHeight[5], "news5.bmp");
	NewsImg[6] = LoadImageFromBitmap(NewsImg[6], &NewsWidth[6], &NewsHeight[6], "news4.bmp");
	NewsImg[7] = LoadImageFromBitmap(NewsImg[7], &NewsWidth[7], &NewsHeight[7], "news3.bmp");
	NewsImg[8] = LoadImageFromBitmap(NewsImg[8], &NewsWidth[8], &NewsHeight[8], "news2.bmp");
	NewsImg[9] = LoadImageFromBitmap(NewsImg[9], &NewsWidth[9], &NewsHeight[9], "news1.bmp");

	Letters[0][0] = LoadImageFromBitmap(Letters[0][0], &LetterWidth, &LetterHeight, "Letters\\White\\AW.bmp");

	//anggap semuanya huruf A dulu untuk percobaan
	for(i=1; i<26; i++) Letters[0][i]=Letters[0][0];
	for(i=0; i<26; i++) Letters[1][i]=Letters[0][0];

	Hit=false;
	Atk=false;

	PoseNo=0;
	NSprNo = 0;
	SprNo = 0;
	TickCount = 0;
	NTickCount = 0;
	BM->Width=ScreenWidth;
	BM->Height=ScreenHeight;

	CopyScreen(Back, Process, ScreenWidth, ScreenHeight);
	PutImage(RoachImg[PoseNo][SprNo], RoachWidth[PoseNo][SprNo], RoachHeight[PoseNo][SprNo], 900, 430, Process);
	PutImage(NewsImg[NSprNo], NewsWidth[NSprNo], NewsHeight[NSprNo], -120, 0, Process);
	CopyScreenToBitmap(Process, BM, ScreenWidth, ScreenHeight);
	ImgScr->Picture->Bitmap = BM;

	WordIsMoving=false;
	randomize();

	//Application->OnIdle = MainLoop;
}
//---------------------------------------------------------------------------
__fastcall TFrmPlayLevel::TFrmPlayLevel(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmPlayLevel::FormCreate(TObject *Sender)
{
 int i;
	KoneksiDB->Close();
	KoneksiDB->ConnectionString="Provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseTesttttttttPls.mdb;Persist Security Info=False";
	KoneksiDB->Open();

	TblUserWord->Connection=KoneksiDB;
	TblUserWord->TableName="UserWord";
	TblUserWord->Open();
	
	QueryWord->Connection=KoneksiDB;
	QueryWord->Close();
	QueryWord->SQL->Clear();
	QueryWord->SQL->Add("Select * From Word Where WordID Like 'W1%' Order By WordID");
	QueryWord->Open();
	QueryWord->ExecSQL();

	WordCount=QueryWord->RecordCount;
	QueryWord->First();
	ShowMessage(IntToStr(WordCount));
	WordsDB=new char * [WordCount];
	for(i=0; i<WordCount; i++) {
	 WordsDB[i]=new char [15];
	 AnsiToCStr(QueryWord->FieldByName("Word")->AsString, WordsDB[i]);
	 QueryWord->Next();
	}
	QueryWord->Close();
	//KoneksiDB->Close(); //pindahkan ke FormClose
	PrepareImages();
	LO<<loCaseInsensitive;
}

void __fastcall TFrmPlayLevel::MainLoop(TObject *Sender, bool &Done){
	int i;

	CopyScreen(Back, Process, ScreenWidth, ScreenHeight);
	PutImage(RoachImg[PoseNo][SprNo], RoachWidth[PoseNo][SprNo], RoachHeight[PoseNo][SprNo], 900, 430, Process);
	//PutImage(NewsImg[0], NewsWidth[0], NewsHeight[0], -114, 0, Process);
	PutImage(NewsImg[NSprNo], NewsWidth[NSprNo], NewsHeight[NSprNo], -120, 0, Process);
	//PutImage(RoachAtk[SprNo], RoachWidth[SprNo], RoachHeight[SprNo], 990, 450, Process);

   Label1->Caption=IntToStr(xWord) + " , " + IntToStr(yWord) + " " + WordOutput;
   if (WordIsMoving) {
	   for(i=0; i<3; i++)
		  PutImage(Letters[0][ WordOutput[i]-97 ], LetterWidth, LetterHeight, xWord+i*LetterWidth, yWord, Process);

	   if (xWord>ScreenWidth/2) xWord--; else WordIsMoving=false;
   } else {
	   strcpy(WordOutput, WordsDB[ Random(WordCount) ]);
	   WordIsMoving=true;
	   xWord=ScreenWidth-100;
	   yWord=300;
	   HurufKe=0;
   }

	CopyScreenToBitmap(Process, BM, ScreenWidth, ScreenHeight);
	ImgScr->Picture->Bitmap = BM;

	//kecoa idle
	if(PoseNo==0){
		if (TickCount %25 == 0) {
			SprNo = (SprNo+1) % 6;
		}
	}

	//if kecoa get hit
	if(NSprNo==5){
		Hurt=true;
		PoseNo=2;
		SprNo=0;
	}

	//trigger animation for kecoa getting hit
	if(Hurt){
		//PoseNo=2;
		//SprNo=0;
		if(TickCount %10==0){
			SprNo++;
			if(SprNo>=8){
				PoseNo=0;
				SprNo=0;
				Hurt=false;

			}
		}
	}

	//if hand attacks
	if (TickCount %5 == 0 && Hit) {
		NSprNo++;
		//if(TickCount %10 == 0 && Hurt){//slower kecoa getting hit animation
			//PoseNo=2;
			//SprNo++;
		//}
		if (NSprNo>=9) {
			NSprNo=0;
			Hit=false;
		}

	}


	if(PoseNo==1){//if kecoa attack
		if (TickCount %5 == 0 && Atk) {
			SprNo++;

			if (SprNo>=20) {
				PoseNo=0;
				SprNo=0;
				Atk=false;
			}
		}
	}

	Done = false;
	TickCount++;
}

//---------------------------------------------------------------------------
void __fastcall TFrmPlayLevel::FormClose(TObject *Sender, TCloseAction &Action)
{
	SetScreenResolution(OldScreenWidth, OldScreenHeight);
}
//---------------------------------------------------------------------------
void __fastcall TFrmPlayLevel::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	AnsiString Cari;
	switch (Key) {
		case 27: Close(); break;
		case '1':
			Atk=true;
			PoseNo=1;
			break;
			//Application->OnIdle = KecoaIdleLoop; break;
		case 13:
			Hit=true; break;
			//Application->OnIdle = KecoaIdleLoop;
			//Application->OnIdle = NewsLoop;
			//AnimationFinished = false; break;
			//if (NSprNo == 8) {
			//	Application->OnIdle = KecoaIdleLoop; break;
			//}
		default: 
			if (Key>='A' && Key<='Z') Key+=32;
			if (Key>='a' && Key<='z') {
				WordInput[HurufKe]=Key;
				HurufKe++;
				WordInput[HurufKe]=0;

				if (HurufKe==3) {
				   Cari=WordInput;
				   if (!TblUserWord->Locate('Word', Cari, LO)) {
					   TblUserWord->Append();
					   //TblUserWord->FieldByName("UserID")->AsString=...;
					   TblUserWord->FieldByName("Word")->AsString=Cari;
					   TblUserWord->Post();
				   }
				}
			}
			
	}
}
//---------------------------------------------------------------------------
