import javax.swing.*;
import java.awt.*;
import javax.swing.filechooser.*;
import java.awt.event.*;

public class MenuAndFileDialogEx extends JFrame {
	private JLabel imageLabel = new JLabel();
	
	public MenuAndFileDialogEx() {
		setTitle("Menu and JFileChooser");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		c.add(imageLabel);
		createMenu();
		setSize(300,300);
		setVisible(true);
	}
	
	private void createMenu() {
		JMenuBar mb = new JMenuBar();
		JMenu fileMenu = new JMenu("File");
		JMenuItem openItem = new JMenuItem("Open");
		
		openItem.addActionListener(new OpenActionListener());
		
		fileMenu.add(openItem);
		mb.add(fileMenu);
		
		setJMenuBar(mb);
	}
	
	class OpenActionListener implements ActionListener{
		private JFileChooser chooser;
		
		public OpenActionListener () {
			chooser = new JFileChooser();
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			FileNameExtensionFilter filter = 
					new FileNameExtensionFilter("JPG & GIF Images", "jpg", "gif");
			chooser.setFileFilter(filter);
			
			int ret = chooser.showOpenDialog(null);
			if(ret != JFileChooser.APPROVE_OPTION) {
				JOptionPane.showMessageDialog(null, "파일을 선택하지 않았습니다", "경고", JOptionPane.WARNING_MESSAGE);
				return;
			}
			
			String filePath = chooser.getSelectedFile().getPath();
			imageLabel.setIcon(new ImageIcon(filePath));
			pack();
		}
	}
	public static void main(String[] args) {
		new MenuAndFileDialogEx();
	}

}
