import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

class file {
	static int n, m;//n����Ʒ ÿ������
	static double[][] shuxing_all;//��������
	static double[] limite;//��������ֵ
	static double[] value_all;//ȫ����ֵ
	public file() {// ��д�ࡤ�Ĺ��췽��
		try {
			f();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void f() throws IOException {// ��ȡtxt���ݷ���
		FileReader file = null;
		file = new FileReader("F:\\�������\\java\\input2.txt");// �޸��ļ����·��
		BufferedReader rf = new BufferedReader(file);// ��ȡ�ļ�try {
		int[] aa = new int[3];
		String[] sp = null;
		String line = rf.readLine();// ��ȡһ������
		sp = line.split(" ");
		for (int i = 0; i < sp.length - 1; i++) {
			aa[i] = Integer.parseInt(sp[i]);// ������ת��Ϊint���� aa[0]=n,aa[1]=m;
		}
		m = aa[1];
		n = aa[0];
		System.out.println("��Ʒ����" + n);
		shuxing_all = new double[m][n];
		limite = new double[m];
		value_all = new double[n];
		sp = null;
		line = rf.readLine();// ��ȡһ������
		sp = line.split(" ");
		for (int i = 0; i < sp.length; i++) {
			value_all[i] = Double.parseDouble(sp[i]);//��ȡ��ֵ
		}
		int count = 0;
		while ((line = rf.readLine()) != null) {// ���ж�ȡ
			sp = line.split(" ");// ���ո���зָ�
			for (int i = 0; i < sp.length; i++) {
				shuxing_all[count][i] = Double.parseDouble(sp[i]);
			}
			count++;
			if (count % m == 0)
				break;
		}
		limite = new double[m];
		sp = null;
		line = rf.readLine();// ��ȡһ������
		sp = line.split(" ");
		for (int i = 0; i < sp.length; i++) {
			limite[i] = Integer.parseInt(sp[i]);
		}
	}
}

public class Bag {
	file x = new file();// ʵ�����࣬���������еĶ��ļ�����
	int n = x.n;
	int m = x.m;
	double[] c_shuxing = new double[m];
	double[] value_all;
	double c_value = 0;
	double bestv = 0;
	int[] best_selection = new int[n];// �洢����ѡ��
	int[] selection = new int[n];// ѡ��ѡ0��ѡ1ѡ

	// �ж��Ƿ񳬳����ƺ���
	private boolean ok(double[] c_shuxing, int m, double[] limite, int t,
			double[][] shuxing_all) {
		int i;
		for (i = 0; i < m; i++) {
			if (c_shuxing[i] + shuxing_all[i][t] < limite[i])
				continue;
			else
				break;//�����i�����Ƴ���ֱ�������жϷ���false���ݵ���һ������
		}
		if (i == m)
			return true;
		else
			return false;
	}

	private void backtrack(int t) {
		// System.out.println("running");
		if (t >= n) {//�Ƿ񵽸��ڵ�
			if (c_value > bestv) {
				bestv = c_value;
				// �������ŵ�selectionֵ
				for (int i = 0; i < n; i++) {
					best_selection[i] = selection[i]; // �����ŵ�ѡ�����б�����best_selection��
				}
			}
		}

		else {
			// ����������
			if (ok(c_shuxing, m, x.limite, t, x.shuxing_all)) {// �ж��Ƿ񳬹�����
				for (int i = 0; i < m; i++) {
					c_shuxing[i] += x.shuxing_all[i][t];
				}
				c_value += x.value_all[t];

				selection[t] = 1;//ѡ���t����Ʒ
				backtrack(t + 1);

				// ������ǰ���Ի�ԭ������������
				for (int i = 0; i < m; i++) {
					c_shuxing[i] -= x.shuxing_all[i][t];
				}
				c_value -= x.value_all[t];
			}

			selection[t] = 0;
			backtrack(t + 1); // ����������

		}
	}

	public static void main(String args[]) {
		Bag bag = new Bag();//ʵ����
		bag.backtrack(0);
		System.out.println("���ݷ�����������ֵΪ��" + bag.bestv);

	}
}