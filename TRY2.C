#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

struct inven {
    int prodID;
    char prodname[50];
    int quantity;
};

void list_inven();
void add_inven();
void update_inven();
void delete_inven();

void main() {
    int choice;
    clrscr();
    printf(":::::::::: ITEM MENU ::::::::::\n");
    printf("1. List Items\n");
    printf("2. Add New Item\n");
    printf("3. Update Item info\n");
    printf("4. Delete item\n");
    printf("5. Exit\n");
    printf("Enter Your Choice : ");
    do {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                clrscr();
                list_inven();
                break;
            case 2:
                clrscr();
                add_inven();
                break;
            case 3:
                clrscr();
                update_inven();
                break;
            case 4:
                clrscr();
                delete_inven();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\t\t\t\t\t\t\t\t\t\t");
                printf("Invalid Choice, Please Enter Valid Number : ");
                flushall();
                break;
        }
    } while (choice < 6 || choice > 0);

    choice = 0;
    flushall();
}

void add_inven() {
    int flv = 0,ch;
    struct inven item;
    FILE *cfile;

    if (cfile == NULL) {
        cfile = fopen("item.DAT", "ab+");
        item.prodID = 1;
    } else {
        cfile = fopen("item.DAT", "ab+");
        while (fread( &item, sizeof(struct inven), 1, cfile) != 0) {
            item.prodID++;
        }
    }

    printf(":::::::::: NEW ITEM ENTRY ::::::::::\n");
    flushall();
    printf("\nEnter The Product Name : ");
    gets(item.prodname);
    flushall();
    printf("\nEnter the Quantity of the product : ");

    do {
        flushall();
        flv = scanf("%d", & item.quantity);

        if (flv != 1) {
            gotoxy(8, 16);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(8, 16);
            printf("Enter Valid Quantity : ");
        }
    } while (flv != 1);

    fwrite( & item, sizeof(struct inven), 1, cfile);
    fclose(cfile);
    gotoxy(8, 20);
    printf("Record Added Successfully");
    printf("Continue ? (y/n) : ");

    scanf("%d",&ch);
    if(ch=='y') {
        add_inven();
    } else {
     main();
    }
}

void list_inven() {
    int x = 13;
    struct inven item;
    FILE *cfile = fopen("item.DAT", "rb+");

    printf(":::::::::: LIST OF ITEMS ::::::::::");
    if (cfile == NULL) {
        gotoxy(15, 15);
        printf("No Records Found");
    } else {
        gotoxy(5, x - 2);
        printf("%-3s | %-15s | %-3s ", "ID", "NAME", "Qun");

        while (fread( & item, sizeof(struct inven), 1, cfile) != 0) {
            gotoxy(5, x);
            x++;
            printf("%-3d | %-15.15s | %-3d ", item.prodID, item.prodname, item.quantity);
        }

        printf("\n");
        fclose(cfile);
    }
    getch();
}

void update_inven() {
	int Temp = 0, flag = 0, flv = 0;
	struct inven item;
	FILE *cfile;
	cfile = fopen("item.DAT", "rb+");
    cfile = fopen("TMP.DAT", "wb");
	flushall();
	printf(":::::::::: UPDATE ITEM INFORMATION ::::::::::");
	gotoxy(8, 12);

	if (cfile == NULL) {
	    gotoxy(15, 15);
	    printf("No Records For Update");
	} else {
	    printf("Enter The Item ID Which You Want To Update : ");
        scanf("%d", &Temp);

	    while (fread( & item, sizeof(struct inven), 1, cfile)) {
            if (item.prodID == Temp) {
                gotoxy(8, 14);
                flushall();
                printf("Enter The Item Name <%s>: ", item.prodname);
                gets(item.prodname);

                gotoxy(8, 15);
                flushall();
                printf("Enter The Quantity Of The Product <%d>:", item.quantity);
                do {
                    flushall();
                    scanf("%d", &item.quantity);
                    if (item.quantity < 1) {
                        gotoxy(8, 18);
                        printf("\t\t\t\t\t\t\t\t\t\t");
                        gotoxy(8, 18);
                        printf("Enter Valid Quantity : ");
                    } else { flag = 1; }
                } while (flag == 0);
            }

            fclose(cfile);
            gotoxy(8, 21);

            if (flag) {
                printf("Record Updated Successfully.");
            } else {
                printf("No Record For Update.");
            }
        }
	}
}

void delete_inven() {
    int Temp = 0, flag = 0, flv = 0;
    struct inven item;
    FILE * cfile, *cfile_TMP;
    cfile = fopen("item.DAT", "rb");
    cfile_TMP = fopen("TMP.DAT", "wb");
    printf(":::::::::: Delete Item Entry ::::::::::");
    gotoxy(8, 12);

    if (cfile == NULL) {
        gotoxy(15, 15);
        printf("No Record For Update");
    } else {
        printf("Enter The Item ID Which You Want To Delete : ");
        do {
            flushall();
            flv = scanf("%d", & Temp);
            if (flv != 1) {
                gotoxy(8, 12);
                printf("\t\t\t\t\t\t\t\t\t\t");
                gotoxy(8, 12);
                printf("Please Enter Valid ID : ");
            }
        } while (flv != 1);
        while (fread( & item, sizeof(struct inven), 1, cfile)); {
            if (item.prodID != Temp) {
                fwrite( & item, sizeof(struct inven), 1, cfile_TMP);
            } else {
                flag = 1;
            }
        }
    }

    fclose(cfile);
    fclose(cfile_TMP);
    remove("item.DAT");
    rename("TMP.DAT", "item.DAT");

    if (flag) {
        printf("Record Deleted Successfully.");
    } else {
        printf("No Record Found To Delete.");
    }
}
