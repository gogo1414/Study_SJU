import java.util.*;

public class VectorEx {
	public static void main(String[] args) {
//		Vector<int> v = new Vector<int>(); 불가능
		Vector<Integer> V = new Vector<Integer>(); // 안에 숫자 기입시 크기 설정, 기본값 10

		V.add(Integer.valueOf(5));
		V.add(4); // 자동 Boxing이 있어 정수형 숫자만 넣어도 가능
		V.add(-1);
		V.add(0, 10);
		V.add(null);
		V.remove(0);                                                                   
		
		
		for(int i=0;i < V.size();i++)
			System.out.print(V.get(i) + " ");
		System.out.println();
		
		System.out.println("Vector Size : " + V.size());
		System.out.println("Vector Capacity : " + V.capacity());
		
		Integer obj = V.get(1);
		System.out.println(obj.intValue() + 10);
		
		System.out.println(V.lastElement());
		System.out.println(V.remove(V.size() - 1));
		
		int sum = 0;
		for(int i=0;i<V.size();i++) {
			sum += V.elementAt(i);
		}
		System.out.println("sum = " + sum);
		
		V.addAll(V);
		
		for(int i=0;i < V.size();i++)
			System.out.print(V.get(i) + " ");
		System.out.println();
		
		if(V.contains(4))
			System.out.println("yes");
		
		System.out.println(V.capacity());
		System.out.println(V.size());
		System.out.println(V.indexOf(4));
		
		Integer[] arr = new Integer[V.size()];
		arr = (Integer[])V.toArray(arr);
		
		for(int i=0;i < 8;i++)
			System.out.print(" " + arr[i]);
	}

}
