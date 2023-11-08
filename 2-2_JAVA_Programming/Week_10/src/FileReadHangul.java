import java.io.*;
public class FileReadHangul {

	public static void main(String[] args) {
		FileInputStream input = null;
		InputStreamReader reader = null;
		BufferedReader in = null;
		try {
			input = new FileInputStream("C:\\first.txt");
			reader = new InputStreamReader(input, "MS949");
			in = new BufferedReader(reader);
			int s;
			while ((s = in.read()) != -1) {
				System.out.print((char) s);
			}
			in.close();
		} catch (IOException E) {
			System.out.println(E);
		}
	}

}
