#include "stdafx.h"
#include "TriangleF.h"


IMPLEMENT_SERIAL(TriangleF, CObject, 1)


TriangleF::TriangleF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor) : Figure(p1, p2, Pen_Thin, curColor, fillSColor) //c'tor
{
}

void TriangleF::Draw(CDC* dc) const //draw triangle
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPoint trianglePoints[3];

	//insert points to trianglePoints (arr points)
	trianglePoints[0].SetPoint(p1.x, p2.y); //start+end  
	trianglePoints[1].SetPoint(p2.x, p2.y);
	trianglePoints[2].SetPoint((p1.x + p2.x) / 2, p1.y);

	CPen myPen1(PS_SOLID, Pen_Thin, curColor);
	CPen* old_pen;
	old_pen = dc->SelectObject(&myPen1);
	CBrush brush(fillSColor);
	CBrush *oldBrush = dc->SelectObject(&brush);
	dc->Polygon(trianglePoints, 3); //draw
	dc->SelectObject(old_pen);
	dc->SelectObject(oldBrush);
}



