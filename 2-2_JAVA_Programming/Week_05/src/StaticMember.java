import java.util.Scanner;

public class StaticMember {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("환율(1달러)>> ");
		double rate = scanner.nextDouble();
		CurrencyConverter.setRate(rate);
		System.out.println("백만원은 $" + CurrencyConverter.toDollar(1000000));
		System.out.println("$100는 " + CurrencyConverter.toKWR(100));
		scanner.close();
	}

}
