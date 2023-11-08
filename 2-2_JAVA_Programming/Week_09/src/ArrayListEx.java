import java.util.*;

public class ArrayListEx {
	
	public static void main(String[] args) {
		ArrayList<String> S = new ArrayList<>();
		Scanner scanner = new Scanner(System.in);
		
		for(int i=0;i<4;i++) {
			System.out.print("Input name : ");
			S.add(scanner.nextLine());
		}
		
		S.add(2, "Hi");
		
		for(int i=0;i<S.size();i++)
			System.out.print(S.get(i) + " ");
		
		int longest = 0;
		for(int i = 1; i < S.size(); i++ )
			if(S.get(longest).length() < S.get(i).length())
				longest = i;
		
		System.out.println("longest String : " + S.get(longest));
		scanner.close();
	}

}
