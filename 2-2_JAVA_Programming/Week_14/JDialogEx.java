import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class MyDialog extends JDialog {
	private JTextField tf = new JTextField(10);
	private JButton btn = new JButton("OK");
	
	public MyDialog(JFrame frame, String title) {
		super(frame,title);
		setLayout(new FlowLayout());
		add(tf);
		add(btn);
		setSize(200,100);
		
		btn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				setVisible(false);
			}
		});
	}
}

public class JDialogEx extends JFrame{
	private MyDialog dialog;
	public JDialogEx() {
		setTitle("dialogEx");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JButton b = new JButton("Show Dialog");
		
		dialog = new MyDialog(this, "Test Dialog");
		
		b.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				dialog.setVisible(true);
			}
		});
		
		c.add(b);
		
		setSize(400,300);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new JDialogEx();
	}

}
