//A * B Problem Plus
//bigInteger’Ê «Ã´∞Ù¡À
import java.math.BigInteger;
import java.util.Scanner;
class Main{
    public static void main(String[] args) {
        Scanner read=new Scanner(System.in);
        while(read.hasNext()){
            BigInteger m,n;
            m=read.nextBigInteger();
            n=read.nextBigInteger();
            System.out.println(m.multiply(n));
            read.close();
        }
    }
}