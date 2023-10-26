public class ArrayException {

	public static void main(String[] args) {
		int intArray[] = new int[5];
		intArray[0] = 0;
		
		try {
			for(int i=0;i<intArray.length;i++) {
				intArray[i+1] = i+1 + intArray[i];
				System.out.println("intArray[" + i + "] = " + intArray[i]);
			}
		}
		catch(OutOfMemoryError er) {
			System.out.println(er);
		}
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println(e);
		}
		
	}

}
