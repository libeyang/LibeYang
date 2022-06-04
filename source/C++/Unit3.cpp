//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

bool mousedown = false;
AnsiString componentType = "";
int componentValue = 0;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



void __fastcall TForm3::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{

	int posX = X;
	int posY = Y;
                /*
        	for (int i = 0; i < 64; i++) {
			Form2->labels[i]->RotationAngle = 0;
			Form2->buttons[i]->RotationAngle = 0;
			Form2->textboxes[i]->RotationAngle = 0;
			Form2->checkboxes[i]->RotationAngle = 0;
			Form2->comboedits[i]->RotationAngle = 0;
			Form2->memo[i]->RotationAngle = 0;

	}
                  */

	for (int i = 0; i < 32; i++) {



		if (posX >= Form2->labels[i]->Left && posY >= Form2->labels[i]->Top) {
			if (posX <= Form2->labels[i]->Left + Form2->labels[i]->Width && posY <= Form2->labels[i]->Top + Form2->labels[i]->Height) {
                                Form2->Panel4->Caption = "글씨" + IntToStr(i);
				componentType = "label";
				componentValue = i;
                                Form2->UpdateProperty();

			}
		}
                if (posX >= Form2->textboxes[i]->Left && posY >= Form2->textboxes[i]->Top) {
			if (posX <= Form2->textboxes[i]->Left + Form2->textboxes[i]->Width && posY <= Form2->textboxes[i]->Top + Form2->textboxes[i]->Height) {
                                Form2->Panel4->Caption = "입력 상자" + IntToStr(i);
				componentType = "textbox";
				componentValue = i;
                                Form2->UpdateProperty();
			}
		}

                if (posX >= Form2->memo[i]->Left && posY >= Form2->memo[i]->Top) {
			if (posX <= Form2->memo[i]->Left + Form2->memo[i]->Width && posY <= Form2->memo[i]->Top + Form2->memo[i]->Height) {
                                Form2->Panel4->Caption = "큰 입력 상자" + IntToStr(i);
				componentType = "memo";
				componentValue = i;
                                Form2->UpdateProperty();
			}
		}
                if (posX >= Form2->checkboxes[i]->Left && posY >= Form2->checkboxes[i]->Top) {
			if (posX <= Form2->checkboxes[i]->Left + Form2->checkboxes[i]->Width && posY <= Form2->checkboxes[i]->Top + Form2->checkboxes[i]->Height) {
                                Form2->Panel4->Caption = "예/아니오" + IntToStr(i);
				componentType = "checkbox";
				componentValue = i;
                                Form2->UpdateProperty();

			}
		}
                if (posX >= Form2->comboedits[i]->Left && posY >= Form2->comboedits[i]->Top) {
			if (posX <= Form2->comboedits[i]->Left + Form2->comboedits[i]->Width && posY <= Form2->comboedits[i]->Top + Form2->comboedits[i]->Height) {
                                Form2->Panel4->Caption = "선택" + IntToStr(i);
				componentType = "comboedit";
				componentValue = i;
                                Form2->UpdateProperty();
			}
		}
                if (posX >= Form2->buttons[i]->Left && posY >= Form2->buttons[i]->Top) {
			if (posX <= Form2->buttons[i]->Left + Form2->buttons[i]->Width && posY <= Form2->buttons[i]->Top + Form2->buttons[i]->Height) {
                                Form2->Panel4->Caption = "단추" + IntToStr(i);
				componentType = "button";
				componentValue = i;
                                Form2->UpdateProperty();
			}
		}

	}


}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{


                /*
		if (posX >= Form2->labels[i]->Position->X && posY >= Form2->labels[i]->Position->Y) {
			if (posX <= Form2->labels[i]->Position->X + Form2->labels[i]->Width && posY <= Form2->labels[i]->Position->Y + Form2->labels[i]->Height) {
				Form2->labels[i]->Position->X = posX;
				Form2->labels[i]->Position->Y = posY;
			}
		}

		if (posX >= Form2->textboxes[i]->Position->X && posY >= Form2->textboxes[i]->Position->Y) {
			if (posX <= Form2->textboxes[i]->Position->X + Form2->textboxes[i]->Width && posY <= Form2->textboxes[i]->Position->Y + Form2->textboxes[i]->Height) {
				Form2->textboxes[i]->Position->X = posX;
				Form2->textboxes[i]->Position->Y = posY;
			}
		}

		if (posX >= Form2->buttons[i]->Position->X && posY >= Form2->buttons[i]->Position->Y) {
			if (posX <= Form2->buttons[i]->Position->X + Form2->buttons[i]->Width && posY <= Form2->buttons[i]->Position->Y + Form2->buttons[i]->Height) {
				Form2->buttons[i]->Position->X = posX;
				Form2->buttons[i]->Position->Y = posY;
			}
		}

		if (posX >= Form2->memo[i]->Position->X && posY >= Form2->memo[i]->Position->Y) {
			if (posX <= Form2->memo[i]->Position->X + Form2->memo[i]->Width && posY <= Form2->memo[i]->Position->Y + Form2->memo[i]->Height) {
				Form2->memo[i]->Position->X = posX;
				Form2->memo[i]->Position->Y = posY;
			}
		}

		if (posX >= Form2->checkboxes[i]->Position->X && posY >= Form2->checkboxes[i]->Position->Y) {
			if (posX <= Form2->checkboxes[i]->Position->X + Form2->checkboxes[i]->Width && posY <= Form2->checkboxes[i]->Position->Y + Form2->checkboxes[i]->Height) {
				Form2->checkboxes[i]->Position->X = posX;
				Form2->checkboxes[i]->Position->Y = posY;
			}
		}

                */

                     /*
			if (componentType == "button") {
				Form2->buttons[componentValue]->Left = posX;
				Form2->buttons[componentValue]->Top = posY;
			}
                        if (componentType == "label") {
				Form2->labels[componentValue]->Left = posX;
				Form2->labels[componentValue]->Top = posY;
			}
                        if (componentType == "textbox") {
				Form2->textboxes[componentValue]->Left = posX;
				Form2->textboxes[componentValue]->Top = posY;
			}
                        if (componentType == "memo") {
				Form2->memo[componentValue]->Left = posX;
				Form2->memo[componentValue]->Top = posY;
			}
                        if (componentType == "checkbox") {
				Form2->checkboxes[componentValue]->Left = posX;
				Form2->checkboxes[componentValue]->Top = posY;
			}
                        if (componentType == "comboedit") {
				Form2->comboedits[componentValue]->Left = posX;
				Form2->comboedits[componentValue]->Top = posY;
                        }
                     */
}

//---------------------------------------------------------------------------

void __fastcall TForm3::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
            /*
    for (int i = 0; i < 64; i++) {
			Form2->labels[i]->RotationAngle = 0;
			Form2->buttons[i]->RotationAngle = 0;
			Form2->textboxes[i]->RotationAngle = 0;
			Form2->checkboxes[i]->RotationAngle = 0;
			Form2->comboedits[i]->RotationAngle = 0;
			Form2->memo[i]->RotationAngle = 0;
	}
    */

    //componentValue = 0;
    //componentType = "";

}
//---------------------------------------------------------------------------





