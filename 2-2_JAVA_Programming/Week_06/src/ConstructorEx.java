class A {
	public A() {
		System.out.println("Default Const. A");
		show();
	}
	void show() {
		System.out.println("어쩌라고");
	}
	public A(int x) {
		System.out.println("Parameter Const. A");
	}
}

class B extends A {
	public B() {
		super();
		System.out.println("Default Const. B");
	}
	public B(int x) {
		super(x); // super 생성자 호출
		System.out.println("Parameter Const. B");
	}
}


public class ConstructorEx {

	public static void main(String[] args) {
		B b = new B();
		// B에서 -> A호출 ->  A 출력 -> B 출력
		B c = new B(5);
		// B에서 -> A호출 ->  A 출력 -> B 출력
		c.show();
	}

}
