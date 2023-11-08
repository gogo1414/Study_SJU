import java.io.*;
import java.util.*;
public class FileWriterEx {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		FileWriter fout = null;
		
		try {
			fout = new FileWriter("C:\\Users\\wnstn_000\\Desktop\\C.txt");
			
			while(true) {
				String line = scanner.nextLine();
				if(line.length() == 0) break;
				fout.write(line, 0, line.length());
				fout.write("\r\n", 0, 2);
			}
			
			fout.close();
		} catch(IOException E) {
			System.out.println("Error!");
		}
		
		scanner.close();
	}

}
