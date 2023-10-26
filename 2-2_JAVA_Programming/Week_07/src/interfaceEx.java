interface Phone {
	int TIMEOUT = 10000; // public static final 생략
	void sendCall(); // public abstract 생략
	void receiveCall(); // public abstract 생략
	default void printLogo() { //
		System.out.println("**Phone**");
	}
}

interface MobilePhone extends Phone {
	void sendSMS();
	void receiveSMS();
}

interface MP3 {
	public void play();
	public void stop();
}

class PDA {
	public int calculate(int x, int y) {
		return x+y;
	}
}

class SmartPhone extends PDA implements MobilePhone, MP3 {
	@Override
	public  void sendCall() {
		System.out.println("띠리리리리링 ");
	}
	                                                            
	@Override
	public void receiveCall() {
		System.out.println("전화가 왔습니다 ");
	}
	@Override
	public void sendSMS() {
		System.out.println("문자를 전송했습니다.");
	}
	@Override
	public void receiveSMS() {
		System.out.println("문자가 도착했습니다.");
	}
	@Override
	public void play() {
		System.out.println("music start!");
	}
	@Override
	public void stop() {
		System.out.println("music stop!");
	}
	public void flash() {
		System.out.println("불이 켜졌습니다 ");
	}
}

public class interfaceEx {

	public static void main(String[] args) {
		SmartPhone phone = new SmartPhone();
		System.out.println(phone.TIMEOUT);
		phone.play();
		phone.stop();
		phone.receiveSMS();
		phone.sendSMS();
		phone.sendCall();
		phone.receiveCall();
		phone.flash();
	}

}
