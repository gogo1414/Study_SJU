class Person {
	String name;
	String id;
	
	public Person (String name) {
		this.name = name;
	}
}

class Student extends Person {
	public Student(String grade,String department,String name) {
		super(name);
		this.grade = grade;
		this.department = department;
//		this.show();
	}
	public void show() {
		System.out.println("name : " + name);
		System.out.println("grade : " + grade);
		System.out.println("department : " + department);
	}
	String grade;
	String department;
}

public class UpcastingEx {

	public static void main(String[] args) {
		Person p = new Student("A", "Computer Science", "Leo"); // 업캐스팅은 자연스럽게 가능. 
		
//		System.out.println(p.name);
//		p.id = "1234";
//		System.out.println(p.id);
//		System.out.println(p.grade); p.grade 접근 불가
		
		
		Student S = new Student("B", "CS", "MAn");
//		Person a = S;
//		
//		System.out.println(S.grade);
//		System.out.println(a.grade); 출력 불가능
		
		S = (Student) p;
		System.out.println(S.department); // 다운캐스팅은 강제 형변환 필요
	}

}
