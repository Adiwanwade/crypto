import java.util.*;
import java.math.BigInteger;

public class RSA {
    public static int gcd(int a, int b) {
        BigInteger big1 = new BigInteger(Integer.toString(a));
        BigInteger big2 = new BigInteger(Integer.toString(b));
        BigInteger bigVal = big1.gcd(big2);
        return bigVal.intValue();
    }

    public static BigInteger RSA_Encrypt(BigInteger M, int e, int n) {
        return M.modPow(BigInteger.valueOf(e), BigInteger.valueOf(n));
    }

    public static BigInteger RSA_Decrypt(BigInteger C, int d, int n) {
        return C.modPow(BigInteger.valueOf(d), BigInteger.valueOf(n));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of p:");
        int p = sc.nextInt();
        System.out.println("Enter the value of q:");
        int q = sc.nextInt();
        int n = p * q;
        int phi = (p - 1) * (q - 1);
        int e = 1, d = 1;

        for (int i = 2; i < phi; i++) {
            if (gcd(i, phi) == 1) {
                e = i;
                break;
            }
        }

        for (int i = 1; i < phi; i++) {
            if (((i * e) % phi) == 1) {
                d = i;
                break;
            }
        }

        System.out.println("Enter the value of M:");
        double M = sc.nextDouble();
        BigInteger MInt = BigInteger.valueOf((int) M);

        BigInteger C = RSA_Encrypt(MInt, e, n);
        System.out.println("Encrypted C: " + C);

        BigInteger M1 = RSA_Decrypt(C, d, n);
        System.out.println("Decrypted M: " + M1);
    }
}
