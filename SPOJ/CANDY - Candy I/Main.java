import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
	Scanner scan = new Scanner(System.in);
	int n;
	while(true) {
	    n = scan.nextInt();
	    if(n == -1)
		break;
	    int [] candies = new int[n];
	    int sum = 0;
	    for(int i = 0; i < n; i++) {
		candies[i] = scan.nextInt();
		sum += candies[i];
	    }

	    int avg = (sum / n);
	    if(sum % n != 0) {
		System.out.println(-1);
	    } else {
		int moves = 0;
		for(int i = 0; i < n; i++) {
		    if(avg > candies[i]) {
			moves += (avg - candies[i]);
		    }
		}
		System.out.println(moves);
	    }
	}
    }
}
