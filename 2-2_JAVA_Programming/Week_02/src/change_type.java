
public class change_type {

	public static void main(String[] args) {
		byte b = 127;
		int i = 100;
		
		System.out.println(b+i); // 정수 
		System.out.println(10/4); // 정수
		System.out.println(10.0/4); // 실수
		System.out.println((char)0x12340041); // 문자
		System.out.println((byte)(b+i)); // 바이트
		System.out.println((int)2.9 + 1.8); //실수
		System.out.println((int)(2.9+1.8)); // 정수
		System.out.println((int)2.9 + (int)1.8); // 정수
	}

}
