#include <stdio.h>

#define N 3  // N元1次方程式の解を求める．

void main(void) {

    // 拡大係数行列を表す2次元配列
    double a[N][N+1] = {{ 2.0, 3.0,  1.0,  4.0},
                        { 4.0, 1.0, -3.0, -2.0},
                        {-1.0, 2.0,  2.0,  2.0}};
    double p;  // ピボット係数
    double d;  // 各行の先頭要素
    int i, j, k;

    // ピボットを0から(N-1)まで繰り返す
    for (k=0; k<=N-1; k++) {

        p = a[k][k];                // ピボット係数 (対角要素)

        // ピボットの存在する行の全要素をピボットで割る       
        for(j=k; j<=N; j++) {       // ピボット以前の要素は既に0であるから割らなくても良い
            a[k][j] = a[k][j] / p;  // ピボットpで割る
        }

        // ピボット以外の行について列の掃き出し
        for(i=0; i<=N-1; i++) {
            if(i != k) {               // ピボットの行を除く
                d = a[i][k];           // 各行の0を除く先頭要素

                for(j=k; j<=N; j++) {  // ピボット以降の列について適用
                    a[i][j] = a[i][j] - d * a[k][j];  // (各行の要素)-(各行の先頭の要素)*(ピボット行の各要素)の計算
                }
            }
        }
    }

    // 解の出力 (拡大係数行列におけるN+1列目の全要素)
    for(k=0; k<=N-1; k++) {
        printf("x_%d = %f\n", k+1, a[k][N]);
    }
}
