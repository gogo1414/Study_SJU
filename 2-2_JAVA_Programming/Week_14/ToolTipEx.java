import javax.swing.*;
import java.awt.*;

public class ToolTipEx extends JFrame{
	private Container c;
	public ToolTipEx() {
		setTitle("툴팁 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		c = getContentPane();
		c.setLayout(new FlowLayout());
		
		createToolBar();
		
		setSize(400, 150);
		setVisible(true);
	}
	
	public void createToolBar() {
		JToolBar bar = new JToolBar("Kitae Menu");
		bar.setBackground(Color.LIGHT_GRAY);
		JButton newBtn = new JButton("New");
		newBtn.setToolTipText("파일을 생성합니다.");
		bar.add(newBtn);
		
		JButton openBtn = new JButton(new ImageIcon("images/apple.jpg"));
		openBtn.setToolTipText("파일을 엽니다.");
		bar.add(openBtn);
		
		JButton saveBtn = new JButton(new ImageIcon("images/cherry.jpg"));
		saveBtn.setToolTipText("파일을 저장합니다.");
		bar.add(saveBtn);
		
		JTextField tf = new JTextField("search text field");
		tf.setToolTipText("찾고자하는 문자열을 입력하세요.");
		bar.add(tf);
		
		c.add(bar);
	}

	public static void main(String[] args) {
		new ToolTipEx();
	}

}
