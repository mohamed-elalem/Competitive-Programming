import java.util.Scanner;
import java.math.BigInteger;
public class Main {

    public static void main(String [] args) {
	Scanner scan = new Scanner(System.in);

	for(int i = 0; i < 10; i++) {
	    BigInteger total = scan.nextBigInteger();
	    BigInteger diff = scan.nextBigInteger();
	    BigInteger natalia = total.divide(BigInteger.valueOf(2)).subtract(diff.divide(BigInteger.valueOf(2)));
	    BigInteger klaudia = natalia.add(diff);
	    System.out.println(klaudia + "\n" + natalia);
	}
    }
}
