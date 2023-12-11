import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MyDialog2 extends JDialog {
	private JTextField tf = new JTextField(15);
	private JButton btn = new JButton("OK");
	public MyDialog2(JFrame frame, String title) {
		super(frame, title, true);
		setLayout(new FlowLayout());
		add(tf);
		add(btn);
		
		setSize(200, 100);
		
		btn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				setVisible(false);
			}
		});
	}
	
	public String getInput() {
		if(tf.getText().length() == 0) return null;
		else return tf.getText();
	}
}

public class DialogEx2 extends JFrame{
	private MyDialog2 dialog;
	private JButton b;
	public DialogEx2() {
		setTitle("Dialog Ex2");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		b = new JButton("Show Modal Dialog");
		
		
		dialog = new MyDialog2(this, "Test Modal Dialog");
		
		b.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				dialog.setVisible(true);
				
				String text = dialog.getInput();
				System.out.println(text);
				if(text == null) return;
				
				JButton b2 = (JButton)e.getSource();
				b2.setText(text);
			}
		});
		
		c.add(b);
		
		setSize(300,200);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new DialogEx2();
	}

}
