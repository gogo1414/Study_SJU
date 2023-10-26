public class Circle1 {

	int radius;
	String  name;

	public double getArea() {
		return 3.14*radius*radius;
	}
	
	public Circle1(int r) { radius = r; }
	public Circle1(int r, String n) { name = n; radius = r;};
	
	public static void main(String[] args) {
		Circle1 a = new Circle1(2);
		
		Circle1 pizza;
		pizza = new Circle1(10, "어쩔피자");
//		pizza.radius = 20;
//		pizza.name = "게살피자";
		double area = pizza.getArea();
		System.out.println("피자 이름 : " + pizza.name + ", 면적 : " + area);
		
		Circle1 donut = new Circle1(5, "도넛 피자");
		double area2 = donut.getArea();
		System.out.println("도넛 이름 : " + donut.name + ", 면적 : " + area2);
	}

}
