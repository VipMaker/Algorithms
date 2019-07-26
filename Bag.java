import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

class file {
	static int n, m;//n个物品 每个限制
	static double[][] shuxing_all;//各个属性
	static double[] limite;//各个限制值
	static double[] value_all;//全部价值
	public file() {// 重写类·的构造方法
		try {
			f();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void f() throws IOException {// 读取txt数据方法
		FileReader file = null;
		file = new FileReader("F:\\程序设计\\java\\input2.txt");// 修改文件你的路径
		BufferedReader rf = new BufferedReader(file);// 读取文件try {
		int[] aa = new int[3];
		String[] sp = null;
		String line = rf.readLine();// 读取一行数据
		sp = line.split(" ");
		for (int i = 0; i < sp.length - 1; i++) {
			aa[i] = Integer.parseInt(sp[i]);// 将数据转化为int类型 aa[0]=n,aa[1]=m;
		}
		m = aa[1];
		n = aa[0];
		System.out.println("物品数：" + n);
		shuxing_all = new double[m][n];
		limite = new double[m];
		value_all = new double[n];
		sp = null;
		line = rf.readLine();// 读取一行数据
		sp = line.split(" ");
		for (int i = 0; i < sp.length; i++) {
			value_all[i] = Double.parseDouble(sp[i]);//读取价值
		}
		int count = 0;
		while ((line = rf.readLine()) != null) {// 按行读取
			sp = line.split(" ");// 按空格进行分割
			for (int i = 0; i < sp.length; i++) {
				shuxing_all[count][i] = Double.parseDouble(sp[i]);
			}
			count++;
			if (count % m == 0)
				break;
		}
		limite = new double[m];
		sp = null;
		line = rf.readLine();// 读取一行数据
		sp = line.split(" ");
		for (int i = 0; i < sp.length; i++) {
			limite[i] = Integer.parseInt(sp[i]);
		}
	}
}

public class Bag {
	file x = new file();// 实例化类，并调用类中的读文件方法
	int n = x.n;
	int m = x.m;
	double[] c_shuxing = new double[m];
	double[] value_all;
	double c_value = 0;
	double bestv = 0;
	int[] best_selection = new int[n];// 存储最优选择
	int[] selection = new int[n];// 选不选0不选1选

	// 判断是否超出限制函数
	private boolean ok(double[] c_shuxing, int m, double[] limite, int t,
			double[][] shuxing_all) {
		int i;
		for (i = 0; i < m; i++) {
			if (c_shuxing[i] + shuxing_all[i][t] < limite[i])
				continue;
			else
				break;//如果第i个限制超过直接跳出判断返回false回溯到上一个活结点
		}
		if (i == m)
			return true;
		else
			return false;
	}

	private void backtrack(int t) {
		// System.out.println("running");
		if (t >= n) {//是否到根节点
			if (c_value > bestv) {
				bestv = c_value;
				// 保存最优的selection值
				for (int i = 0; i < n; i++) {
					best_selection[i] = selection[i]; // 把最优的选择序列保存在best_selection中
				}
			}
		}

		else {
			// 搜索左子树
			if (ok(c_shuxing, m, x.limite, t, x.shuxing_all)) {// 判断是否超过限制
				for (int i = 0; i < m; i++) {
					c_shuxing[i] += x.shuxing_all[i][t];
				}
				c_value += x.value_all[t];

				selection[t] = 1;//选择第t个物品
				backtrack(t + 1);

				// 背包当前属性还原，遍历右子树
				for (int i = 0; i < m; i++) {
					c_shuxing[i] -= x.shuxing_all[i][t];
				}
				c_value -= x.value_all[t];
			}

			selection[t] = 0;
			backtrack(t + 1); // 搜索右子树

		}
	}

	public static void main(String args[]) {
		Bag bag = new Bag();//实例化
		bag.backtrack(0);
		System.out.println("回溯法背包的最优值为：" + bag.bestv);

	}
}