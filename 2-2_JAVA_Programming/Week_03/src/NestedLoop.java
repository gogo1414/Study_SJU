public class NestedLoop {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for(int i=1;i<=9;i++) {
			for(int j=1;j<=9;j++) {
				System.out.printf("%dx%d=%d", j, i, j*i);;
				System.out.print('\t');
			}
			System.out.println();
		}
	}

}
