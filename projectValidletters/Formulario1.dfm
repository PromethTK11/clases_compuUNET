object Form1: TForm1
  Left = 228
  Top = 143
  Width = 264
  Height = 117
  Caption = 'VALIDADOR DE LETRAS'
  Color = clBtnShadow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object L1: TLabel
    Left = 0
    Top = 0
    Width = 248
    Height = 18
    Caption = '    Ingrese letras nada mas    '
    Color = clBlue
    Font.Charset = ANSI_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'Consolas'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object T1: TEdit
    Left = 8
    Top = 32
    Width = 233
    Height = 25
    AutoSize = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnKeyPress = T1KeyPress
  end
end
