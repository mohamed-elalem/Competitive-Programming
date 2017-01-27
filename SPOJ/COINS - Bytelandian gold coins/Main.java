import java.util.Scanner;
import java.util.HashMap;

public class Main {
    private static HashMap<Long, Long> memo;
    
    public static void main(String [] args) {
	Scanner scan = new Scanner(System.in);
	memo = new HashMap<>();
	while(scan.hasNext()) {
	    long n = scan.nextLong();
	    System.out.println(maxCoins(n));
	}
    }

    public static long maxCoins(long coins) {
	if(coins == 0)
	    return 0;
	if(memo.get(coins) != null) {
	    return memo.get(coins);
	}
	memo.put(coins, Math.max(coins, maxCoins(coins / 2) + maxCoins(coins / 3) + maxCoins(coins / 4)));
	return memo.get(coins);
    }
}
