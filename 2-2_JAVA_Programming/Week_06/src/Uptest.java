class Animal {
	
}

class Tiger extends Animal {
	
}

class Lion extends Animal {
	
}

class dog extends Animal {
	
}

class cat extends dog{
	
}

class pig extends cat {
	
}

public class Uptest {
	
	static  void print(Animal a)
	{
		if(a instanceof Animal) 
			System.out.print("Animal.");
		if(a instanceof Lion) 
			System.out.print("Lion.");
		else if(a instanceof Tiger) 
			System.out.print("Tiger.");
		else if(a instanceof dog) 
			System.out.print("dog.");

	}
	public static void main(String[] args) {
		Animal [] N = new Animal[3]; // 다중상속은 안된다.
		
		N[0] = new Lion();
		N[1] = new Tiger();
		N[2] = new dog();
		
//		Lion L = (Lion)N[0];
		
		print(N[0]); // Animal + Lion.
		// 상속 받은 객체의 경우 두가지 개념이 출력
	}

}
