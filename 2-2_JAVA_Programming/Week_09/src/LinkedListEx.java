import java.util.*;

public class LinkedListEx {
	public static void printList(LinkedList<String> L) {
		Iterator<String> it = L.iterator();
		while(it.hasNext()) {
			String name = it.next();
			String sep;
			
			if(it.hasNext())
				sep = " -> ";
			else
				sep = "\n";
			
			System.out.print(name+sep);
		}
	}
	
	public static void main(String[] args) {
		LinkedList<String> L = new LinkedList<>();
		L.add("매트릭스");
		L.add("라라랜드");
		L.add("위대한쇼맨");
		L.add("너의 이름은");
		L.add(1, "아이언맨");
		
		printList(L);
		
		Collections.sort(L);
		printList(L);
		
		Collections.reverse(L);
		printList(L);
		
	}

}
