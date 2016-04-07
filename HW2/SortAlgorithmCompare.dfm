object Form1: TForm1
  Left = 207
  Top = 55
  Width = 903
  Height = 629
  Caption = 'Sort Algorithm Compare build by YI-YING 2016/4/7'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lblCPUTime: TLabel
    Left = 24
    Top = 16
    Width = 116
    Height = 20
    Caption = 'CPU Time(s) ='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblNum: TLabel
    Left = 27
    Top = 54
    Width = 33
    Height = 20
    Caption = 'N = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblRange: TLabel
    Left = 5
    Top = 78
    Width = 99
    Height = 20
    Caption = 'Range = 1 ~'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 399
    Top = 135
    Width = 59
    Height = 20
    Caption = 'Sorting'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblRunLoop: TLabel
    Left = 5
    Top = 103
    Width = 89
    Height = 20
    Caption = 'RunLoop ='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object edNum: TEdit
    Left = 117
    Top = 48
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '100'
    OnKeyPress = edNumKeyPress
  end
  object edRange: TEdit
    Left = 117
    Top = 76
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '1000'
    OnKeyPress = edRangeKeyPress
  end
  object Memo1: TMemo
    Left = 16
    Top = 160
    Width = 297
    Height = 417
    BiDiMode = bdRightToLeft
    ParentBiDiMode = False
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object Memo2: TMemo
    Left = 560
    Top = 160
    Width = 297
    Height = 417
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object cbShowData: TCheckBox
    Left = 24
    Top = 135
    Width = 153
    Height = 17
    Caption = 'Show Random Data ?'
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    State = cbChecked
    TabOrder = 4
  end
  object cbShowResult: TCheckBox
    Left = 562
    Top = 135
    Width = 153
    Height = 17
    Caption = 'Show Result ?'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object btHeap: TButton
    Left = 336
    Top = 176
    Width = 201
    Height = 41
    Caption = 'Heap Sort'
    TabOrder = 6
    OnClick = btHeapClick
  end
  object btInorder: TButton
    Left = 336
    Top = 240
    Width = 201
    Height = 41
    Caption = 'Inorder Traversal'
    TabOrder = 7
  end
  object btInorderNR: TButton
    Left = 336
    Top = 296
    Width = 201
    Height = 41
    Caption = 'Inorder Traversal (none recursive)'
    TabOrder = 8
  end
  object btSelection: TButton
    Left = 336
    Top = 360
    Width = 201
    Height = 41
    Caption = 'Selection Sort'
    TabOrder = 9
  end
  object btInsertion: TButton
    Left = 336
    Top = 424
    Width = 201
    Height = 41
    Caption = 'Insertion Sort'
    TabOrder = 10
  end
  object btBubble: TButton
    Left = 336
    Top = 480
    Width = 201
    Height = 41
    Caption = 'Bubble Sort'
    TabOrder = 11
  end
  object btQuick: TButton
    Left = 336
    Top = 539
    Width = 201
    Height = 41
    Caption = 'Quick Sort'
    TabOrder = 12
  end
  object btRandom: TButton
    Left = 250
    Top = 48
    Width = 118
    Height = 74
    Caption = 'Random'
    TabOrder = 13
    OnClick = btRandomClick
  end
  object edRunLoop: TEdit
    Left = 117
    Top = 101
    Width = 121
    Height = 21
    TabOrder = 14
    Text = '5'
    OnKeyPress = edRangeKeyPress
  end
end
