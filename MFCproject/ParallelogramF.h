#pragma once
#include "Figure.h"
#include "RectangleF.h"

class ParallelogramF : public RectangleF
{
	DECLARE_SERIAL(ParallelogramF)   //!!! NO ";"  

public:

	// must 4 serialization
	ParallelogramF() {}
	ParallelogramF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor);
	void Draw(CDC* dc) const override; //draw parallelogram
};


