object Form1: TForm1
  Left = 207
  Top = 55
  Width = 893
  Height = 642
  Caption = 'Sort Algorithm Compare build by YI-YING 2016/4/7 Ver1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 877
    Height = 603
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Select Sort Algorithm'
      object Label4: TLabel
        Left = 399
        Top = 127
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
      object btBubble: TButton
        Left = 336
        Top = 463
        Width = 201
        Height = 41
        Caption = 'Bubble Sort'
        TabOrder = 0
        OnClick = btBubbleClick
      end
      object btHeap: TButton
        Left = 336
        Top = 162
        Width = 201
        Height = 41
        Caption = 'Heap Sort'
        TabOrder = 1
        OnClick = btHeapClick
      end
      object btInorder: TButton
        Left = 336
        Top = 226
        Width = 201
        Height = 41
        Caption = 'Inorder Traversal'
        TabOrder = 2
        OnClick = btInorderClick
      end
      object btInorderNR: TButton
        Left = 336
        Top = 282
        Width = 201
        Height = 41
        Caption = 'Inorder Traversal (none recursive)'
        TabOrder = 3
        OnClick = btInorderNRClick
      end
      object btInsertion: TButton
        Left = 336
        Top = 406
        Width = 201
        Height = 41
        Caption = 'Insertion Sort'
        TabOrder = 4
        OnClick = btInsertionClick
      end
      object btQuick: TButton
        Left = 336
        Top = 513
        Width = 201
        Height = 41
        Caption = 'Quick Sort'
        TabOrder = 5
        OnClick = btQuickClick
      end
      object btRandom: TButton
        Left = 250
        Top = 48
        Width = 118
        Height = 49
        Caption = 'Random'
        TabOrder = 6
        OnClick = btRandomClick
      end
      object btSelection: TButton
        Left = 336
        Top = 346
        Width = 201
        Height = 41
        Caption = 'Selection Sort'
        TabOrder = 7
        OnClick = btSelectionClick
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
        TabOrder = 8
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
        TabOrder = 9
      end
      object edNum: TEdit
        Left = 117
        Top = 48
        Width = 121
        Height = 21
        TabOrder = 10
        Text = '100'
        OnKeyPress = edNumKeyPress
      end
      object edRange: TEdit
        Left = 117
        Top = 76
        Width = 121
        Height = 21
        TabOrder = 11
        Text = '1000'
        OnKeyPress = edRangeKeyPress
      end
      object Memo1: TMemo
        Left = 16
        Top = 155
        Width = 297
        Height = 417
        BiDiMode = bdRightToLeft
        ParentBiDiMode = False
        ScrollBars = ssVertical
        TabOrder = 12
      end
      object Memo2: TMemo
        Left = 560
        Top = 155
        Width = 297
        Height = 417
        ScrollBars = ssVertical
        TabOrder = 13
      end
    end
  end
end
