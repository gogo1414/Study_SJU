import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;

public class SliderChangeEx extends JFrame{
	private JLabel colorLabel;
	private JSlider[] j = new JSlider[3];
	
	public SliderChangeEx() {
		setTitle("슬라이더와 ChangeEvent 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		myChangeListener listener = new myChangeListener();
		for(int i = 0; i<j.length;i++) {
			j[i] = new JSlider(0, 255, 128);
			j[i].setPaintLabels(true);
			j[i].setPaintTicks(true);
			j[i].setPaintTrack(true);
			j[i].setMajorTickSpacing(50);
			j[i].setMinorTickSpacing(10);
			j[i].addChangeListener(listener);
			c.add(j[i]);
		}
		j[0].setForeground(Color.RED);
		j[1].setForeground(Color.green);
		j[2].setForeground(Color.blue);
		
		int r = j[0].getValue();
		int g = j[1].getValue();
		int b = j[2].getValue();
		
		colorLabel = new JLabel("SLIDER EXAMPLE");
		colorLabel.setOpaque(true);
		colorLabel.setBackground(new Color(r,g,b));
		c.add(colorLabel);
		
		setSize(300, 300);
		setVisible(true);
	}
	
	class myChangeListener implements ChangeListener {
		@Override
		public void stateChanged(ChangeEvent e) {
			int r = j[0].getValue();
			int g = j[1].getValue();
			int b = j[2].getValue();
			
			colorLabel.setBackground(new Color(r,g,b));
		}
	}

	public static void main(String[] args) {
		new SliderChangeEx();
	}

}
