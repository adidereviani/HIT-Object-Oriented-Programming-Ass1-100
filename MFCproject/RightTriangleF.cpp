#include "stdafx.h"
#include "RightTriangleF.h"

IMPLEMENT_SERIAL(RightTriangleF, CObject, 1)


RightTriangleF::RightTriangleF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor) : TriangleF(p1, p2, Pen_Thin, curColor, fillSColor) //c'tor
{
}

void RightTriangleF::Draw(CDC* dc) const //draw right triangle
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPoint rightTrianglePoints[3];
	int p3_x = p1.x; //3 point x same like start point x
	int p3_y = p2.y; //3 point y same like end point y

	//put points inside arr points
	rightTrianglePoints[0].SetPoint(p1.x, p1.y); //start point
	rightTrianglePoints[1].SetPoint(p2.x, p2.y);//end point
	rightTrianglePoints[2].SetPoint(p3_x, p3_y); //90 degrees point


	CPen myPen1(PS_SOLID, Pen_Thin, curColor);
	CPen* old_pen;
	old_pen = dc->SelectObject(&myPen1);
	CBrush brush(fillSColor);
	CBrush* oldBrush = dc->SelectObject(&brush);
	dc->Polygon(rightTrianglePoints, 3); //draw
	dc->SelectObject(old_pen);
	dc->SelectObject(oldBrush);
}



