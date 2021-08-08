#pragma once
#include "Figure.h"

class EllipseF :public Figure 
{
	
	DECLARE_SERIAL(EllipseF)   //!!! NO ";"  
	
public:
	
	// must 4 serialization
	EllipseF() {}
	EllipseF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor);
	void Draw(CDC* dc) const override; // draw ellipse 
};
