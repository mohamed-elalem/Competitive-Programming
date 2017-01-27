import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
	Scanner scan = new Scanner(System.in);
	int t = scan.nextInt();
	
	while(t-- > 0) {
	    long sum = 0;
	    int n = scan.nextInt();
	    for(int i = 0; i < n; i++) {
		sum = (sum + scan.nextLong()) % n; 
	    }
	    if(sum == 0) {
		System.out.println("YES");
	    }
	    else {
		System.out.println("NO");
	    }
	}
	
    }
}
