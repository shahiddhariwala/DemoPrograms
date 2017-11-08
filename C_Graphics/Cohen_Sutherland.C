#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
int gd=DETECT, gm;
float i,xmax,ymax,xmin,ymin,x1,y1,x2,y2,m;
float begin1[4],end1[4],code[4];
clrscr();
initgraph(&gd,&gm,"c://turboc3//bgi");
printf("\n\tPlease enter the bottom left co-ordinate of viewport: ");
scanf("%f %f",&xmin,&ymin);
printf("\n\tPlease enter the top right co-ordinate of viewport: ");
scanf("%f %f",&xmax,&ymax);
printf("\nPlease enter the co-ordinates for starting point of line: ");
scanf("%f %f",&x1,&y1);
printf("\nPlease enter the co-ordinates for ending point of line: ");
scanf("%f %f",&x2,&y2);
for(i=0;i <4;i++)
{
begin1[i]=0;
end1[i]=0;
}
m=(y2-y1)/(x2-x1);

if(x1 <xmin) begin1[0]=1;
if(x1 >xmax) begin1[1]=1;
if(y1 >ymax) begin1[2]=1;
if(y1 <ymin) begin1[3]=1;
if(x2 <xmin) end1[0]=1;
if(x2 >xmax) end1[1]=1;
if(y2 >ymax) end1[2]=1;
if(y2 <ymin) end1[3]=1;
for(i=0;i <4;i++)
code[i]=begin1[i]&&end1[i];
if((code[0]==0)&&(code[1]==0)&&(code[2]==0)&&(code[3]==0))
{
if((begin1[0]==0)&&(begin1[1]==0)&&(begin1[2]==0)&&(begin1[3]==0)&&(end1[0]==0)&&(end1[1]==0)&&(end1[2]==0)&&(end1[3]==0))
{
cleardevice();
    printf("\n\t\tThe line is totally visible\n\t\tand not a clipping candidate");
    rectangle(xmin,ymin,xmax,ymax);
    line(x1,y1,x2,y2);
    getch();
}
else
{
    cleardevice();
    printf("\n\t\tLine is partially visible");
    rectangle(xmin,ymin,xmax,ymax);
    line(x1,y1,x2,y2);
    getch();

if((begin1[2]==1)&&(begin1[3]==0))
{
     x1=x1+(ymin-y1)/m;
     y1=ymin;
}
if((end1[2]==1)&&(end1[3]==0))
{
     x2=x2+(ymin-y2)/m;
     y2=ymin;
}
if((begin1[2]==0)&&(begin1[3]==1))
{
     x1=x1+(ymax-y1)/m;
     y1=ymax;
}
if((end1[2]==0)&&(end1[3]==1))
{
     x2=x2+(ymax-y2)/m;
     y2=ymax;
}
if((begin1[1]==0)&&(begin1[0]==1))
{
     y1=y1+m*(xmin-x1);
     x1=xmin;
}
if((end1[1]==0)&&(end1[0]==1))
{
     y2=y2+m*(xmin-x2);
     x2=xmin;
}
if((begin1[1]==1)&&(begin1[0]==0))
{
     y1=y1+m*(xmax-x1);
     x1=xmax;
}
if((end1[1]==1)&&(end1[0]==0))
{
     y2=y2+m*(xmax-x2);
     x2=xmax;
}

clrscr();
cleardevice();
printf("\n\t\tAfter clippling:");
rectangle(xmin,ymin,xmax,ymax);
line(x1,y1,x2,y2);
getch();
}
}
else
{
    clrscr();
    cleardevice();
    printf("\nLine is invisible");
    rectangle(xmin,ymin,xmax,ymax);
}
getch();
closegraph();
}