import java.awt.*;
import javax.swing.*;

public class SliderEx extends JFrame {
	public SliderEx() {
		setTitle("슬라이더 예제 만들기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JSlider S = new JSlider(0, 200, 100);
		S.setPaintLabels(true);
		S.setPaintTicks(true);
		S.setPaintTrack(true);
		S.setMajorTickSpacing(50);
		S.setMinorTickSpacing(10);
		
		c.add(S);
		
		setSize(300, 300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new SliderEx();
	}

}
