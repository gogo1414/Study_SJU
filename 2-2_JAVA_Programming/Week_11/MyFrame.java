package GUIEx;

import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame {
	public MyFrame() {
		setTitle("My First GUI Program.");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container contentPane = getContentPane();
		
		contentPane.setBackground(Color.YELLOW);
		
		contentPane.setLayout(new FlowLayout());
		
		contentPane.add(new JButton("Ok"));
		contentPane.add(new JButton("Cancel"));
		contentPane.add(new JButton("Ignore"));
		
		setSize(300,150);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		MyFrame first = new MyFrame();
//		new MyFrame();
		
	}

}
