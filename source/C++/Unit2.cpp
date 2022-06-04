//---------------------------------------------------------------------------

#include <vcl.h>
#include <IdGlobal.hpp>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int StaticComponentX = 100;
int StaticComponentY = 100;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
        if (Edit5->Text == "#INTERNAL#RAWCOMPONENT#$?#") {
                ShowMessage("이 값은 사용할 수 없습니다.");
        } else {

        if (Panel4->Caption != "선택된 도구 없음"){


        AnsiString str = getComponentName(Panel4->Caption);
        int num = getComponentNumber(Panel4->Caption);

        if (ComboBox1->Text == "글씨") {

		if (str == "label") {
			labels[num]->Caption = Edit1->Text;
		} else if (str == "button") {
			buttons[num]->Caption = Edit1->Text;
		} else if (str == "edit") {
			textboxes[num]->Text = Edit1->Text;
		} else if (str == "memo") {
			memo[num]->Text = Memo2->Text;
		} else if (str == "checkbox") {
			checkboxes[num]->Caption = Edit1->Text;
		}

	} else if (ComboBox1->Text == "가로 위치") {

		if (str == "label") {
			labels[num]->Left= StrToInt(Edit1->Text);
		} else if (str == "button") {
			buttons[num]->Left= StrToInt(Edit1->Text);
		} else if (str == "edit") {
			textboxes[num]->Left= StrToInt(Edit1->Text);
		} else if (str == "memo") {
			memo[num]->Left= StrToInt(Edit1->Text);
		} else if (str == "checkbox") {
			checkboxes[num]->Left= StrToInt(Edit1->Text);
		} else if (str == "combobox") {
			comboedits[num]->Left= StrToInt(Edit1->Text);
		}

	} else if (ComboBox1->Text == "세로 위치") {

		if (str == "label") {
			labels[num]->Top = StrToInt(Edit1->Text);
		} else if (str == "button") {
			buttons[num]->Top = StrToInt(Edit1->Text);
		} else if (str == "edit") {
			textboxes[num]->Top = StrToInt(Edit1->Text);
		} else if (str == "memo") {
			memo[num]->Top = StrToInt(Edit1->Text);
		} else if (str == "checkbox") {
			checkboxes[num]->Top = StrToInt(Edit1->Text);
		} else if (str == "combobox") {
			comboedits[num]->Top = StrToInt(Edit1->Text);
		}

	} else if (ComboBox1->Text == "가로 길이") {

		if (str == "label") {
			labels[num]->Width = StrToInt(Edit1->Text);
		} else if (str == "button") {
			buttons[num]->Width = StrToInt(Edit1->Text);
		} else if (str == "edit") {
			textboxes[num]->Width = StrToInt(Edit1->Text);
		} else if (str == "memo") {
			memo[num]->Width = StrToInt(Edit1->Text);
		} else if (str == "checkbox") {
			checkboxes[num]->Width = StrToInt(Edit1->Text);
		} else if (str == "combobox") {
			comboedits[num]->Width = StrToInt(Edit1->Text);
		}

	} else if (ComboBox1->Text == "세로 길이") {

		if (str == "label") {
			labels[num]->Height = StrToInt(Edit1->Text);
		} else if (str == "button") {
			buttons[num]->Height = StrToInt(Edit1->Text);
		} else if (str == "edit") {
			textboxes[num]->Height = StrToInt(Edit1->Text);
		} else if (str == "memo") {
			memo[num]->Height = StrToInt(Edit1->Text);
		} else if (str == "checkbox") {
			checkboxes[num]->Height = StrToInt(Edit1->Text);
		} else if (str == "combobox") {
			comboedits[num]->Height = StrToInt(Edit1->Text);
		}

	} else if (ComboBox1->Text == "항목") {

                if (str == "combobox") {
		        comboedits[num]->Items->Text = Memo2->Text;
		}


        } else if (ComboBox1->Text == "선택 여부") {

                if (str == "checkbox") {
			if (Edit1->Text.UpperCase() == "O") {
                                checkboxes[num]->Checked = true;
                        } else {
                                checkboxes[num]->Checked = false;
                        }
		}

        }

        }
        else {
                ShowMessage("도구를 선택해 주세요.");
        }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormShow(TObject *Sender)
{
        ComponentAmount = 0;

        this->Color = (TColor)RGB(108, 185, 255);
        Panel6->Color = (TColor)RGB(255, 180, 0);
        Panel7->Color = (TColor)RGB(0, 211, 176);


	for (int i = 0; i < 32; i++) {

		buttons[i] = new TButton(Form4);
                buttons[i]->Caption = "#INTERNAL#RAWCOMPONENT#$?#";

		labels[i] = new TLabel(Form4);
                labels[i]->Caption = "#INTERNAL#RAWCOMPONENT#$?#";


		//TCheckBox* CHECKBOX = new TCheckBox(NULL);
		//CHECKBOX
                checkboxes[i] = new TCheckBox(Form4);
		checkboxes[i]->Caption = "#INTERNAL#RAWCOMPONENT#$?#";

		//TMemo* MEMO = new TMemo(NULL);
		//MEMO->Text = "#INTERNAL#RAWCOMPONENT#$?#";
                memo[i] = new TMemo(Form4);
		memo[i]->Text = "#INTERNAL#RAWCOMPONENT#$?#";

	       //	TEdit* EDIT = new TEdit(NULL);
		//EDIT->Text = "#INTERNAL#RAWCOMPONENT#$?#";
                textboxes[i] = new TEdit(Form4);
	       	textboxes[i]->Text = "#INTERNAL#RAWCOMPONENT#$?#";

		//TComboEdit* CMBE = new TComboEdit(NULL);
		//CMBE->Text = "#INTERNAL#RAWCOMPONENT#$?#";
                comboedits[i] = new TComboBox(Form4);
		comboedits[i]->Text = "#INTERNAL#RAWCOMPONENT#$?#";

	}

        if (Form1->state == "Load") {
                LoadMemo->Lines->LoadFromFile(Form1->ProjectLocation);

                for (int i = 0; i < LoadMemo->Lines->Count; i++){

                        AnsiString str = LoadMemo->Lines->Strings[i];
                        if (str.SubString(0, 3) == "new") {
                                if (str.SubString(5, 2) == "bu") {
                                        addButton();
                                }
                                else if (str.SubString(5, 2) == "la") {
                                        addLabel();
                                }
                                else if (str.SubString(5, 2) == "me") {
                                        addMemo();
                                }
                                else if (str.SubString(5, 2) == "ch") {
                                        addCheckbox();
                                }
                                else if (str.SubString(5, 2) == "co") {
                                        addCombobox();
                                }
                                else if (str.SubString(5, 2) == "ed") {
                                        addEdit();
                                }


                        } else if (str.SubString(0, 5) == "event") {

                                int breakchar = -1;

                                for (int j = 0; j < str.Length() - 1; j++) {
                                        if (str.SubString(j, 1) == " ") {
                                                breakchar = j;
                                        }
                                }

                                EventMemo->Lines->Add(str.SubString(7, breakchar - 7) + "@" + str.SubString(breakchar + 1, str.Length()));

                        } else {

                                int breakchar1 = -1;
                                int breakchar2 = -1;

                                for (int j = 0; j < str.Length() - 1; j++) {
                                        if (str.SubString(j, 1) == " ") {
                                                if (breakchar1 != -1) {
                                                        breakchar2 = j;
                                                } else {
                                                        breakchar1 = j;
                                                }
                                        }
                                }


                                 // label0 text

                                if (str.SubString(0, 2) == "bu") {
                                        if (str.SubString(breakchar1 + 1, 2) == "te") {
                                                buttons[StrToInt(str.SubString(7, breakchar1 - 7))]->Caption = RewindString(str.SubString(breakchar2 + 1, str.Length()));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "si") {
                                                buttons[StrToInt(str.SubString(7, breakchar1 - 7))]->Width = getX(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                                buttons[StrToInt(str.SubString(7, breakchar1 - 7))]->Height = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "po") {
                                                buttons[StrToInt(str.SubString(7, breakchar1 - 7))]->Left = getX(str.SubString(breakchar2, str.Length() - breakchar2 - 1));
                                                buttons[StrToInt(str.SubString(7, breakchar1 - 7))]->Top = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }
                                } if (str.SubString(0, 2) == "la") {
                                        if (str.SubString(breakchar1 + 1, 2) == "te") {
                                                labels[StrToInt(str.SubString(6, breakchar1 - 6))]->Caption = RewindString(str.SubString(breakchar2 + 1, str.Length()));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "si") {
                                                labels[StrToInt(str.SubString(6, breakchar1 - 6))]->Width = getX(str.SubString(breakchar2, str.Length() - breakchar2 - 1));
                                                labels[StrToInt(str.SubString(6, breakchar1 - 6))]->Height = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "po") {
                                                labels[StrToInt(str.SubString(6, breakchar1 - 6))]->Left = getX(str.SubString(breakchar2, str.Length() - breakchar2 - 1));
                                                labels[StrToInt(str.SubString(6, breakchar1 - 6))]->Top = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }
                                }  if (str.SubString(0, 2) == "ed") {
                                        if (str.SubString(breakchar1 + 1, 2) == "te") {
                                                textboxes[StrToInt(str.SubString(5, breakchar1 - 5))]->Text = RewindString(str.SubString(breakchar2 + 1, str.Length()));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "si") {
                                                textboxes[StrToInt(str.SubString(5, breakchar1 - 5))]->Width = getX(str.SubString(breakchar2 + 1, str.Length() - breakchar2 - 1));
                                                textboxes[StrToInt(str.SubString(5, breakchar1 - 5))]->Height = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "po") {
                                                textboxes[StrToInt(str.SubString(5, breakchar1 - 5))]->Left = getX(str.SubString(breakchar2 + 1, str.Length() - breakchar2 - 1));
                                                textboxes[StrToInt(str.SubString(5, breakchar1 - 5))]->Top = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }
                                }  if (str.SubString(0, 2) == "me") {
                                        if (str.SubString(breakchar1 + 1, 2) == "te") {
                                                memo[StrToInt(str.SubString(5, breakchar1 - 5))]->Lines->Text = RewindString(str.SubString(breakchar2 + 1, str.Length()));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "si") {
                                                memo[StrToInt(str.SubString(5, breakchar1 - 5))]->Width = getX(str.SubString(breakchar2 + 1, str.Length() - breakchar2 - 1));
                                                memo[StrToInt(str.SubString(5, breakchar1 - 5))]->Height = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "po") {
                                                memo[StrToInt(str.SubString(5, breakchar1 - 5))]->Left = getX(str.SubString(breakchar2 + 1, str.Length() - breakchar2 - 1));
                                                memo[StrToInt(str.SubString(5, breakchar1 - 5))]->Top = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }
                                }  if (str.SubString(0, 2) == "co") {
                                        if (str.SubString(breakchar1 + 1, 2) == "te") {
                                                comboedits[StrToInt(str.SubString(9, breakchar1 - 9))]->Items->Text = RewindString(str.SubString(breakchar2 + 1, str.Length()));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "si") {
                                                comboedits[StrToInt(str.SubString(9, breakchar1 - 9))]->Width = getX(str.SubString(breakchar2 + 1, str.Length() - breakchar2 - 1));
                                                comboedits[StrToInt(str.SubString(9, breakchar1 - 9))]->Height = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "po") {
                                                comboedits[StrToInt(str.SubString(9, breakchar1 - 9))]->Left = getX(str.SubString(breakchar2 + 1, str.Length() - breakchar2 - 1));
                                                comboedits[StrToInt(str.SubString(9, breakchar1 - 9))]->Top = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }
                                }  if (str.SubString(0, 2) == "ch") {
                                        if (str.SubString(breakchar1 + 1, 2) == "te") {
                                                checkboxes[StrToInt(str.SubString(9, breakchar1 - 9))]->Caption = RewindString(str.SubString(breakchar2 + 1, str.Length()));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "si") {
                                                checkboxes[StrToInt(str.SubString(9, breakchar1 - 9))]->Width = getX(str.SubString(breakchar2 + 1, str.Length() - breakchar2 - 1));
                                                checkboxes[StrToInt(str.SubString(9, breakchar1 - 9))]->Height = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "po") {
                                                checkboxes[StrToInt(str.SubString(9, breakchar1 - 9))]->Left = getX(str.SubString(breakchar2 + 1, str.Length() - breakchar2 - 1));
                                                checkboxes[StrToInt(str.SubString(9, breakchar1 - 9))]->Top = getY(str.SubString(breakchar2 + 1, str.Length() - breakchar2));
                                        }  if (str.SubString(breakchar1 + 1, 2) == "se") {
                                                if (str.SubString(breakchar2, str.Length()) == "false") {
                                                        checkboxes[StrToInt(str.SubString(9, breakchar1 - 9))]->Checked = false;
                                                }  {
                                                        checkboxes[StrToInt(str.SubString(9, breakchar1 - 9))]->Checked = true;
                                                }

                                        }
                                }


                        }

                }

        }


	Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::addLabel()
{
        TLabel* lbl = new TLabel(Form3);
		bool b = false;
		for (int i = 0; i < 32; i++) {
			if (labels[i]->Caption == "#INTERNAL#RAWCOMPONENT#$?#" && b == false) {
				labels[i] = lbl;
				labels[i]->Enabled = false;
				labels[i]->Visible = true;
				labels[i]->Left = StaticComponentX;
				labels[i]->Top = StaticComponentY;
				labels[i]->Height = 40;
				labels[i]->Width = 100;
				labels[i]->Caption = "글씨" + IntToStr(i);
                                labels[i]->Font->Name = "맑은 고딕";
                                labels[i]->Font->Size = 15;
				labels[i]->Parent = Form3;
				StaticComponentY += 40;
				StaticComponentX += 100;
				++ComponentAmount;
				b = true;
				//ComboBox2->Items->Add("글씨" + IntToStr(i));
                                ComboBox3->Items->Add("글씨" + IntToStr(i));
                                ComboBox8->Items->Add("글씨" + IntToStr(i));
                                ComboBox6->Items->Add("글씨" + IntToStr(i));
			}
		}
}

void __fastcall TForm2::addButton()
{
        TButton* btn = new TButton(Form3);
                bool b = false;
                for (int i = 0; i < 32; i++) {
                if (buttons[i]->Caption == "#INTERNAL#RAWCOMPONENT#$?#" && b == false) {
                        buttons[i] = btn;
                        buttons[i]->Enabled = false;
                        buttons[i]->Visible = true;
                        buttons[i]->Left = StaticComponentX;
                        buttons[i]->Top = StaticComponentY;
                        buttons[i]->Height = 40;
                        buttons[i]->Width = 100;
                        buttons[i]->Caption = "단추" + IntToStr(i);
                        buttons[i]->Font->Name = "맑은 고딕";
                        buttons[i]->Font->Size = 15;
                        buttons[i]->Parent = Form3;
                        /*
                        if (ComponentAmount == 0) {
                                buttons[i]->Left = 100;
                                buttons[i]->Top = 150;
                                buttons[i]->Left = StaticComponentX;
                                buttons[i]->Top = StaticComponentY;
                        }
                        */
                        StaticComponentY += 40;
                        StaticComponentX += 100;
                        ++ComponentAmount;
                        b = true;
                        //ComboBox2->Items->Add("단추" + IntToStr(i));
                        ComboBox3->Items->Add("단추" + IntToStr(i));
                        ComboBox8->Items->Add("단추" + IntToStr(i));
                        ComboBox6->Items->Add("단추" + IntToStr(i));
                        }
                }
}

void __fastcall TForm2::addEdit()
{
        TEdit* tbx = new TEdit(Form3);
                bool b = false;
                for (int i = 0; i < 32; i++) {
                if (textboxes[i]->Text == "#INTERNAL#RAWCOMPONENT#$?#" && b == false) {
                        textboxes[i] = tbx;
                        textboxes[i]->Enabled = false;
                        textboxes[i]->Visible = true;
                        textboxes[i]->Left = StaticComponentX;
                        textboxes[i]->Top = StaticComponentY;
                        textboxes[i]->Height = 20;
                        textboxes[i]->Width = 100;
                        textboxes[i]->Text = "입력 상자" + IntToStr(i);    \
                        textboxes[i]->Font->Name = "맑은 고딕";
                        textboxes[i]->Font->Size = 15;
                        textboxes[i]->Parent = Form3;
                        StaticComponentY += 40;
                        StaticComponentX += 100;
                        ++ComponentAmount;
                        b = true;
                        //ComboBox2->Items->Add("입력 상자" + IntToStr(i));
                        ComboBox3->Items->Add("입력 상자" + IntToStr(i));
                        ComboBox8->Items->Add("입력 상자" + IntToStr(i));
                        ComboBox6->Items->Add("입력 상자" + IntToStr(i));
                        }
                }
}

void __fastcall TForm2::addCombobox()
{
        TComboBox* cmbe = new TComboBox(Form3);
                bool b = false;
                for (int i = 0; i < 32; i++) {
                if (comboedits[i]->Text == "#INTERNAL#RAWCOMPONENT#$?#" && b == false) {
                        comboedits[i] = cmbe;
                        comboedits[i]->Enabled = false;
                        comboedits[i]->Visible = true;
                        comboedits[i]->Left = StaticComponentX;
                        comboedits[i]->Top = StaticComponentY;
                        comboedits[i]->Height = 20;
                        comboedits[i]->Width = 100;
                        comboedits[i]->Text = "선택" + IntToStr(i);
                        comboedits[i]->Font->Name = "맑은 고딕";
                        comboedits[i]->Font->Size = 15;
                        comboedits[i]->Parent = Form3;
                        StaticComponentY += 20;
                        StaticComponentX += 100;
                        ++ComponentAmount;
                        b = true;
                        //ComboBox2->Items->Add("선택" + IntToStr(i));
                        ComboBox3->Items->Add("선택" + IntToStr(i));
                        ComboBox8->Items->Add("선택" + IntToStr(i));
                        ComboBox6->Items->Add("선택" + IntToStr(i));
                }
                }
}

void __fastcall TForm2::addCheckbox()
{
        TCheckBox* cbx = new TCheckBox(Form3);
		bool b = false;
		for (int i = 0; i < 32; i++) {
			if (checkboxes[i]->Caption == "#INTERNAL#RAWCOMPONENT#$?#" && b == false) {
				checkboxes[i] = cbx;
				checkboxes[i]->Enabled = false;
				checkboxes[i]->Visible = true;
				checkboxes[i]->Left = StaticComponentX;
				checkboxes[i]->Top = StaticComponentY;
				checkboxes[i]->Height = 40;
				checkboxes[i]->Width = 100;
				checkboxes[i]->Caption = "예/아니오" + IntToStr(i);
                                checkboxes[i]->Font->Name = "맑은 고딕";
                                checkboxes[i]->Font->Size = 15;
				checkboxes[i]->Parent = Form3;
				StaticComponentY += 40;
				StaticComponentX += 100;
				++ComponentAmount;
				b = true;
				//ComboBox2->Items->Add("예/아니오" + IntToStr(i));
                                ComboBox3->Items->Add("예/아니오" + IntToStr(i));
                                ComboBox8->Items->Add("예/아니오" + IntToStr(i));
                                ComboBox6->Items->Add("예/아니오" + IntToStr(i));
			}
		}
}

void __fastcall TForm2::addMemo()
{
        TMemo* tmm = new TMemo(Form3);
		bool b = false;
		for (int i = 0; i < 32; i++) {
			if (memo[i]->Text == "#INTERNAL#RAWCOMPONENT#$?#" && b == false) {
				memo[i] = tmm;
				memo[i]->Enabled = false;
				memo[i]->Visible = true;
				memo[i]->Left = StaticComponentX;
				memo[i]->Top = StaticComponentY;;
				memo[i]->Height = 100;
				memo[i]->Width = 100;
				memo[i]->Text = "큰 입력 상자" + IntToStr(i);
                                memo[i]->Font->Name = "맑은 고딕";
                                memo[i]->Font->Size = 15;
				memo[i]->Parent = Form3;
				StaticComponentY += 100;
				StaticComponentX += 100;
				++ComponentAmount;
				b = true;
				//ComboBox2->Items->Add("큰 입력 상자" + IntToStr(i));
                                ComboBox3->Items->Add("큰 입력 상자" + IntToStr(i));
                                ComboBox8->Items->Add("큰 입력 상자" + IntToStr(i));
                                ComboBox6->Items->Add("큰 입력 상자" + IntToStr(i));
			}
		}
}


//---------------------------------------------------------------------------

void __fastcall TForm2::Panel3Click(TObject *Sender)
{
        addLabel();
}

void __fastcall TForm2::Button4Click(TObject *Sender)
{
        addButton();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Edit2Click(TObject *Sender)
{
        addEdit();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Memo1Click(TObject *Sender)
{
        addMemo();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image8Click(TObject *Sender)
{
        addCombobox();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::CheckBox1Click(TObject *Sender)
{
        addCheckbox();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::UpdateEdit1()
{

	Edit1->Enabled = true;

      //	AnsiString property = ComboBox1->Text;
      //	AnsiString component = ComboBox3->Text;

        int num = getComponentNumber(Panel4->Caption);
        AnsiString str = getComponentName(Panel4->Caption);

	if (ComboBox1->Text == "글씨") {

		if (str == "label") {
			Edit1->Text = labels[num]->Caption;
		} else if (str == "button") {
			Edit1->Text = buttons[num]->Caption;
		} else if (str == "edit") {
			Edit1->Text = textboxes[num]->Text;
		} else if (str == "memo") {
			Memo2->Text = memo[num]->Text;
		} else if (str == "checkbox") {
			Edit1->Text = checkboxes[num]->Caption;
		}

	} else if (ComboBox1->Text == "가로 위치") {

		if (str == "label") {
			Edit1->Text = IntToStr((int)(labels[num]->Left));
		} else if (str == "button") {
			Edit1->Text = IntToStr((int)(buttons[num]->Left));
		} else if (str == "edit") {
			Edit1->Text = IntToStr((int)(textboxes[num]->Left));
		} else if (str == "memo") {
			Edit1->Text = IntToStr((int)(memo[num]->Left));
		} else if (str == "checkbox") {
			Edit1->Text = IntToStr((int)(checkboxes[num]->Left));
		} else if (str == "combobox") {
			Edit1->Text = IntToStr((int)(comboedits[num]->Left));
		}

	} else if (ComboBox1->Text == "세로 위치") {

		if (str == "label") {
			Edit1->Text = IntToStr((int)(labels[num]->Top));
		} else if (str == "button") {
			Edit1->Text = IntToStr((int)(buttons[num]->Top));
		} else if (str == "edit") {
			Edit1->Text = IntToStr((int)(textboxes[num]->Top));
		} else if (str == "memo") {
			Edit1->Text = IntToStr((int)(memo[num]->Top));
		} else if (str == "checkbox") {
			Edit1->Text = IntToStr((int)(checkboxes[num]->Top));
		} else if (str == "combobox") {
			Edit1->Text = IntToStr((int)(comboedits[num]->Top));
		}

	} else if (ComboBox1->Text == "가로 길이") {

		if (str == "label") {
			Edit1->Text = IntToStr((int)(labels[num]->Width));
		} else if (str == "button") {
			Edit1->Text = IntToStr((int)(buttons[num]->Width));
		} else if (str == "edit") {
			Edit1->Text = IntToStr((int)(textboxes[num]->Width));
		} else if (str == "memo") {
			Edit1->Text = IntToStr((int)(memo[num]->Width));
		} else if (str == "checkbox") {
			Edit1->Text = IntToStr((int)(checkboxes[num]->Width));
		} else if (str == "combobox") {
			Edit1->Text = IntToStr((int)(comboedits[num]->Width));
		}

	} else if (ComboBox1->Text == "세로 길이") {

		if (str == "label") {
			Edit1->Text = IntToStr((int)(labels[num]->Height));
		} else if (str == "button") {
			Edit1->Text = IntToStr((int)(buttons[num]->Height));
		} else if (str == "edit") {
			Edit1->Text = IntToStr((int)(textboxes[num]->Height));
		} else if (str == "memo") {
			Edit1->Text = IntToStr((int)(memo[num]->Height));
		} else if (str == "checkbox") {
			Edit1->Text = IntToStr((int)(checkboxes[num]->Height));
		} else if (str == "combobox") {
			Edit1->Text = IntToStr((int)(comboedits[num]->Height));
		}

        } else if (ComboBox1->Text == "항목") {

                if (str == "combobox") {
			Memo2->Text = comboedits[num]->Items->Text;
		}


        } else if (ComboBox1->Text == "선택 여부") {

                if (str == "checkbox") {
			if (checkboxes[num]->Checked) {
                                Edit1->Text = "O";
                        } else {
                                Edit1->Text = "X";
                        }
		}

        }


}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
        if (Edit5->Text == "#INTERNAL#RAWCOMPONENT#$?#") {
                ShowMessage("이 값은 사용할 수 없습니다.");
        } else {

        if (Panel4->Caption != "선택된 도구 없음") {

        if (ComboBox1->Text == "글씨" || ComboBox1->Text == "항목") {

		if (getComponentName(Panel4->Caption) == "memo") {
			memo[getComponentNumber(Panel4->Caption)]->Text = Memo2->Text;
		}

                if (getComponentName(Panel4->Caption) == "combobox") {
                        for (int i = 0; i < Memo2->Lines->Count; i++) {
                                comboedits[getComponentNumber(Panel4->Caption)]->Items->Add(Memo2->Lines->Strings[i]);
                        }
		}

	}
        }
        else {
                ShowMessage("도구를 선택해 주세요.");
        }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image5Click(TObject *Sender)
{
        Form3->Show();
}
//---------------------------------------------------------------------------



void __fastcall TForm2::ComboBox1Change(TObject *Sender)
{
        UpdateEdit1();        
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


void __fastcall TForm2::Edit3KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0xd) {

	}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ComboBox2Change(TObject *Sender)
{
      /*  for (int i = 0; i < 64; i++) {
			labels[i]->RotationAngle = 0;
			buttons[i]->RotationAngle = 0;
			textboxes[i]->RotationAngle = 0;
			checkboxes[i]->RotationAngle = 0;
			comboedits[i]->RotationAngle = 0;
			memo[i]->RotationAngle = 0;
	}    */



}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image7Click(TObject *Sender)
{

//ProgressBar1->Position = 0;
//Timer1->Enabled = true;

SaveMemo->Clear();


for (int i = 0; i < 32; i++) {

	if (buttons[i]->Caption != "#INTERNAL#RAWCOMPONENT#$?#") {
		SaveMemo->Lines->Add("new button" + IntToStr(i) + " _");
	}
        if (labels[i]->Caption != "#INTERNAL#RAWCOMPONENT#$?#") {
		SaveMemo->Lines->Add("new label" + IntToStr(i) + " _");
	}
        if (textboxes[i]->Text != "#INTERNAL#RAWCOMPONENT#$?#") {
		SaveMemo->Lines->Add("new edit" + IntToStr(i) + " _");
	}
        if (checkboxes[i]->Caption != "#INTERNAL#RAWCOMPONENT#$?#") {
		SaveMemo->Lines->Add("new checkbox" + IntToStr(i) + " _");
	}
        if (comboedits[i]->Text != "#INTERNAL#RAWCOMPONENT#$?#") {
		SaveMemo->Lines->Add("new combobox" + IntToStr(i) + " _");
	}
        if (memo[i]->Text != "#INTERNAL#RAWCOMPONENT#$?#") {
		SaveMemo->Lines->Add("new memo" + IntToStr(i) + " _");
	}
	
	//buttons labels textboxes checkboxes comboedits
	
}

SaveMemo->Lines->Add("form text \"" + Form3->Caption + "\"");
SaveMemo->Lines->Add("form size " + IntToStr(Form3->Width) + ";" + IntToStr(Height));
SaveMemo->Lines->Add("form position " + IntToStr(Form3->Left) + ";" + IntToStr(Top));



for (int i = 0; i < 32; i++) {

	if (buttons[i]->Caption != "#INTERNAL#RAWCOMPONENT#$?#") {
		SaveMemo->Lines->Add("button" + IntToStr(i) + " text \"" + ConvertString(buttons[i]->Caption) + "\"");
		SaveMemo->Lines->Add("button" + IntToStr(i) + " size " + IntToStr(buttons[i]->Width) + ";" + IntToStr(buttons[i]->Height));
		SaveMemo->Lines->Add("button" + IntToStr(i) + " position " + IntToStr(buttons[i]->Left) + ";" + IntToStr(buttons[i]->Top));
	}
        if (labels[i]->Caption != "#INTERNAL#RAWCOMPONENT#$?#") {
		SaveMemo->Lines->Add("label" + IntToStr(i) + " text \"" + ConvertString(labels[i]->Caption) + "\"");
		SaveMemo->Lines->Add("label" + IntToStr(i) + " size " + IntToStr(labels[i]->Width + 100) + ";" + IntToStr(labels[i]->Height));
		SaveMemo->Lines->Add("label" + IntToStr(i) + " position " + IntToStr(labels[i]->Left) + ";" + IntToStr(labels[i]->Top));
	}
        if (textboxes[i]->Text != "#INTERNAL#RAWCOMPONENT#$?#") {
		SaveMemo->Lines->Add("edit" + IntToStr(i) + " text \"" + ConvertString(textboxes[i]->Text) + "\"");
		SaveMemo->Lines->Add("edit" + IntToStr(i) + " size " + IntToStr(textboxes[i]->Width) + ";" + IntToStr(textboxes[i]->Height));
		SaveMemo->Lines->Add("edit" + IntToStr(i) + " position " + IntToStr(textboxes[i]->Left) + ";" + IntToStr(textboxes[i]->Top));
	}
        if (checkboxes[i]->Caption != "#INTERNAL#RAWCOMPONENT#$?#") {
		SaveMemo->Lines->Add("checkbox" + IntToStr(i) + " text \"" + ConvertString(checkboxes[i]->Caption) + "\"");
		SaveMemo->Lines->Add("checkbox" + IntToStr(i) + " size " + IntToStr(checkboxes[i]->Width) + ";" + IntToStr(checkboxes[i]->Height));
		SaveMemo->Lines->Add("checkbox" + IntToStr(i) + " position " + IntToStr(checkboxes[i]->Left) + ";" + IntToStr(checkboxes[i]->Top));
	}
        if (comboedits[i]->Text != "#INTERNAL#RAWCOMPONENT#$?#") {
		AnsiString insertString = "";

                if (comboedits[i]->Items->Text != "") {
                        for (int j = 0; j < comboedits[i]->Items->Count; j++) {
			        insertString += "\"" + comboedits[i]->Items->Strings[j] + "\";";
		        }
		        insertString = insertString.SubString(0, insertString.Length() - 1);
                } else {
                        insertString = "\"\"";
                }
		SaveMemo->Lines->Add("combobox" + IntToStr(i) + " items " + ConvertString(insertString));
		SaveMemo->Lines->Add("combobox" + IntToStr(i) + " size " + IntToStr(comboedits[i]->Width) + ";" + IntToStr(comboedits[i]->Height));
		SaveMemo->Lines->Add("combobox" + IntToStr(i) + " position " + IntToStr(comboedits[i]->Left) + ";" + IntToStr(comboedits[i]->Top));
	}
        if (memo[i]->Text != "#INTERNAL#RAWCOMPONENT#$?#") {
		AnsiString insertString = "";
                if (memo[i]->Lines->Text != "") {
		        for (int j = 0; j < memo[i]->Lines->Count; j++) {
			        insertString += "\"" + memo[i]->Lines->Strings[j] + "\";";

		        }
                        //insertString = insertString.SubString(0, insertString.Length() - 1);
                } else {                                     
                        insertString = "\"\"";
                }

		SaveMemo->Lines->Add("memo" + IntToStr(i) + " lines " + ConvertString(insertString));
		SaveMemo->Lines->Add("memo" + IntToStr(i) + " size " + IntToStr(memo[i]->Width) + ";" + IntToStr(memo[i]->Height));
		SaveMemo->Lines->Add("memo" + IntToStr(i) + " position " + IntToStr(memo[i]->Left) + ";" + IntToStr(memo[i]->Top));
	}

	//buttons labels textboxes checkboxes comboedits


}

for (int i = 0; i < EventMemo->Lines->Count; i++) {

	//btn lbl mem chk cmb edt

        AnsiString str = EventMemo->Lines->Strings[i];

	SaveMemo->Lines->Add("event " + str.SubString(0, str.Pos("@") - 1) + " " + str.SubString(str.Pos("@") + 1, str.Length()));

}

SaveMemo->Lines->SaveToFile(Form1->ProjectLocation);


system("java -jar C:\\Code4Every1\\CompileLang.jar \"C:\\Code4Every1\\Translate.cfeo\"");

Timer1->Enabled = false;
ProgressBar1->Position = 0;

}
//---------------------------------------------------------------------------
AnsiString __fastcall TForm2::getComponentName(AnsiString str)
{

        AnsiString returnString = "";

        if (str.SubString(1, 4) == "글씨") {
                returnString = "label";
	}
	else if (str.SubString(1, 4) == "단추") {
                returnString = "button";
	}
	else if (str.SubString(1, 9) == "입력 상자") {
                returnString = "edit";
	}
	else if (str.SubString(1, 12) == "큰 입력 상자") {
                returnString = "memo";
	}
	else if (str.SubString(1, 9) == "예/아니오") {
                returnString = "checkbox";
	}
        else if (str.SubString(1, 4) == "선택") {
                returnString = "combobox";
	}

        return returnString;
}



AnsiString __fastcall TForm2::ConvertString(AnsiString str)
{
        AnsiString returnString = "";

        returnString = StringReplace(str, " ", "_", Sysutils::TReplaceFlags() << Sysutils::rfReplaceAll);
        returnString = StringReplace(str, "\n", ";", Sysutils::TReplaceFlags() << Sysutils::rfReplaceAll);
        
        return returnString;
}

AnsiString __fastcall TForm2::RewindString(AnsiString str)
{
        AnsiString returnString = "";

        returnString = StringReplace(str, "\"", "", Sysutils::TReplaceFlags() << Sysutils::rfReplaceAll);
        returnString = StringReplace(returnString, " ", "_", Sysutils::TReplaceFlags() << Sysutils::rfReplaceAll);
        returnString = StringReplace(returnString, ";", "\n", Sysutils::TReplaceFlags() << Sysutils::rfReplaceAll);

        return returnString;
}

int __fastcall TForm2::getX(AnsiString str)
{
        int returnint = 0;

        returnint = StrToInt(str.SubString(0, str.Pos(";") - 1));

        return returnint;
}

int __fastcall TForm2::getY(AnsiString str)
{
        int returnint = 0;

        returnint = StrToInt(str.SubString(str.Pos(";") + 1, 4));

        return returnint;
}



void __fastcall TForm2::ComboBox3Change(TObject *Sender)
{
        ComboBox5->Items->Text = "";

        if (ComboBox3->Text.SubString(1, 4) == "글씨") {
		ComboBox5->Items->Add("글씨");
		ComboBox5->Items->Add("가로 위치");
		ComboBox5->Items->Add("세로 위치");
		ComboBox5->Items->Add("가로 길이");
		ComboBox5->Items->Add("세로 길이");
	}
	else if (ComboBox3->Text.SubString(1, 4) == "단추") {
		ComboBox5->Items->Add("글씨");
		ComboBox5->Items->Add("가로 위치");
		ComboBox5->Items->Add("세로 위치");
		ComboBox5->Items->Add("가로 길이");
		ComboBox5->Items->Add("세로 길이");
	}
	else if (ComboBox3->Text.SubString(1, 9) == "입력 상자") {
		ComboBox5->Items->Add("글씨");
		ComboBox5->Items->Add("가로 위치");
		ComboBox5->Items->Add("세로 위치");
		ComboBox5->Items->Add("가로 길이");
		ComboBox5->Items->Add("세로 길이");
	}
	else if (ComboBox3->Text.SubString(1, 12) == "큰 입력 상자") {
		ComboBox5->Items->Add("가로 위치");
		ComboBox5->Items->Add("세로 위치");
		ComboBox5->Items->Add("가로 길이");
		ComboBox5->Items->Add("세로 길이");
	}
	else if (ComboBox3->Text.SubString(1, 9) == "예/아니오") {
		ComboBox5->Items->Add("글씨");
                ComboBox5->Items->Add("선택 여부");
		ComboBox5->Items->Add("가로 위치");
		ComboBox5->Items->Add("세로 위치");
		ComboBox5->Items->Add("가로 길이");
		ComboBox5->Items->Add("세로 길이");
	} else if (ComboBox3->Text.SubString(1, 4) == "선택") {
		ComboBox5->Items->Add("가로 위치");
		ComboBox5->Items->Add("세로 위치");
		ComboBox5->Items->Add("가로 길이");
		ComboBox5->Items->Add("세로 길이");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ComboBox8Change(TObject *Sender)
{
        ComboBox9->Items->Text = "";

        if (ComboBox8->Text.SubString(1, 4) == "글씨") {
		ComboBox9->Items->Add("글씨");
	}
	else if (ComboBox8->Text.SubString(1, 4) == "단추") {
		ComboBox9->Items->Add("글씨");
	}
	else if (ComboBox8->Text.SubString(1, 9) == "입력 상자") {
		ComboBox9->Items->Add("글씨");
	}
	else if (ComboBox8->Text.SubString(1, 12) == "큰 입력 상자") {
                ComboBox9->Items->Add("글씨");
	}
	else if (ComboBox8->Text.SubString(1, 9) == "예/아니오") {
		ComboBox9->Items->Add("글씨");
                ComboBox9->Items->Add("선택 여부");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ComboBox6Change(TObject *Sender)
{
        ComboBox7->Items->Text = "";

        if (ComboBox6->Text.SubString(1, 4) == "글씨") {
		ComboBox7->Items->Add("글씨");
	}
	else if (ComboBox6->Text.SubString(1, 4) == "단추") {
		ComboBox7->Items->Add("글씨");
	}
	else if (ComboBox6->Text.SubString(1, 9) == "입력 상자") {
		ComboBox7->Items->Add("글씨");
	}
	else if (ComboBox6->Text.SubString(1, 12) == "큰 입력 상자") {
		ComboBox7->Items->Add("글씨");
	}
	else if (ComboBox6->Text.SubString(1, 9) == "예/아니오") {
		ComboBox7->Items->Add("글씨");
                ComboBox7->Items->Add("선택 여부");
	}
        else if (ComboBox6->Text.SubString(1, 4) == "선택") {
		ComboBox7->Items->Add("선택 항목");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button10Click(TObject *Sender)
{
        if (Edit5->Text == "#INTERNAL#RAWCOMPONENT#$?#") {
                ShowMessage("이 값은 사용할 수 없습니다.");
        } else {

        if (ComboBox3->Text != "") {

                AnsiString comp = getComponentName(ComboBox3->Text);
                int compnum = getComponentNumber(ComboBox3->Text);
                AnsiString prop = getPropertyName(ComboBox5->Text);
                AnsiString input = ConvertString(Edit5->Text);
                AnsiString retreat = getComponentName(Panel4->Caption) + getComponentNumber(Panel4->Caption) + "@" + comp + compnum;

                if (comp == "label") {

                        if (prop == "text") {
                                EventMemo->Lines->Add(retreat + "#text#\"" + input + "\"#_");
                        }
                        if (prop == "width") {
                                EventMemo->Lines->Add(retreat + "#size#" + input + ";" + IntToStr(labels[compnum]->Height) + "#_");
                        }
                        if (prop == "height") {
                                EventMemo->Lines->Add(retreat + "#size#" + IntToStr(labels[compnum]->Width) + ";" + input + "#_");
                        }
                        if (prop == "x") {
                                EventMemo->Lines->Add(retreat + "#position#" + input + ";" + IntToStr(labels[compnum]->Top) + "#_");
                        }
                        if (prop == "y") {
                                EventMemo->Lines->Add(retreat + "#position#" + IntToStr(labels[compnum]->Left) + ";" + input + "#_");
                        }

                }
                if (comp == "button") {

                        if (prop == "text") {
                                EventMemo->Lines->Add(retreat + "#text#\"" + input + "\"#_");
                        }
                        if (prop == "width") {
                                EventMemo->Lines->Add(retreat + "#size#" + input + ";" + IntToStr(buttons[compnum]->Height) + "#_");
                        }
                        if (prop == "height") {
                                EventMemo->Lines->Add(retreat + "#size#" + IntToStr(buttons[compnum]->Width) + ";" + input + "#_");
                        }
                        if (prop == "x") {
                                EventMemo->Lines->Add(retreat + "#position#" + input + ";" + IntToStr(buttons[compnum]->Top) + "#_");
                        }
                        if (prop == "y") {
                                EventMemo->Lines->Add(retreat + "#position#" + IntToStr(buttons[compnum]->Left) + ";" + input + "#_");
                        }

                }
                if (comp == "edit") {

                        if (prop == "text") {
                                EventMemo->Lines->Add(retreat + "#text#\"" + input + "\"#_");
                        }
                        if (prop == "width") {
                                EventMemo->Lines->Add(retreat + "#size#" + input + ";" + IntToStr(textboxes[compnum]->Height) + "#_");
                        }
                        if (prop == "height") {
                                EventMemo->Lines->Add(retreat + "#size#" + IntToStr(textboxes[compnum]->Width) + ";" + input + "#_");
                        }
                        if (prop == "x") {
                                EventMemo->Lines->Add(retreat + "#position#" + input + ";" + IntToStr(textboxes[compnum]->Top) + "#_");
                        }
                        if (prop == "y") {
                                EventMemo->Lines->Add(retreat + "#position#" + IntToStr(textboxes[compnum]->Left) + ";" + input + "#_");
                        }

                }
                if (comp == "memo") {

                        if (prop == "width") {
                                EventMemo->Lines->Add(retreat + "#size#" + input + ";" + IntToStr(memo[compnum]->Height) + "#_");
                        }
                        if (prop == "height") {
                                EventMemo->Lines->Add(retreat + "#size#" + IntToStr(memo[compnum]->Width) + ";" + input + "#_");
                        }
                        if (prop == "x") {
                                EventMemo->Lines->Add(retreat + "#position#" + input + ";" + IntToStr(memo[compnum]->Top) + "#_");
                        }
                        if (prop == "y") {
                                EventMemo->Lines->Add(retreat + "#position#" + IntToStr(memo[compnum]->Left) + ";" + input + "#_");
                        }

                }
                if (comp == "checkbox") {

                        AnsiString boolt = "false";

                        if (input.UpperCase() == "O") {
                                boolt = "true";
                        }

                        if (prop == "text") {
                                EventMemo->Lines->Add(retreat + "#text#\"" + input + "\"#_");
                        }
                        if (prop == "width") {
                                EventMemo->Lines->Add(retreat + "#size#" + input + ";" + IntToStr(checkboxes[compnum]->Height) + "#_");
                        }
                        if (prop == "height") {
                                EventMemo->Lines->Add(retreat + "#size#" + IntToStr(checkboxes[compnum]->Width) + ";" + input + "#_");
                        }
                        if (prop == "x") {
                                EventMemo->Lines->Add(retreat + "#position#" + input + ";" + IntToStr(checkboxes[compnum]->Top) + "#_");
                        }
                        if (prop == "y") {
                                EventMemo->Lines->Add(retreat + "#position#" + IntToStr(checkboxes[compnum]->Left) + ";" + input + "#_");
                        }
                        if (prop == "checked") {
                                EventMemo->Lines->Add(retreat + "#checked#" + boolt + "#_");
                        }

                }
                if (comp == "combobox") {


                        if (prop == "width") {
                                EventMemo->Lines->Add(retreat + "#size#" + input + ";" + IntToStr(comboedits[compnum]->Height) + "#_");
                        }
                        if (prop == "height") {
                                EventMemo->Lines->Add(retreat + "#size#" + IntToStr(comboedits[compnum]->Width) + ";" + input + "#_");
                        }
                        if (prop == "x") {
                                EventMemo->Lines->Add(retreat + "#position#" + input + ";" + IntToStr(comboedits[compnum]->Top) + "#_");
                        }
                        if (prop == "y") {
                                EventMemo->Lines->Add(retreat + "#position#" + IntToStr(comboedits[compnum]->Left) + ";" + input + "#_");
                        }
                        

                }

        }
        }

}
//---------------------------------------------------------------------------

AnsiString __fastcall TForm2::getPropertyName(AnsiString str) {

        AnsiString returnString = "";

        if (str == "글씨") {
                returnString = "text";
        }
        if (str == "가로 길이") {
                returnString = "width";
        }
        if (str == "세로 길이") {
                returnString = "height";
        }
        if (str == "가로 위치") {
                returnString = "x";
        }
        if (str == "세로 위치") {
                returnString = "y";
        }
        if (str == "선택 여부") {
                returnString = "checked";
        }
        if (str == "선택 항목") {
                returnString = "selected";
        }

        return returnString;

}

int __fastcall TForm2::getComponentNumber(AnsiString str) {

        int returnint = 0;

        if (str.SubString(1, 4) == "글씨") {
                returnint = StrToInt(str.SubString(5, 2));
	}
	else if (str.SubString(1, 4) == "단추") {
                returnint = StrToInt(str.SubString(5, 2));
	}
	else if (str.SubString(1, 9) == "입력 상자") {
                returnint = StrToInt(str.SubString(10, 2));
	}
	else if (str.SubString(1, 12) == "큰 입력 상자") {
                returnint = StrToInt(str.SubString(13, 2));
	}
	else if (str.SubString(1, 9) == "예/아니오") {
                returnint = StrToInt(str.SubString(10, 2));
	}
        else if (str.SubString(1, 4) == "선택") {
                returnint = StrToInt(str.SubString(5, 2));
	}

        return returnint;


}

void __fastcall TForm2::UpdateProperty() {

        ComboBox1->Items->Text = "";
	ComboBox1->Enabled = true;


        if (getComponentName(Panel4->Caption) == "label") {
                ComboBox1->Items->Add("글씨");
		ComboBox1->Items->Add("가로 위치");
		ComboBox1->Items->Add("세로 위치");
		ComboBox1->Items->Add("가로 길이");
		ComboBox1->Items->Add("세로 길이");
        }

        if (getComponentName(Panel4->Caption) == "button") {
                ComboBox1->Items->Add("글씨");
		ComboBox1->Items->Add("가로 위치");
		ComboBox1->Items->Add("세로 위치");
		ComboBox1->Items->Add("가로 길이");
		ComboBox1->Items->Add("세로 길이");
        }

        if (getComponentName(Panel4->Caption) == "edit") {
                ComboBox1->Items->Add("글씨");
		ComboBox1->Items->Add("가로 위치");
		ComboBox1->Items->Add("세로 위치");
		ComboBox1->Items->Add("가로 길이");
		ComboBox1->Items->Add("세로 길이");
        }

        if (getComponentName(Panel4->Caption) == "memo") {
                ComboBox1->Items->Add("글씨");
		ComboBox1->Items->Add("가로 위치");
		ComboBox1->Items->Add("세로 위치");
		ComboBox1->Items->Add("가로 길이");
		ComboBox1->Items->Add("세로 길이");
        }

        if (getComponentName(Panel4->Caption) == "combobox") {
                ComboBox1->Items->Add("항목");
		ComboBox1->Items->Add("가로 위치");
		ComboBox1->Items->Add("세로 위치");
		ComboBox1->Items->Add("가로 길이");
		ComboBox1->Items->Add("세로 길이");
        }

        if (getComponentName(Panel4->Caption) == "checkbox") {
                ComboBox1->Items->Add("글씨");
                ComboBox1->Items->Add("선택 여부");
		ComboBox1->Items->Add("가로 위치");
		ComboBox1->Items->Add("세로 위치");
		ComboBox1->Items->Add("가로 길이");
		ComboBox1->Items->Add("세로 길이");
        }

        if (Edit1->Text != "") {
		if (ComboBox1->Text != "") {
			UpdateEdit1();
		}
	}



}

void __fastcall TForm2::moveComponent(AnsiString dir) {

        AnsiString str = getComponentName(Panel4->Caption);
        int num = getComponentNumber(Panel4->Caption);
        int dx = 10;
        int dy = 10;

        if (dir == "^") {
                if (str == "label" && labels[num]->Top >= 100 + dy) {
                        labels[num]->Top -= dy;
                }
                if (str == "button" && buttons[num]->Top >= 100 + dy) {
                        buttons[num]->Top -= dy;
                }
                if (str == "memo" && memo[num]->Top >= 100 + dy) {
                        memo[num]->Top -= dy;
                }
                if (str == "edit" && textboxes[num]->Top >= 100 + dy) {
                        textboxes[num]->Top -= dy;
                }
                if (str == "checkbox" && checkboxes[num]->Top >= 100 + dy) {
                        checkboxes[num]->Top -= dy;
                }
                if (str == "combobox" && comboedits[num]->Top >= 100 + dy) {
                        comboedits[num]->Top -= dy;
                }
        }
        if (dir == "V") {
                if (str == "label") {
                        labels[num]->Top += dy;
                }
                if (str == "button") {
                        buttons[num]->Top += dy;
                }
                if (str == "memo") {
                        memo[num]->Top += dy;
                }
                if (str == "edit") {
                        textboxes[num]->Top += dy;
                }
                if (str == "checkbox") {
                        checkboxes[num]->Top += dy;
                }
                if (str == "combobox") {
                        comboedits[num]->Top += dy;
                }
        }
        if (dir == "<") {
                if (str == "label" && labels[num]->Left >= 100 + dx) {
                        labels[num]->Left -= dx;
                }
                if (str == "button" && buttons[num]->Left >= 100 + dx) {
                        buttons[num]->Left -= dx;
                }
                if (str == "memo" && memo[num]->Left >= 100 + dx) {
                        memo[num]->Left -= dx;
                }
                if (str == "edit" && textboxes[num]->Left >= 100 + dx) {
                        textboxes[num]->Left -= dx;
                }
                if (str == "checkbox" && checkboxes[num]->Left >= 100 + dx) {
                        checkboxes[num]->Left -= dx;
                }
                if (str == "combobox" && comboedits[num]->Top >= 100 + dx) {
                        comboedits[num]->Top -= dx;
                }
        }
        if (dir == ">") {
                if (str == "label") {
                        labels[num]->Left += dx;
                }
                if (str == "button") {
                        buttons[num]->Left += dx;
                }
                if (str == "memo") {
                        memo[num]->Left += dx;
                }
                if (str == "edit") {
                        textboxes[num]->Left += dx;
                }
                if (str == "checkbox") {
                        checkboxes[num]->Left += dx;
                }
                if (str == "combobox") {
                        comboedits[num]->Left += dx;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{

        if (Panel4->Caption != "선택된 도구 없음")
                moveComponent("^");
        else
                ShowMessage("도구를 선택해 주세요.");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button8Click(TObject *Sender)
{
        if (Panel4->Caption != "선택된 도구 없음")
                moveComponent("<");
        else
                ShowMessage("도구를 선택해 주세요.");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button9Click(TObject *Sender)
{
        if (Panel4->Caption != "선택된 도구 없음")
                moveComponent(">");
        else
                ShowMessage("도구를 선택해 주세요.");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
        if (Panel4->Caption != "선택된 도구 없음")
                moveComponent("V");
        else
                ShowMessage("도구를 선택해 주세요.");
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button12Click(TObject *Sender)
{
        if (Edit5->Text == "#INTERNAL#RAWCOMPONENT#$?#") {
                ShowMessage("이 값은 사용할 수 없습니다.");
        } else {

        AnsiString input = ConvertString(Edit4->Text);
        AnsiString retreat = getComponentName(Panel4->Caption) + getComponentNumber(Panel4->Caption) + "@";

        EventMemo->Lines->Add(retreat + "pop#\"" + input + "\"#_#_");
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button11Click(TObject *Sender)
{

        if (ComboBox8->Text != "") {

                AnsiString fromcomp = getComponentName(ComboBox8->Text);
                int fromcompnum = getComponentNumber(ComboBox8->Text);
                AnsiString fromprop = getPropertyName(ComboBox9->Text);

                AnsiString tocomp = getComponentName(ComboBox6->Text);
                int tocompnum = getComponentNumber(ComboBox6->Text);
                AnsiString toprop = getPropertyName(ComboBox7->Text);

                AnsiString retreat = getComponentName(Panel4->Caption) + getComponentNumber(Panel4->Caption) + "@" + fromcomp + fromcompnum + "#" + fromprop + "#" + tocomp + tocompnum + "#" + toprop;

                EventMemo->Lines->Add(retreat);



        }
}
//---------------------------------------------------------------------------






void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
        ProgressBar1->Position += 15;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
        Form1->Visible = true;
        Form3->Visible = false;
        Form1->Close();       
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image2Click(TObject *Sender)
{
        ShowMessage("개발자 : 강문석, 홍승빈, 정유민 \nCode4Every1 모두를 위한 코드 v1.0");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

