//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
// Инициализация формы
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// Обработка нажатия кнопки / закртыие формы
void __fastcall TForm1::Click(TObject *Sender)
{
		Close();
}
//---------------------------------------------------------------------------
// Обработка нажатия кнопки расчета
void __fastcall TForm1::Click_count(TObject *Sender)
{
                     Memo1->Lines->Clear();
					 Memo1->Lines->Text = r;
                     //this->ShowModal();
}

//---------------------------------------------------------------------------
// Метод для размещения текста на текстовом поле
void TForm1::SetText(const AnsiString& text)
{
	Memo1->Lines->Text =  text;
}
//---------------------------------------------------------------------------
// 1
void TForm1::SetLitres(const AnsiString& text)
{
	  litr->Text = text;
}
//---------------------------------------------------------------------------
//
void TForm1::SetPrice(const AnsiString& text)
{
           price->Text = text;
}
//---------------------------------------------------------------------------
// забираем текст с формы
AnsiString TForm1:: GetText()
{
			   return Memo1->Lines->Text;
}

 AnsiString TForm1:: GetValues(const int FieldNum)
{
				   if (FieldNum == 1) {

						return litr->Text;
				   }
				   else{
						 return price->Text;
				   }
}
void TForm1 :: GetRsp(const AnsiString& value)
{
			 r = value;
}


