#pragma once
#include "Figure.h"

class TriangleF :public Figure
{
	DECLARE_SERIAL(TriangleF)   //!!! NO ";"  

public:

	// must 4 serialization
	TriangleF() {}
	TriangleF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor);
	void Draw(CDC* dc) const override; //draw triangle
};
