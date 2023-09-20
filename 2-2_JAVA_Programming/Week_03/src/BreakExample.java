import java.util.Scanner;

public class BreakExample {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String ch;
		
		System.out.println("exit을 입력하면 종료합니다.");
		
		while (true) {
			ch = scanner.nextLine();
			if(ch.equals("exit"))
				break;
		}
		System.out.println("종료합니다.");
		
		scanner.close();
	}

}
