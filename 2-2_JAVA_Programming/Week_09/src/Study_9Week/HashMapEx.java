package Study_9Week;

import java.util.*;

public class HashMapEx {

	public static void main(String[] args) {
		HashMap<String, String> H = new HashMap<>(5);
		Scanner scanner = new Scanner(System.in);
		
		H.put("apple","사과");
		H.put("love", "사랑");
		H.put("baby","아기");
		
		System.out.print("찾고 싶은 단어는 : ");
		String S = scanner.nextLine();
		
		while(true) {
			if(H.containsKey(S))
				System.out.println("key : " + S + ", value : " + H.get(S));
			else if (S.equals("exit"))
				break;
			else
				System.out.println(S + "는 없는 단어입니다."); 
			System.out.print("찾고 싶은 단어는 : ");
			S = scanner.nextLine();
		} 
		
		
		System.out.println("종료합니다.");
		
		scanner.close();
	}

}
