import java.math.BigInteger;
import java.util.*;

public class SHA512 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the message size:");
        int mSize = sc.nextInt();
        BigInteger P = (BigInteger.valueOf(-1 * mSize).subtract(BigInteger.valueOf(128))).mod(BigInteger.valueOf(1024));
        System.out.println("The padding consists of one 1 followed by " + P.subtract(BigInteger.valueOf(1)) + " 0's");
        int[] a = new int[4];
        int[] b = new int[4];
        int[] c = new int[4];
        int[] result = new int[4];
        System.out.println("Enter the binary digits of buffer A:");
        for (int i = 0; i < 4; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println("Enter the binary digits of buffer B:");
        for (int i = 0; i < 4; i++) {
            b[i] = sc.nextInt();
        }
        System.out.println("Enter the binary digits of buffer C:");
        for (int i = 0; i < 4; i++) {
            c[i] = sc.nextInt();
        }
        for (int i = 0; i < 4; i++) {
            result[i] = ((a[i] & b[i]) ^ (b[i] & c[i]) ^ (c[i] & a[i]));
        }
        System.out.print("The result of Majority function is: ");
        for (int i = 0; i < 4; i++) {
            System.out.print(result[i] + " ");
        }
        System.out.println();
        int[] e = new int[4];
        int[] f = new int[4];
        int[] g = new int[4];
        int[] result1 = new int[4];
        System.out.println("Enter the binary digits of buffer E:");
        for (int i = 0; i < 4; i++) {
            e[i] = sc.nextInt();
        }
        System.out.println("Enter the binary digits of buffer F:");
        for (int i = 0; i < 4; i++) {
            f[i] = sc.nextInt();
        }
        System.out.println("Enter the binary digits of buffer G:");
        for (int i = 0; i < 4; i++) {
            g[i] = sc.nextInt();
        }
        for (int i = 0; i < 4; i++) {
            result1[i] = ((e[i] & f[i]) ^ ((~(e[i]) & g[i])));
        }
        System.out.print("The result of Conditional function is: ");
        for (int i = 0; i < 4; i++) {
            System.out.print(result1[i] + " ");
        }
        sc.close();
    }
}