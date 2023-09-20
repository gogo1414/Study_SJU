import java.util.Scanner;
public class NesteddIf {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int score, year;
		System.out.println("점수를 입력하세요(0~100):");
		score = scanner.nextInt();
		System.out.println("학년을 입력하세요(1~4):");
		year = scanner.nextInt();
		
		if(year == 4) {
			if(score >= 70) System.out.println("합격");
			else System.out.println("불합격");
		}
		else {
			if(score >= 60) System.out.println("합격");
			else System.out.println("불합격");
		}
		
		scanner.close();
	}

}
