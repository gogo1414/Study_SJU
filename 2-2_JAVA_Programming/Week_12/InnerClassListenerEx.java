import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class InnerClassListenerEx extends JFrame {
	public InnerClassListenerEx() {
		setTitle("Outter Class");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JButton Btn = new JButton("Action");
		c.add(Btn);
		
		Btn.addActionListener(new MyActionListener());
		
		add(new JButton("Exam"));
		
		setSize(300,150);
		setVisible(true);
	}
	
	class MyActionListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			JButton b = (JButton)e.getSource();
			
			if(b.getText().equals("Action"))
				b.setText("액션");
			else
				b.setText("Action");
		
		InnerClassListenerEx.this.setTitle(b.getText());
		}
	}
	
	public static void main(String[] args) {
		new InnerClassListenerEx();
	}
}
