#include "stdafx.h"
#include "SquareF.h"

IMPLEMENT_SERIAL(SquareF, CObject, 1)


SquareF::SquareF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor) : RectangleF(p1, p2, Pen_Thin, curColor,  fillSColor) //c'tor
{
}

void SquareF::Draw(CDC* dc) const //draw square
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPen myPen1(PS_SOLID, Pen_Thin, curColor);
	CPen* old_pen;
	old_pen = dc->SelectObject(&myPen1);
	CBrush brush(fillSColor);
	CBrush *oldBrush = dc->SelectObject(&brush);
	
	if (p2.x - p1.x == p2.y - p1.y) // The size of the width is equal to the size of the height
	{
		dc->Rectangle(p1.x, p1.y, p2.x, p2.y);
	}
	else
	{
		if (p1.x > p2.x) //draw from right(start) to left(end)
		{
			if (p2.y > p1.y) //draw from right bottom to left top 
			{
				if (p1.x - p2.x > p2.y - p1.y) //width bigger then height
				{
					p2.y = p1.y + (p1.x - p2.x);
				}
				else //height bigger then width
				{
					p2.x = p1.x - (p2.y - p1.y);
				}
			}
			else if (p2.y < p1.y) //draw from right top to left bottom
			{
				if (p1.x - p2.x > p1.y - p2.y) //width bigger then height
				{
					p2.y = p1.y - (p1.x - p2.x);
				}
				else //height bigger then width
				{
					p2.x = p1.x - (p1.y - p2.y);
				}

			}
		}
		if (p1.x < p2.x) //draw from left(start) to right(end)
		{
			if (p2.y > p1.y) //draw from left bottom to right top
			{
				if (p2.x - p1.x > p2.y - p1.y) //width bigger then height
				{
					p2.y =  p1.y + (p2.x - p1.x);
				}
				else //height bigger then width
				{
					p2.x = p1.x + (p2.y - p1.y);
				}
			}
			else if (p2.y < p1.y) //draw from left top to right bottom
			{
				if (p2.x - p1.x > p1.y - p2.y) //width bigger then height
				{
					p2.y = p1.y - (p2.x - p1.x);
				}
				else //height bigger then width
				{
					p2.x = p1.x + (p1.y - p2.y);
				}
			}
		}
	}

	dc->Rectangle(p1.x, p1.y, p2.x, p2.y); //draw
	dc->SelectObject(old_pen);
	dc->SelectObject(oldBrush);
}