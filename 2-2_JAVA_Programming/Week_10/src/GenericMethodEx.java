
public class GenericMethodEx {

	public static <T> Gstack<T> reverse(Gstack<T> G) {
		Gstack<T> s = new Gstack<T>();
		s.set(5);
		while (true) {
			T a = G.pop();
			if (a == null)
				break;
			s.push(a);
		}
		return s;
	}

	public static void main(String[] args) {
		Gstack<Double> gs = new Gstack<>();
		gs.set(5);
		for (int i = 0; i < 5; i++)
			gs.push(Double.valueOf(i + 1));

		gs = reverse(gs);

		for (int i = 0; i < 5; i++) {
			System.out.println(gs.pop());
		}
	}

}
