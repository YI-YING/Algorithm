object fSortingAlgorithm: TfSortingAlgorithm
  Left = 199
  Top = 17
  Width = 940
  Height = 702
  Caption = 'Sorting Algorithm created by YI-YING 2016/6/12'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object pControl: TPanel
    Left = 0
    Top = 0
    Width = 257
    Height = 663
    Align = alLeft
    TabOrder = 0
    object gbInput: TGroupBox
      Left = 1
      Top = 1
      Width = 255
      Height = 184
      Align = alTop
      Caption = 'Input'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      object lblTimes: TLabel
        Left = 61
        Top = 27
        Width = 63
        Height = 20
        Caption = 'Times ='
      end
      object lblNum: TLabel
        Left = 97
        Top = 72
        Width = 28
        Height = 20
        Caption = 'N ='
      end
      object lblRange: TLabel
        Left = 9
        Top = 116
        Width = 116
        Height = 20
        Caption = 'Range 1 ~ N ='
      end
      object edTimes: TEdit
        Left = 133
        Top = 25
        Width = 108
        Height = 28
        TabOrder = 0
        Text = '1'
      end
      object edNum: TEdit
        Left = 133
        Top = 67
        Width = 108
        Height = 28
        TabOrder = 1
        Text = '5'
      end
      object edRange: TEdit
        Left = 133
        Top = 112
        Width = 108
        Height = 28
        TabOrder = 2
        Text = '100'
      end
    end
    object gbSorting: TGroupBox
      Left = 1
      Top = 185
      Width = 255
      Height = 264
      Align = alTop
      Caption = 'Sorting'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      object clbAlgorithms: TCheckListBox
        Left = 93
        Top = 22
        Width = 141
        Height = 154
        Align = alCustom
        ItemHeight = 20
        Items.Strings = (
          'Selection Sort'
          'Insert Sort'
          'Bubble Sort'
          'Quick Sort'
          'Heap Sort'
          'Merge Sort'
          'Radix Sort')
        TabOrder = 0
      end
      object cbSeeData: TCheckBox
        Left = 6
        Top = 216
        Width = 90
        Height = 17
        Caption = 'See Data'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        State = cbChecked
        TabOrder = 1
      end
      object btDrawDiagram: TButton
        Left = 94
        Top = 210
        Width = 139
        Height = 25
        Caption = 'Draw Diagram'
        TabOrder = 2
        OnClick = btDrawDiagramClick
      end
    end
    object gbCheck: TGroupBox
      Left = 1
      Top = 449
      Width = 255
      Height = 213
      Align = alClient
      Caption = 'Check'
      TabOrder = 2
      object memCheck: TMemo
        Left = 2
        Top = 15
        Width = 251
        Height = 180
        Align = alCustom
        TabOrder = 0
      end
    end
  end
  object pShowResult: TPanel
    Left = 257
    Top = 0
    Width = 667
    Height = 663
    Align = alClient
    TabOrder = 1
    object pcShowData: TPageControl
      Left = 1
      Top = 1
      Width = 665
      Height = 661
      ActivePage = tsData
      Align = alClient
      TabIndex = 1
      TabOrder = 0
      object tsDiagram: TTabSheet
        Caption = 'Diagram'
        object chDiagram: TChart
          Left = 0
          Top = 0
          Width = 657
          Height = 633
          BackWall.Brush.Color = clWhite
          BackWall.Brush.Style = bsClear
          Title.Font.Charset = ANSI_CHARSET
          Title.Font.Color = clBlue
          Title.Font.Height = -19
          Title.Font.Name = 'Arial Black'
          Title.Font.Style = [fsBold]
          Title.Text.Strings = (
            'Sorting')
          BottomAxis.Automatic = False
          BottomAxis.AutomaticMaximum = False
          BottomAxis.AutomaticMinimum = False
          BottomAxis.Maximum = 12
          BottomAxis.Title.Caption = 'Data 10^3'
          BottomAxis.Title.Font.Charset = DEFAULT_CHARSET
          BottomAxis.Title.Font.Color = clBlack
          BottomAxis.Title.Font.Height = -16
          BottomAxis.Title.Font.Name = 'Arial'
          BottomAxis.Title.Font.Style = [fsBold]
          LeftAxis.Automatic = False
          LeftAxis.AutomaticMaximum = False
          LeftAxis.AutomaticMinimum = False
          LeftAxis.Maximum = 400
          LeftAxis.Title.Caption = 'CPU Time (M sec)'
          LeftAxis.Title.Font.Charset = DEFAULT_CHARSET
          LeftAxis.Title.Font.Color = clBlack
          LeftAxis.Title.Font.Height = -16
          LeftAxis.Title.Font.Name = 'Arial'
          LeftAxis.Title.Font.Style = [fsBold]
          Legend.LegendStyle = lsSeries
          View3D = False
          Align = alClient
          TabOrder = 0
          object Series1: TLineSeries
            Marks.ArrowLength = 8
            Marks.Visible = False
            SeriesColor = clRed
            Pointer.InflateMargins = True
            Pointer.Style = psRectangle
            Pointer.Visible = False
            XValues.DateTime = False
            XValues.Name = 'X'
            XValues.Multiplier = 1
            XValues.Order = loAscending
            YValues.DateTime = False
            YValues.Name = 'Y'
            YValues.Multiplier = 1
            YValues.Order = loNone
          end
        end
      end
      object tsData: TTabSheet
        Caption = 'Data'
        ImageIndex = 1
        object memData: TMemo
          Left = 0
          Top = 0
          Width = 657
          Height = 633
          Align = alClient
          TabOrder = 0
        end
      end
    end
  end
end
