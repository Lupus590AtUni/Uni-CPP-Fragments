#include "stdafx.h"
#include "NA_GU.h"

extern cRenderClass graphics;
extern NA_MathsLib maths;

NA_GU::NA_GU()
{
	clipBoundry.max.x = 0;
	clipBoundry.max.y = 0;
	clipBoundry.min.x = 0;
	clipBoundry.min.y = 0;
}

NA_GU::~NA_GU()
{
}

void NA_GU::n_ds(const NA_Pixel start, const NA_Pixel end)
{
	//direct scan
	float m;
	if ((start.position.x-end.position.x)==0) return; //this error escape should not need to run
	m = (start.position.y-end.position.y)/(start.position.x-end.position.x);
	int c = start.position.y-m*start.position.x;
	if(DEBUG) cout<<"m: "<<m<<"\n";

	//increment along x
	for (int x =start.position.x; x<end.position.x;x++)
	{
		float y=m*x+c;
		y = y+0.5f;
		graphics.drawPixel(x, (int) y);
		if (DEBUG) cout<<"start.position.x "<<start.position.x<<", start.position.y "<<start.position.y<<", end.position.x "<<end.position.x<<", end.position.y "<<end.position.y<<", x "<<x<<", "<<(int)y<<"\n";
	}
}

void NA_GU::n_vertical(const NA_Pixel start, const NA_Pixel end)
{
	//direct scan
	if (start.position.y < end.position.y)
	{
		for (int y =start.position.y; y<end.position.y;y++)
		{
			graphics.drawPixel(start.position.x, y);
			if (DEBUG)
			{
				cout<<"0,"<<y<<"\n";
			}
		}
	}
	else
	{
		for (int y =end.position.y; y<start.position.y;y++)
		{
			graphics.drawPixel(end.position.x, y);
			if (DEBUG)
			{
				cout<<"0,"<<y<<"\n";
			}
		}
	}
}

void NA_GU::directScan(const NA_Pixel start, const NA_Pixel end)
{
	if ((end.position.x-start.position.x)==0)//special case, stright up (greadient is infinite - which causes an error in normal method)
	{
		this->n_vertical(start,end);
	}
	else
	{
		if ((start.position.x<end.position.x))//must intergreate along x going from left to right, this fixes that

		{
			n_ds(start,end);
		}
		else
		{
			n_ds(end,start);
		}
	}
}

void NA_GU::n_dda(const NA_Pixel start, const NA_Pixel end)
{
	//DDA
	float m;
	if ((start.position.x-end.position.x)==0) return; //this error escape should not need to run
	m = (start.position.y-end.position.y)/(start.position.x-end.position.x);
	int c = start.position.y-m*start.position.x;
	if(DEBUG) 
		if (m<0) 
		{
			cout<<"***M < 0: "<<"start.position.x "<<start.position.x<<", start.position.y "<<start.position.y<<", end.position.x "<<end.position.x<<", end.position.y "<<end.position.y<<", m "<<m<<"\n";
		}
		else
		{
			cout<<"M!<0\n";
		}
	if(m>1)//the improvement of DDA over DS is the conditional ntergrate along y
	{
		//increment along y
		for (int y =start.position.y; y<end.position.y;y++)
		{
			float x=(y-c)/m;
			x = x+0.5f;
			graphics.drawPixel((int)x,y);
			if (DEBUG) cout<<"start.position.x "<<start.position.x<<", start.position.y "<<start.position.y<<", end.position.x "<<end.position.x<<", end.position.y "<<end.position.y<<", x "<<(int)x<<", "<<y<<"\n";
		}
	}
	else
	{
		//increment along x
		for (int x =start.position.x; x<end.position.x;x++)
		{
			float y=m*x+c;
			y = y+0.5f;
			graphics.drawPixel(x, (int) y);
			if (DEBUG) cout<<"start.position.x "<<start.position.x<<", start.position.y "<<start.position.y<<", end.position.x "<<end.position.x<<", end.position.y "<<end.position.y<<", x "<<x<<", "<<(int)y<<"\n";
		}
	}
}

void NA_GU::DDA(const NA_Pixel start, const NA_Pixel end)
{
	if ((end.position.x-start.position.x)==0)//special case, stright up (greadient is infinite - which causes an error in normal method)
	{
		this->n_vertical(start,end);
	}
	else
	{
		if ((start.position.x<end.position.x))//must intergreate along x going from left to right, this fixes that
		{
			n_dda(start,end);
		}
		else
		{
			n_dda(end,start);
		}
	}
}


