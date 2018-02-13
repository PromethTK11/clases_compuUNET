object Form1: TForm1
  Left = 327
  Top = 162
  Width = 246
  Height = 128
  Caption = 'Medidas - 30mins'
  Color = clGradientActiveCaption
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Consolas'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object L1: TLabel
    Left = 0
    Top = 0
    Width = 230
    Height = 17
    Align = alTop
    Alignment = taCenter
    AutoSize = False
    Caption = 'Ingrese medida de grados '#176'F'
    Color = clNavy
    Font.Charset = ANSI_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'Consolas'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object E1: TEdit
    Left = 8
    Top = 32
    Width = 209
    Height = 21
    AutoSize = False
    TabOrder = 0
    OnKeyPress = E1KeyPress
  end
  object B1: TButton
    Left = 8
    Top = 64
    Width = 89
    Height = 17
    Caption = 'Ingresar'
    TabOrder = 1
    OnClick = B1Click
  end
  object B2: TButton
    Left = 128
    Top = 64
    Width = 89
    Height = 17
    Caption = 'Salir'
    TabOrder = 2
    OnClick = B2Click
  end
end
