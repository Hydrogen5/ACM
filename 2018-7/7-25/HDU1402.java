//A * B Problem Plus
//bigInteger’Ê «Ã´∞Ù¡À
import java.math.BigInteger;
import java.util.Scanner;
class Main{
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext()){
            BigInteger m,n;
            m=cin.nextBigInteger();
            n=cin.nextBigInteger();
            System.out.println(m.multiply(n));
        }
    }
}