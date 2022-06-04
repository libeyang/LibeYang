//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString saveLocation = "";
AnsiString openLocation = "";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        SaveDialog1->Execute();
	saveLocation = SaveDialog1->FileName;
        state = "Save";
	ShowMessage("다음 위치에 저장됩니다 : " + saveLocation);
	ProjectLocation = saveLocation;
	Button2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        OpenDialog1->Execute();
	openLocation = OpenDialog1->FileName;
        ShowMessage("다음 위치에 저장됩니다 : " + openLocation);
        ProjectLocation = openLocation;
	Button4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{

        ProjectLocation = "C:\\Code4Every1\\Translate.cfeo";
	Form2->Show();
        Form1->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        ProjectLocation = "C:\\Code4Every1\\Translate.cfeo";
        state = "Load";
        Form2->Show();
        Form1->Visible = false;

}
//---------------------------------------------------------------------------

