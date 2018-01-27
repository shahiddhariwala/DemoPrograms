import java.util.*;
//Substitution Cryptography 
//for example, input : abc key: 7 ;; output hij  a>>7 = h; b>>7 = i etc;;;
public class Substitution {

	private static char cts[];

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int temp;
		
		System.out.println("Enter Input String :\n");
		String inpu = sc.nextLine();
		String outpu;
		int charvr;
		char pt[]= inpu.toCharArray();
		System.out.println("Enter the key:\n");
		int key =  sc.nextInt();
		System.out.println("Text is \t"+new String (pt));
		cts = new char[pt.length];
		System.out.println("Menu:: \t  1)Encrypt \t 2)Decrypt ::\n");
		int opt = sc.nextInt();
		switch(opt)
		{
		case 1:
			for(int i=0;i<pt.length;i++)
			{
				charvr= (int)pt[i];
				temp= charvr+key;
				if(temp > 122 || (temp > 90 && temp < 97))
				{
					temp= charvr-(26-key);
				}
				cts[i] = (char)temp;
			}
			System.out.println("Cipher Text is : \t");
			System.out.println(cts);
			break;
		case 2:
			for(int i=0;i<pt.length;i++)
			{
				charvr= (int)pt[i];
				temp= charvr-key;
				if(temp < 65 || (temp > 90 && temp < 97))
				{
					temp= charvr+(26-key);
				}
				cts[i] = (char)temp;
			}
			System.out.println("Plain Text is : \t");
			System.out.println(cts);
		

	}

}
}