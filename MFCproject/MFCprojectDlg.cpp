
// MFCprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCprojectDlg dialog



CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent) //c'tor
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	delete_Shape = false; //delete shape button
	m_PenWidth = 1; //Default pen width - 1
	curColor = RGB(0, 0, 0); //Default pen color- Black
	fillSColor = RGB(255, 255, 255); //Default fill color- White
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_ComboPenWidth);
	DDX_Control(pDX, IDC_BUTTON1, saveB);
	DDX_Control(pDX, IDC_BUTTON2, loadB);
	DDX_Control(pDX, IDC_BUTTON4, fillB);
	DDX_Control(pDX, IDC_BUTTON3, colorChooseB);
	DDX_Control(pDX, IDC_BUTTON6, deleteShapeB);
	DDX_Control(pDX, IDC_BUTTON5, clearB);
	DDX_Control(pDX, IDC_BUTTON7, UndoB);
	DDX_Control(pDX, IDC_BUTTON8, RedoB);
	DDX_Control(pDX, IDOK, exitB);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &CMFCprojectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCprojectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCprojectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCprojectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCprojectDlg::OnBnClickedRadio4)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCprojectDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCprojectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCprojectDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCprojectDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCprojectDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCprojectDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCprojectDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCprojectDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CMFCprojectDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CMFCprojectDlg::OnBnClickedRadio8)
END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	curColor = RGB(0, 0, 0);
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//icons
	saveB.ModifyStyle(0, BS_ICON);
	HICON save = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON1),
		IMAGE_ICON, 40, 40, LR_DEFAULTCOLOR);
	saveB.SetIcon(save);
	loadB.ModifyStyle(0, BS_ICON);
	HICON load = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON2),
		IMAGE_ICON, 40, 40, LR_DEFAULTCOLOR);
	loadB.SetIcon(load);
	fillB.ModifyStyle(0, BS_ICON);
	HICON fill = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3),
		IMAGE_ICON, 50, 50, LR_DEFAULTCOLOR);
	fillB.SetIcon(fill);
	colorChooseB.ModifyStyle(0, BS_ICON);
	HICON colors = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON4),
		IMAGE_ICON, 50, 50, LR_DEFAULTCOLOR);
	colorChooseB.SetIcon(colors);
	HICON deleteShape = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON5),
		IMAGE_ICON, 40, 40, LR_DEFAULTCOLOR);
	deleteShapeB.SetIcon(deleteShape);
	HICON clear = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON6),
		IMAGE_ICON, 45, 45, LR_DEFAULTCOLOR);
	clearB.SetIcon(clear);
	HICON undo = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON7),
		IMAGE_ICON, 45, 45, LR_DEFAULTCOLOR);
	UndoB.SetIcon(undo);
	HICON redo = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON8),
		IMAGE_ICON, 45, 45, LR_DEFAULTCOLOR);
	RedoB.SetIcon(redo);
	HICON exit = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON9),
		IMAGE_ICON, 45, 45, LR_DEFAULTCOLOR);
	exitB.SetIcon(exit);


	//select the default radio button - Rectangle shape
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	
	//pen width combo button
	m_ComboPenWidth.SetItemData(m_ComboPenWidth.AddString(L"0.1 mm"), 1);
	m_ComboPenWidth.SetItemData(m_ComboPenWidth.AddString(L"0.2 mm"), 2);
	m_ComboPenWidth.SetItemData(m_ComboPenWidth.AddString(L"0.4 mm"), 4);
	m_ComboPenWidth.SetItemData(m_ComboPenWidth.AddString(L"0.8 mm"), 8);
	m_ComboPenWidth.SetItemData(m_ComboPenWidth.AddString(L"1 mm"), 10);
	m_ComboPenWidth.SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < figs.GetSize(); i++) //draw all the shapes inside the figs arr
			figs[i]->Draw(&dc);
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	startP = point;
	isPressed = true;

	if (delete_Shape == true) //click on Delete Shape button
	{
		for (INT_PTR i = figs.GetSize() - 1; i >= 0; i--) //checks all shapes in the figs arr
		{
			if (figs[i]->isInside(point)) //if the click point inside the shape
			{
				if (figs[i] != NULL)
				{
					temp.Add(figs[i]); // add the shape to the temp arr
					figs.RemoveAt(i); //remove the pointer from the figs arr
					break;
				}
				break;
			}
		}
		isPressed = false;
		Invalidate();
	}

	if (delete_Shape == false) //unclick on Delete Shape button
	{
		switch (F_Kind) // add choosen shape to figs arr (arr of pointers to Figure)
		{
		case 1:
			figs.Add(new RectangleF(startP, startP, m_PenWidth, curColor, fillSColor));
			break;
		case 2:
			figs.Add(new EllipseF(startP, startP, m_PenWidth, curColor, fillSColor));
			break;
		case 3:
			figs.Add(new TriangleF(startP, startP, m_PenWidth, curColor, fillSColor));
			break;
		case 4:
			figs.Add(new LineF(startP, startP, m_PenWidth, curColor, fillSColor));
			break;
		case 5:
			figs.Add(new SquareF(startP, startP, m_PenWidth, curColor, fillSColor));
			break;
		case 6:
			figs.Add(new CircleF(startP, startP, m_PenWidth, curColor, fillSColor));
			break;
		case 7:
			figs.Add(new ParallelogramF(startP, startP, m_PenWidth, curColor, fillSColor));
			break;
		case 8:
			figs.Add(new RightTriangleF(startP, startP, m_PenWidth, curColor, fillSColor));
			break;
		}
	}
	delete_Shape = false;

	CDialogEx::OnLButtonDown(nFlags, point);
}

