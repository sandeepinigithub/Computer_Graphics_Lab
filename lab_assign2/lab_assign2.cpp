#include <graphics.h>
#include <conio.h>

int main()
{
	//initilizing graphic driver and 
	//graphic mode variable
	int graphicdriver=DETECT,graphicmode;

	//calling initgraph function with 
	//certain parameters
	initgraph(&graphicdriver,&graphicmode," ");
	
	//set font style 
	// font style 
    int font = 8; 
  
    // font direction 
    int direction = 0; 
  
    // font size 
    int font_size = 3;
	
	settextstyle(font, direction, font_size); 

	//Printing message for user
	outtextxy(10, 10 + 10, "Program to draw a smiley face in C graphics (Sandeep Kumar Shukla(1729010140))");

	//setting color to yellow
	setcolor(YELLOW);
	
	//creating circle and fill it with 
	//yellow color using floodfill.
	circle(300, 100, 40);
	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(300, 100, YELLOW);

	//setting color to black
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);

	//using fill ellipse and ellipse for creating face.
	fillellipse(310, 85, 2, 6);
	fillellipse(290, 85, 2, 6);

	ellipse(300, 100, 205, 335, 20, 9);
	ellipse(300, 100, 205, 335, 20, 10);
	ellipse(300, 100, 205, 335, 20, 11);


	getch();
	return 0;	
}
