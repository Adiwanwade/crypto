import java.math.BigInteger;
import java.util.Scanner;

public class ElGamal {
  

    public static BigInteger[] ElGamal_Encrypt(BigInteger M,int e1, int r, int p,int d) {
        BigInteger S1=BigInteger.valueOf(e1).modPow(BigInteger.valueOf(r), BigInteger.valueOf(p));
        BigInteger RInv=BigInteger.valueOf(r).modInverse(BigInteger.valueOf(p-1));
        BigInteger S2=(((M.subtract((BigInteger.valueOf(d).multiply(S1)))).multiply(RInv))).mod(BigInteger.valueOf(p-1));
        BigInteger[] arr={M,S1,S2};
        return arr;
    }

    public static BigInteger[] ElGamal_Decrypt(BigInteger M,int e1, BigInteger e2 ,int p , BigInteger S1,BigInteger S2) {
        BigInteger V1=BigInteger.valueOf(e1).modPow(M, BigInteger.valueOf(p));
        BigInteger V2=(e2.modPow(S1,BigInteger.valueOf(p))).multiply(S1.modPow(S2, BigInteger.valueOf(p))).mod(BigInteger.valueOf(p));
        BigInteger[]verify={V1,V2};
        return verify;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of p:");
        int p = sc.nextInt();
        System.out.println("Enter the value of e1:");
        int e1 = sc.nextInt();
        System.out.println("Enter the value of d:");
        int d = sc.nextInt();
        BigInteger e2 = BigInteger.valueOf(e1).modPow(BigInteger.valueOf(d), BigInteger.valueOf(p));
        System.out.println("The value of e2:"+e2);
        System.out.println("Enter the value of r:");
        int r = sc.nextInt();
        System.out.println("The value of e1,e2,p: "+e1+" "+e2+" "+p);

        

        System.out.println("Enter the value of M:");
        int M = sc.nextInt();
        BigInteger MInt = BigInteger.valueOf(M);

        BigInteger digi[] = ElGamal_Encrypt(MInt, e1,r, p,d);
        System.out.println("Digital Signature:(S1,S2):(" +digi[1]+","+digi[2]+")" );

        BigInteger verify[] = ElGamal_Decrypt(MInt, e1,e2,p, digi[1],digi[2]);
        System.out.println("Decrypted :(V1,V2): " + verify[0]+" "+verify[1] );
        if(verify[0].equals(verify[1])){
            System.out.println("They are congruent");
        }
        else{
            System.out.println("They are not congruent");
        }
        sc.close();
    }
}
