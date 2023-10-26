// super 사용법
public class Circle2 extends Shape{
	protected String name;
	public void paint() {
		draw();
	}
	public void draw() {
		this.name = "Circle";
		super.name = "Shape";
		super.draw();
		System.out.println(name);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Shape a = new Circle2();
		a.paint();
	}

}
