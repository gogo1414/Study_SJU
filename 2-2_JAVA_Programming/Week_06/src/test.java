import java.util.Scanner;

class math {
//	public void math() {}
	int plus(int a, int b) {
		return a+b;
	}
	int minus(int a, int b) {
		return a > b ? a-b : b-a;
	}
}

public class test {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		math c = new math();
		Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		System.out.println(c.plus(a,b));
		scanner.close();
	}

}
