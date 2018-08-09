import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	private static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);
		long n=in.nextLong();
		Main m =new Main();
		BigInteger res =m.fib(n);
		System.out.print((res.divideAndRemainder(new BigInteger("10000")))[1]);
	}
	BigInteger fib(long n){
		 if(n==1 || n==2){
			 return BigInteger.ONE;
		 }else{
			 BigInteger pnum=BigInteger.ONE;
			 BigInteger cnum=BigInteger.ONE;
			 for(int i=3;i<=n;i++){
				 cnum= cnum.add(pnum);
				 pnum =cnum.subtract(pnum);
			 }
			 return cnum;
		 }
	}
}