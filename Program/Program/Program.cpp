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

	clock_t start_time_1 = clock();
	//Вычисление через цикл
	for (int i = 1; i <= n; ++i) {
		s += (long double)(pow((-1), i) * pow((1 + x), 2 * i)) / i;
	}
	clock_t end_time_1 = clock();

	cout << "Ответ, полученный в цикле: " << s << endl;

	clock_t  start_time_2 = clock();
	//Вычисление через рекурсию
	s = rec_exp(n, x, 1);
	clock_t end_time_2 = clock();

	cout << "Ответ, полученный в рекурсии: " << s << endl;
	cout << "Время работы цикла: " << (long double)(end_time_1 - start_time_1) / CLOCKS_PER_SEC << endl;
	cout << "Время работы цикла: " << (long double)(end_time_2 - start_time_2) / CLOCKS_PER_SEC << endl;
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

int** matr;
int maxv;

void fun_form(int n) 
{
	maxv = n;
	matr = new int* [3];
	for (int i = 0; i < 3; ++i) {
		matr[i] = new int[n];
	}
	for (int i = 0; i < n; ++i) {
		matr[0][i] = maxv - i;
		matr[1][i] = 0;
		matr[2][i] = 0;
	}
}

void fun_print(int n, int s, int e)
{
	int in1 = 0, in2 = 0;
	while (matr[s][in1] != n) {
		in1++;
	}
	while (matr[e][in2] != 0) {
		in2++;
	}
	matr[e][in2] = matr[s][in1];
	matr[s][in1] = 0;

	for (int i = 0; i < maxv; ++i) {
		for (int ii = 0; ii < 3; ++ii) {
			cout << matr[ii][maxv - 1 - i] << '\t';
			for (int j = 0; j < maxv - matr[ii][maxv - 1 - i]; j++) {
				cout << ' ';
			}
			for (int j = 0; j < matr[ii][maxv - 1 - i]; j++) {
				cout << '=';
			}
			cout << '=';
			for (int j = 0; j < matr[ii][maxv - 1 - i]; j++) {
				cout << '=';
			}
			for (int j = 0; j < maxv - matr[ii][maxv - 1 - i]; j++) {
				cout << ' ';
			}
			cout << " | ";
		}
		cout << endl;
	}
}


//Рекурсивная функция для решения "Ханойской башни"
void rec_han(int i, int start, int end, int temp, int* c) {
	if (i > 1) {
		cout << endl << "Диск " << i << ": заблокирован, переход к следующему диску" << endl << endl;
	}
	if (i > 0) {
		cout << "\t\tВызов rec_han(" << i - 1 << ", " << start << ", " << temp << ", " << end << ")" << endl;
		rec_han(i - 1, start, temp, end, c);
		//cout << "\t\trec_han(" << i - 1 << ", " << start << ", " << temp << ", " << end << ")" << " Возврат к родителю" << endl;
		
		cout << endl << "Шаг " << (*c) ++ << ": Диск " << i << ": cо стержня " << start << " на стержень " << end << endl << endl;
		fun_print(i, start - 1, end - 1);

		cout << "\t\tВызов rec_han(" << i - 1 << ", " << temp << ", " << end << ", " << start << ")" << endl;
		rec_han(i - 1, temp, end, start, c);
		//cout << "\t\trec_han(" << i - 1 << ", " << start << ", " << temp << ", " << end << ")" << " Возврат к родителю" << endl;
	}
	cout << "\t\trec_han(" << i << ", " << start << ", " << end << ", " << temp << ")" << " Возврат к родителю" << endl;
}

//Основная функция для решения "Ханойской башни"
void funk_hanoy(int n) {
	int count = 1;
	cout << "Вариант перемещения дисков: " << endl;
	cout << "\t\tВызов rec_han(" << n << ", 1, 2, 3)";
	fun_form(n);
	rec_han(n, 1, 2, 3, &count);
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

