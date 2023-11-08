import java.util.*;

public class IteratorEx {

	public static void main(String[] args) {
		Vector<Integer> V = new Vector<>();
		
		V.add(5); V.add(4); V.add(-1); V.add(2, 100);
		
		Iterator<Integer> it = V.iterator();
		
		while(it.hasNext())
			System.out.println(it.next());
		
		var sum = 0;
		it = V.iterator(); // 위치가 달라졌기 때문에 다시 처음으로 돌아오게 하기 위함.
		
		while(it.hasNext())
			sum += it.next();
		System.out.println("sum = " + sum);
	}

}
