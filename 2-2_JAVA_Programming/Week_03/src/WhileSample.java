import java.util.Scanner;
public class WhileSample {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int n, sum1 = 0, cnt = 0;
		double avg1;
		System.out.println("정수를 입력하고 마지막에 -1을 입력하세요.");
		n = scanner.nextInt();
		
		while(n != -1) {
			cnt++;
			sum1 += n;
			n = scanner.nextInt();
		}
		avg1 = sum1 / cnt;
		System.out.printf("정수의 개수는 %d개이며 평균은 %.1f입니다.", cnt, avg1);
	
		scanner.close();
	}

}
