//Bezier Curve for 'N' control Points
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>
int fact(int x)
{
	if(x==0)
		return 1;
	else
		return x*fact(x-1);
}
void Bezier(int x[100],int y[100],int ctr_point)
{
	int i,n=ctr_point-1,coeff[100];
	double u,xt,yt,blend,u1,u2;
	//coefficient
	for(i=0;i<=n;i++)
	{
		coeff[i]=fact(n)/(fact(i)*fact(n-i));
	}
	//blend function
	for(u=0.0;u<=1;u+=0.0005)
	{
		xt=0.0;
		yt=0.0;
		for(i=0;i<=n;i++)
		{
			if(i==0)
			{
				u1=1;
			}
			else
			{
				u1=pow(u,i);
			}
			u2=pow(1-u,n-i);
			blend=coeff[i]*u1*u2;

			xt+=blend*x[i];
			yt+=blend*y[i];
		}
		putpixel(xt,yt,12);
	}
	for(i=0;i<ctr_point;i++)
		putpixel(x[i],y[i],RED);
}
void main()
{
	int gd=DETECT,gm,n,i,x[100],y[100];
	initgraph(&gd,&gm,"C://Turboc3/BGI");
	clrscr();
	clearviewport();
	printf("Enter the Number of Control points \n");
	scanf("%d",&n);
	printf("Enter the Control Points :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	Bezier(x,y,n);
	getch();
	closegraph();
}

//Shahid Dhariwala
//RollNo 33