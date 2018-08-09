import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        BigInteger a=BigInteger.ONE;
        int n=sc.nextInt();
        int k=sc.nextInt();
        for(int i=1;i<=n;i++)
        {
            a=a.multiply(BigInteger.valueOf(i));
        }
        BigInteger ans=BigInteger.ZERO;
        while(a.compareTo(BigInteger.ZERO)==1)
        {
            ans=ans.add(a.mod(BigInteger.valueOf(k)));
            a=a.divide(BigInteger.valueOf(k));
        }
        System.out.println(ans);
    }
}