import java.util.Scanner;

public class MultipleOfThree {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n;
		
		System.out.print("수를 입력하시오 : ");
		n = scanner.nextInt();
		
		if(n % 3 == 0)
			System.out.println("3의 배수입니다.");
		else
			System.out.printf("%d는 3의 배수가 아닙니다.", n);
		
		scanner.close();
	}

}
