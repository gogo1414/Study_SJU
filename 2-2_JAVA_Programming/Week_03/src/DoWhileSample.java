
public class DoWhileSample {

	public static void main(String[] args) {
		char c = 'a';
		
		do {
			System.out.printf("%c", c);
			c = (char)(c+1);
		} while(c != 'z'+1);
	}

}
