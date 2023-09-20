import java.util.Scanner;

public class ContinueExample {

	public static void main(String[] args) {
		int [] n = new int[5];
		int sum = 0;
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("정수를 5개 입력하세요.");
		for(int i=0;i<n.length;i++) {
			n[i] = scanner.nextInt();
			if(n[i] < 0)
				continue;
			else sum+=n[i];
		}
		System.out.println("양수의 합은 "+sum);
		
		scanner.close();
	}

}
