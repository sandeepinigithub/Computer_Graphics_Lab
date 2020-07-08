#include<graphics.h>  
#include<conio.h>  
#include<stdio.h>
#include<math.h>

//DDA Circle Logic
void DDA_Circle()
{
	int errorcode,tmp,i=1,rds;
    float st_x,st_y,x1,x2,y1,y2,ep;
    printf("Enter Radius:");
    scanf("%d",&rds);
    while(rds>pow(2,i))
      i++;
    ep=1/pow(2,i);
    x1=rds;  y1=0;
    st_x=rds; st_y=0;
    do
    { x2=x1+(y1*ep);
      y2=y1-(x2*ep);
      putpixel(x2+200,y2+200,10);
      x1=x2;
      y1=y2;
    }while((y1-st_y)<ep || (st_x-x1)>ep);

}
// DDA Line Logic 
void DDA_Line()
{
	float x, y,dx,dy,steps;  
    int x0, x1, y0, y1,i;  
   
    printf("Enter x0, y0 and x1, y1 of line :");
    scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
    dx = (float)(x1 - x0);  
    dy = (float)(y1 - y0);  
    if(dx>=dy)  
           {  
        steps = dx;  
    }  
    else  
           {  
        steps = dy;  
    }  
    dx = dx/steps;  
    dy = dy/steps;  
    x = x0;  
    y = y0;  
    i = 1;  
    while(i<= steps)  
    {  
        putpixel(x, y, BLUE);  
        x += dx;  
        y += dy;  
        i=i+1;  
    }
}

//**********Main Fuction**********  
int main()  
{  
    int gd = DETECT ,gm, i; 
    initgraph(&gd, &gm, "");  
	DDA_Line(); 
    DDA_Circle();
    getch();  
    closegraph();  
    return 0;
}
