
// MFCprojectDlg.h : header file
//

#pragma once

#include "Figure.h"
#include "RectangleF.h"
#include "EllipseF.h"
#include "TriangleF.h"
#include "LineF.h"
#include "SquareF.h"
#include "CircleF.h"
#include "ParallelogramF.h"
#include "RightTriangleF.h"
#include  "afxdlgs.h"


using namespace std;


// CMFCprojectDlg dialog
class CMFCprojectDlg : public CDialogEx
{
// Construction
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	CPoint startP, endP;
	bool isPressed = false;
	CTypedPtrArray< CObArray, Figure*> figs; //arr of pointers to figure
	CTypedPtrArray< CObArray, Figure*> temp; //temp arr for undo, redo and delete
	int F_Kind = 1; //Rectangle (2 - Ellipse, 3 - tringle, 4 - line, 5 - square, 6 - circle, 7 - parallelogram, 8 - right triangle)
	COLORREF curColor, fillSColor; //pen and fill color
	int m_PenWidth; //pen thickness
	bool delete_Shape = false; //delete button
	
	 
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnCbnSelchangeCombo1();
private:
	CComboBox m_ComboPenWidth;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	// CButton for each button- icons
	CButton saveB;
	CButton loadB;
	CButton fillB;
	CButton colorChooseB;
	CButton deleteShapeB;
	CButton clearB;
	CButton UndoB;
	CButton RedoB;
	CButton exitB;
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
};
