// 단일연결리스트
public class UsingOverride {

	public static void main(String[] args) {
		Shape start, last, obj;
		
		start = new Line1(); // Line1 연결
		last = start;
		obj = new Rect(); 
		last.next = obj; // Rect 연결 
		last = obj;
		obj = new Line1();
		last.next = obj;
		last = obj;
		obj = new Circle();
		last.next = obj;
		// 모든 도형 출력
		Shape p = start;
		while(p != null) {
			p.draw();
			p = p.next;
		}
	}

}
