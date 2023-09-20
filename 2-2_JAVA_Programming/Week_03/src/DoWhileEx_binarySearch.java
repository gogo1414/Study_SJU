import java.util.Scanner;

public class DoWhileEx_binarySearch {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int answer, guess, tries = 0;
		
		System.out.println("Guess the answer(1 ~ 100) : ");
		
		answer = (int)(Math.random() * 100 + 1);
		
		do {
			guess = scanner.nextInt();
			tries++;
			if(guess < answer)
				System.out.println("Higher than your answer.");
			else if (guess > answer)
				System.out.println("Lower than your answer.");
		}while(guess != answer);
		
		System.out.printf("You correct Answer %d in %d times.", guess, tries);
		scanner.close();
	}

}
