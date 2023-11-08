import java.util.Scanner;

class Gstack<T> {

	private int top, size;
	private Object stack[];

	public Gstack() {
		this.top = -1;
	}

	public void set(int size) {
		this.size = size;
		this.stack = new Object[size];
	}

	public void push(T item) {
		if (top == size) {
			System.out.println("스택이 꽉 찼습니다.");
			return;
		}
		this.stack[++top] = item;
	}

	public T pop() {
		if (this.top == -1) {
			System.out.println("스택이 비어있습니다.");
			return null;
		}
		T n = (T) this.stack[top];

		this.stack[top--] = null;

		return n;
	}
}

public class MyStack {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Gstack<String> G = new Gstack<>();
		String S;
		System.out.print("사이즈 입력 : ");
		int size = scanner.nextInt();
		G.set(size);

		scanner.nextLine();

		for (int i = 0; i < size; i++) {
			System.out.print("삽입할 문자열 : ");
			S = scanner.nextLine();
			G.push(S);
		}
		for (int i = 0; i < size; i++) {
			System.out.println(i + 1 + " : " + G.pop());
		}

		System.out.println("정수형 프로그램 진행");

		Gstack<Integer> G2 = new Gstack<>();
		System.out.print("사이즈2 입력 : ");
		int size2 = scanner.nextInt();
		scanner.nextLine();

		G2.set(size2);

		for (int i = 0; i < size2; i++) {
			System.out.print("삽입할 정수 : ");
			G2.push(scanner.nextInt());
		}

		for (int i = 0; i < size2; i++) {
			System.out.println(i + 1 + " : " + G2.pop());
		}

		System.out.println("모든 프로그램 종료");

		scanner.close();
	}

}