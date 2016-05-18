object fMST: TfMST
  Left = 192
  Top = 115
  Width = 974
  Height = 610
  Caption = 'MST_KruscalAndPrim Algorithm made by YI-YING 2016/5/12'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    958
    571)
  PixelsPerInch = 96
  TextHeight = 13
  object gpbGraphic: TGroupBox
    Left = 0
    Top = 0
    Width = 417
    Height = 313
    Align = alCustom
    Caption = 'G = ( V, E )'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object lblVertex: TLabel
      Left = 32
      Top = 40
      Width = 67
      Height = 33
      Caption = '|V| = '
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lblWeightRange: TLabel
      Left = 32
      Top = 80
      Width = 154
      Height = 33
      Caption = 'range(w(e)) = '
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lblWeightLimit: TLabel
      Left = 32
      Top = 120
      Width = 113
      Height = 33
      Caption = 'if (w(e)) > '
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lblWeightMax: TLabel
      Left = 32
      Top = 160
      Width = 338
      Height = 33
      Caption = 'w(e) = MaxInt(                            )'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object btGenerateG: TButton
      Left = 32
      Top = 208
      Width = 338
      Height = 49
      Caption = 'Generate G'
      TabOrder = 0
      OnClick = btGenerateGClick
    end
    object edVertexNum: TEdit
      Left = 120
      Top = 40
      Width = 121
      Height = 31
      TabOrder = 1
      Text = '8'
    end
    object edWeightRange: TEdit
      Left = 216
      Top = 82
      Width = 121
      Height = 31
      TabOrder = 2
      Text = '100'
    end
    object edWeightLimit: TEdit
      Left = 216
      Top = 120
      Width = 121
      Height = 31
      TabOrder = 3
      Text = '100'
    end
    object edWeightMax: TEdit
      Left = 216
      Top = 162
      Width = 121
      Height = 31
      TabOrder = 4
      Text = '99999'
    end
    object cbPrintG: TCheckBox
      Left = 32
      Top = 272
      Width = 185
      Height = 25
      Caption = 'Echo print G'
      Checked = True
      State = cbChecked
      TabOrder = 5
    end
  end
  object gpbMSTAlgorithm: TGroupBox
    Left = 0
    Top = 320
    Width = 417
    Height = 249
    Anchors = [akLeft, akTop, akBottom]
    Caption = 'MST Solver'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    object btKruscal: TButton
      Left = 32
      Top = 48
      Width = 338
      Height = 49
      Caption = 'Kruscal'#39's algorithm'
      TabOrder = 0
      OnClick = btKruscalClick
    end
    object btPrim: TButton
      Left = 32
      Top = 112
      Width = 338
      Height = 49
      Caption = 'Prim'#39's algorithm'
      TabOrder = 1
      OnClick = btPrimClick
    end
    object cbPrintEdges: TCheckBox
      Left = 32
      Top = 198
      Width = 217
      Height = 25
      Caption = 'Echo print edges in MST'
      TabOrder = 2
    end
    object cbPrintEdgesMatrix: TCheckBox
      Left = 32
      Top = 174
      Width = 217
      Height = 25
      Caption = 'Echo print Edges Matrix'
      TabOrder = 3
    end
  end
  object pcOutput: TPageControl
    Left = 424
    Top = 8
    Width = 529
    Height = 561
    ActivePage = tsMSTFound
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabIndex = 0
    TabOrder = 2
    object tsMSTFound: TTabSheet
      Caption = 'MST Found'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 521
        Height = 527
        Align = alClient
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object tbAjacentMatrix: TTabSheet
      Caption = 'Ajacent Matrix'
      ImageIndex = 1
      object sgAjacentMatrix: TStringGrid
        Left = 0
        Top = 0
        Width = 521
        Height = 527
        Align = alClient
        FixedCols = 0
        FixedRows = 0
        Options = [goVertLine, goHorzLine]
        TabOrder = 0
      end
    end
    object tbEdgesMatrix: TTabSheet
      Caption = 'Edges Matrix'
      ImageIndex = 2
      object sgEdgesMatrix: TStringGrid
        Left = 0
        Top = 0
        Width = 521
        Height = 527
        Align = alClient
        FixedCols = 0
        FixedRows = 0
        TabOrder = 0
      end
    end
  end
end
