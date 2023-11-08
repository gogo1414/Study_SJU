import java.util.*;

public class HashMapEx1 {
	public static void printHashMap(HashMap<String, String> H) {
		Set<String> keys = H.keySet();
		Iterator<String> it = keys.iterator();
		
		while(it.hasNext())
		{
			String key = it.next();
			String value = H.get(key);
			System.out.println("key : " + key + ", value : " + value);
		}
	
	}
	
	public static void main(String[] args) {
		HashMap<String, String> H = new HashMap<>();
		
		H.put("baby", "아기");
		H.put("Love", "사랑");
		H.put("apple", "사과");
		
		System.out.println("Map Size : " + H.size());
		System.out.println(H.get("apple"));
		System.out.println(H.get("boy"));
		System.out.println();
		printHashMap(H);
		Scanner scanner = new Scanner(System.in);
		while(true) {
			System.out.print("Input Key : ");
			String key = scanner.nextLine();
			
			if(key.equals("exit"))
				break;
			
			String value = H.get(key);
			
			if(value == null)
				System.out.println(key + " => Not exist.");
			else
				System.out.println(key + " => exist.");
		}
		scanner.close();
	}

}
