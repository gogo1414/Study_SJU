import java.util.Scanner;

public class BookArray {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Book [] b = new Book[1];
		
		for(int i=0; i<b.length;i++) {
			System.out.print("Title : ");
			String title = scanner.nextLine();
			System.out.print("Author : ");
			String author = scanner.nextLine();
			b[i] = new Book(title, author);
		}
		
		for(int i=0;i<b.length;i++)
			b[i].show();
		scanner.close();
	}

}
