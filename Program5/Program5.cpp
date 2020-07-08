#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<math.h>

void Translation();
void translateLine ( int P[][2], int T[]);

void Rotation();
void TriAngle(int x1, int y1, int x2, int y2, int x3, int y3);
void Rotate(int x1, int y1, int x2, int y2, int x3, int y3);

void Scaling();
void scale(int x[], int y[], int sx, int sy);

void Reflection();
void DrawFn();
void FlipV();
void FlipH();


int main()
{
	int T;
	do{		
		printf("Please select your task to perform: \n");
		printf(" 1. Translation \n 2. Rotation \n 3. Scaling \n 4. Reflection \n 5. Exit \n");
		scanf("%d",&T);
		
		switch(T)
		{
			case 1 :
				Translation();				
				break;
			case 2 :
				Rotation();
				break;
			case 3 :
				Scaling();
				break;
			case 4 :
				Reflection();
				break;
			case 5 :
				exit(1);
			default :
				printf("Invalid Choice!!");			
		
		}
    }while(T!=5);
	
	
}

//****************Translation Function Start****************//
void Translation()
{
	int P[2][2] = {100, 100,200 , 200}; // coordinates of point 
	int T[] = {10, 50}; // translation factor 
	translateLine (P, T);
	
}

// function to translate line 
void translateLine ( int P[][2], int T[]) 
{ 
	/* init graph and line() are used for 
	representing line through graphical 
	functions 
	*/
	int gd = DETECT, gm, errorcode; 
	initgraph (&gd, &gm, ""); 
	
	// drawing original line using graphics functions 
	setcolor (2); 
	line(P[0][0], P[0][1], P[1][0], P[1][1]); 

	// calculating translated coordinates 
	P[0][0] = P[0][0] + T[0]; 
	P[0][1] = P[0][1] + T[1]; 
	P[1][0] = P[1][0] + T[0]; 
	P[1][1] = P[1][1] + T[1]; 

	// drawing translated line using graphics functions 
	setcolor(3); 
	line(P[0][0], P[0][1], P[1][0], P[1][1]); 
	getch();
	cleardevice();
	getch();
	closegraph(); 
}

//****************Translation Function End****************//

//****************Rotation Function Start****************//

void Rotation()
{
   int gd = DETECT, gm;
   int x1, y1, x2, y2, x3, y3;
   initgraph(&gd, &gm, " ");

   printf("Enter the 1st point for the triangle:");
   scanf("%d%d", &x1, &y1);
   printf("Enter the 2nd point for the triangle:");
   scanf("%d%d", &x2, &y2);
   printf("Enter the 3rd point for the triangle:");
   scanf("%d%d", &x3, &y3);
   TriAngle(x1, y1, x2, y2, x3, y3);
   getch();
   //cleardevice();
   Rotate(x1, y1, x2, y2, x3, y3);
   //setcolor(1);
   TriAngle(x1, y1, x2, y2, x3, y3);
   getch();
}
void TriAngle(int x1, int y1, int x2, int y2, int x3, int y3) {
   line(x1, y1, x2, y2);
   line(x2, y2, x3, y3);
   line(x3, y3, x1, y1);
}

void Rotate(int x1, int y1, int x2, int y2, int x3, int y3) {
   int x, y, a1, b1, a2, b2, a3, b3, p = x2, q = y2;
   float Angle;
   printf("Enter the angle for rotation:");
   scanf("%f", &Angle);
   //cleardevice();
   Angle = (Angle * 3.14) / 180;
   a1 = p + (x1 - p) * cos(Angle)-(y1 - q) * sin(Angle);
   b1 = q + (x1 - p) * sin(Angle)+(y1 - q) * cos(Angle);
   a2 = p + (x2 - p) * cos(Angle)-(y2 - q) * sin(Angle);
   b2 = q + (x2 - p) * sin(Angle)+(y2 - q) * cos(Angle);
   a3 = p + (x3 - p) * cos(Angle)-(y3 - q) * sin(Angle);
   b3 = q + (x3 - p) * sin(Angle)+(y3 - q) * cos(Angle);
   printf("Rotate");
   TriAngle(a1, b1, a2, b2, a3, b3);
   getch();
}

//****************Rotation Function End****************//


//****************Scaling Function Start****************//
void Scaling()
{
    int x[] = { 100, 200, 300 }; 
	int y[] = { 200, 100, 200 }; 
	int sx = 2, sy = 2; 

	int gd, gm; 
	initgraph(&gd, &gm," "); 

	scale(x, y, sx,sy); 
	getch();
	
}
void findNewCoordinate(int s[][2], int p[][1]) 
{ 
	int temp[2][1] = { 0 }; 

	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 1; j++) 
			for (int k = 0; k < 2; k++) 
				temp[i][j] += (s[i][k] * p[k][j]); 

	p[0][0] = temp[0][0]; 
	p[1][0] = temp[1][0]; 
} 
void scale(int x[], int y[], int sx, int sy) 
{ 
	// Triangle before Scaling 
	line(x[0], y[0], x[1], y[1]); 
	line(x[1], y[1], x[2], y[2]); 
	line(x[2], y[2], x[0], y[0]); 

	// Initializing the Scaling Matrix. 
	int s[2][2] = { sx, 0, 0, sy }; 
	int p[2][1]; 

	// Scaling the triangle 
	for (int i = 0; i < 3; i++) 
	{ 
		p[0][0] = x[i]; 
		p[1][0] = y[i]; 

		findNewCoordinate(s, p); 

		x[i] = p[0][0]; 
		y[i] = p[1][0]; 
	} 

	// Triangle after Scaling 
	line(x[0], y[0], x[1], y[1]); 
	line(x[1], y[1], x[2], y[2]); 
	line(x[2], y[2], x[0], y[0]); 
}

//****************Scaling Function End****************//


//****************Reflection Function Start****************//

int graDriver=DETECT,graMode;
int n,xs[100],ys[100],i;
int tempYaxis,tempXaxis;
void Reflection()
{
	printf("Enter number of sides: ");
	scanf("%d",&n);
	printf("Enter co-rdinates: x,y for each point ");
	for(i=0;i<n;i++)
    scanf("%d%d",&xs[i],&ys[i]);	
	initgraph(&graDriver,&graMode,"");
	setcolor(RED);
	DrawFn();//original
	FlipV();
	setcolor(BLUE);
	DrawFn();//vertical flip
	FlipH();
	setcolor(GREEN);
	DrawFn();//Horizontal flip
	getch();
	
}

void DrawFn()
{
	for(i=0;i<n;i++)
     line(xs[i],ys[i],xs[(i+1)%n],ys[(i+1)%n]);
}

void FlipV()
{
	tempXaxis=getmaxy()/2;
	for(i=0;i<n;i++)
	 ys[i]=tempXaxis+(tempXaxis-ys[i]);
	//drawing horizontal axis to flip about
	
	for(i=0;i<getmaxx();i++)
	 putpixel(i,tempXaxis,WHITE);
}

void FlipH()
{
	tempYaxis=getmaxx()/2;
	for(i=0;i<n;i++)
	 xs[i]=tempYaxis+(tempYaxis-xs[i]);
	setcolor(WHITE);
	//drawing vertical axis
	for(i=0;i<getmaxy();i++)
	 putpixel(tempYaxis,i,WHITE);

}

//****************Reflection Function End****************//

