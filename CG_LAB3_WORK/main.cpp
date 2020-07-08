#include<stdio.h>
#include<graphics.h>

// function for drawing circle 
void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
	putpixel(x0 + x, y0 + y, 7);
	putpixel(x0 + y, y0 + x, 7);
	putpixel(x0 - y, y0 + x, 7);
	putpixel(x0 - x, y0 + y, 7);
	putpixel(x0 - x, y0 - y, 7);
	putpixel(x0 - y, y0 - x, 7);
	putpixel(x0 + y, y0 - x, 7);
	putpixel(x0 + x, y0 - y, 7);
 
	if (err <= 0)
	{
	    y += 1;
	    err += 2*y + 1;
	}
 
	if (err > 0)
	{
	    x -= 1;
	    err -= 2*x + 1;
	}
    }
}

//*************** Main Function Starts here *************** 
int main()
{
	int gd=DETECT, gm, error,x,y,r;
	initgraph(&gd, &gm, "");
	printf("\n****************************************************\n");
	printf("\t Name - Sandeep Kumar Shukla \n\t RollNo. - 1729010140 \n\t 3CS C \n");
	printf("\t Internal Lab \n\t Computer Graphics (RCS 653)\n ");
	printf("\n\n\t P-3: WAP in C to create a circle using Mid-Point circle algorithm. \n\n");
	printf("\n****************************************************\n");	 
	printf("\nEnter radius of circle: ");
	scanf("%d", &r); 
	printf("Enter co-ordinates of center(x and y): ");
	scanf("%d%d", &x, &y);
		
	drawcircle(x, y, r);  //Calling drawcircle() function by giving parameter. 
	
	getch();
	closegraph();
 
	return 0;
}

