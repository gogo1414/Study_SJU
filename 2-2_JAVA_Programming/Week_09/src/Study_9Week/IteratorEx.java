package Study_9Week;

import java.util.*;

public class IteratorEx {

	public static void main(String[] args) {
		Vector<Integer> V = new Vector<>(5);
		V.add(5);
		V.add(4);
		V.add(100);
		V.add(-1);
		int sum = 0;
		Iterator<Integer> it = V.iterator();
		while(it.hasNext()) {
			int n = it.next();
			System.out.println(n);
			sum += n;
//			it.remove();
		}
		System.out.println("sum = " + sum);
		
		
		
	}

}
