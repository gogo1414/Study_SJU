import javax.swing.*;
import javax.swing.border.*;
import javax.swing.JTextPane;
import javax.swing.text.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class SortingProgram extends JFrame {
	JFrame frame;
	private JPanel AllArea = new JPanel(new BorderLayout());
	private JTextPane textPane = new JTextPane();
	private StyledDocument doc = textPane.getStyledDocument();
	private JTextField insertnum = new JTextField(20);
	private JButton[] btn = new JButton[5];
	private JPanel BtnPanel;
	private JLabel first = new JLabel();

	private JButton start;
	private JPanel EN;

	private String[] names = { "선택 정렬", "삽입 정렬", "힙정렬", "퀵정렬", "뒤로가기" };
	private int[] intArr = new int[11];
	private int cnt = 1;
	private SimpleAttributeSet style = new SimpleAttributeSet();

	public SortingProgram() { // 정렬 프로그램 시작

		setTitle("정렬 구현");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		Container c = getContentPane();
		c.setLayout(new FlowLayout(FlowLayout.CENTER));

		EnterNumber(c);
		getRootPane().setDefaultButton(start);
		SortingPane(c);

		c.add(AllArea, BorderLayout.CENTER);

		pack();
		setSize(500, 500);
		setVisible(true);
	}

	public void SortingPane(Container c) { // 정렬 Pane 기초 설정
		AllArea.add(first, BorderLayout.NORTH);

		createBtn(c);
		AllArea.add(BtnPanel, BorderLayout.CENTER);

		AllArea.setBorder(new LineBorder(Color.gray, 1));

		textPane.setBackground(Color.white);
		textPane.setEditable(false);
		textPane.setFont(new Font("Arial", Font.BOLD, 15));
		textPane.setBorder(new LineBorder(Color.gray, 1));
		textPane.setPreferredSize(new Dimension(50, 350));
		AllArea.add(new JScrollPane(textPane), BorderLayout.SOUTH);

		AllArea.setVisible(false);
	}

	public void EnterNumber(Container c) { // 초기화면 - 숫자 입력 및 설명
		EN = new JPanel(new BorderLayout());

		EN.setBorder(new LineBorder(Color.gray, 1));

		JTextArea explain = new JTextArea(20, 30);

		explain.setFont(new Font(null, Font.BOLD, 10)); // 윈도우
		explain.setText("본 프로그램은 정렬의 과정을 보여주고자 하는 프로그램입니다.\n\n" + "회전의 수와 그 아래 바뀐 숫자들을 빨간색으로 표시하고 있습니다.\n"
				+ "같은 위치의 빨간색으로 표시된 숫자를 포함한 배열이 두번 나오는데,\n" + "위는 바뀌기 전 아래는 바뀐 후의 숫자를 표시합니다.\n\n"
				+ "각 정렬마다 회전의 수를 명시하여 정렬이 완료될 경우 회전을 멈춥니다.\n\n" + "프로그램 시작을 위해서 아래의 과정을 따라주세요.\n"
				+ "10개의 숫자(중복 가능)를 입력해 주세요.\n" + "예시)\n" + "10 9 8 7 6 5 4 3 2 1\n" + "9 10 7 5 3 6 8 2 4 1\n"
				+ "3 9 10 7 4 5 6 2 8 1\n" + "10 9 7 5 5 5 3 2 6 1\n");
		explain.setEditable(false);

		start = new JButton("Start");

		EN.add(explain, BorderLayout.NORTH);
		EN.add(insertnum, BorderLayout.CENTER);
		EN.add(start, BorderLayout.EAST);

		c.add(EN);

		first.setBackground(Color.white);
		first.setOpaque(true);
		first.setBorder(new LineBorder(Color.gray, 1));
		first.setFont(new Font("Serial", Font.BOLD, 15));
		first.setHorizontalAlignment(SwingConstants.CENTER);

		start.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				String Str = insertnum.getText().trim();
				String[] numberString = Str.split(" ");

				first.setText("입력된 수 : " + Str);

				if (numberString.length != 10) {
					JOptionPane.showMessageDialog(frame, "10개의 숫자를 형식에 맞게 입력해주세요.");
				} else if (!isNumeric(Str)) {
					JOptionPane.showMessageDialog(frame, "숫자를 입력해주세요.");
				} else {
					for (int i = 0; i < numberString.length; i++) {
						intArr[i + 1] = Integer.parseInt(numberString[i]);
					}
					insertnum.setText("");

					JButton s = (JButton) e.getSource();

					s.setVisible(false);
					EN.setVisible(false);
					AllArea.setVisible(true);
				}
			}
		});
	}

	public void displayNumber(int[] arr) { // 배열의 숫자 출력
		StyleConstants.setForeground(style, Color.RED);
		String S;

		for (int i = 1; i < arr.length; i++) {
			S = Integer.toString(arr[i]) + " ";
			try {
				doc.insertString(doc.getLength(), S, null);
			} catch (BadLocationException e) {
				e.printStackTrace();
			}
		}

		try {
			doc.insertString(doc.getLength(), "\n", null);
		} catch (BadLocationException e) {
			e.printStackTrace();
		}
	}

	public void displayNumber(int[] arr, int index) { // index를 빨간색으로 바꾼후 배열 숫자 출력
		StyleConstants.setForeground(style, Color.RED);
		String S;

		for (int i = 1; i < arr.length; i++) {
			S = Integer.toString(arr[i]) + " ";
			try {
				if (i == index) {
					doc.insertString(doc.getLength(), S, style);
				} else {
					doc.insertString(doc.getLength(), S, null);
				}
			} catch (BadLocationException e) {
				e.printStackTrace();
			}
		}
		try {
			doc.insertString(doc.getLength(), "\n", null);
		} catch (BadLocationException e) {
			e.printStackTrace();
		}
	}

	public void displayNumber(int[] arr, int index1, int index2) { // index1, 2의 숫자 빨간색으로 바꿔서 배열 숫자 출력
		StyleConstants.setForeground(style, Color.RED);
		String S;

		for (int i = 1; i < arr.length; i++) {
			S = Integer.toString(arr[i]) + " ";
			try {
				if (i == index1 || i == index2) {
					doc.insertString(doc.getLength(), S, style);
				} else {
					doc.insertString(doc.getLength(), S, null);
				}
			} catch (BadLocationException e) {
				e.printStackTrace();
			}
		}
		try {
			doc.insertString(doc.getLength(), "\n", null);
		} catch (BadLocationException e) {
			e.printStackTrace();
		}
	}

	public void createBtn(Container c) { // 정렬 및 뒤로가기 버튼 생성
		BtnPanel = new JPanel(new FlowLayout());
		BtnPanel.setBackground(Color.LIGHT_GRAY);
		BtnPanel.setBorder(new LineBorder(Color.gray, 1));

		myActionListener listener = new myActionListener();

		for (int i = 0; i < btn.length; i++) {
			btn[i] = new JButton(names[i]);
			btn[i].setBackground(Color.WHITE);
			btn[i].addActionListener(listener);
			BtnPanel.add(btn[i]);
		}
	}

	public void SelectionSort() { // 선택 정렬 알고리즘
		int[] arr = intArr.clone();
		textPane.setText("");

		int small_index;
		for (int i = 1; i < arr.length - 1; i++) {
			if (isSorted(arr))
				break;

			small_index = i;

			for (int j = i + 1; j < arr.length; j++) {
				if (arr[small_index] > arr[j])
					small_index = j;
			}

			try {
				doc.insertString(doc.getLength(), "\t    --------------------" + i + " 회전--------------------\n\t\t",
						null);
			} catch (BadLocationException e) {
				e.printStackTrace();
			}

			displayNumber(arr, i, small_index);

			if (small_index != i) {
				swapElement(arr, i, small_index);
			}

			try {
				doc.insertString(doc.getLength(), "\t\t", null);
			} catch (BadLocationException e) {
				e.printStackTrace();
			}

			displayNumber(arr, i, small_index);
		}

		try {
			doc.insertString(doc.getLength(), "\n\t        정렬 후 : ", null);
		} catch (BadLocationException e) {
			e.printStackTrace();
		}

		displayNumber(arr);
	}

	public void InsertionSort() { // 삽입 정렬 알고리즘
		int[] arr = intArr.clone();
		textPane.setText("");

		for (int i = 2; i < arr.length; i++) {
			if (isSorted(arr))
				break;
			try {
				doc.insertString(doc.getLength(), "\t    --------------------" + (i - 1) + " 회전--------------------\n",
						null);
			} catch (BadLocationException e) {
				e.printStackTrace();
			}
			for (int j = 1; j <= i; j++) {
				if (arr[i] < arr[j]) {
					try {
						doc.insertString(doc.getLength(), "\t\t", null);
					} catch (BadLocationException e) {
						e.printStackTrace();
					}
					displayNumber(arr, i, j);
					swapElement(arr, i, j);
					try {
						doc.insertString(doc.getLength(), "\t\t", null);
					} catch (BadLocationException e) {
						e.printStackTrace();
					}
					displayNumber(arr, i, j);
				}
			}
		}
		try {
			doc.insertString(doc.getLength(), "\n\t        정렬 후 : ", null);
		} catch (BadLocationException e) {
			e.printStackTrace();
		}
		displayNumber(arr);
	}

	public void QuickSort() { // 퀵 정렬 알고리즘
		int[] arr = intArr.clone();
		cnt = 1;
		textPane.setText("");

		try {
			doc.insertString(doc.getLength(), "퀵 정렬의 경우 빨간색으로 표시된 숫자는 피벗을 의미합니다.\n", null);
		} catch (BadLocationException e) {
			e.printStackTrace();
		}

		inPlaceQuickSort(arr, 1, 10);

		try {
			doc.insertString(doc.getLength(), "\n\t        정렬 후 : ", null);
		} catch (BadLocationException e) {
			e.printStackTrace();
		}

		displayNumber(arr);
	}

	public void inPlaceQuickSort(int[] L, int l, int r) { // 퀵 정렬 알고리즘 - 2
		if (isSorted(L))
			return;
		int[] P;
		if (l > r)
			return;

		int k = findPivot(l, r);
		try {
			doc.insertString(doc.getLength(), "\t    --------------------" + cnt++ + " 회전--------------------\n\t\t",
					null);
			displayNumber(L, k);
			doc.insertString(doc.getLength(), "\t\t", null);
		} catch (BadLocationException e) {
			e.printStackTrace();
		}
		P = inPlacePartition(L, l, r, k);
		displayNumber(L, k);
		inPlaceQuickSort(L, l, P[0] - 1);
		inPlaceQuickSort(L, P[1] + 1, r);
	}

	public int findPivot(int l, int r) { // 퀵 정렬의 피벗 찾기 함수
		long seed = System.currentTimeMillis();
		Random rand = new Random(seed);
		int pivot = rand.nextInt(l, r + 1);
		return pivot;
	}

	public int[] inPlacePartition(int[] L, int l, int r, int k) { // 퀵 정렬 분할 함수
		int p = L[k], i, j;
		int[] P = new int[2];
		swapElement(L, k, r);
		i = l;
		j = r - 1;
		// 주석 단 부분은 고민해야할 부분이다.
		// pivot 이상의 값을 모두 오른쪽으로 이동시킨다고 생각한다.
		while (i <= j) {
			while (i <= j && L[i] < p) { // 이하가 아니다. (pivot 이상 값만)
				i = i + 1;
			}
			while (i <= j && L[j] >= p) { // 초과가 아니다. (pivot 미만 값)
				j = j - 1;
			}
			if (i < j)
				swapElement(L, i, j);
		}
		P[0] = i; // 왼쪽 pivot의 위치
		j = r - 1;
		while (i <= j) {
			while (i <= j && L[i] <= p) { // i가 점점 증가해 pivot 초과값에서 멈춘다는 것을 생각한다.
				i = i + 1;
			}
			while (i <= j && L[j] > p) { // 피벗보다 클 경우 (피벗 이하 값이 나와야 함)
				j = j - 1;
			}
			if (i < j)
				swapElement(L, i, j);
		}
		P[1] = i; // 오른쪽 pivot의 위치
		swapElement(L, P[1], r); // P[0] 이 아닌 P[1] 값과 교환이다.
		return P;
	}

	public void swapElement(int[] arr, int a, int b) { // 배열의 a, b 숫자 교체
		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}

	public void HeapSort() { // 힙 정렬
		int[] arr = intArr.clone();
		textPane.setText("");
		for (int i = (arr.length - 1) / 2; i >= 1; i--) {
			downHeap(arr, arr.length - 1, i);
		}

		try {
			doc.insertString(doc.getLength(),
					"힙 정렬의 경우는 최대 힙화를 먼저 진행한 후 " + "제자리 힙 정렬을 진행하게 됩니다.\n" + "\t        힙화 : ", null);
		} catch (BadLocationException e) {
			e.printStackTrace();
		}

		displayNumber(arr);

		int j = 1;
		for (int i = arr.length - 1; i >= 1; i--) {
			if (isSorted(arr))
				break;
			try {
				doc.insertString(doc.getLength(), "\t    --------------------" + j++ + " 회전--------------------\n\t\t",
						null);
			} catch (BadLocationException e) {
				e.printStackTrace();
			}

			displayNumber(arr, i);

			swapElement(arr, i, 1);

			downHeap(arr, i - 1, 1);
			try {
				doc.insertString(doc.getLength(), "\t\t", null);
			} catch (BadLocationException e) {
				e.printStackTrace();
			}
			displayNumber(arr, i);
		}

		try {
			doc.insertString(doc.getLength(), "\n\t        정렬 후 : ", null);
		} catch (BadLocationException e) {
			e.printStackTrace();
		}
		displayNumber(arr);
	}

	public void downHeap(int arr[], int size, int n) {
		int left = n * 2, right = n * 2 + 1;
		if (left > size)
			return;
		int greater = left;
		if (right <= size) {
			if (arr[greater] < arr[right]) {
				greater = right;
			}
		}
		if (arr[n] > arr[greater])
			return;
		swapElement(arr, n, greater);
		downHeap(arr, size, greater);
	}

	public boolean isNumeric(String str) { // 문자열이 숫자로 구성되어 있는지 확인하는 함수
		if (str == null || str.isEmpty()) {
			return false;
		}

		for (char c : str.toCharArray()) {
			if (c == ' ')
				continue;
			if (!Character.isDigit(c)) {
				return false;
			}
		}

		return true;
	}

	public boolean isSorted(int[] arr) { // 정렬이 이루어졌는지 확인하는 함수
		for (int i = 1; i < 10; i++) {
			if (arr[i] > arr[i + 1]) {
				return false;
			}
		}
		return true;
	}

	class myActionListener implements ActionListener { // 이벤트 리스너
		@Override
		public void actionPerformed(ActionEvent e) {
			if (e.getActionCommand().equals("선택 정렬")) {
				SelectionSort();
			} else if (e.getActionCommand().equals("삽입 정렬")) {
				InsertionSort();
			} else if (e.getActionCommand().equals("힙정렬")) {
				HeapSort();
			} else if (e.getActionCommand().equals("퀵정렬")) {
				QuickSort();
			} else {
				AllArea.setVisible(false);
				EN.setVisible(true);
				start.setVisible(true);
			}
		}
	}

	public static void main(String[] args) {
		new SortingProgram();
	}
}
