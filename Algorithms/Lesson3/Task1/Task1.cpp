#include <iostream>

void merge_array(int array_value[], int left_value, int middle_value, int right_value)
{
	int number_1 = middle_value - left_value + 1;
	int number_2 = right_value - middle_value;

	int L[number_1], R[number_2];

	for (int i = 0; i < number_1; i++)
		L[i] = array_value[left_value + i];
	for (int i = 0; i < number_2; i++)
		R[i] = array_value[middle_value + 1 + i];

	int i_1 = 0, j_1 = 0, k_1 = left_value;

	while (i_1 < number_1 && j_1 < number_2)
	{
		if (L[i_1] <= R[j_1])
		{
			array_value[k_1] = L[i_1];
			i_1++;
		}
		else
		{
			array_value[k_1] = R[j_1];
			j_1++;
		}

		k_1++;
	}

	while (i_1 < number_1)
	{
		array_value[k_1] = L[i_1];
		i_1++;
		k_1++;
	}

	while (j_1 < number_2)
	{
		array_value[k_1] = R[j_1];
		j_1++;
		k_1++;
	}
}


void merge_sort(int array_value[], int left_value, int right_value)
{
	if (left_value >= right_value)
		return;

	int middle_value = left_value + (right_value - left_value) / 2;
	merge_sort(array_value, left_value, middle_value);
	merge_sort(array_value, middle_value + 1, right_value);
	merge_array(array_value, left_value, middle_value, right_value);
}

void print_array(int array_values[], int size_of_array)
{
	for (int i = 0; i < size_of_array; i++)
		std::cout << array_values[i] << " ";
	std::cout << std::endl;
}

int main()
{
	int array_values[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33};

	int size_of_array = sizeof(array_values) / sizeof(array_values[0]);

	std::cout << "Исходный массив: ";
	print_array(array_values, size_of_array);

	merge_sort(array_values, 0, size_of_array - 1);

	std::cout << "Отсортированный массив: ";
	print_array(array_values, size_of_array);

	return 0;
}