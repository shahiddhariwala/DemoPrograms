import java.util.*;

public class Sorting {
	private static Scanner sc;

	public static void main(String args[]) {
		sc = new Scanner(System.in);
		int z;
		System.out.println("Enter the Number of Elements : \n");
		int num = sc.nextInt();
		System.out.println("Enter the Elements :\n");

		int a[] = new int[num+1];
		for (int i = 0; i < num; i++) {
			a[i] = sc.nextInt();
		}
		for (int m = 0; m < num; m++)
			for (int n =0; n < num; n++) {
				if (a[n]<a[n + 1]) {
					int temp = a[n];
					a[n] = a[n + 1];
					a[n + 1] = temp;
				}
			}
		for (z = 0; z < num; z++) {
			System.out.println(a[z]);
		}

	}
}
