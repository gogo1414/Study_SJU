import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JOptionPaneEx extends JFrame{
	public JOptionPaneEx() {
		setTitle("옵션 팬 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		c.add(new MyPanel(), BorderLayout.NORTH);
		setSize(500, 200);
		setVisible(true);
	}
	
	class MyPanel extends Panel{
		private JButton btn1 = new JButton("Input Name");
		private JButton btn2 = new JButton("Confirm");
		private JButton btn3 = new JButton("Message");
		private JTextField tf = new JTextField(10);
		
		public MyPanel() {
			setBackground(Color.LIGHT_GRAY);
			add(btn1);
			add(btn2);
			add(btn3);
			add(tf);
			
			btn1.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					String name = JOptionPane.showInputDialog("이름을 입력하세요,");
					if(name != null)
						tf.setText(name);
				}
			});
			
			btn2.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					int result = JOptionPane.showConfirmDialog(null, 
							"계속할 것입니까?", "Confirm", JOptionPane.YES_NO_OPTION);
					if(result == JOptionPane.CLOSED_OPTION)
						tf.setText("Just Closed without Selection");
					else if (result == JOptionPane.YES_OPTION)
						tf.setText("Yes");
					else
						tf.setText("No");
					
				}
			});
			
			btn3.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					JOptionPane.showMessageDialog(null, "조심하세요", "Message",
							JOptionPane.ERROR_MESSAGE);
				}
			});
		
		}	
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new JOptionPaneEx();
	}

}
