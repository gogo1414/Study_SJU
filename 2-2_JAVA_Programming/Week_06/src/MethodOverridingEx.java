class Shape {
	// 단일연결리스트 구조
	public void show3() {System.out.println("어쩌라고333");}
	protected String name;
	public Shape next;
	public Shape() {next = null;}
	public void paint() {
		draw();
	}
	public void draw() {
		System.out.println(name);
	}
}

class Line1 extends Shape{
	public void draw() {
		System.out.println("Line");
	}
}

class Rect extends Shape{
	public void draw() {
		System.out.println("Rect");
	}
}

class Circle extends Shape{
	public void draw() {
		System.out.println("Circle");
	}
}

class Line2 extends Line1 {
	public void show2() {System.out.println("어쩌라고");}
	public void draw() {
		System.out.println("Line2");
	}
}

class Line3 extends Line2 {
	public void draw() {
		System.out.println("Line3");
		super.show3();
	}
}

class Line4 extends Line3 {
	public void draw() {
		System.out.println("Line4");
		show3();
	}
}

public class MethodOverridingEx {
	
	static void paint(Shape p) {
		p.draw();
	}
	
	public static void main(String[] args) {
		Shape a1 = new Line1();
		Shape a2 = new Line2();
		Shape a3 = new Circle();
		Shape a4 = new Rect();
		Shape a5 = new Line3();
		Shape a6 = new Line4();
		paint(a6);
	}

}
