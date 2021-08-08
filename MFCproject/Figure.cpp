#include "stdafx.h"  
#include "Figure.h"


IMPLEMENT_SERIAL(Figure, CObject, 1)

Figure::Figure(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor) : P1(p1), P2(p2) //c'tor
{
	this->Pen_Thin = Pen_Thin;
	this->curColor = curColor;
	this->fillSColor = fillSColor;
}

CPoint Figure::getP1() const //get start point
{
	return P1;
}
CPoint Figure::getP2() const //get end point
{
	return P2;
}

void Figure::Serialize(CArchive& ar) //for save/load
{
	CObject::Serialize(ar);
	if (ar.IsStoring()) //Saving, storing
	{
		ar << P1;
		ar << P2;
		ar << curColor;
		ar << Pen_Thin;
		ar << fillSColor;
	}
	else // Loading, not storing
	{
		ar >> P1;
		ar >> P2;
		ar >> curColor;
		ar >> Pen_Thin;
		ar >> fillSColor;
	}
}


bool Figure::isInside(const CPoint& P) const //check if the point is inside any shape
{
	return (P1.x <= P.x && P.x <= P2.x || P1.x >= P.x && P.x >= P2.x) &&
		(P1.y <= P.y && P.y <= P2.y || P1.y >= P.y && P.y >= P2.y);
}


void Figure::Redefine(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor)
{
	this->P1 = p1;
	this->P2 = p2;
	this->Pen_Thin = Pen_Thin;
	this->curColor = curColor;
	this->fillSColor = fillSColor;
}

void Figure::Draw(CDC* dc) const //draw rectangle function - default radio button
{
	CPen myPen1(PS_SOLID, Pen_Thin, curColor);
	CPen* old_pen;
	old_pen = dc->SelectObject(&myPen1);
	CBrush brush(fillSColor);
	CBrush* oldBrush = dc->SelectObject(&brush);
	dc->Rectangle(P1.x, P1.y, P2.x, P2.y); //draw
	dc->SelectObject(old_pen);
	dc->SelectObject(oldBrush);
}