void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		endP = point;
		isPressed = false;
		figs[figs.GetSize() - 1]->Redefine(startP, endP, m_PenWidth, curColor, fillSColor);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		endP = point;
		figs[figs.GetSize() - 1]->Redefine(startP, endP, m_PenWidth, curColor, fillSColor);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCprojectDlg::OnBnClickedRadio1() //rectangle
{
	// TODO: Add your control notification handler code here
	F_Kind = 1;
}


void CMFCprojectDlg::OnBnClickedRadio2() //ellipse
{
	// TODO: Add your control notification handler code here
	F_Kind = 2;
}


void CMFCprojectDlg::OnBnClickedButton1() //save
{
	// TODO: Add your control notification handler code here
	
	             // FALSE to SAVE
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
	
}


void CMFCprojectDlg::OnBnClickedButton2() //load
{
	// TODO: Add your control notification handler code here
	
			     // TRUE to LOAD
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
	
}


void CMFCprojectDlg::OnBnClickedRadio3() //triangle
{
	// TODO: Add your control notification handler code here
	F_Kind = 3;
}


void CMFCprojectDlg::OnBnClickedRadio4() //line
{
	// TODO: Add your control notification handler code here
	F_Kind = 4;
}


void CMFCprojectDlg::OnCbnSelchangeCombo1() //combo to select the pen thickness
{
	// TODO: Add your control notification handler code here
	m_PenWidth = m_ComboPenWidth.GetItemData(m_ComboPenWidth.GetCurSel()); //choose the pen thickness
}


void CMFCprojectDlg::OnBnClickedButton3() //shape line color
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) 
	{
		curColor = dlg.GetColor(); 
	}
}


void CMFCprojectDlg::OnBnClickedButton4() //shape fill color
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) 
	{
		fillSColor = dlg.GetColor();
	}
}


void CMFCprojectDlg::OnBnClickedButton5() //clear
{
	// TODO: Add your control notification handler code here
	while (figs.IsEmpty() == false)
	{
		CObject* pa;
		if ((pa = figs.GetAt(0)) != NULL) 
		{
			figs.RemoveAt(0);  // Element 1 moves to 0.
			delete pa; // Delete the original element at 0.
		}
	}
	Invalidate();
}


void CMFCprojectDlg::OnBnClickedButton6() //delete Shape
{
	// TODO: Add your control notification handler code here
	delete_Shape = true;
}


void CMFCprojectDlg::OnBnClickedButton7() //undo
{
	// TODO: Add your control notification handler code here
	if (figs.GetSize() != 0)
	{
		temp.Add(figs[figs.GetSize() - 1]);
		figs.RemoveAt(figs.GetSize() - 1);
		Invalidate();
	}
}


void CMFCprojectDlg::OnBnClickedButton8() //redo
{
	// TODO: Add your control notification handler code here
	if (temp.GetSize() != 0)
	{
		figs.InsertAt(figs.GetSize(), temp.GetAt(temp.GetSize() - 1));
		temp.RemoveAt(temp.GetSize() - 1);
		Invalidate();
	}
}


void CMFCprojectDlg::OnBnClickedRadio5() // square
{
	// TODO: Add your control notification handler code here
	F_Kind = 5;
}


void CMFCprojectDlg::OnBnClickedRadio6() //circle
{
	// TODO: Add your control notification handler code here
	F_Kind = 6;
}


void CMFCprojectDlg::OnBnClickedRadio7() //parallelogram
{
	// TODO: Add your control notification handler code here
	F_Kind = 7;
}


void CMFCprojectDlg::OnBnClickedRadio8() // right triangle
{
	// TODO: Add your control notification handler code here
	F_Kind = 8;
}
