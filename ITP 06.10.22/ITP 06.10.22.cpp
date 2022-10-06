#include <iostream>
#include <vector>
using namespace std;

int get_count_dividers(int number);
pair <int*,int> get_simple_dividers(int number);

int main()
{
	setlocale(LC_ALL, "Rus");
	int number;
	cin >> number;

	auto t=get_simple_dividers(number);
	int* arr = t.first;
	int size = t.second;
	int maxcount = 0;
	int divider = 0;

	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < size; ++i)
	{
		int count = 0;

		for (int j = i+1; j < size; ++j)
		{
			if (arr[i] == arr[j])
			{
				count += 1;
			}
		}

		if (count > maxcount)
		{
			maxcount = count;
			divider = arr[i];
		}
	}

	if (maxcount==0)
	{
		cout << "Нет множителя с наибольшей кратностью" << endl;
	}
	else cout << divider << endl;
	

	return 0;
}

int get_count_dividers(int number)
{
	int countdiv = 0;
 	int d = 2;
	while (d * d <= number) {
		if (number % d == 0) {
			countdiv += 1;
			number /= d;
		}
		else
		{
			d += 1;
		}
	}

	if (number > 1) {
		countdiv += 1;
	}
	return countdiv;
}

pair <int*,int> get_simple_dividers(int number)
{	
	int t = get_count_dividers(number);
	int* arr = new int[t];
	
	int i = 0;
	int d = 2;
	while (d * d <= number) {
		if (number % d == 0) {
			arr[i] = d;
			++i;
			number /= d;
		}
		else
		{
			d += 1;
		}
	}

	if (number > 1) {
		arr[i] = number; 
	}
	
	return pair<int*, int>(arr, i + 1);
}
