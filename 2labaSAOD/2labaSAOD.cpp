#include "stdafx.h" 
#include <iostream>
#include <fstream>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
#pragma warning(disable : 4996)
//Описание функции сортировки простым слиянием
void Simple_Merging_Sort(char *name) {
	int a1, a2, k, i, j, kol, tmp;
	FILE *f, *f1, *f2;
	kol = 0;
	if ((f = fopen(name, "r")) == NULL)
		printf("\nИсходный файл не может быть прочитан...");
	else {
		while (!feof(f)) {
			fscanf(f, "%d", &a1);
			kol++;
		}
		fclose(f);
	}
	k = 1;
	while (k < kol) {
		f = fopen(name, "r");
		f1 = fopen("smsort_1", "w");
		f2 = fopen("smsort_2", "w");
		if (!feof(f)) fscanf(f, "%d", &a1);
		while (!feof(f)) {
			for (i = 0; i < k && !feof(f); i++) {
				fprintf(f1, "%d ", a1);
				fscanf(f, "%d", &a1);
			}
			for (j = 0; j < k && !feof(f); j++) {
				fprintf(f2, "%d ", a1);
				fscanf(f, "%d", &a1);
			}
		}
		fclose(f2);
		fclose(f1);
		fclose(f);

		f = fopen(name, "w");
		f1 = fopen("smsort_1", "r");
		f2 = fopen("smsort_2", "r");
		if (!feof(f1)) fscanf(f1, "%d", &a1);
		if (!feof(f2)) fscanf(f2, "%d", &a2);
		while (!feof(f1) && !feof(f2)) {
			i = 0;
			j = 0;
			while (i < k && j < k && !feof(f1) && !feof(f2)) {
				if (a1 < a2) {
					fprintf(f, "%d \n", a1);
					fscanf(f1, "%d", &a1);
					i++;
				}
				else {
					fprintf(f, "%d \n", a2);
					fscanf(f2, "%d", &a2);
					j++;
				}
			}
			while (i < k && !feof(f1)) {
				fprintf(f, "%d \n", a1);
				fscanf(f1, "%d", &a1);
				i++;
			}
			while (j < k && !feof(f2)) {
				fprintf(f, "%d\n ", a2);
				fscanf(f2, "%d", &a2);
				j++;
			}
		}
		while (!feof(f1)) {
			fprintf(f, "%d \n", a1);
			fscanf(f1, "%d", &a1);
		}
		while (!feof(f2)) {
			fprintf(f, "%d \no", a2);
			fscanf(f2, "%d", &a2);
		}
		fclose(f2);
		fclose(f1);
		fclose(f);
		k *= 2;
	}
	remove("smsort_1");
	remove("smsort_2");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	cout << "Введите размер массива:\n";
	cin >> size;
	ofstream file;
	ofstream file1;
	file1.open("C:\\Users\\Ruta\\Documents\\Visual Studio 2017\\Projects\\2labaSAOD\\in.txt");
	file.open("C:\\Users\\Ruta\\Documents\\Visual Studio 2017\\Projects\\2labaSAOD\\data_merge.txt");
	int *ar = new int[size];
	for (int i = 0; i < size; i++)
	{
		ar[i] = rand() % 1000+0;
		file << ar[i] << endl;
		file1 << ar[i] << endl; 
	}
	Simple_Merging_Sort("C:\\Users\\Ruta\\Documents\\Visual Studio 2017\\Projects\\2labaSAOD\\data_merge.txt");
	system("pause");
	return 0;

}

