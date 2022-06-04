//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <sstream>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image5;
        TImage *Image7;
        TEdit *Edit1;
        TButton *Button1;
        TButton *Button3;
        TButton *Button4;
        TCheckBox *CheckBox1;
        TMemo *Memo1;
        TEdit *Edit2;
        TImage *Image8;
        TPanel *Panel3;
        TComboBox *ComboBox1;
        TComboBox *ComboBox3;
        TLabel *Label4;
        TLabel *Label6;
        TEdit *Edit4;
        TMemo *Memo2;
        TButton *Button5;
        TButton *Button7;
        TButton *Button8;
        TButton *Button9;
        TPanel *Panel4;
        TMemo *SaveMemo;
        TMemo *EventMemo;
        TComboBox *ComboBox5;
        TLabel *Label10;
        TComboBox *ComboBox6;
        TLabel *Label11;
        TComboBox *ComboBox7;
        TButton *Button10;
        TEdit *Edit5;
        TMemo *LoadMemo;
        TPanel *Panel5;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TComboBox *ComboBox8;
        TLabel *Label16;
        TComboBox *ComboBox9;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TPanel *Panel6;
        TButton *Button11;
        TButton *Button12;
        TPanel *Panel7;
        TProgressBar *ProgressBar1;
        TTimer *Timer1;
        TImage *Image2;
        TShape *Shape3;
        TShape *Shape2;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TShape *Shape4;
        TImage *Image3;
        TImage *Image4;
        TImage *Image6;
        TImage *Image9;
        TImage *Image10;
        TShape *Shape5;
        TImage *Image11;
        TShape *Shape6;
        TLabel *Label1;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TGroupBox *GroupBox5;
        TGroupBox *GroupBox6;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Edit2Click(TObject *Sender);
        void __fastcall Memo1Click(TObject *Sender);
        void __fastcall Image8Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Panel3Click(TObject *Sender);
        void __fastcall Edit3KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall Image7Click(TObject *Sender);
        void __fastcall ComboBox3Change(TObject *Sender);
        void __fastcall ComboBox8Change(TObject *Sender);
        void __fastcall ComboBox6Change(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Image2Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);

	int ComponentAmount;

	TButton* buttons[32];
	TLabel* labels[32];
	TEdit* textboxes[32];
	TCheckBox* checkboxes[32];
	TComboBox* comboedits[32];
	TMemo* memo[32];

        void __fastcall addButton();
        void __fastcall addEdit();
        void __fastcall addMemo();
        void __fastcall addCheckbox();
        void __fastcall addCombobox();
        void __fastcall addLabel();
        AnsiString __fastcall getComponentName(AnsiString str);
        AnsiString __fastcall getPropertyName(AnsiString str);
        int __fastcall getComponentNumber(AnsiString str);
        void __fastcall UpdateProperty();
        void __fastcall moveComponent(AnsiString dir);

	void __fastcall UpdateEdit1();
	void __fastcall MouseLeaveImages();
        AnsiString __fastcall ConvertString(AnsiString str);
        AnsiString __fastcall RewindString(AnsiString str);
        int __fastcall getX(AnsiString str);
        int __fastcall getY(AnsiString str);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
