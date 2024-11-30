#include <stdio.h>
#include <string.h>
#include <conio.h>

int main() {
	char month[10];  
	do {
		printf("Enter month: ");
		scanf_s("%s", month, 9);

		if (_stricmp(month, "January") == 0) {
			printf("January has 31 days\n");
		}
		else if (_stricmp(month, "February") == 0) {
			printf("February has 28 or 29 days\n");
		}
		else if (_stricmp(month, "March") == 0) {
			printf("March has 31 days\n");
		}
		else if (_stricmp(month, "April") == 0) {
			printf("April has 30 days\n");
		}
		else if (_stricmp(month, "May") == 0) {
			printf("May has 31 days\n");
		}
		else if (_stricmp(month, "June") == 0) {
			printf("June has 30 days\n");
		}
		else if (_stricmp(month, "July") == 0) {
			printf("July has 31 days\n");
		}
		else if (_stricmp(month, "August") == 0) {
			printf("August has 31 days\n");
		}
		else if (_stricmp(month, "September") == 0) {
			printf("September has 30 days\n");
		}
		else if (_stricmp(month, "October") == 0) {
			printf("October has 31 days\n");
		}
		else if (_stricmp(month, "November") == 0) {
			printf("November has 30 days\n");
		}
		else if (_stricmp(month, "December") == 0) {
			printf("December has 31 days\n");
		}
		else {
			printf("try again\n");
		}
	} while (puts("\nFor the next month press - 1, to exit the program - 0"), _getch() == '1');
	return 0;
}