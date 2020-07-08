#include<stdio.h>
#include<conio.h>
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define NO_HUE -1
void rgbtohsv(float r,float g,float b)
{
  float h,s,v;
  float max=MAX(r,MAX(g,b)),min=MIN(r,MIN(g,b));
  float delta=max-min;
  v=max;
  if(max!=0.0)
    s=delta/max;
  else
    s=0.0;
  if(s==0.0)
    h=NO_HUE;
  else
  {
   if(r==max)
     h=(g-b)/delta;
   else if(g==max)
     h=2+(b-r)/delta;
   else if(b==max)
     h=4+(r-g)/delta;
   h*=60.0;
   if(h<0)
     h+=360.0;
   h/=360.0;
  }
  printf("\n H=%f\n S=%f\n V=%f",h,s,v);
}
int main()
{
  float a,b,c;

  printf("\n Enter the RGB values:\n");
  scanf("%f%f%f",&a,&b,&c);
  printf("\nThe HSV values:\n");
  rgbtohsv(a,b,c);
}
