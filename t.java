import java.math.BigInteger;

public class t {

    public static void main(String[] args) {
        BigInteger bi = BigInteger.ONE;
        for (int i = 1; i < 1000; i++) {
            bi = bi.multiply(BigInteger.valueOf(i));
        }
        System.out.println(bi);
    }
}