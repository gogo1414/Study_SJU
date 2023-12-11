import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class MouseAdapterEx extends JFrame {
	private JLabel la = new JLabel("hello");
	
	public MouseAdapterEx() {
		setTitle("MouseAdapter");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(null);
		c.add(la);
		
		la.setSize(50, 50);
		la.setLocation(30,30);
		
		c.addMouseListener(new MyMouseAdapter());
		
		setSize(500,500);
		setVisible(true);
	}
	
	class MyMouseAdapter extends MouseAdapter {
		public void mousePressed(MouseEvent e) {
			int x = e.getX();
			int y = e.getY();
			la.setLocation(x, y);
			setTitle("(" + x + ", " + y + ")");
		}
	}
	
	public static void main(String[] args) {
		new MouseAdapterEx();
	}
}
