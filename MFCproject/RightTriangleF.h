#pragma once
#include "Figure.h"
#include "TriangleF.h"

class RightTriangleF :public TriangleF
{
	DECLARE_SERIAL(RightTriangleF)   //!!! NO ";"  

public:

	// must 4 serialization
	RightTriangleF() {}
	RightTriangleF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor);
	void Draw(CDC* dc) const override;// draw right triangle
};

