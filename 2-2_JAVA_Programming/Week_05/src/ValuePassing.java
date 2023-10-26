
public class ValuePassing {

	public static void main(String[] args) {
		int n = 3;
		increase(n);
		System.out.println(n);
	}
	
	static void increase(int m) {
		m = m + 1;
	}

}
