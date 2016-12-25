object fKnapsack: TfKnapsack
  Left = 259
  Top = 135
  Width = 1284
  Height = 675
  Caption = 
    '0/1 Knapsack Solved by Branch And Bound  created by YI-YING 2016' +
    '/12/24'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 24
  object Splitter1: TSplitter
    Left = 356
    Top = 0
    Width = 5
    Height = 636
    Cursor = crHSplit
  end
  object PLeft: TPanel
    Left = 0
    Top = 0
    Width = 356
    Height = 636
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 100
      Top = 8
      Width = 127
      Height = 24
      Caption = 'Generate Items'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblItemNum: TLabel
      Left = 16
      Top = 48
      Width = 91
      Height = 24
      Caption = 'Item Num: '
    end
    object lblWeightRange: TLabel
      Left = 16
      Top = 87
      Width = 156
      Height = 24
      Caption = 'Weight Range: 1 ~'
    end
    object lblBagCapacity: TLabel
      Left = 16
      Top = 172
      Width = 114
      Height = 24
      Caption = 'Bag Capacity:'
    end
    object Label5: TLabel
      Left = 125
      Top = 357
      Width = 68
      Height = 24
      Caption = 'Solution'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblProfitRange: TLabel
      Left = 16
      Top = 127
      Width = 138
      Height = 24
      Caption = 'Profit Range: 1 ~'
    end
    object btGenerate: TButton
      Left = 52
      Top = 233
      Width = 215
      Height = 33
      Caption = 'Generate'
      TabOrder = 5
      OnClick = btGenerateClick
    end
    object edItemNum: TEdit
      Left = 185
      Top = 42
      Width = 121
      Height = 32
      TabOrder = 0
      Text = '5'
      OnChange = edItemNumChange
      OnExit = edItemNumExit
    end
    object edWeightRange: TEdit
      Tag = 1
      Left = 185
      Top = 83
      Width = 121
      Height = 32
      TabOrder = 1
      Text = '20'
      OnChange = edItemNumChange
      OnExit = edItemNumExit
    end
    object edBagCapacity: TEdit
      Tag = 3
      Left = 185
      Top = 165
      Width = 121
      Height = 32
      TabOrder = 3
      Text = '34'
      OnChange = edItemNumChange
      OnExit = edItemNumExit
    end
    object cbPrintItems: TCheckBox
      Left = 16
      Top = 289
      Width = 129
      Height = 17
      Caption = 'Print Items'
      Checked = True
      State = cbChecked
      TabOrder = 4
    end
    object btBranchAndBound: TButton
      Left = 52
      Top = 407
      Width = 215
      Height = 33
      Caption = 'Branch and Bound'
      TabOrder = 6
    end
    object edProfitRange: TEdit
      Tag = 2
      Left = 185
      Top = 123
      Width = 121
      Height = 32
      TabOrder = 2
      Text = '10'
      OnChange = edItemNumChange
      OnExit = edItemNumExit
    end
  end
  object PRight: TPanel
    Left = 361
    Top = 0
    Width = 907
    Height = 636
    Align = alClient
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 905
      Height = 634
      ActivePage = tsSolution
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabIndex = 0
      TabOrder = 0
      object tsSolution: TTabSheet
        Caption = 'Solution'
        object memSolution: TMemo
          Left = 0
          Top = 0
          Width = 897
          Height = 595
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          Lines.Strings = (
            'Please generate Items, then execute the program to find answer')
          ParentFont = False
          TabOrder = 0
        end
      end
      object tsItems: TTabSheet
        Caption = 'Item Weight and Profit'
        ImageIndex = 1
        object sgItems: TStringGrid
          Left = 0
          Top = 0
          Width = 897
          Height = 595
          Align = alClient
          TabOrder = 0
        end
      end
    end
  end
end
