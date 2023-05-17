
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 500

int main() {
    int num_left_vertices, num_right_vertices;
    double edge_probability;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int has_edge = 0;
    int i, j;

	for(int o=0;0<20;o++){
		for(int i=0;i<num_left_vertices;i++){
			for(int j=0;j<num_right_vertices;j++){
				graph[i][j]=0;
			}
		}
		
		srand(time(NULL)); // �����������

    printf("�������󲿵㼯�Ĵ�С��1-500����");
    scanf("%d", &num_left_vertices);


    printf("�������Ҳ��㼯�Ĵ�С��1-500����");
    scanf("%d", &num_right_vertices);


    printf("������ÿ����֮����ڱߵĸ��ʣ�0.0-1.0����");
    scanf("%lf", &edge_probability);

    // ȷ�� L �㼯�� R �㼯�е�ÿ����������һ����
    for (i = 0; i < num_left_vertices; i++) {
        has_edge = 0;
        for (j = num_left_vertices; j < num_left_vertices + num_right_vertices; j++) {
            if ((double) rand() / RAND_MAX < edge_probability) {
                graph[i][j] = 1;
                has_edge = 1;
            }
        }
        if (!has_edge) {
            graph[i][num_left_vertices] = 1;
        }
    }

    for (i = 0; i < num_right_vertices; i++) {
        has_edge = 0;
        for (j = 0; j < num_left_vertices; j++) {
            if ((double) rand() / RAND_MAX < edge_probability) {
                graph[j][num_left_vertices + i] = 1;
                has_edge = 1;
            }
        }
        if (!has_edge) {
            graph[0][num_left_vertices + i] = 1;
        }
    }

    // ����������ɱ�
    for (i = 0; i < num_left_vertices; i++) {
        for (j = num_left_vertices; j < num_left_vertices + num_right_vertices; j++) {
            if ((double) rand() / RAND_MAX < edge_probability && !graph[i][j]) {
                graph[i][j] = 1;
            }
        }
    }

    // �����д���ļ�
    char filename[100];
    sprintf(filename, "C:\\Users\\WYLS\\Desktop\\edges_test\\edge_%d_%d_%.1f.txt", num_left_vertices, num_right_vertices, edge_probability);
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("�޷������ļ� %s\n", filename);
        exit(1);
    }

    // ���������ļ���
    for (i = 0; i < num_left_vertices; i++) {
        for (j = num_left_vertices; j < num_left_vertices + num_right_vertices; j++) {
            if (graph[i][j]) {
                fprintf(fp, "%d %d\n", i+1, j+1);
            }
        }
    }

    fclose(fp);

    printf("���ɵĶ���ͼ�ѱ������ļ� %s �С�\n", filename);
	}

    return 0;
}
