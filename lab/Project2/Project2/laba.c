#include "Header.h"

int main() {
    int size = 0;
    Book *my_array = NULL;
    int v;
    do {
         menu();
        v=checkinput(0, 6);

switch(v) {

    case 1: {
        my_array = take_struct(&size);
    }
        break;
    case 2: {
        show(my_array, size);
    }
        break;
    case 3: {
        if (size > 0) {
            printf("%s", "Enter the number of the item you want to overwrite\n");
            add_one(my_array, checkinput(1, size) - 1);
        } else {
            printf("%s", "Structure array is empty\n");
        }
    }
        break;
    case 4: {
        if (size > 0) {
            sort_str(my_array, size);
            show(my_array, size);
        } else {
            printf("%s", "Structure array is empty");
        }


    }
        break;
    case 5: {
        if (size > 0) {
            sort_name(my_array, size);
            show(my_array, size);

        } else {
            printf("%s", "Structure array is empty");
        }
    }
        break;
    case 6: {
        if (size > 0) {
            sort_str(my_array, size);
            show(my_array, size);
        } else {
            printf("%s", "Structure array is empty");
        }
    }
        break;
    default: {
        printf("");
    }
}
    } while (v!= 0);
    free_array(my_array, size);
    return 0;
}



