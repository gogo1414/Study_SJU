import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class JListEx extends JFrame{
	private String names[] = {"apple", "banana", "kiwi", "mango",
			"pear","peach","berry","strawberry","blackberry"};
	private ImageIcon[] images = {
		new ImageIcon("images/icon1.png"),
		new ImageIcon("images/icon2.png"),
		new ImageIcon("images/icon3.png"),
		new ImageIcon("images/icon4.png")
	};
	
	public JListEx() {
		setTitle("리스트 만들기 예제");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JList<String> list = new JList<>(names);
		c.add(list);
		
		JList<ImageIcon> imagelist = new JList<>();
		imagelist.setListData(images);
		c.add(imagelist);
		
		JList<String> scrollList = new JList<>(names);
		c.add(new JScrollPane(scrollList));
		
		setSize(300,300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new JListEx();
	}

}
