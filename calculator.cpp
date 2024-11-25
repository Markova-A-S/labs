#include <iostream>
#include <conio.h>
#include <cstdlib>

void clearScreen() {
    system("CLS");
}

int main() {
    setlocale(LC_ALL, "ru");
    long long A = 0, B = 0;
    int currentLine = 0;
    char key;

    while (true) {
        clearScreen();
        printf("1. Введите число A %s\n", (currentLine == 0 ? "<-" : "  "));
        printf("2. Введите число B %s\n", (currentLine == 1 ? "<-" : "  "));
        printf("3. Сложение %s\n", (currentLine == 2 ? "<-" : "  "));
        printf("4. Вычитание %s\n", (currentLine == 3 ? "<-" : "  "));
        printf("5. Умножение %s\n", (currentLine == 4 ? "<-" : "  "));
        printf("6. Деление %s\n", (currentLine == 5 ? "<-" : "  "));
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
                printf("Введите число A: ");
                scanf_s("%lld", &A); 
                while (true) {
                    if (A < -65536 || A > 65535) {
                        printf("Число должно быть в диапазоне от -65536 до 65535\n");
                        printf("Попробуйте еще раз: ");
                        scanf_s("%lld", &A); 
                    }
                    else {
                        break;
                    }
                }
                printf("Нажмите любую кнопку для продолжения");
                break;
            case 1:
                printf("Введите число B: ");
                scanf_s("%lld", &B);
                while (true) {
                    if (B < -65536 || B > 65535) {
                        printf("Число должно быть в диапазоне от -65536 до 65535\n");
                        printf("Попробуйте еще раз: ");
                        scanf_s("%lld", &B); 
                    }
                    else {
                        break;
                    }
                }
                printf("Нажмите любую кнопку для продолжения");
                break;
            case 2:
                printf("Результат: %lld\n", A + B);
                break;
            case 3:
                printf("Результат: %lld\n", A - B);
                break;
            case 4:
                printf("Результат: %lld\n", A * B);
                break;
            case 5:
                if (B != 0) {
                    printf("Результат: %.3f\n", (double)A / B);
                }
                else {
                    printf("Делить на ноль нельзя\n");
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