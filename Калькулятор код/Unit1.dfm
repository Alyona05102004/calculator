object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 467
  ClientWidth = 306
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 16
    Top = 32
    Width = 22
    Height = 54
    BiDiMode = bdLeftToRight
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
  end
  object btn_1: TButton
    Left = 16
    Top = 320
    Width = 65
    Height = 65
    Caption = '1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = number_click
  end
  object btn_2: TButton
    Left = 87
    Top = 320
    Width = 65
    Height = 65
    Caption = '2'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = number_click
  end
  object btn_3: TButton
    Left = 158
    Top = 320
    Width = 65
    Height = 65
    Caption = '3'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = number_click
  end
  object btn_4: TButton
    Left = 16
    Top = 249
    Width = 65
    Height = 65
    Caption = '4'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = number_click
  end
  object btn_5: TButton
    Left = 87
    Top = 249
    Width = 65
    Height = 65
    Caption = '5'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = number_click
  end
  object btn_9: TButton
    Left = 158
    Top = 178
    Width = 65
    Height = 65
    Caption = '9'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = number_click
  end
  object btn_7: TButton
    Left = 16
    Top = 178
    Width = 65
    Height = 65
    Caption = '7'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = number_click
  end
  object btn_6: TButton
    Left = 158
    Top = 249
    Width = 65
    Height = 65
    Caption = '6'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = number_click
  end
  object btn_8: TButton
    Left = 87
    Top = 178
    Width = 65
    Height = 65
    Caption = '8'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = number_click
  end
  object btn_0: TButton
    Left = 87
    Top = 391
    Width = 65
    Height = 65
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = number_click
  end
  object btn_dots: TButton
    Left = 158
    Top = 391
    Width = 65
    Height = 65
    Caption = ','
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = number_click
  end
  object btn_equal: TButton
    Left = 229
    Top = 391
    Width = 65
    Height = 65
    Caption = '='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = btn_equalClick
  end
  object btn_sum: TButton
    Left = 229
    Top = 320
    Width = 65
    Height = 65
    Caption = '+'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    OnClick = number_click
  end
  object btn_sub: TButton
    Left = 229
    Top = 249
    Width = 65
    Height = 65
    Caption = '-'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = number_click
  end
  object btn_umnoj: TButton
    Left = 229
    Top = 178
    Width = 65
    Height = 65
    Caption = '*'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
    OnClick = number_click
  end
  object btn_del: TButton
    Left = 158
    Top = 107
    Width = 65
    Height = 65
    Caption = '/'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    OnClick = number_click
  end
  object btn_backspace: TButton
    Left = 229
    Top = 107
    Width = 65
    Height = 65
    Caption = #8592
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 16
    OnClick = btn_backspaceClick
  end
  object btn_min: TButton
    Left = 16
    Top = 107
    Width = 136
    Height = 65
    Caption = 'Min(x,y)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 17
    OnClick = btn_minClick
  end
  object btn_delete_all: TButton
    Left = 16
    Top = 391
    Width = 65
    Height = 65
    Caption = 'C'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 18
    OnClick = btn_delete_allClick
  end
end
