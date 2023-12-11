import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MenuActionEventEx extends JFrame {
	private JLabel imageLabel = new JLabel();
	private String[] names = {"Load", "Hide", "Re Show", "Exit"};
	private JMenuItem[] JI = new JMenuItem[4];
	public MenuActionEventEx() {
		setTitle("Menu Event Ex");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		
		imageLabel = new JLabel();
		c.add(imageLabel);
		
		createMenu();
		
		setSize(300,300);
		setVisible(true);
	}
	
	public void createMenu() {
		JMenuBar menuBar = new JMenuBar();
		JMenu screen = new JMenu("Screen");
		menuBar.add(screen);
		myActionListener listener = new myActionListener();
		for(int i = 0; i<JI.length;i++) {
			JI[i] = new JMenuItem(names[i]);
			JI[i].addActionListener(listener);
			screen.add(JI[i]);
		}
		
		setJMenuBar(menuBar);
	}
	
	public class myActionListener implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent e) {
			String cmd = e.getActionCommand();
			switch(cmd) {
			case "Load" :
				if(imageLabel.getIcon() != null)
					return;
				imageLabel.setIcon(new ImageIcon("images/apple.jpg"));
				break;
			case "Hide" :
				imageLabel.setVisible(false);
				break;
			case "Re Show" :
				imageLabel.setVisible(true);
				break;
			case "Exit" :
				System.exit(0);
				break;
				
			}
//			JMenuItem mi = (JMenuItem)e.getSource();
//			if(mi == JI[0]) {
//				imageLabel.setIcon(new ImageIcon("images/apple.jpg"));
//			}
//			else if(mi == JI[1]) {
//				imageLabel.setVisible(false);
//			}
//			else if(mi == JI[2]) {
//				imageLabel.setVisible(true);
//			}
//			else if(mi == JI[3]) {
//				System.exit(0);
//			}
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MenuActionEventEx();
	}

}
