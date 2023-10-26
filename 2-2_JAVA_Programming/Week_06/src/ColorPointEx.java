class Point{
	private int x, y;
	public Point() { this.x = this.y = 0; }
	public Point(int x,int y) {
		this.x = x; this.y = y;
	}
	public void set(int x,int y) {
		this.x = x;
		this.y = y;
	}
	
	public void showPoint() {
		System.out.println("(" + x + ", " + y + ")");
	}
}

class ColorPoint extends Point {
	private String color;
	public ColorPoint() {}
	public ColorPoint(int x,int y, String color) {
		super(x, y);
		this.color = color;
		showColor();
	}
	public ColorPoint(String color) {
		this.color = color;
	}
	public void set(String color) {
		this.color = color;
	}
	
	public void showColor() {
		System.out.println(color);
		showPoint();
	}
}

public class ColorPointEx {

	public static void main(String[] args) {
		Point p = new Point();
		p.set(1, 2);
		p.showPoint();
//		p.set("Green"); 작동 안함

		ColorPoint cp = new ColorPoint(3, 4, "Red");
		
		Point a = new ColorPoint(3, 4, "GREEN"); // 다운캐스팅
		ColorPoint A = new ColorPoint(1, 2, "RED");
		Point k = A; // 업캐스팅
//		cp.set(3, 4);
//		cp.set("Red");
//		cp.showColor();
	}

}
