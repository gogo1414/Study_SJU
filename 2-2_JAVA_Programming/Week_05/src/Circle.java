public class Circle {
	int radius;
	public Circle(int radius) {this.radius = radius;}
	public void set(int radius) {this.radius = radius;}
	
	public double getArray() {
		return this.radius * this.radius * 3.14;
		}
	
	public static void main(String[] args) {
		Circle ob1 = new Circle(1);
		Circle ob2 = new Circle(2);
		Circle ob3;
		
		
		ob3 = ob2; // 객체 치환
		ob1 = ob2; // 객체 복사 x 레퍼런스(ex : ob1, ob3) 복사
		System.out.println("ob1 : " + ob1.radius);
		System.out.println("ob2 : "+ ob2.radius);
		System.out.println("ob3 : "+ ob3.radius);
	}

}
