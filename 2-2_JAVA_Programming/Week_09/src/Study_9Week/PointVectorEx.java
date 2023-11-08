package Study_9Week;

import java.util.*;

class Point {
	private int x, y;
	
	public Point (int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public String toString() {
		return "(" + this.x + ", " + this.y + ")";
	}
}

public class PointVectorEx {
	public static void print_Point (Vector<Point> P) {
		Iterator<Point> it = P.iterator();
		
		while(it.hasNext()) {
			System.out.print(it.next() + " -> ");
		}
		System.out.println("End");
	}
	
	public static void main(String[] args) {
		Vector<Point> P = new Vector<>();
		P.add(new Point(3, 5));
		P.add(new Point(2, 4));
		
		print_Point(P);
		
	}

}
