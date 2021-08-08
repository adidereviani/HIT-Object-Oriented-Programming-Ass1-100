#pragma once
#include "Figure.h"
#include "EllipseF.h"

class CircleF : public EllipseF
{
	DECLARE_SERIAL(CircleF)   //!!! NO ";"  

public:

	// must 4 serialization
	CircleF() {}
	CircleF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor);
	void Draw(CDC* dc) const override;// draw circle 
};

