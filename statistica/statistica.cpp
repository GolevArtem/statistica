#include <iostream>
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
	cout << "���� ���������:" << endl;
	for (int i = 0; i < num_meas; i++)
	{
		cout << ' ' << meas[i] << endl;
	}
}
void average_meas(double* meas, int num_meas, double sum_meas = 0.0, double avg_meas = 0.0) {
	for (int i = 0; i < num_meas; i++)
	{
		sum_meas = sum_meas + meas[i];
	}
	avg_meas = sum_meas / num_meas;
	cout << "������� ����� " << avg_meas << endl;
}
int main()
{
	setlocale(0, "");
	int num_meas; //���������� ���������� ���������
	cout << "������� ������ �������. ������ ������ ���� �� 50 �� 100" << endl;
	cin >> num_meas;
	if (num_meas < 50)
	{
		cout << "������ ������� ������ ���� ������ ��� ����� 50";
	}
	else if (num_meas > 100)
	{
		cout << "������ ������� ������ ���� ������ ��� ����� 100";
	}
	else
	{
		double* meas = new double[num_meas];
		create_meas(meas, num_meas);
		show_meas(meas, num_meas);
		average_meas(meas, num_meas);
	}
}