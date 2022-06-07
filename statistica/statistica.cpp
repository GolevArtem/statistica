#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

void create_meas(double* meas, int num_meas) {
	for (int i = 0; i < num_meas; i++)
	{
		cout << ++i << ". ";
		i--;
		cin >> meas[i];
	}
}
void show_meas(double* meas, int num_meas) {
	cout << "Ваши измерения:" << endl;
	for (int i = 0; i < num_meas; i++)
	{
		cout << ' ' << meas[i] << endl;
	}
}
void calc_meas(double* meas, int num_meas, double max = 0.0, double min = 0.0, double sum_meas = 0.0, double avg_meas = 0.0, double d_s = 0.0, double dispersion = 0.0, double sd = 0.0, double avg_dev = 0.0, double G1 = 0.0, double G2 = 0.0) {
	for (int i = 0; i < num_meas; i++)
	{
		sum_meas = sum_meas + meas[i];
	}
	
	avg_meas = sum_meas / num_meas;
	cout << "Среднее равно " << avg_meas << endl;
	
	for (int i = 0; i < num_meas; i++)
	{
		d_s = d_s + pow((meas[i] - avg_meas), 2);
	}
	
	dispersion = d_s / (num_meas - 1);
	cout << "Дисперсия равняется " << dispersion << endl;
	
	sd = sqrt(dispersion);
	cout << "СКО равняется " << sd << endl;

	avg_dev = avg_meas / (sqrt(num_meas));
	cout << "Среднее квадратическое отклонение равняется от среднего арифеметического " << avg_dev << endl;

	max = meas[0];
	for (int i = 0; i < num_meas; i++)
	{
		if (meas[i] > max)
		{
			max = meas[i];
		}
	}

	min = meas[0];
	for (int i = 0; i < num_meas; i++)
	{
		if (meas[i] < min)
		{
			min = meas[i];
		}
	}

	G1 = fabs(max - avg_meas) / sd;
	cout << "Критерий Граббса G1 равняется " << G1 << endl;

	G2 = fabs(avg_meas - min) / sd;
	cout << "Критерий Граббса G2 равзяется " << G2 << endl;

}
int main()
{
	setlocale(0, "");
	int num_meas; //объявление количества измерений
	cout << "Введите размер массива. Размер должен быть от 50 до 100" << endl;
	cin >> num_meas;
	if (num_meas < 50)
	{
		cout << "Размер массива должен быть больше или равен 50";
	}
	else if (num_meas > 100)
	{
		cout << "Размер массива должен быть меньше или равен 100";
	}
	else
	{
		double* meas = new double[num_meas];
		create_meas(meas, num_meas);
		show_meas(meas, num_meas);
		calc_meas(meas, num_meas);
	}
}