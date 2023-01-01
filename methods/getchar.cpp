#include <stdio.h>
#include <iostream>




using namespace std;


int putchar(){

    char c;
    for (c = 'A'; c <= 'z'; c++){
        putchar(c);
        cout << endl;
    };

    return 0;

}

int main() {


    // Interger type but does save other values.
    int c;
    puts("enter text. Inlcude a dot to exit: ");
    do {
        // getchar() method pulls in the whole line
        c=getchar();
        putchar(c);

    } while (c != '.');


    printf("Now running putchar() method: ");

    putchar();

    return 0;
};
