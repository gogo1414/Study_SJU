public class BitOperator {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		short a = (short)0x55ff;
		short b = (short)0x00ff;
		
		//비트 논리 연산
		System.out.println("비트 연산 결과");
		System.out.printf("%04x\n", (short)(a&b)); // 비트 and
		System.out.printf("%04x\n", (short)(a|b)); // 비트 or
		System.out.printf("%04x\n", (short)(a^b)); // 비트 xor
		System.out.printf("%04x\n", (short)(~a)); // 비트 not
	
		byte c = 20; // 0x14
		byte d = -8; // 0xf8
		
		// 비트 시프트 연산
		System.out.println("[시프트 연산 결과]");
		System.out.println(c << 2);
		System.out.println(c >> 2);
		System.out.println(d >> 2);
		System.out.printf("%x\n", (d>>>2));
	}

}
