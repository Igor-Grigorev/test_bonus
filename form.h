//---------------------------------------------------------------------------

#ifndef formH
#define formH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.JumpList.hpp>
#include "json.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *отправить;
	TMemo *Memo1;
	TLabel *litres;
	TEdit *litr;
	TLabel *Label1;
	TEdit *price;
	void __fastcall Click(TObject *Sender);
	void __fastcall Click_count(TObject *Sender);
private:	// User declarations
		 AnsiString r;
public:		// User declarations
	  // string PresetPrice;
	__fastcall TForm1(TComponent* Owner);
	void SetText(const AnsiString& text);
	AnsiString GetText();
	void SetLitres(const AnsiString& text);
	void SetPrice(const AnsiString& text);
	AnsiString GetValues(const int FieldNum);
	void GetRsp(const AnsiString& r);


};
//---------------------------------------------------------------------------
extern  TForm1 *Form1; // с параметром package - не работает
//---------------------------------------------------------------------------
#endif
