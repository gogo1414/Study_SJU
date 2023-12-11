import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class KeyListenerEx extends JFrame {
	private JLabel[] keyMessages;

	public KeyListenerEx() {
		setTitle("KeyListener Ex");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		c.addKeyListener(new MyKeyListener());
		
		keyMessages = new JLabel[3];
		keyMessages[0] = new JLabel(" getKeyCode() ");
		keyMessages[1] = new JLabel(" getKeyChar() ");
		keyMessages[2] = new JLabel(" getKeyText() ");
		
		for (int i = 0; i < 3; i++) {
			c.add(keyMessages[i]);
			keyMessages[i].setOpaque(true);
			keyMessages[i].setBackground(Color.YELLOW);
		}

		setSize(300, 150);
		setVisible(true);

		c.setFocusable(true);
		c.requestFocus();
	}
	
	class MyKeyListener implements KeyListener {
		@Override
		public void keyPressed(KeyEvent e) {
			int keyCode = e.getKeyCode();
			char keyChar = e.getKeyChar();
			
			keyMessages[0].setText(Integer.toString(keyCode));
			keyMessages[1].setText(Character.toString(keyChar));
			keyMessages[2].setText(e.getKeyText(keyCode));
		}
		@Override
		public void keyReleased(KeyEvent e) {
			// TODO Auto-generated method stub
			
		}@Override
		public void keyTyped(KeyEvent e) {
			// TODO Auto-generated method stub
			
		}
	}

	public static void main(String[] args) {
		new KeyListenerEx();
	}

}
