#include "Header.h"

int checkinput(int min, int max) {
	int a;
	printf("%s%d%s%d%s", "Enter an integer number that belongs to the interval [", min, " : ", max, "]\n");
	while (scanf_s("%d", &a) != 1 || getchar() != '\n' || a < min || a > max) {
		printf("%s");
		rewind(stdin);
	}
	return a;
}
void add_one(Book* my_array, int number) {
	my_array[number].author = (char*)malloc(sizeof(char) * 100);
	my_array[number].name = (char*)malloc(sizeof(char) * 100);
	printf("%s", "Enter book title\n");
	fgets(my_array[number].name, 100, stdin);
	my_array[number].name[strlen(my_array[number].name)] = '\0';
	rewind(stdin);
	printf("%s", "Enter author name\n");
	fgets(my_array[number].author, 100, stdin);
	my_array[number].author[strlen(my_array[number].author)] = '\0';
	rewind(stdin);
	printf("%s", "Enter the number of pages in the book\n");
	my_array[number].kol_str = checkinput(1, 5000);
	rewind(stdin);
}
void show(Book* my_array, int size) {
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			printf("%d%s", i + 1, ") ");
			printf("%s", "Book title: ");
			for (int j = 0; j < strlen(my_array[i].name); j++) {
				printf("%c", my_array[i].name[j]);
			}
			printf("%s", "book author: ");
			for (int j = 0; my_array[i].author[j] != '\0'; j++) {
				printf("%c", my_array[i].author[j]);
			}
			printf("%s%d%c", "Number of pages in a book: ", my_array[i].kol_str, '\n');
		}
	}
	else {
		printf("%s", "Structure array is empty\n");
	}
}
Book* take_struct(int* kol) {
	printf("Enter number of books: ");
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
	printf("%s", "Enter 0 to exit\n");
	printf("%s", "Enter 1 to initialize a new structure array\n");
	printf("%s", "Enter 2 to display an array of structures\n");
	printf("%s", "Enter 3 to initialize the new nth element of the structure\n");
	printf("%s", "Type 4 to sort the array of structures in descending page order.\n");
	printf("%s", "Enter 5 to sort the array struct by book title\n");
	printf("%s", "Enter 6 to sort the array struct by author\n");
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
		printf("%s", "Structure array is empty");
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
		printf("%s", "Structure array is empty");
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
		printf("%s", "Structure array is empty");
	}
}
void free_array(Book* students, int size) {
	for (int i = 0; i < size; i++) {
		free(students[i].name);
		free(students[i].author);
	}
	free(students);
}
