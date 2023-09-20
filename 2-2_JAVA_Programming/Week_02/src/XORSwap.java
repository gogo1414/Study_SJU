import java.util.Scanner;

public class XORSwap {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Input two digit : ");
		int x = scanner.nextInt();
		int y = scanner.nextInt();
		
		System.out.println("x = " + x + " y = " + y);
		
		x ^= y;
		y ^= x;
		x ^= y;
		
		System.out.println("x = " + x + " y = " + y);
		
		scanner.close();
	}

}
