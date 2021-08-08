#include "stdafx.h"
#include "CircleF.h"

IMPLEMENT_SERIAL(CircleF, CObject, 1)


CircleF::CircleF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor) : EllipseF(p1, p2, Pen_Thin, curColor, fillSColor) //c'tor
{
}

void CircleF::Draw(CDC* dc) const //draw circle
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPen myPen1(PS_SOLID, Pen_Thin, curColor);
	CPen* old_pen;
	old_pen = dc->SelectObject(&myPen1);
	CBrush brush(fillSColor);
	CBrush* oldBrush = dc->SelectObject(&brush);

	if (p2.x - p1.x == p2.y - p1.y) //The size of the perpendicular radius is equal to the size of the balanced radius
	{
		dc->Ellipse(p1.x, p1.y, p2.x, p2.y); //draw
	}
	else
	{
		if (p1.x > p2.x) //draw from right(start) to left(end)
		{
			if (p2.y > p1.y) //draw from right bottom to left top 
			{
				if (p1.x - p2.x > p2.y - p1.y) //"Width radius" bigger then "Height radius"
				{
					p2.y = p1.y + (p1.x - p2.x);
				}
				else //"Height radius" bigger then "Width radius"
				{
					p2.x = p1.x - (p2.y - p1.y);
				}
			}
			else if (p2.y < p1.y) //draw from right top to left bottom
			{
				if (p1.x - p2.x > p1.y - p2.y) //"Width radius" bigger then "Height radius"
				{
					p2.y = p1.y - (p1.x - p2.x);
				}
				else //"Height radius" bigger then "Width radius"
				{
					p2.x = p1.x - (p1.y - p2.y);
				}

			}
		}
		if (p1.x < p2.x) //draw from left(start) to right(end)
		{
			if (p2.y > p1.y) //draw from left bottom to right top 
			{
				if (p2.x - p1.x > p2.y - p1.y) //"Width radius" bigger then "Height radius"
				{
					p2.y = p1.y + (p2.x - p1.x);
				}
				else //"Height radius" bigger then "Width radius"
				{
					p2.x = p1.x + (p2.y - p1.y);
				}
			}
			else if (p2.y < p1.y) //draw from left top to right bottom
			{
				if (p2.x - p1.x > p1.y - p2.y) //"Width radius" bigger then "Height radius"
				{
					p2.y = p1.y - (p2.x - p1.x);
				}
				else //"Height radius" bigger then "Width radius"
				{
					p2.x = p1.x + (p1.y - p2.y);
				}
			}
		}
	}

	dc->Ellipse(p1.x, p1.y, p2.x, p2.y); //draw
	dc->SelectObject(old_pen);
	dc->SelectObject(oldBrush);
}