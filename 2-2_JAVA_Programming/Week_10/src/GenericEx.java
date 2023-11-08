class Myclass<T> {
	T val;

	void set(T val) {
		this.val = val;
	}

	T get() {
		return val;
	}
}

public class GenericEx {

	public static void main(String[] args) {
		Myclass<String> c1 = new Myclass<>();

		c1.set("Hello");
		System.out.println(c1.get());

		Myclass<Integer> c2 = new Myclass<>();

		c2.set(35);
		System.out.println(c2.get());
	}

}
