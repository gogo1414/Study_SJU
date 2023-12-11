import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ButtonEx extends JFrame {
	public ButtonEx() {
		setTitle("이미지 버튼 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		c.setLayout(new BorderLayout()); // 영역 전체가 버튼으로 활성화됨.
		
		ImageIcon normalIcon = new ImageIcon("images/normalIcon.gif");
		ImageIcon rolloverIcon = new ImageIcon("images/rolloverIcon.gif");
		ImageIcon pressedIcon = new ImageIcon("images/pressedIcon.gif");
		
		JButton btn = new JButton("call~~", normalIcon);
		btn.setPressedIcon(pressedIcon);
		btn.setRolloverIcon(rolloverIcon);
		btn.setHorizontalAlignment(SwingConstants.CENTER);
		
		c.add(btn);
		setSize(250, 150);
		setVisible(true);
	}
	
	public static void main(String[] args) {
			new ButtonEx();
	}

}
