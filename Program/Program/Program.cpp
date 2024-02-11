#include <iostream>
#include <clocale>
#include <chrono>
using namespace std;

double rec_exp(int n, long double x, int i) {
	if (i < n) {
		return ((double)pow((-1), i) * pow((1 + x), 2 * i) / i) + rec_exp(n, x, i + 1);
	}
	if (i == n) {
		return (double)pow((-1), i) * pow((1 + x), 2 * i) / i;
	}
}

void funk_expression() {
	long double x, s = 0;
	//clock_t mem_time_1, mem_time_2, get_time;
	int n;

	cout << "Введите количество итераций выражения: ";
	cin >> n;

	cout << "Введите переменную: ";
	cin >> x;


	//auto begin = std::chrono::steady_clock::now();
	for (int i = 1; i <= n; ++i) {
		s += (double)(pow((-1), i) * pow((1 + x), 2 * i)) / i;
	}
	//auto end = std::chrono::steady_clock::now();
	//auto mem_time_1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);


	cout << "Ответ, полученный в цикле: " << s << endl;

	//begin = std::chrono::steady_clock::now();
	s = rec_exp(n, x, 1);
	//end = std::chrono::steady_clock::now();
	//auto mem_time_2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	cout << "Ответ, полученный в рекурсии: " << s << endl;


	//cout << "Время работы цикла: " << mem_time_1.count() << endl;
	//cout << "Время работы рекурсии: " << mem_time_2.count() << endl;
	//cout << "Разница времени: " << mem_time_1.count() - mem_time_2.count() << endl;
}

int rec_fib(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n > 2) return rec_fib(n - 1) + rec_fib(n - 2);
}

void funk_fibonachi(int n) {
	cout << "Ряд Фибоначи до указанного элемента:" << endl;
	for (int i = 1; i <= n; ++i) {
		cout << rec_fib(i);
	}
}

void rec_han(int i, int start, int end, int temp) {
	if (i > 1) {
		cout << "Диск " << i << ": заблокирован, переход к следующему кольцу" << endl;
	}
	if (i > 0) {

		rec_han(i - 1, start, temp, end);
		cout << "Диск " << i << ": cо стержня " << start << " на стержень " << end << endl;
		rec_han(i - 1, temp, end, start);

	}
}

void funk_hanoy(int n) {
	cout << "Вариант перемещения дисков: " << endl;
	rec_han(n, 1, 2, 3);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int nav, n;

	cout << "Выберете задачу: \n1. Решение рекурсивного выражения \n2. Числа Фибоначи \n3. Ханойская башня \nВведите номер:";
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
		cout << "Введите количество колец: ";
		cin >> n;
		funk_hanoy(n);
		break;
	default:
		break;
	}

	return 0;
}

