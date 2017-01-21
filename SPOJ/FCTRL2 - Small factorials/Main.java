import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String [] args) {
	Scanner scan = new Scanner(System.in);
	BigInteger [] fact = new BigInteger[101];
	fact[0] = new BigInteger("1");
	fact[1] = new BigInteger("1");
	for(int i = 2; i <= 100; i++) {
	    fact[i] = new BigInteger(BigInteger.valueOf(i).multiply(fact[i - 1]).toString());
	}

	int t = scan.nextInt();

	while(t-- > 0) {
	    int n = scan.nextInt();

	    System.out.println(fact[n]);
	}
    }
}
