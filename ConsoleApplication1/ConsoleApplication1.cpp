#include <iostream>

//вывод элементов матрицы
void print(double a[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void clear_matrix(double **matrix) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matrix[i][j] = 0;
}

//копирование матрицы с подстановкой столбцов
void temp_matrix(double** matrix, double a[5][5], double b[5], int  k) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == k)
                matrix[i][j] = b[i];
            else
                matrix[i][j] = a[i][j];
        }
    }
}

// подсчёт коэффов C
double sum_c(double m[], int k) {
    double s = 0;
    for (int i = 0; i < 5; i++)
        s += pow(m[i], k);
    return s;
}

// подсчёт коэфов b
double sum_b(double x[], double y[], int k) {
    double s = 0;
    for (int i = 0; i < 5; i++)
        s += pow(x[i], k) * y[i];
    return s;
}

//вычисляет определитель
double det(double **a) {
    int n = 5;
    double tmp, d;
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            if (a[k][k] == 0)
                break;
            tmp = a[i][k] / a[k][k];
            for (int j = 0; j < n; j++) {
                a[i][j] -= a[k][j] * tmp;
            }
            
        }
    }
    d = 1;
    for (int i = 0; i < n; i++) {
        d *= a[i][i];
    }
    return d;
}

int main()
{
    double c[5][5];
    double x[5], y[5];
    double b[5];
    double d[5];
    double **matrix = new double *[5];
    for (int i = 0; i < 5; i++)
        matrix[i] = new double[5];
    clear_matrix(matrix);

    for (int i = 0; i < 5; i++) {
        std::cin >> x[i];
    }
    for (int i = 0; i < 5; i++) {
        std::cin >> y[i];
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            c[i][j] = sum_c(x, j + i);
        }
    }
    for (int i = 0; i < 5; i++)
        b[i] = sum_b(x, y, i);
    for (int i = -1; i < 5; i++) {
        temp_matrix(matrix, c, b, i);
        d[i + 1] = det(matrix);
        clear_matrix(matrix);
    }
    for (int i = 0; i < 5; i++) {
        std::cout << d[i + 1]/d[0] << " ";
    }
    return 0;
}


