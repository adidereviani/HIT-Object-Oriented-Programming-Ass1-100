#pragma once
#include "Figure.h"

class LineF :public Figure
{
	DECLARE_SERIAL(LineF)   //!!! NO ";"  

public:

	// must 4 serialization
	LineF() {}
	LineF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor);
	void Draw(CDC* dc) const override; // draw line
};


