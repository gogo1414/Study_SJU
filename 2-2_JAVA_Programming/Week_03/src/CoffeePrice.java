import java.util.Scanner;

public class CoffeePrice {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("무슨 커피 드릴까요? ");
		String order = scanner.nextLine();
		
		switch(order) {
		case "에스프레소" :
		case "카푸치노" :
		case "카페라떼" : System.out.println(order + "은 3500원 입니다."); break;
		case "아메리카노" : System.out.println(order + "은 2000원 입니다."); break;
		default : System.out.println("메뉴를 다시 주문해주세요.");
		}
		scanner.close();
	}

}
