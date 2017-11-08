#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define MAX 30
void matrix_mul();
void translation();
void rotation_s();
void rotation_f();
void reflection_x();
void reflection_y();
void reflection_o();
void reflection_l();
void scale_o();
void scale_f();
void shearx();
void sheary();

float co_m[MAX][3];
float mat[MAX][3];
float res[MAX][3];
int n;
void main()
{
	int gd = DETECT, gm;
	int i, j, ch,xh;
	initgraph(&gd, &gm, "..//bgi");
	line(0,240,640,240);
	line(320,0,320,480);
	printf("Enter the number of co-ordinates: ");
	scanf("%d",&n);
	printf("Enter coordinates for: \n");
	for(i=0;i<n;i++)
	{
		printf("Point %d",i+1);
		for(j=0;j<2;j++)
			scanf("%f",&co_m[i][j]);
		co_m[i][2]=1;
	}
	for(i=0;i<n-1;i++)
		line(320+co_m[i][0],240-co_m[i][1],320+co_m[i+1][0],240-co_m[i+1][1]);
	line(320+co_m[0][0],240-co_m[0][1],320+co_m[n-1][0],240-co_m[n-1][1]);
	printf("1. Translation\n2. Simple Rotation\n3. Fixed Point Rotation\n4.Simple Scale\n5.Fixed Point Scaling\n6.Reflection\n7.Shear\n8.exit\n");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:
		translation();
		matrix_mul();
		break;
		case 2:
		rotation_s();
		matrix_mul();
		break;
		case 3:
		rotation_f();
		matrix_mul();
		break;
		case 4:
		scale_o();
		matrix_mul();
		break;
		case 5:
		scale_f();
		matrix_mul();
		break;
		case 6:
		printf("About 1.X-Axis\n2.Y-Axis\n3.Origin\n4.Line\n");
		scanf("%d",&xh);
		switch(xh)
		{
			case 1:
			reflection_x();
			matrix_mul();
			break;
			case 2:
			reflection_y();
			matrix_mul();
			break;
			case 3:
			reflection_o();
			matrix_mul();
			break;
			case 4:
			reflection_l();
			matrix_mul();
			break;
			default:
			printf("Invalid Option");
			ch=5;
			break;
		}
		break;
		case 7:
		printf("1.X Shear\n2.Y Shear\n");
		scanf("%d",&xh);
		switch(xh)
		{
			case 1:
			shearx();
			matrix_mul();
			break;
			case 2:
			sheary();
			matrix_mul();
			break;
		}
		break;
	}
	for(i=0;i<n-1;i++)
		line(320+res[i][0],240-res[i][1],320+res[i+1][0],240-res[i+1][1]);
	line(320+res[0][0],240-res[0][1],320+res[n-1][0],240-res[n-1][1]);
	getch();
	closegraph();
}

void translation()

{
	int i;
	float tx, ty;
	printf("Enter tx and ty: ");
	scanf("%f%f", &tx, &ty);
	for(i=0;i<3;i++)
		mat[i][i]=1;
	mat[2][0]=tx;
	mat[2][1]=ty;

}

void rotation_s()

{
	int i, j;
	float t;
	printf("Enter theta");
	scanf("%f", &t);
	t=(t*3.14)/180;
	mat[0][0]=cos(t);
	mat[0][1]=sin(t);
	mat[1][0]=-sin(t);
	mat[1][1]=cos(t);
	mat[2][2]=1;
}
void rotation_f()
{
	int i, j;
	float t;
	printf("Enter theta");
	scanf("%f", &t);
	t=(t*3.14)/180;
	mat[0][0]=cos(t);
	mat[0][1]=sin(t);
	mat[1][0]=-sin(t);
	mat[1][1]=cos(t);
	mat[2][0]=co_m[0][0]*(1-cos(t))+co_m[0][1]*sin(t);
	mat[2][1]=co_m[0][1]*(1-cos(t))-co_m[0][0]*sin(t);
	mat[2][2]=1;
}

void reflection_x()
{
	mat[0][0]=1;
	mat[1][1]=-1;
	mat[2][2]=1;
}

void reflection_y()
{
	mat[0][0]=-1;
	mat[1][1]=1;
	mat[2][2]=1;
}

void reflection_o()
{
	mat[0][0]=-1;
	mat[1][1]=-1;
	mat[2][2]=1;
}
void reflection_l()
{
	mat[0][1]=1;
	mat[1][0]=1;
	mat[2][2]=1;
}
void scale_o()
{
	int sx,sy;
	printf("Enter Sx and Sy\n");
	scanf("%d%d",&sx,&sy);
	mat[0][0]=sx;
	mat[1][1]=sy;
	mat[2][2]=1;
}
void scale_f()

{
	int sx,sy;
	printf("enter sx and sy:");
	scanf("%d%d",&sx,&sy);
	mat[0][0]=sx;
	mat[1][1]=sy;
	mat[2][0]=(-co_m[0][0]*sx)+co_m[0][0];
	mat[2][1]=(-co_m[0][1]*sy)+co_m[0][1];
	mat[2][2]=1;
}
void shearx()
{
int sh;
printf("Enter the Shearing Factor\n");
scanf("%d",&sh);
mat[0][0]=1;
mat[1][0]=sh;
mat[1][1]=1;
mat[2][2]=1;
}
void sheary()
{
int sh;
printf("Enter the Shearing Factor\n");
scanf("%d",&sh);
mat[0][0]=1;
mat[0][1]=sh;
mat[1][1]=1;
mat[2][2]=1;
}
void matrix_mul()
{
	int i, j, k;
	float sum;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			sum=0;
			for(k=0;k<3;k++)
			{
				sum+=co_m[i][k]*mat[k][j];
			}
			res[i][j]=sum;
		}
	}
}

