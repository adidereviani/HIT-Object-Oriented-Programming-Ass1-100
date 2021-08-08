#include "stdafx.h"
#include "EllipseF.h"


IMPLEMENT_SERIAL(EllipseF, CObject, 1)


EllipseF::EllipseF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor) : Figure(p1, p2, Pen_Thin, curColor, fillSColor) //c'tor
{
}

void EllipseF::Draw(CDC* dc) const// draw ellipse
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPen myPen1(PS_SOLID, Pen_Thin, curColor);
	CPen* old_pen;
	old_pen = dc->SelectObject(&myPen1);
	CBrush brush(fillSColor);
	CBrush *oldBrush = dc->SelectObject(&brush);
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y); //draw
	dc->SelectObject(old_pen);
	dc->SelectObject(oldBrush);
}

