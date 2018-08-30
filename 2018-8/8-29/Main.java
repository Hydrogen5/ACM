//E
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        BigInteger[] a = new BigInteger[10010];
        a[1] = BigInteger.ONE;
        a[2] = BigInteger.valueOf(3);
        for (int i = 3; i <= 10000; i++) {
            a[i] = a[i - 1].add(a[i - 2]);
        }
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            System.out.println(a[n]);
        }
    }
}