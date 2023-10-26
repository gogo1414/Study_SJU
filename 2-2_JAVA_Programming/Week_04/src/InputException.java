import java.util.Scanner;
import java.util.InputMismatchException;

public class InputException {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Input 3 disits : ");
		int sum = 0, n = 0;
		
		for(int i=0;i<3;i++) {
			System.out.print(i+1 + " >> ");
			
			try {
				n = scanner.nextInt();
			} 
			catch (InputMismatchException error) 
			{
				System.out.println("Not a digit.Input again.");
				System.out.println(error);
				scanner.nextLine(); 
				// nextLine() 안할 시 위의 에러 구문 반복 출력
				i--;
				continue;
			}
			sum += n;
		}
		System.out.println("sum = " + sum);
		scanner.close();
		
	}

}
