
public class ForSample {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int sum1 = 0;
		
		for(int i=1;i<=10;i++) {
			sum1 += i;
			System.out.printf("%d", i);
			if(i == 10) {
				System.out.printf("=%d\n", sum1);
				break;
			}
			System.out.print("+");
		}
		
	}

}
