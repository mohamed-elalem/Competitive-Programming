import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
	Scanner scan = new Scanner(System.in);
	int t = scan.nextInt();

	while(t-- > 0) {
	    int a = scan.nextInt();
	    int b = scan.nextInt();

	    System.out.println(reverseAndParse(reverseAndParse(a) + reverseAndParse(b)));
	}
    }

    public static int reverseAndParse(int num) {
	return Integer.parseInt(new StringBuilder(Integer.toString(num)).reverse().toString());
    }
}
