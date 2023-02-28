#include "Header.h"

int checkinput(int min, int max) {
	int a;
	printf_s("%s%d%s%d%s", "������� ����� ����� ������������� ���������� [", min, " : ", max, "]\n");
	while (scanf_s("%d", &a) != 1 || getchar() != '\n' || a < min || a > max) {
		printf_s("%s");
		rewind(stdin);
	}
	return a;
}
void add_one(Book* my_array, int number) {
	my_array[number].author = (char*)malloc(sizeof(char) * 100);
	my_array[number].name = (char*)malloc(sizeof(char) * 100);
	printf_s("%s", "������� �������� �����\n");
	fgets(my_array[number].name, 100, stdin);
	my_array[number].name[strlen(my_array[number].name)] = '\0';
	rewind(stdin);
	printf_s("%s", "������� �������� ������\n");
	fgets(my_array[number].author, 100, stdin);
	my_array[number].author[strlen(my_array[number].author)] = '\0';
	rewind(stdin);
	printf_s("%s", "������� ����������� ������� � �����\n");
	my_array[number].kol_str = checkinput(1, 5000);
	rewind(stdin);
}
void show(Book* my_array, int size) {
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			printf_s("%d%s", i + 1, ") ");
			printf_s("%s", "�������� �����: ");
			for (int j = 0; j < strlen(my_array[i].name); j++) {
				printf_s("%c", my_array[i].name[j]);
			}
			printf_s("%s", "����� �����: ");
			for (int j = 0; my_array[i].author[j] != '\0'; j++) {
				printf_s("%c", my_array[i].author[j]);
			}
			printf_s("%s%d%c", "����������� ������� � �����: ", my_array[i].kol_str, '\n');
		}
	}
	else {
		printf_s("%s", "������ �������� ����\n");
	}
}
Book* take_struct(int* kol) {
	printf("������� ���������� ����: ");
	rewind(stdin);
	int ans = checkinput(1, 100);
	*kol = ans;
	Book* my_array = (Book*)malloc(ans * sizeof(Book));
	for (int i = 0; i < ans; i++) {
		add_one(my_array, i);
	}
	return my_array;
}
int menu() {
	printf_s("%s", "������� 0, ��� �� ��������� ������\n");
	printf_s("%s", "������� 1, ��� �� ���������������� ����� ������ ��������\n");
	printf_s("%s", "������� 2, ��� �� ������� ������ ��������\n");
	printf_s("%s", "������� 3, ��� �� ���������������� ����� n-� ������� ���������\n");
	printf_s("%s", "������� 4, ��� �� �������������� ������ �������� �� �������� �������\n");
	printf_s("%s", "������� 5, ��� �� ������������� ������ ������� �� �������� ����\n");
	printf_s("%s", "������� 6, ��� �� ������������� ������ ������� �� ������\n");
	return (checkinput(0, 6));
}
void sort_name(Book* my_array, int size) {
	if (size > 0) {
		int i, j;
		for (i = 0; i < size - 1; i++) {
			for (j = i + 1; j < size; j++) {
				if (strcmp(my_array[i].name, my_array[j].name) > 0) {
					char* dp = my_array[i].name;
					my_array[i].name = my_array[j].name;
					my_array[j].name = dp;

					dp = my_array[i].author;
					my_array[i].author = my_array[j].author;
					my_array[j].author = dp;

					int dp1 = my_array[i].kol_str;
					my_array[i].kol_str = my_array[j].kol_str;
					my_array[j].kol_str = dp1;
				}
			}
		}
		show(my_array, size);
	}
	else {
		printf_s("%s", "������ �������� ����");
	}
}
void sort_author(Book* my_array, int size) {
	if (size > 0) {
		int i, j;
		for (i = 0; i < size - 1; i++) {
			for (j = i + 1; j < size; j++) {
				if (strcmp(my_array[i].author, my_array[j].author) > 0) {
					char* dp = my_array[i].name;
					my_array[i].name = my_array[j].name;
					my_array[j].name = dp;

					dp = my_array[i].author;
					my_array[i].author = my_array[j].author;
					my_array[j].author = dp;

					int dp1 = my_array[i].kol_str;
					my_array[i].kol_str = my_array[j].kol_str;
					my_array[j].kol_str = dp1;
				}
			}
		}
		show(my_array, size);
	}
	else {
		printf_s("%s", "������ �������� ����");
	}
}
void sort_str(Book* my_array, int size) {
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			int p = i;
			while (p > 0 && my_array[p].kol_str > my_array[p - 1].kol_str) {
				char* dp = my_array[p].name;
				my_array[p].name = my_array[p - 1].name;
				my_array[p - 1].name = dp;

				dp = my_array[p].author;
				my_array[p].author = my_array[p - 1].author;
				my_array[p - 1].author = dp;

				int dp1 = my_array[p].kol_str;
				my_array[p].kol_str = my_array[p - 1].kol_str;
				my_array[p - 1].kol_str = dp1;
				p--;
			}
		}
		show(my_array, size);
	}
	else {
		printf_s("%s", "������ �������� ����");
	}
}
void free_array(Book* students, int size) {
	for (int i = 0; i < size; i++) {
		free(students[i].name);
		free(students[i].author);
	}
	free(students);
}
