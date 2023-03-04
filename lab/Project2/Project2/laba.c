#include "Header.h"

int main() {
	int size = 0;
	Book* my_array = NULL;
	while (1) {
		int v = menu();
		if (v == 0)break;
		if (v == 1) {
			my_array = take_struct(&size);
		}
		if (v == 2) {
			show(my_array, size);
		}
		if (v == 3) {
			if (size > 0) {
				printf("%s", "Enter the number of the item you want to overwrite\n");
				add_one(my_array, checkinput(1, size) - 1);
			}
			else {
				printf("%s", "Structure array is empty\n");
			}
		}
		if (v == 4) {
                  if (size > 0) {
			sort_str(my_array, size);
                  show(my_array, size);
                  }
                    
	else {
		printf("%s", "Structure array is empty");
	}
                  
                              
		}
		if (v == 5) {
			       if (size > 0) {
			sort_name(my_array, size);
                  show(my_array, size);
                    
                               }
	else {
		printf("%s", "Structure array is empty");
	}
		}
		if (v == 6) {
			        if (size > 0) {
			sort_str(my_array, size);
                  show(my_array, size);
                                }
	else {
		printf("%s", "Structure array is empty");
	}
		}
	}
	free_array(my_array, size);
	return 0;
}


