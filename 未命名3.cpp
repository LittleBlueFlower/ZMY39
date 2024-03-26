#include <stdio.h>

// �����������нϴ��ֵ
int max(int a, int b) {
    return (a > b) ? a : b;
}

// ��̬�滮��� 0-1 ��������
// W: ����������
// weights: ��Ʒ����������
// values: ��Ʒ�ļ�ֵ����
// n: ��Ʒ������
int knapsack(int W, int weights[], int values[], int n) {
    int i, w;
    int K[n+1][W+1];
    for (i=0;i<=n;i++) {
        for (w=0;w<=W;w++) {
            // ���������û����Ʒ���߱�������Ϊ0ʱ����ֵΪ0
            if (i==0||w==0)
                K[i][w]=0;
            // ��ǰ��Ʒ���������Է��뱳��ʱ�������Ƿ�������Ʒ�Ի�ø����ֵ
            else if (weights[i-1]<=w)
            	//��ÿһ�е��ܼ�ֵ����֮ǰ�Ĵ� 
                K[i][w]=max(values[i-1]+K[i-1][w-weights[i-1]], K[i-1][w]);
            // ��ǰ��Ʒ�������޷����뱳��ʱ��ֻ��ѡ�񲻷���
            else
                K[i][w]=K[i-1][w];
        }
    }
    // ���ر�����͵��������ֵ���������һ�� 
    return K[n][W];
}

int main() {
    int weights[] = {2, 3, 4, 5}; // ��Ʒ������
    int values[] = {3, 4, 5, 6};   // ��Ʒ�ļ�ֵ
    int W = 8;                     // ����������
    int n = 4;					   // ��Ʒ������
    printf("������͵��������ֵΪ��%d\n", knapsack(W, weights, values, n)); 
    return 0;
}

