import java.util.Scanner;

public class GameEx {

	public static void main(String[] args) {
		int com, user;
		int counts = 0, wins = 0;
		
		final int scissors = 1;
		final int rock = 2;
		final int paper = 3;
		
		Scanner scanner = new Scanner(System.in);
		
		while(true) {
			System.out.print("Input Scissors(1), rock(2), paper(3) : ");
			user = scanner.nextInt();
			
			if(user != scissors && user != rock && user != paper)
				break;
			
			counts++;
			
			com = (int)(Math.random()*3 + 1);
			
			if(com == user)
				System.out.println("Draw!");
			else if ((user == 1 && com == 3)||(user == 2 && com == 1)||(user == 3 && com == 2)) {
				wins++;
				System.out.println("User Win!!");
			}
			else
				System.out.println("Com Win!!");
		}
		
		System.out.printf("In %d games %d times win.", counts, wins);
		
		scanner.close();
	}

}
