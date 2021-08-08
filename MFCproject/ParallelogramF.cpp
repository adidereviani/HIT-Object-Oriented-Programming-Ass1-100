#include "stdafx.h"
#include "ParallelogramF.h"

IMPLEMENT_SERIAL(ParallelogramF, CObject, 1)


ParallelogramF::ParallelogramF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor) : RectangleF(p1, p2, Pen_Thin, curColor, fillSColor) //c'tor
{
}

void ParallelogramF::Draw(CDC* dc) const //draw parallelogram
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPen myPen1(PS_SOLID, Pen_Thin, curColor);
	CPen* old_pen;
	old_pen = dc->SelectObject(&myPen1);
	CBrush brush(fillSColor);
	CBrush* oldBrush = dc->SelectObject(&brush);

	CPoint ParallelogramPoints[4];

	//put points inside arr points
	if (p1.x > p2.x) //draw from right(start) to left(end)
	{
		ParallelogramPoints[0].SetPoint(p1.x, p1.y); //start point
		ParallelogramPoints[1].SetPoint(p1.x - (p1.x - p2.x) / 3, p2.y);
		ParallelogramPoints[2].SetPoint(p2.x, p2.y); //end point
		ParallelogramPoints[3].SetPoint(p2.x + (p1.x - p2.x) / 3, p1.y);
	}
	else //draw from left(start) to right(end)
	{
		ParallelogramPoints[0].SetPoint(p1.x, p1.y); //start point
		ParallelogramPoints[1].SetPoint(p2.x - (p2.x - p1.x) / 3, p1.y);
		ParallelogramPoints[2].SetPoint(p2.x, p2.y); //end point
		ParallelogramPoints[3].SetPoint(p2.x - 2 * (p2.x - p1.x) / 3, p2.y);
	}
	dc->Polygon(ParallelogramPoints, 4); //draw
	dc->SelectObject(old_pen);
	dc->SelectObject(oldBrush);
}