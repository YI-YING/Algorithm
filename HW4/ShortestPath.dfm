object fShowtestPath: TfShowtestPath
  Left = 181
  Top = 65
  Width = 973
  Height = 621
  Caption = 'Showtest Path by YI-YING 2016/5/25'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object panlControl: TPanel
    Left = 0
    Top = 0
    Width = 337
    Height = 582
    Align = alLeft
    TabOrder = 0
    object gbInputGroup: TGroupBox
      Left = 1
      Top = 1
      Width = 335
      Height = 355
      Align = alClient
      Caption = 'Input Control'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      object lblVertexNum: TLabel
        Left = 24
        Top = 32
        Width = 37
        Height = 24
        Caption = '|V| ='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lblRange: TLabel
        Left = 24
        Top = 71
        Width = 121
        Height = 24
        Caption = 'Range(w(e)) ='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lblSource: TLabel
        Left = 24
        Top = 191
        Width = 71
        Height = 24
        Caption = 'Source :'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lblWeightLimit: TLabel
        Left = 24
        Top = 109
        Width = 83
        Height = 24
        Caption = 'if (w(e)) > '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lblWeightMax: TLabel
        Left = 24
        Top = 150
        Width = 53
        Height = 24
        Caption = 'w(e) ='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object edVertexNum: TEdit
        Left = 158
        Top = 31
        Width = 121
        Height = 28
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = '5'
      end
      object edRange: TEdit
        Left = 157
        Top = 71
        Width = 121
        Height = 28
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Text = '100'
      end
      object edWeightLimit: TEdit
        Left = 157
        Top = 112
        Width = 121
        Height = 28
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Text = '100'
      end
      object edWeightMax: TEdit
        Left = 156
        Top = 152
        Width = 121
        Height = 28
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        Text = '999999'
      end
      object edSource: TEdit
        Left = 156
        Top = 193
        Width = 121
        Height = 28
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        Text = '0'
      end
      object btGenerateG: TButton
        Left = 23
        Top = 232
        Width = 257
        Height = 31
        Caption = 'Generate G'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
      end
      object cbUndirectedG: TCheckBox
        Left = 23
        Top = 282
        Width = 119
        Height = 17
        Caption = 'Undirected G'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
      end
      object cbPrintG: TCheckBox
        Left = 23
        Top = 305
        Width = 113
        Height = 17
        Caption = 'Echo print G'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
      end
    end
    object gbOutputGroup: TGroupBox
      Left = 1
      Top = 356
      Width = 335
      Height = 225
      Align = alBottom
      Caption = 'Output Methods'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      object btSingleSource: TButton
        Left = 26
        Top = 46
        Width = 256
        Height = 31
        Caption = 'Single Source All Destinations'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object btAllPairs: TButton
        Left = 26
        Top = 91
        Width = 256
        Height = 31
        Caption = 'All Pairs'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object btTransitiveClosure: TButton
        Left = 26
        Top = 139
        Width = 256
        Height = 31
        Caption = 'Transitive Closure'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object cbPrintResult: TCheckBox
        Left = 26
        Top = 189
        Width = 108
        Height = 17
        Caption = 'Print Result'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
    end
  end
  object pcOutput: TPageControl
    Left = 337
    Top = 0
    Width = 620
    Height = 582
    ActivePage = tsTransitiveClosure
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabIndex = 3
    TabOrder = 1
    object tsSolutions: TTabSheet
      Caption = 'Solutions'
      object memSolutions: TMemo
        Left = 0
        Top = 0
        Width = 612
        Height = 547
        Align = alClient
        TabOrder = 0
      end
    end
    object tsAjacentMatrix: TTabSheet
      Caption = 'G in ajacent Matrix'
      ImageIndex = 1
      object sgAjacentMatrix: TStringGrid
        Left = 0
        Top = 0
        Width = 612
        Height = 547
        Align = alClient
        TabOrder = 0
      end
    end
    object tsShortestPaths: TTabSheet
      Caption = 'Costs of all pairs shortest paths'
      ImageIndex = 2
      object sgShortestPaths: TStringGrid
        Left = 0
        Top = 0
        Width = 612
        Height = 547
        Align = alClient
        TabOrder = 0
      end
    end
    object tsTransitiveClosure: TTabSheet
      Caption = 'Transitive closure'
      ImageIndex = 3
      object sgTransitiveClosure: TStringGrid
        Left = 0
        Top = 0
        Width = 612
        Height = 547
        Align = alClient
        TabOrder = 0
      end
    end
  end
end
