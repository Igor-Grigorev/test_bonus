//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
// ������������� �����
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// ��������� ������� ������ / �������� �����
void __fastcall TForm1::Click(TObject *Sender)
{
		Close();
}
//---------------------------------------------------------------------------
// ��������� ������� ������ �������
void __fastcall TForm1::Click_count(TObject *Sender)
{
                     Memo1->Lines->Clear();
					 Memo1->Lines->Text = r;
                     //this->ShowModal();
}

//---------------------------------------------------------------------------
// ����� ��� ���������� ������ �� ��������� ����
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
// �������� ����� � �����
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


