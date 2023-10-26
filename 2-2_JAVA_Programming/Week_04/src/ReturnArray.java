public class ReturnArray {
	static int[] makeArray() {
		int temp[] = new int[10];
		for(int i=0; i<temp.length; i++)
			temp[i] = i;
		return temp;
	}
	
	static int[] makeArray2(int Array[]) {
		int temp[] = Array;
		for(int i = 4;i<=9;i++)
			temp[i] = i+1;
		return temp;
	}
	
	static void println(int Array[]) {
		int temp[] = Array;
		for(int i=0; i<Array.length;i++)
			System.out.print(temp[i] + " ");
	}
	
	public static void main(String[] args) {
		int intArray[];
		
		intArray = makeArray();
		intArray = makeArray2(intArray);
		
		println(intArray);
		
		System.out.println();
	}

}
