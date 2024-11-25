#include <cstdio>
#include<iostream>
#include <conio.h> 

void printMatrix(int matrix[11][11], int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", matrix[i][j]); 
            if (j < N - 1) {
                printf(""); 
            }
        }
        printf("\n"); 
        if (i < M - 1) {
            for (int j = 0; j < N; j++) {
                if (j < N - 1) {
                    printf(""); 
                }
            }
            printf("\n");
        }
    }
}

void fillSpiral(int matrix[11][11], int M, int N) {
    int value = 1;
    int top = 0, bottom = M - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            matrix[top][i] = value++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = value++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }
}


void fillSpiralRightIn(int matrix[11][11], int M, int N) {
    int value = 1;
    int top = 0, bottom = M - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            matrix[top][i] = value++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = value++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }
}

void fillSpiralLeftIn(int matrix[11][11], int M, int N) {
    int value = 1;
    int top = 0, bottom = M - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right) {
        for (int i = right; i >= left; i--) {
            matrix[top][i] = value++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            matrix[i][left] = value++;
        }
        left++;

        if (top <= bottom) {
            for (int i = left; i <= right; i++) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][right] = value++;
            }
            right--;
        }
    }
}

void fillSpiralOutLeft(int matrix[11][11], int M, int N) {
    int value = N*M;
    int top = 0, bottom = M - 1, left = 0, right = N - 1 ;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            matrix[top][i] = value--;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = value--;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value--;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value--;
            }
            left++;
        }
    }
}

void fillSpiralOutRight(int matrix[11][11], int M, int N) {
    int value = N*M;
    int top = 0, bottom = M - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right) {
        for (int i = right; i >= left; i--) {
            matrix[top][i] = value--;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            matrix[i][left] = value--;
        }
        left++;

        if (top <= bottom) {
            for (int i = left; i <= right; i++) {
                matrix[bottom][i] = value--;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][right] = value--;
            }
            right--;
        }
    }
}
void clearScreen() {
    system("CLS");
}

int main() {
    setlocale(LC_ALL, "ru");
    int M = 0, N = 0;
    int matrix[11][11];
    char key;
    int currentLine = 0;

    while (true) {
        clearScreen();
        printf("1. Введите N %s\n", (currentLine == 0 ? "<-" : "  "));
        printf("2. Введите M %s\n", (currentLine == 1 ? "<-" : "  "));
        printf("3. Сприаль вправо внутрь %s\n", (currentLine == 2 ? "<-" : "  "));
        printf("4. Спираль влево внутрь %s\n", (currentLine == 3 ? "<-" : "  "));
        printf("5. Спираль вправо наружу %s\n", (currentLine == 4 ? "<-" : "  "));
        printf("6. Спираль влево наружу %s\n", (currentLine == 5 ? "<-" : "  "));
        printf("7. Выход %s\n", (currentLine == 6 ? "<-" : "  "));
        key = _getch();
        if (key == 72) {
           currentLine = (currentLine > 0) ? currentLine - 1 : 0;
        }
        else if (key == 80) {
           currentLine = (currentLine < 6) ? currentLine + 1 : 6;
        }
        else if (key == 27) {
           return 0;
        }
        else if (key == '\r' || (key >= '1' && key <= '7')) {
           if (key >= '1' && key <= '7') {
              currentLine = key - '1';
           }
           switch (currentLine) {
           case 0:
               printf("Введите N: ");
               scanf_s("%d", &N);
               while (true) {
                   if (N < 1 || N > 11) {
                       printf("Число должно быть в диапазоне от 1 до 11\n");
                       printf("Попробуйте еще раз: ");
                       scanf_s("%d", &N);
                   }
                   else {
                       break;
                   }
               }
               printf("Нажмите любую кнопку для продолжения");
               break;
           case 1:
               printf("Введите M: ");
               scanf_s("%d", &M);
               while (true) {
                   if (M < 1 || M > 11) {
                       printf("Число должно быть в диапазоне от 1 до 11\n");
                       printf("Попробуйте еще раз: ");
                       scanf_s("%d", &M);
                   }
                   else {
                       break;
                   }
               }
               printf("Нажмите любую кнопку для продолжения");
               break;
                case 2:
                    if (M && N) {
                        for (int i = 0; i < M; i++) {
                            for (int j = 0; j < N; j++){
                                matrix[i][j] = 0;
                            }
                        }
                        fillSpiralRightIn(matrix, M, N);
                        printMatrix(matrix, M, N);
                    }
                    else {
                        printf("Введите все нужные значения \n");
                    }
                    break;
                case 3:
                    if (M && N) {
                        for (int i = 0; i < M; i++) {
                            for (int j = 0; j < N; j++) {
                                matrix[i][j] = 0;
                            }
                        }
                        fillSpiralLeftIn(matrix, M, N);
                        printMatrix(matrix, M, N);
                    }
                    else {
                        printf("Введите все нужные значения \n");
                    }
                    break;
                case 4:
                    if (M && N) {
                        for (int i = 0; i < M; i++) {
                            for (int j = 0; j < N; j++) {
                                matrix[i][j] = 0;
                            }
                        }
                        fillSpiralOutRight(matrix, M, N);
                        printMatrix(matrix, M, N);
                    }
                    else {
                        printf("Введите все нужные значения \n");
                    }
                    break;
                case 5:
                    if (M && N) {
                        for (int i = 0; i < M; i++) {
                            for (int j = 0; j < N; j++) {
                                matrix[i][j] = 0;
                            }
                        }
                        fillSpiralOutLeft(matrix, M, N);
                        printMatrix(matrix, M, N);
                    }
                    else {
                        printf("Введите все нужные значения \n");
                    }
                    break;
                case 6:
                    return 0;
               }
               _getch();
        }
    }
    return 0;
}