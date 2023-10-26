class Point {
	private int x, y;
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public String toString() {
		return "Point(" + x + ", " + y + ")";
	}
	
	public boolean equals(Object obj) {
		Point r = (Point) obj; // 다운캐스팅
		if((r.x == this.x) && (r.y == this.y))
			return true;
		return false;
	}
}
public class ObjectPropertyEx {
	public static void print(Object obj) {
		System.out.println(obj.getClass());
		System.out.println(obj.hashCode());
		System.out.println(obj.toString());
		System.out.println(obj);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Point p = new Point(3, 5);
		Point q = new Point(3, 5);
		
		print(p);
		System.out.println("***********");
		if(p.equals(q))
			System.out.println("true");
		else
			System.out.println("false");
	}

}
