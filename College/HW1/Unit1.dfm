object Form1: TForm1
  Left = 233
  Top = 111
  Width = 673
  Height = 626
  Caption = 'BST by YI-YING 2016/3/11'
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
    Width = 657
    Height = 587
    ActivePage = TabSheet3
    Align = alClient
    TabIndex = 2
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'BST'
      DesignSize = (
        649
        559)
      object Label1: TLabel
        Left = 16
        Top = 333
        Width = 127
        Height = 16
        Caption = '# of Integer ( 5 to 100 )'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 16
        Top = 424
        Width = 134
        Height = 16
        Caption = 'Range ( 100 to  10000 )'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 27
        Top = 270
        Width = 97
        Height = 16
        Caption = 'None Recursive'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object edInsertIntoBST: TEdit
        Left = 16
        Top = 8
        Width = 121
        Height = 21
        BiDiMode = bdLeftToRight
        ParentBiDiMode = False
        TabOrder = 0
        Text = '100'
        OnKeyDown = edInsertIntoBSTKeyDown
        OnKeyPress = edInsertIntoBSTKeyPress
      end
      object btInsertIntoBST: TButton
        Left = 16
        Top = 40
        Width = 121
        Height = 25
        Caption = 'Insert into BST'
        TabOrder = 1
        OnClick = btInsertIntoBSTClick
      end
      object edDeleteFromBST: TEdit
        Left = 16
        Top = 88
        Width = 121
        Height = 21
        TabOrder = 2
        Text = '100'
        OnKeyDown = edDeleteFromBSTKeyDown
        OnKeyPress = edDeleteFromBSTKeyPress
      end
      object btDeletefromBST: TButton
        Left = 16
        Top = 120
        Width = 121
        Height = 25
        Caption = 'Delete from BST'
        TabOrder = 3
        OnClick = btDeletefromBSTClick
      end
      object trbNumOfInteger: TTrackBar
        Left = 8
        Top = 349
        Width = 135
        Height = 25
        Max = 100
        Min = 5
        Orientation = trHorizontal
        PageSize = 5
        Frequency = 5
        Position = 10
        SelEnd = 0
        SelStart = 0
        TabOrder = 4
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = trbNumOfIntegerChange
      end
      object edNumOfInteger: TEdit
        Left = 16
        Top = 389
        Width = 121
        Height = 21
        TabOrder = 5
        Text = '10'
        OnChange = edNumOfIntegerChange
        OnKeyPress = edNumOfIntegerKeyPress
      end
      object trbRange: TTrackBar
        Left = 8
        Top = 440
        Width = 135
        Height = 25
        Max = 10000
        Min = 100
        Orientation = trHorizontal
        PageSize = 500
        Frequency = 500
        Position = 100
        SelEnd = 0
        SelStart = 0
        TabOrder = 6
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = trbRangeChange
      end
      object edRange: TEdit
        Left = 16
        Top = 472
        Width = 121
        Height = 21
        TabOrder = 7
        Text = '100'
        OnChange = edRangeChange
        OnKeyPress = edRangeKeyPress
      end
      object btRandom: TButton
        Left = 16
        Top = 497
        Width = 121
        Height = 25
        Caption = 'Random integers'
        TabOrder = 8
        OnClick = btRandomClick
      end
      object Memo1: TMemo
        Left = 176
        Top = 8
        Width = 464
        Height = 539
        Anchors = [akLeft, akTop, akRight, akBottom]
        Lines.Strings = (
          'Please input integer')
        ScrollBars = ssBoth
        TabOrder = 9
      end
      object btPreorder: TButton
        Left = 16
        Top = 160
        Width = 121
        Height = 25
        Caption = 'Preorder Search'
        TabOrder = 10
        OnClick = btPreorderClick
      end
      object btPostOrder: TButton
        Left = 16
        Top = 200
        Width = 121
        Height = 25
        Caption = 'Postorder Search'
        TabOrder = 11
        OnClick = btPostOrderClick
      end
      object btLevelOrder: TButton
        Left = 16
        Top = 240
        Width = 121
        Height = 25
        Caption = 'Level Order'
        TabOrder = 12
        OnClick = btLevelOrderClick
      end
      object btPrefix: TButton
        Left = 8
        Top = 294
        Width = 40
        Height = 17
        Caption = 'Prefix'
        TabOrder = 13
        OnClick = btPrefixClick
      end
      object btInfix: TButton
        Left = 58
        Top = 294
        Width = 40
        Height = 17
        Caption = 'Infix'
        TabOrder = 14
        OnClick = btInfixClick
      end
      object btPostfix: TButton
        Left = 109
        Top = 294
        Width = 40
        Height = 17
        Caption = 'Postfix'
        TabOrder = 15
        OnClick = btPostfixClick
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Could Input Character'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 152
        Top = 0
        Width = 497
        Height = 559
        Align = alRight
        Lines.Strings = (
          'Memo2')
        TabOrder = 0
      end
      object GroupBox1: TGroupBox
        Left = 0
        Top = 0
        Width = 145
        Height = 89
        Caption = 'Insert Operation'
        TabOrder = 1
        object edInsert: TEdit
          Left = 8
          Top = 20
          Width = 121
          Height = 21
          BiDiMode = bdLeftToRight
          ParentBiDiMode = False
          TabOrder = 0
          Text = '(A+B)*C/(D+E)'
        end
        object btInsert: TButton
          Left = 8
          Top = 48
          Width = 121
          Height = 25
          Caption = 'Insert'
          TabOrder = 1
          OnClick = btInsertClick
        end
      end
      object GroupBox2: TGroupBox
        Left = 0
        Top = 96
        Width = 145
        Height = 97
        Caption = 'Tree Traversal'
        TabOrder = 2
        object cbTreeTraversal: TComboBox
          Left = 5
          Top = 20
          Width = 135
          Height = 21
          ItemHeight = 13
          TabOrder = 0
          Text = 'Preorder Traversal'
          Items.Strings = (
            'Preorder Traversal'
            'Inorder Traversal'
            'Postorder Traversal')
        end
        object btTreeTraversal: TButton
          Left = 4
          Top = 53
          Width = 135
          Height = 25
          Caption = 'Tree Traversal'
          TabOrder = 1
          OnClick = btTreeTraversalClick
        end
      end
      object GroupBox3: TGroupBox
        Left = 0
        Top = 216
        Width = 145
        Height = 121
        Caption = 'Tree State'
        TabOrder = 3
        object lblElementNum: TLabel
          Left = 11
          Top = 20
          Width = 69
          Height = 13
          Caption = 'Element Num :'
        end
        object lblLevelHeight: TLabel
          Left = 11
          Top = 39
          Width = 66
          Height = 13
          Caption = 'Level Height :'
        end
        object lblStatus: TLabel
          Left = 11
          Top = 60
          Width = 36
          Height = 13
          Caption = 'Status :'
        end
        object btResetTree: TButton
          Left = 13
          Top = 85
          Width = 121
          Height = 25
          Caption = 'Reset Tree'
          TabOrder = 0
          OnClick = btResetTreeClick
        end
      end
      object btDraw_BT_C: TButton
        Left = 8
        Top = 448
        Width = 121
        Height = 25
        Caption = 'Draw Tree'
        TabOrder = 4
        OnClick = btDraw_BT_CClick
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Draw Tree'
      ImageIndex = 2
      object imDrawTree: TImage
        Left = 0
        Top = 0
        Width = 649
        Height = 559
        Align = alClient
      end
    end
  end
end
