import java.util.Scanner;
public class AssignmentlncDecOperator {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int a = 3, b = 3, c = 3;
		
		a +=3;
		b *= 3;
		c %= 2;
		System.out.println(" a = " + a + " b = " + b + " c = " + c);
		
		int d = 3;
		
		a = d++;
		System.out.println("a = " + a + " d = " + d);
		a = ++d;
		System.out.println("a = " + a + " d = " + d);
		a = d--;
		System.out.println("a = " + a + " d = " + d);
		a = --d;
		System.out.println("a = " + a + " d = " + d);
		
		scanner.close();
	}

}
