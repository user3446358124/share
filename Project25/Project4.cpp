#define _CRT_SECURE_NO_DEPRECATE

#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#include<stdio.h>
void sort(int* a, int l);
const int N = 1010;
int n;
int a[N], b[N];
int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		sort(a + 1, *(a + n + 1));
		sort(b + 1, *(b + n + 1));
		//p��Ԩ����������ָ�룬q�ǹ�����������ָ�� 
		//win��ʾԨ�����ʤ���� 
		int p = 1, q = 1, win = 0;
		while ((p <= n) && (q <= n)) {
			if (a[p] > b[q]) {//Ԩ������սʤ������PK��һ���� 
				win++;
				p++;
				q++;
			}
			else {//Ԩ������սʤ������Ԩ������һƥ��ȥPK 
				p++;
			}
		}
		if (win > (n - win)) {
			printf("%s\n", "YES");
		}
		else {
			printf("%s\n", "NO");
		}
	}
	return 0;
}
void sort(int* a, int l)//aΪ�����ַ��lΪ���鳤�ȡ�
{
	int i, j;
	int v;
	//��������
	for (i = 0; i < l - 1; i++)
		for (j = i + 1; j < l; j++)
		{
			if (a[i] > a[j])//��ǰ��ıȺ���Ĵ��򽻻���
			{
				v = a[i];
				a[i] = a[j];
				a[j] = v;
			}
		}
}