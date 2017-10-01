import java.util.Vector;
class Vect
 {
   public static void main(String args[])
     {
       Vector<Integer> vct = new Vector<Integer>(3,2);
       vct.add(1);
       vct.add(2);
       vct.add(4);
       vct.add(5);
       vct.add(2,10);
       System.out.println();
       System.out.println(" Size is "+vct.size());
       System.out.println(" capacity is "+vct.capacity());
       System.out.println("First element is "+vct.firstElement());
       System.out.println("Last element is "+vct.lastElement());
       System.out.println(vct);
       System.out.println();
       vct.removeAllElements();
       System.out.println(" Size is "+vct.size());
       System.out.println(" capacity is "+vct.capacity());

    }
}
/* output
Now Size is 5
Now capacity is 5
First element is 1
Last element is 5
[1, 2, 10, 4, 5]

Now Size is 0
Now capacity is 5
*/




//Welcome To Shahid Dhariwala's Programming World