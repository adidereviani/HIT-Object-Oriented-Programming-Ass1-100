#include "stdafx.h" 
#include "RectangleF.h"


IMPLEMENT_SERIAL(RectangleF, CObject, 1)


RectangleF::RectangleF(CPoint p1, CPoint p2, int Pen_Thin, COLORREF curColor, COLORREF fillSColor) : Figure(p1, p2, Pen_Thin, curColor, fillSColor) //c'tor
{

}