void NA_GU::bresenham(const NA_Pixel start, const NA_Pixel end)//i can't get this to work properly, even looked at wikipedia and compared with axls code (made sure not to outright copy)
{
	//bresenham
	if (DEBUG) cout<<"start.position.x "<<start.position.x<<", start.position.y "<<start.position.y<<", end.position.x "<<end.position.x<<", end.position.y "<<end.position.y<<"\n";
	int dx = end.position.x - start.position.x;
	int dy = end.position.y - start.position.y;
	if(DEBUG) cout<<"dx: "<<dx<<", dy: "<<dy<<"\n"; 
	int p = (2*dy)-dx; //decision parameter
	if (end.position.x<start.position.x)
	{
		graphics.drawPixel(end.position.x,end.position.y);
		int y = end.position.y;
		for (int x = end.position.x; x<start.position.x;x++)
		{
			if(p<0)
			{
				if(DEBUG) cout<<"Move over\n";
				graphics.drawPixel(x+1,y);
				p+=2*dy;
			}
			else
			{
				if(DEBUG) cout<<"Going up\n";
				graphics.drawPixel(x+1,y+1);
				p+=(2*dy - 2*dx);
				y++;
			}
		}
	}
	else
	{
		graphics.drawPixel(start.position.x,start.position.y);
		int y = start.position.y;
		for (int x = start.position.x; x<end.position.x;x++)
		{
			if(p<0)
			{
				if(DEBUG) cout<<"Move over\n";
				graphics.drawPixel(x+1,y);
				p+=2*dy;
			}
			else
			{
				if(DEBUG) cout<<"Going up\n";
				graphics.drawPixel(x+1,y+1);
				p+=(2*dy - 2*dx);
				y++;
			}
		}
	}
}



void NA_GU::drawCirclePoints(const NA_Pixel centre, const NA_Pixel point)
{
	graphics.drawPixel(centre.position.x+point.position.x,centre.position.y+point.position.y);
	graphics.drawPixel(centre.position.x-point.position.x,centre.position.y+point.position.y);
	graphics.drawPixel(centre.position.x+point.position.x,centre.position.y-point.position.y);
	graphics.drawPixel(centre.position.x-point.position.x,centre.position.y-point.position.y);
	

	if(DEBUG) cout<<point.position.x<<", "<<point.position.y<<"\n";

}

void NA_GU::drawCircle(const NA_Pixel centre, const float radius)
{
	NA_Pixel point;
	graphics.setColour(0,1,1);
	if (DEBUG) graphics.drawPixel(centre.position.x,centre.position.y);
	graphics.setColour(0,0,0);
	float inc = 360/(2*maths.PI*radius);

	for (float i = 0; i <= 45; i = i + inc)
	{
		point.position.x = 0.5f+radius*cos(maths.degToRad(i));
		point.position.y = 0.5f+radius*sin(maths.degToRad(i));
		if(DEBUG) cout<<"centre: "<<centre.position.x<<", "<<centre.position.y<<"\nradius: "<<radius<<"\n"<<"point.position.x: "<<point.position.x<<"\npoint.position.y: "<<point.position.y<<"\n";
		this->drawCirclePoints(centre,point);
		float temp = point.position.x; point.position.x = point.position.y; point.position.y = temp; //swap point x and y
		this->drawCirclePoints(centre,point);
	}

}

bool NA_GU::visable(NA_Pixel clipMe)
{
	//returns true if point is visable
	if((clipMe.position.x < clipBoundry.max.x) && (clipMe.position.x > clipBoundry.min.x))
	{
		if((clipMe.position.y < clipBoundry.max.y) && (clipMe.position.y > clipBoundry.min.y))
		{
			return true;
		}
	}
	return false;
}

NA_Line NA_GU::clip(NA_Line clipMe)
{
	//cohen-sotherland line clipping
	static enum {centre,left,right,top,bottom,topLeft,bottomLeft,topRight,bottomRight};
	/*
	switch(condition)
		case testValue
			conditional code
		break;
		case ...
	*/
	return clipMe;
}

void NA_GU::setColour(sRGB c)
{
	graphics.setColour(c.r,c.g,c.b);
}

sRGB NA_GU::interpolate(const NA_Pixel p1, const NA_Pixel p, const NA_Pixel p2)
{
	NA_Pixel temp;
	temp.colour.r = ( (p.position.y - p2.position.y)/(p1.position.y - p2.position.y) ) * p1.colour.r + ( (p1.position.y - p.position.y)/(p1.position.y - p2.position.y) ) * p2.colour.r;
	temp.colour.g = ( (p.position.y - p2.position.y)/(p1.position.y - p2.position.y) ) * p1.colour.g + ( (p1.position.y - p.position.y)/(p1.position.y - p2.position.y) ) * p2.colour.g;
	temp.colour.b = ( (p.position.y - p2.position.y)/(p1.position.y - p2.position.y) ) * p1.colour.b + ( (p1.position.y - p.position.y)/(p1.position.y - p2.position.y) ) * p2.colour.b;
	return temp.colour;
}

void NA_GU::drawTriangle(const NA_Pixel p1, const NA_Pixel p2, const NA_Pixel p3)
{
	if ((p2.position.y == p1.position.y) || (p2.position.y == p3.position.y) || (p1.position.y == p3.position.y))
	{
		cout<<"NA_GU::Draw Triangle: one or more points have same y value and vertical lines are not supported\n";
		return;
	}
	for(int i = p2.position.y; i < p1.position.y; i++)
	{
		NA_Pixel p;
		p.position.y = i;
		p.position.x = ((i-(p2.position.y-((p2.position.y-p1.position.y)/(p2.position.x-p1.position.x))*p2.position.x))/((p2.position.y-p1.position.y)/(p2.position.x-p1.position.x)))+0.5f;
		p.colour = this->interpolate(p2,p,p1);
		this->setColour(p.colour);
		graphics.drawPixel(p.position.x,p.position.y);

	}

}