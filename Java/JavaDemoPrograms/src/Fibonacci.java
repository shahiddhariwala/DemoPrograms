import java.util.Scanner;
//Write a program to print fibonacci series.

public class Fibonacci {
	private static Scanner sz;

	public static void main(String args[])
	{
		sz = new Scanner(System.in);
		System.out.print("Enter the Number of Digits Required : ");
		int num = sz.nextInt();
		System.out.print("Fibonacci Series is as follow: \n");
		System.out.print("0 \n1\n");
		int a=0,b=1,c;
		for(int i=0;i<num-2;i++)
		{	
			c=a+b;
			System.out.println(c);
			a=b;
			b=c;
		}
		
	}
}
