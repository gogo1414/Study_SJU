import java.util.Scanner;

public class ScannerEx {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("introduce yourself");
		
		String name = scanner.next();
		System.out.println("name is " + name);
		
		int age = scanner.nextInt();
		System.out.println("age is " + age);
		
		double weight = scanner.nextDouble();
		System.out.println("weight is " + weight);
		
		boolean single = scanner.nextBoolean();
		System.out.println("single is " +single);
		
		scanner.close();
	
	}

}
