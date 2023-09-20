import java.util.Scanner;

public class SuccessOrFail {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int grade;
		
		System.out.println("점수를 입력하시오 : ");
		
		grade = scanner.nextInt();
		
		if(grade >= 80)
			System.out.println("축하합니다, 합격입니다.");
		else
			System.out.println("불합격입니다.");
		
		scanner.close();
	}

}
