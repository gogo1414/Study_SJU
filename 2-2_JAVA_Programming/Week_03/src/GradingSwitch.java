import java.util.Scanner;
public class GradingSwitch {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int score;
		char grade;
		System.out.print("점수를 입력하세요(0~100):");
		score = scanner.nextInt();
		
		switch(score/10) {
			case 10: 
				grade = 'A';
				break;
			case 9: 
				grade = 'A'; 
				break;
			case 8:
				grade = 'B';
				break;
			case 7:
				grade = 'C';
				break;
			case 6:
				grade = 'D';
				break;
			default:
				grade = 'F';
		}
		System.out.printf("학점은 %c 입니다.\n", grade);
		
		scanner.close();
	}

}
