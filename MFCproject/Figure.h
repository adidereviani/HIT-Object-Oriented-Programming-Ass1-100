#pragma once
#include "stdafx.h"
#include  "afxdlgs.h" 

class Figure : public CObject
{
	DECLARE_SERIAL(Figure)   

public:

	// must 4 serialization
	Figure() {}
	Figure(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor); //c'tor
	CPoint getP1() const; //get p1
	CPoint getP2() const; //get p2
	void Serialize(CArchive& ar); //for save/load
	virtual void Draw(CDC* dc) const; //draw rectangle- default radio button
	void Redefine(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor); 
	bool isInside(const CPoint& P) const; //checks if the point is inside shape

protected:
	CPoint P1; //START point
	CPoint P2; //END point
	COLORREF curColor = RGB(0, 0, 0); //line color - Black
	int Pen_Thin = 1; //line thickness - 1
	COLORREF fillSColor = RGB(255, 255, 255); //fill color - White
};