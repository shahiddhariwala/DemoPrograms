import java.util.Scanner;

public class Factorial {
	static int fact(int x)
	{
		if(x==0)
			return 1;
		else
			return x*fact(x-1);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println("Enter the Number :\n");
		Scanner sc = new Scanner(System.in);
		int y= sc.nextInt();
		int sum = fact(y);
		System.out.println("Factorial of "+y+" is "+sum);
		

	}

}
