import java.util.*;

public class HashMapEx2 {
	public static void printMap(HashMap<String, Integer> H) {
		Set<String> keys = H.keySet();
		Iterator<String> it = keys.iterator();
		
		while(it.hasNext()) {
			String name = it.next();
			int score = H.get(name);
			System.out.println(name + " : " + score);
		}
	}
	
	public static void main(String[] args) {
		HashMap<String, Integer> H = new HashMap<String, Integer>();
		
		H.put("Leo", 100);
		H.put("Kim", 99);
		H.put("Juo", 88);
		H.put("Huo", 77);
		
		printMap(H);
		
	}

}
