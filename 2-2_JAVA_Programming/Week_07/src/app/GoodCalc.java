package app;

import library.Calc;

class cal extends Calc {
	@Override
	public int plus(int x,int y) {
		return x+y;
	}
	@Override
	public int minus(int x,int y) {
		return x-y;
	}
}

public class GoodCalc {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		cal c = new cal();
		System.out.println(c.plus(3, 5));
		System.out.println(c.plus(3, 1));
	
	}

}