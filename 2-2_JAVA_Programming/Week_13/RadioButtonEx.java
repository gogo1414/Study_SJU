import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class RadioButtonEx extends JFrame{

	public RadioButtonEx() {
		setTitle("라디오버튼 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		ButtonGroup group = new ButtonGroup();
		
		ImageIcon cherryIcon = new ImageIcon("imgaes/cherry.jpg");
		ImageIcon SelectedCherryIcon = new ImageIcon("images/selectedCherry.jpg");
		JRadioButton apple = new JRadioButton("사과");
		JRadioButton pear = new JRadioButton("배");
		JRadioButton cherry = new JRadioButton("체리", cherryIcon);
		cherry.setSelectedIcon(SelectedCherryIcon);
		
		group.add(apple);
		group.add(pear);
		group.add(cherry);
		
		c.add(apple);
		c.add(pear);
		c.add(cherry);
		
		setSize(300, 300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new RadioButtonEx();
	}

}
