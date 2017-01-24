import java.util.Scanner;

public class Main {

    public static void main(String [] args) {
	Scanner scan = new Scanner(System.in);

	while(true) {
	    int n = scan.nextInt();
	    if(n == 0) {
		break;
	    }
	    String msg = scan.next();
	    int m = msg.length() / n;
	    int padding = Math.max(n, m);
	    for(int j = 0; j < n; j++) {
		for(int i = 0; i < m; i++) {
		    if(i % 2 == 0) {
			System.out.print(msg.charAt(i * n + j));
		    } else {
			System.out.print(msg.charAt(i * n + (n - j - 1)));
		    }
		}
	    }
	    System.out.println();
	}
    }
}
