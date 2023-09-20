import java.util.Scanner;

public class ArithmeticOperator {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("input int data.");
		int time = scanner.nextInt();
		int second = time%60;
		int minute = (time/60)%60;
		int hour = (time/60)/60;
		
		System.out.println("second : " + second);
		System.out.println("minute : " + minute);
		System.out.println("hour : " + hour);
		System.out.println("time : " + time);
		
		scanner.close();
	}
}
