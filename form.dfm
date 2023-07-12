object Form1: TForm1
  Left = 511
  Top = 187
  Caption = 'Bonus'
  ClientHeight = 643
  ClientWidth = 779
  Color = clBtnFace
  Constraints.MaxHeight = 682
  Constraints.MaxWidth = 800
  Constraints.MinHeight = 600
  Constraints.MinWidth = 700
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  TextHeight = 15
  object litres: TLabel
    Left = 426
    Top = 144
    Width = 99
    Height = 16
    Caption = #1050#1086#1083'-'#1074#1086' '#1083#1080#1090#1088#1086#1074':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 426
    Top = 200
    Width = 84
    Height = 16
    Caption = #1062#1077#1085#1072' '#1083#1080#1090#1088#1072' :'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object отправить: TButton
    Left = 448
    Top = 392
    Width = 201
    Height = 49
    Caption = #1086#1090#1087#1088#1072#1074#1080#1090#1100
    TabOrder = 0
    OnClick = Click
  end
  object Memo1: TMemo
    Left = 15
    Top = 40
    Width = 370
    Height = 513
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object litr: TEdit
    Left = 543
    Top = 142
    Width = 66
    Height = 23
    TabOrder = 2
    Text = '0'
  end
  object price: TEdit
    Left = 543
    Top = 198
    Width = 66
    Height = 23
    Ctl3D = True
    DoubleBuffered = False
    ParentCtl3D = False
    ParentDoubleBuffered = False
    TabOrder = 3
    Text = '0'
  end
end
