import java.util.*;

class Point {
	private int x,y;
	
	public Point(int x,int y) {
		this.x = x;
		this.y = y;
	}
	
	public String toString() {
		return "(" + x + ", " + y + ")";
	}
}

public class PointVectorEx {
	
	public static void printVector(Vector<Point> v) {
		for(int i=0;i<v.size();i++) {
			System.out.println(v.get(i));
		}
	}
	
	public static void main(String[] args) {
		Vector<Point> v = new Vector<Point>();
		
		v.add(new Point(2, 3));
		v.add(new Point(-5, 20));
		v.add(new Point(30, -8));
		
		printVector(v);
		System.out.println();
		v.remove(1);
		printVector(v);
	}

}
