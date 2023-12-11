import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MouseEX extends JFrame {
	private JLabel la = new JLabel("Hello");

	public MouseEX() {
		setTitle("Mouse Event");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		Container c = getContentPane();
		c.addMouseListener(new MyMouseListener());
		c.setLayout(null);
		
		la.setSize(50, 20);
		la.setLocation(30, 30);
		c.add(la);
		
		setSize(250, 250);
		setVisible(true);
	}

	class MyMouseListener implements MouseListener {
		public void mousePressed(MouseEvent e) {
			int x = e.getX();
			int y = e.getY();
			
			la.setLocation(x, y);
			setTitle("(" + x + ", " + y + ")");
		}
		public void mouseClicked(MouseEvent e) {}
		public void mouseEntered(MouseEvent e) {
			Container c = (Container)e.getSource();
			c.setBackground(Color.blue);
		}
		public void mouseExited(MouseEvent e) {
			Container c = (Container)e.getSource();
			c.setBackground(Color.yellow);
		}
		public void mouseReleased(MouseEvent e) {}
	}

	public static void main(String[] args) {
		new MouseEX();
	}

}
