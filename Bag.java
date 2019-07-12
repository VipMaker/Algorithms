public class Bag {

	int n=6;
	int m=10;
	int[] geshu;
	double[][] shuxing_all;
	int[] limite;
	double[] c_shuxing = new double[m];
	double[] value_all;
	double c_value=0;
	double bestv=0;
	int[] best_selection;
	int[] selection;
	public Bag() {
		geshu=new int[]{6,10,3800};
		value_all = new double[]{100,600,1200,2400,500,2000};
		shuxing_all=new double[][]{{8,12,13,64,22,41},{8,12,13,75,22,41},
{3,6,4,18,6,4},{5,10,8,32,6,12},{5,13,8,42,6,20},{5,13,8,48,6,20},{0,0,0 ,0,8,0},{3,0,4,0,8,0},{3,2,4,0,8,4},{3,2,4,8,8,4}};
		limite=new int[]{80,96,20,36,44,48,10,18,22,24};
		best_selection = new int[n];
		selection=new int[m];
	}
	private boolean ok(double[] c_shuxing,int m,int[] limite,int t,double[][] shuxing_all){
		int i;
		for(i=0;i<m;i++){
			if(c_shuxing[i]+shuxing_all[i][t]<limite[i])
				continue;
			else break;
		}
		if(i==m)
			return true;
		else 
			return false;
	}
	private void backtrack(int t) {
		if (t >= n) {
			// �޽纯������ȥ��Щ���У��������������Ž����֦
			if (c_value > bestv) {
				bestv = c_value;
				// �������ŵ�selectionֵ���붯̬�Ż���������Ϊselection���ڲ�ͬ�ļ�֦�����з����仯
				for (int i = 0; i < n; i++) {
					best_selection[i] = selection[i]; // �����ŵ�ѡ�����б�����best_selection��
					// System.out.print(selection[i] + " ");
				}
			}
		}

		else {
			// ����������
			if (ok(c_shuxing,m,limite,t,shuxing_all)) {
				for(int i=0;i<m;i++){
				c_shuxing[i] += shuxing_all[i][t];}
				c_value += value_all[t];

				selection[t] = 1;
				backtrack(t + 1);

				// ������ǰ��ֵ��������ԭ������������
				for(int i=0;i<m;i++){
					c_shuxing[i] -= shuxing_all[i][t];}
				//c_weight -= weight[t];
				c_value -= value_all[t];
			}

			selection[t] = 0;
			backtrack(t + 1); // ����������

		}
	}


	public static void main(String args[]) {
		Bag bag= new Bag();
		bag.backtrack(0);
		//int len = bag.n;
		System.out.println("���ݷ�����������ֵΪ��" + bag.bestv);
		/*System.out.println("���ݶ�Ӧ��valueֵ�ֱ�Ϊ��");
		for (int i = 0; i < len; i++) {
			if (bag.best_selection[i] == 1)
				System.out.print(bag.value[i] + " ");
		}*/
	}
}