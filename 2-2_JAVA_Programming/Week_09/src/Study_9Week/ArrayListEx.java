package Study_9Week;

import java.util.*;

public class ArrayListEx {

	public static void main(String[] args) {
		ArrayList<String> V = new ArrayList<>(10);
		Scanner scanner = new Scanner(System.in);
		
		for(int i=0;i<4;i++) {
			System.out.print("이름을 입력하세요 : ");
			String S = scanner.nextLine();
			
			V.add(S);
		}
		
		int l = 0;
		for(int i=1;i<V.size();i++) {
			if(V.get(l).length() < V.get(i).length())
				l = i; 
		}
		
		for(int i=0;i<V.size();i++) {
			System.out.println(i+1 + " : " + V.get(i));
		}
		
		System.out.println("longgest word : "+ V.get(l));
		
		try {
			Collections.sort(V);
			
			for(int i=0;i<V.size();i++) {
				System.out.println(i+1 + " : " + V.get(i));
			}
		} catch(Exception E) {
			System.out.println(E);
		}
		
		scanner.close();
	}

}
