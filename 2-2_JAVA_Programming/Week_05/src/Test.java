
public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Book a = new Book("어린왕자", "생텍쥐페리");
		Book b = new Book("춘향전");
		Book c = new Book();
//		System.out.println(a.title + " " + a.author);
//		System.out.println(b.title + " " + b.author);
		a.show();
		b.show();
		c.show();
	}

}
