import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class FlyingTextEx extends JFrame {
	private JLabel a;
	private int x, y;
	public FlyingTextEx() {
		setTitle("상, 하, 좌, 우 키를 이용");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		x = 50; y= 50;
		
		a = new JLabel("HELLO");
		a.setBackground(Color.YELLOW);
		a.setLocation(x, y);
		a.setSize(100,20);
		
		Container c = getContentPane();
		c.setLayout(null);
		c.addKeyListener(new MyKeyListener());
		
		c.add(a);
		
		setSize(300,300);
		setVisible(true);
		
		c.setFocusable(true);
		c.requestFocus();
	}
	
	class MyKeyListener implements KeyListener {
		@Override
		public void keyPressed(KeyEvent e) {
			int c = e.getKeyCode();
			if(e.getKeyText(c).equals("Left"))
				x = x - 10;
			else if(e.getKeyText(c).equals("Right"))
				x = x + 10;
			else if(e.getKeyText(c).equals("Up"))
				y = y-10;
			else if(e.getKeyText(c).equals("Down"))
				y = y + 10;
			a.setLocation(x, y);
				
		}@Override
		public void keyReleased(KeyEvent e) {
			// TODO Auto-generated method stub
			
		}@Override
		public void keyTyped(KeyEvent e) {
			// TODO Auto-generated method stub
			
		}
	}
	
	public static void main(String[] args) {
		new FlyingTextEx();
	}

}
