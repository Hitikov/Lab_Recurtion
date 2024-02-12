#include <iostream>
#include <clocale>
#include <time.h>
using namespace std;

//В данной программе решение 3-ех задач вызывается через отдельные функции из main()
//Это сделанно для удобства обозрения и редактирования кода


//Рекурсивная функция для вычисления суммы последовательности
double rec_exp(int n, long double x, int i) {
	if (i < n) { 
		return ((double)pow((-1), i) * pow((1 + x), 2 * i) / i) + rec_exp(n, x, i + 1);
	}
	if (i == n) {
		return (double)pow((-1), i) * pow((1 + x), 2 * i) / i;
	}
}

//Основная функция для вычисления суммы последовательности
void funk_expression() {
	long double x, s = 0;
	int n;

	cout << "Введите количество итераций выражения: ";
	cin >> n;

	cout << "Введите переменную: ";
	cin >> x;

	auto start_time_1 = clock();
	//Вычисление через цикл
	for (int i = 1; i <= n; ++i) {
		s += (long double)(pow((-1), i) * pow((1 + x), 2 * i)) / i;
	}
	auto end_time_1 = clock();

	cout << "Ответ, полученный в цикле: " << s << endl;

	auto start_time_2 = clock();
	//Вычисление через рекурсию
	s = rec_exp(n, x, 1);
	auto end_time_2 = clock();

	cout << "Ответ, полученный в рекурсии: " << s << endl;
	cout << "Время работы цикла: " << (end_time_1 - start_time_1) << endl;
	cout << "Время работы цикла: " << (end_time_2 - start_time_2) << endl;
}

//Рекурсивная функция для нахождения ряда Фибоначчи
int rec_fib(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n > 2) return rec_fib(n - 1) + rec_fib(n - 2);
}

//Основная функция для нахождения ряда Фибоначчи
void funk_fibonachi(int n) {
	cout << "Ряд Фибоначи до указанного элемента:" << endl;
	for (int i = 1; i <= n; ++i) {
		cout << rec_fib(i) << " ";
	}
}

//Рекурсивная функция для решения "Ханойской башни"
void rec_han(int i, int start, int end, int temp) {
	if (i > 1) {
		cout << "Диск " << i << ": заблокирован, переход к следующему диску" << endl;
	}
	if (i > 0) {
		rec_han(i - 1, start, temp, end);
		cout << "Диск " << i << ": cо стержня " << start << " на стержень " << end << endl;
		rec_han(i - 1, temp, end, start);
	}
}

//Основная функция для решения "Ханойской башни"
void funk_hanoy(int n) {
	cout << "Вариант перемещения дисков: " << endl;
	rec_han(n, 1, 2, 3);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int nav, n;

	

	cout << "Выберете задачу: \n1. Решение рекурсивного выражения \n2. Числа Фибоначи \n3. Ханойская башня \nВведите номер: ";
	cin >> nav;
	switch (nav) {
	case 1:
		funk_expression();
		break;
	case 2:
		cout << "Введите количество чисел, которое нужно вывести: ";
		cin >> n;
		funk_fibonachi(n);
		break;
	case 3:
		cout << "Введите количество дисков: ";
		cin >> n;
		funk_hanoy(n);
		break;
	default:
		break;
	}

	

	return 0;
}

