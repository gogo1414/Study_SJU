package GUIEx;

import javax.swing.*;
import java.awt.*;

public class FlowLayoutEx extends JFrame {
	public FlowLayoutEx() {
		setTitle("FlowLayout Sample");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		
		c.setBackground(Color.gray);
		
		c.setLayout(new FlowLayout(FlowLayout.CENTER, 30, 40));
		c.add(new Button("add"));
		c.add(new Button("sub"));
		c.add(new Button("multiply"));
		c.add(new Button("div"));
		c.add(new Button("Caculate"));
		
		
		
		setSize(300, 150);
		setVisible(true);
	}
	public static void main(String[] args) {
		new FlowLayoutEx();
	}

}

