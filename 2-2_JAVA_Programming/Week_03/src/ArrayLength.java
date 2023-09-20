import java.util.Scanner;

public class ArrayLength {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int array[], sum = 0;
		double avg = 0;
		array = new int[5];
		
		System.out.print("5개의 정수를 입력하시오. ");
		
		for(int i=0;i<array.length;i++) {
			array[i] = scanner.nextInt();
			sum += array[i];
		}			
		avg = (double) sum/array.length;
		System.out.printf("avg is %.1f", avg);
		
		scanner.close();
	}
}
