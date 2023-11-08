package Study_9Week;

import java.util.*;

class Student {
	private int id;
	private String tel;
	public Student(int id, String tel) {
		this.id = id;
		this.tel = tel;
	}
	public String toString() {
		return "id:" + id + "전화:" + tel;
	}
}

public class HashMapStudentEx {

	public static void main(String[] args) {
		HashMap<String, Student> H = new HashMap<>();
		Scanner scanner = new Scanner(System.in);
		
		H.put("홍길동", new Student(1, "010-111-1111"));
		H.put("이재문", new Student(2, "010-222-2222"));
		H.put("김남윤", new Student(3, "010-333-3333"));
		
		String S;
		while(true) {
			System.out.print("검색할 이름?");
			S = scanner.nextLine();
			if(H.containsKey(S)){
				System.out.println(H.get(S));
			}
			else if(S.equals("exits"))
				break;
			else 
				System.out.println("그런 이름은 존재하지 않습니다.");
		}
		System.out.println("종료되었습니다.");
		scanner.close();
	}

}
