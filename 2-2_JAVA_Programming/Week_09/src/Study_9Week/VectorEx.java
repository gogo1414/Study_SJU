package Study_9Week;

import java.util.*;

public class VectorEx {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		Vector<Integer> V = new Vector<>();
		
		for(int i=0; i < 4;i++) {
			System.out.print("삽입 : ");
			int n = scanner.nextInt();
			V.add(n);
		}
		
		System.out.println("벡터 내의 요소 객체 수 : " + V.size());
		System.out.println("벡터의 현재 용량 : " + V.capacity());
		
		int sum = 0;
		
		for(int i=0;i<V.size();i++) {
			sum += V.get(i);
		}
		
		System.out.println("벡터에 있는 정수 합 : " + sum);
		
		scanner.close();
	}	

}
