import javax.swing.*;
import java.awt.*;

public class ToolTipDelayEx extends JFrame{
	public ToolTipDelayEx() {
		setTitle("툴팁 지연 시간 제어 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JLabel apple = new JLabel(new ImageIcon("images/apple.jpg"));
		apple.setToolTipText("사과 이미지 어때요");
		
		JLabel cherry = new JLabel(new ImageIcon("images/cherry.jpg"));
		cherry.setToolTipText("체리 이미지 어떠냐");
		
		
		c.add(apple);
		c.add(cherry);
		
		ToolTipManager m = ToolTipManager.sharedInstance();
		m.setInitialDelay(0);
		m.setDismissDelay(1000);
		
		setSize(500, 300);
		setVisible(true);
	}
	
	
	public static void main(String[] args) {
		new ToolTipDelayEx();
	}

}
