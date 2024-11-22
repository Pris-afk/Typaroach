//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <IdSMTP.hpp>
#include <IdMessage.hpp>
#include <IdEMailAddress.hpp>


#include "FrmLogin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLogin *Login;

TIdSMTP *SMTP = NULL;
TIdMessage *Message = NULL;
TIdSSLIOHandlerSocketOpenSSL *SSLHandler = NULL;

String lastVerificationCode;
TDateTime codeTimestamp;

//---------------------------------------------------------------------------
__fastcall TLogin::TLogin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
////tovfncpsblvcvjxq

/*void SendVerificationEmail(const String &recipientEmail, const String &verificationCode)
{
	try {
        // Create components if they are not already created
        if (!SMTP) {
            SMTP = new TIdSMTP(NULL);
			SSLHandler = new TIdSSLIOHandlerSocketOpenSSL(NULL);
			Message = new TIdMessage(NULL);
		}

		SMTP->Host = "smtp.gmail.com";
		SMTP->Port = 587; // Use port 587 for TLS
		SMTP->Username = "typaroach@gmail.com"; // Your Gmail address
		SMTP->Password = "tovfncpsblvcvjxq";  // Your Gmail password or App password
		SMTP->IOHandler = SSLHandler;
		SMTP->UseTLS = utUseExplicitTLS; // Explicit TLS for encryption

		Message->From->Address = "typaroach@gmail.com"; // Your email address
		TIdEMailAddressItem *recipient = Message->Recipients->Add();
		recipient->Address = recipientEmail;        // Recipient email address
		Message->Subject = "Email Verification Code";    // Subject of the email
		Message->Body->Text = "Your verification code is: " + verificationCode;

		SMTP->Connect();
		SMTP->Send(Message);
		lastVerificationCode = verificationCode;
		codeTimestamp = Now(); // Store the current time when the code is sent
		ShowMessage("Verification email sent successfully!");
	}

	catch (const Exception &e) {
		ShowMessage("Failed to send email: " + e.Message);
	}
}
// Function to generate a random 6-digit verification code
String GenerateVerificationCode()
{
    String code = "";
    for (int i = 0; i < 6; i++) {
        code += IntToStr(Random(10)); // Random digit between 0-9
    }
    return code;
}
// Function to check if the code has expired (60 seconds timeout)
bool IsVerificationCodeExpired()
{
    TDateTime currentTime = Now();
    TDateTime expirationTime = codeTimestamp + TDateTime(0, 0, 0, 0, 1, 0, 0);  // 60 seconds from the timestamp
    return currentTime > expirationTime; // If the current time is greater than the expiration time, the code has expired
}

*/

//---------------------------------------------------------------------------
void __fastcall TLogin::UserBoxExit(TObject *Sender)
{
	UserOK=false;
	//check nama user 3<x<15
	if (UserBox->Text.Length() <= 3) {
		UserCheck->Caption = "Username must be at least 3 characters long.";
	}
	else if (UserBox->Text.Length()>15){
		UserCheck->Caption = "Username too long";
	}
	else {
		UserOK=true;
		UserCheck->Caption = "yay";
	}
}
//---------------------------------------------------------------------------

void __fastcall TLogin::PassExit(TObject *Sender)
{
	PassOK=false;
	//check pass>8
	if (Pass->Text.Length() <= 8) {
		PassCheck->Caption = "Password must be at least 8 characters long.";
	}
	else if (Pass->Text.Length()>8){
		PassCheck->Caption = "yay";
		PassOK=true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TLogin::EmailExit(TObject *Sender)
{
	EmailOK=false;
	bool valid = false;
	bool EmailReal = false;
	String Domain;
    String EmailUser;

	EmailUser = Email->Text;
	int EmailLen = EmailUser.Length();

	int atPos = EmailUser.Pos("@");
	if (atPos>0) {
		Domain = EmailUser.SubString(atPos + 1, EmailLen - atPos);
        valid = true;

		if (Domain == "gmail.com" || Domain == "yahoo.com") {
			EmailReal = true;
		}
		else {
			EmailReal = false;

		}

	}
	else {
		valid = false;
		EmailCheck->Caption = "Please include @.";
	}

	if (valid && EmailReal) {
		EmailCheck->Caption = "Valid Email";
	}
	else EmailCheck->Caption = "Invalid Email";

}
//---------------------------------------------------------------------------

/*void __fastcall TLogin::SendCodeClick(TObject *Sender)
{
	String recipientEmail = "kluckk183@gmail.com";  // Get the recipient email from input
	String verificationCode = GenerateVerificationCode();
	SendVerificationEmail(recipientEmail, verificationCode);
} */
//---------------------------------------------------------------------------

/*void __fastcall TLogin::VerifyCodeClick(TObject *Sender)
{
	String enteredCode = VerificationCodeEdit->Text; // Assuming user enters the code in an Edit box

	if (IsVerificationCodeExpired()) {
		ShowMessage("The verification code has expired. Please request a new one.");
	}
	else if (enteredCode == lastVerificationCode) {
		ShowMessage("Verification successful!");
		// Proceed with successful verification actions
	}
	else {
		ShowMessage("Invalid verification code. Please try again.");
	}
}   */
//---------------------------------------------------------------------------


