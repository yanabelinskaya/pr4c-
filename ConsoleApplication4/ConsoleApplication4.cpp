#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    string word;
    cout << "Введите слово: ";
    cin >> word;

    int choice;
    cout << "Выберите действие:" << endl;
    cout << "1. Слово выводится задом наперед." << endl;
    cout << "2. Удалить гласные из слова." << endl;
    cout << "3. Удалить согласные из слова." << endl;
    cout << "4. Перемешать буквы в слове." << endl;
    cin >> choice;

    switch (choice) {
        case 1: { // Слово выводится задом наперед
            string reversed_word = word;
            reverse(reversed_word.begin(), reversed_word.end()); // Переворачиваем слово
            cout << "Результат: " << reversed_word << endl; // Выводим результат
            break;
        }
        case 2: { // Удалить гласные из слова
            string result;
            for (char c : word) { // Перебираем все символы в слове
                // Проверяем, является ли текущий символ гласной буквой
                if (tolower(c) != 'a' && tolower(c) != 'e' && tolower(c) != 'i' && tolower(c) != 'o' && tolower(c) != 'u') {
                    result += c; // Добавляем символ к результату, если он не гласный
                }
            }
            cout << "Результат: " << result << endl; // Выводим результат
            break;
        }
        case 3: { // Удалить согласные из слова
            string result;
            for (char c : word) { // Перебираем все символы в слове
                // Проверяем, является ли текущий символ согласной буквой
                if (tolower(c) == 'a'|| tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'u' || tolower(c) == 'o') {
                    result += c; // Добавляем символ к результату, если он не согласный
                }
            }
            cout << "Результат: " << result << endl; // Выводим результат
            break;
        }
        case 4: { // Перемешать буквы в слове
            string shuffled_word = word;
            random_device rd; // Генерируем случайное зерно
            mt19937 g(rd()); // Создаем генератор случайных чисел
            shuffle(shuffled_word.begin(), shuffled_word.end(), g); // Перемешиваем буквы в слове
            cout << "Результат: " << shuffled_word << endl; // Выводим результат
            break;
        }
        default:
            cout << "Ошибка: неверный выбор действия." << endl; // Выводим сообщение об ошибке при неверном выборе действия
            break;
    }

    return 0;
}
