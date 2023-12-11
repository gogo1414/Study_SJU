package GUIEx;

import javax.swing.*;
import java.awt.*;

public class BorderLayoutEx extends JFrame {
	public BorderLayoutEx() {
		setTitle("BorderLayout Sample");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		
		c.setBackground(Color.gray);
		
		c.setLayout(new BorderLayout(30, 20));
		
		c.add(new Button("add"), BorderLayout.NORTH);
		c.add(new Button("sub"), BorderLayout.SOUTH);
		c.add(new Button("multiply"), BorderLayout.EAST);
		c.add(new Button("div"), BorderLayout.WEST);
		c.add(new Button("calculate"), BorderLayout.CENTER);
		
		
		
		setSize(300, 200);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new BorderLayoutEx();
	}

}
