import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class KeyCodeEx extends JFrame {
	private JLabel la;
	public KeyCodeEx() {
		setTitle("KeyCodeEx");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		c.addKeyListener(new MyKeyCodeListener());
		
		la = new JLabel(" getKeyText() ");
		c.add(la);
		
//		la.setOpaque(true);
//		la.setBackground(Color.YELLOW);
		
		setSize(300,300);
		setVisible(true);
		
		c.setFocusable(true);
		c.requestFocus();
	}
	
	class MyKeyCodeListener implements KeyListener {
		@Override
		public void keyPressed(KeyEvent e) {
			Container c = getContentPane();
			int n = e.getKeyCode();
			char s = e.getKeyChar();
			if(e.getKeyText(n).equals("F1"))
				c.setBackground(Color.GREEN);
			else if(s == '%')
				c.setBackground(Color.YELLOW);
			la.setText(e.getKeyText(n));
		}@Override
		public void keyReleased(KeyEvent e) {
			// TODO Auto-generated method stub
			
		}@Override
		public void keyTyped(KeyEvent e) {
			// TODO Auto-generated method stub
			
		}
	}
	
	public static void main(String[] args) {
		new KeyCodeEx();
	}

}
