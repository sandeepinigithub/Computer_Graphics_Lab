#include<stdio.h>
#include<graphics.h>

//**********************Bresenham's Line**********************
//Draw line using Bresenham's Line Drawing Algorithm 
void Bresenham_Line()
{
    int dx, dy, p, x, y ,error, x0, y0, x1, y1;
    printf("Enter co-ordinates of first point: ");
	scanf("%d%d", &x0, &y0); 
	printf("Enter co-ordinates of second point: ");
	scanf("%d%d", &x1, &y1);
 
	dx=x1-x0;
	dy=y1-y0; 
	x=x0;
	y=y0; 
	p=2*dy-dx; 
	while(x<x1)
	{
		if(p>=0)
		{
			putpixel(x,y,7);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
			{
				putpixel(x,y,7);
				p=p+2*dy;
			}
			x=x+1;
	}
}

//**********************Bresenham's Circle********************** 
//Draw Circle using Bresenham's Circle Drawing Algorithm

void drawCircle(int xc, int yc, int x, int y) 
{ 
putpixel(xc+x, yc+y, RED); 
putpixel(xc-x, yc+y, RED); 
putpixel(xc+x, yc-y, RED); 
putpixel(xc-x, yc-y, RED); 
putpixel(xc+y, yc+x, RED); 
putpixel(xc-y, yc+x, RED); 
putpixel(xc+y, yc-x, RED); 
putpixel(xc-y, yc-x, RED); 
}
void Bresenham_Circle() 
{ 
    int xc = 50, yc = 50, r = 30; 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawCircle(xc, yc, x, y); 
        delay(50); 
    } 
}

//**********************Bresenham's Ellipse********************** 
//Draw Circle using Bresenham's Ellipse Drawing Algorithm
void Bresenham_Ellipse()
{
	long int d1,d2;
	int i,x,y;
	long int rx,ry,rxsq,rysq,tworxsq,tworysq,dx,dy;
	printf("Enter the x Radius of the ellipse");
	scanf("%ld",&rx);
	printf("Enter the y Radius of the ellipse");
	scanf("%ld",&ry);

	rxsq=rx*rx;
	rysq=ry*ry;
	tworxsq=2*rxsq;
	tworysq=2*rysq;
	x=0;
	y=ry;
	d1=rysq - (rxsq * ry) + (0.25 * rxsq);
	dx= tworysq * x;
	dy= tworxsq * y;
	do
	{
	  putpixel(200+x,200+y,15);
	  putpixel(200-x,200-y,15);
	  putpixel(200+x,200-y,15);
	  putpixel(200-x,200+y,15);
	  if (d1 < 0)
	   {
	    x=x+1;
	    y=y;
	     dx=dx + tworysq;
	     d1=d1 + dx + rysq;
	     }
	   else
	   {
	    x=x+1;
	    y=y-1;
	    dx= dx + tworysq;
	    dy= dy - tworxsq;
	    d1= d1 + dx - dy + rysq;
	    }
	    delay(50);
	    }while (dx < dy);
	   d2 = rysq * ( x + 0.5) * ( x + 0.5 ) + rxsq * (y - 1) * (y-1) - rxsq * rysq;
	    do
	    {
	     putpixel(200+x,200+y,15);
	  putpixel(200-x,200-y,15);
	  putpixel(200+x,200-y,15);
	  putpixel(200-x,200+y,15);
	
	  if (d2 >0)
	  {
	  x=x;
	  y=y-1;
	  dy = dy - tworxsq;
	  d2 = d2 - dy + rxsq;
	  }
	  else
	  {
	  x= x+1;
	  y=y-1;
	  dy=dy - tworxsq;
	  dx= dx + tworysq;
	  d2 = d2 + dx -dy + rxsq;
	  }
	  delay(50);
	} while ( y> 0);
}

 
int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "");
	
	Bresenham_Line(); //for drawing Bresenham's Line 
	Bresenham_Circle(); // for drawing Bresenham's Circle 
	Bresenham_Ellipse(); // for drawing Bresenham's Ellipse
	
	getch();
	closegraph();
 
	return 0;
}
