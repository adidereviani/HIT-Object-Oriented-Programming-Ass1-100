#pragma once
#include "Figure.h"
#include "RectangleF.h"

class SquareF : public RectangleF
{
	DECLARE_SERIAL(SquareF)   //!!! NO ";"  

public:

	// must 4 serialization
	SquareF() {}
	SquareF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor);
	void Draw(CDC* dc) const override; //draw square
};

