import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CheckBoxItemEx extends JFrame {
	
	private JCheckBox[] fruits = new JCheckBox[3];
	private String [] names = {"Apple", "Pear", "Cherry"};
	private JLabel sumLabel;
	
	public CheckBoxItemEx() {
		setTitle("체크박스와 itemEvent");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		c.add(new JLabel("Apple 1000, Pear 2000, Cherry 5000"));
		
		myItemListener listener = new myItemListener();
		for(int i=0;i<fruits.length;i++) {
			fruits[i] = new JCheckBox(names[i]);
			fruits[i].setBorderPainted(true);
			c.add(fruits[i]);
			fruits[i].addItemListener(listener);
		}
		
		sumLabel = new JLabel("현재 -원 입니다.");
		c.add(sumLabel);
		
		
		
		setSize(400,300);
		setVisible(true);
	}
	
	class myItemListener implements ItemListener {
		private int sum = 0;
		@Override
		public void itemStateChanged(ItemEvent e) {
			if(e.getStateChange() == ItemEvent.SELECTED) {
				if(e.getItem() == fruits[0]) {
					sum += 1000;
				}
				else if (e.getItem() == fruits[1]) {
					sum += 2000;
				}
				else
					sum += 5000;
			}
			else {
				if(e.getItem() == fruits[0]) {
					sum -= 1000;
				}
				else if (e.getItem() == fruits[1]) {
					sum -= 2000;
				}
				else
					sum -= 5000;
				
			}
			sumLabel.setText("현재 " + sum + " 원 입니다.");
		}
	}
	
	public static void main(String[] args) {
		new CheckBoxItemEx();
	}

}
