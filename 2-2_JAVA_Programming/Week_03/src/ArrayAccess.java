import java.util.Scanner;

public class ArrayAccess {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int array[], max = 0;
		
		array = new int[5];
		
		System.out.print("input 5 numbers : ");
		
		for(int i=0;i<5;i++) {
			array[i] = scanner.nextInt();
			if(max < array[i])
				max = array[i];
		}
		
		System.out.printf("biggest number is %d", max);
		
		scanner.close();
	}

}
