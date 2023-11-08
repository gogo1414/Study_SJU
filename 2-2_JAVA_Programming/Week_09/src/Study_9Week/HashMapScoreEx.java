package Study_9Week;
import java.util.*;

public class HashMapScoreEx {

	public static void main(String[] args) {
		HashMap<String, Integer> H = new HashMap<>();
		
		H.put("이재문", 77);
		H.put("한원선", 99);
		H.put("김남윤", 98);
		H.put("김성동", 97);
		H.put("황기태", 88);
		
		System.out.println("HashMap의 요소 개수 " + H.size());
		
		Set<String> keys = H.keySet(); // 집합 셋 컬렉션 반환
		Iterator<String> it = keys.iterator();
		while(it.hasNext()) {
			String S = it.next();
			System.out.println(S + " : " + H.get(S));
		}
		
		
		
	}

}
