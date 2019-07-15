#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "delay.h"

struct students{
    char name[100];
    int age;
    float gpa;
};

int fileChecker(char *fileName){
    FILE *fp;
     if(fp=fopen(fileName,"r")){
        fclose(fp);
        return 1;
     }
     return 0;
}

//Add records to the database
void addRecords(){
    system("cls");
    for(int y=1;y<=57;y++){
        printf("-");
        delay(6);
    }
    printf("\n");
    printf("-----------------------ADD RECORDS-----------------------\n");
    for(int y=1;y<=57;y++){
        printf("-");
        delay(6);
    }
    printf("\n\n");

    int x;
    printf("How many records do you want to enter : ");
    scanf("%d",&x);
    struct students s[x];
    for(int y=0;y<x;y++){
        printf("\nRecord %d\n",y+1);
        printf("\tEnter the name : ");
         scanf(" %[^\t\n]s",&s[y].name);
        printf("\tEnter the age : ");
        scanf("%d",&s[y].age);
        printf("\tEnter the GPA : ");
        scanf("%f",&s[y].gpa);
    }
    int z;
    FILE *fp;
    fp=fopen("data.txt","a+");
    for(int y=0;y<x;y++){
        fprintf(fp,"\n\tName : %s",s[y].name);
        fprintf(fp,"\n\tAge : %d",s[y].age);
        fprintf(fp,"\n\tGPA : %0.2f\n",s[y].gpa);
    }
    fclose(fp);
    printf("\nSaving data.");
    for(int y=0;y<5;y++){
        delay(300);
        printf(".");
    }
    printf("\rSuccessfully saved data.\n\n");
    printf("\n\nPress any key to move to main menu.....");
    getch();
    main();
}

//View records in database
void viewRecords(){
    system("cls");
    for(int y=1;y<=57;y++){
        printf("-");
        delay(6);
    }
    printf("\n");
    printf("------------------------VIEW RECORDS-----------------------\n");
    for(int y=1;y<=57;y++){
        printf("-");
        delay(6);
    }
    printf("\n\n");
    char dataToBeRead[100];
    FILE *fp;
    fp=fopen("data.txt","r");
    fseek( fp, 181, SEEK_SET );
    while( fgets ( dataToBeRead, 50, fp ) != NULL )
        {
            printf( "%s" , dataToBeRead ) ;
         }
    fclose(fp);
    printf("\n\nPress any key to move to main menu.....");
    getch();
    main();
}

//End of the program
void goodBye(){
    system("cls");
    for(int y=1;y<=57;y++){
        printf("-");
        delay(8);
    }
    printf("\n");

    for(int y=1;y<=24;y++){
        printf("-");
        delay(50);
    }
    printf("G");
    delay(50);
    printf("O");
    delay(50);
    printf("O");
    delay(50);
    printf("D");
    delay(50);
    printf(" ");
    delay(50);
    printf("B");
    delay(50);
    printf("Y");
    delay(50);
    printf("E");
    delay(50);

    for(int y=1;y<=25;y++){
        printf("-");
        delay(50);
    }
    printf("\n");
    for(int y=1;y<=57;y++){
        printf("-");
        delay(8);
    }
    printf("\n\n");
}

//main function - menu is written here
int main()
{
    system("cls");
    for(int y=1;y<=57;y++){
        printf("-");
        delay(6);
    }
    printf("\n");
    printf("-------Welcome to student records management system------\n");\
    for(int y=1;y<=57;y++){
        printf("-");
        delay(6);
    }
    printf("\n\n");

    //Checking the data.txt exists or not
    int z=fileChecker("data.txt");
    if(z==0){
        FILE *fp;
        fp=fopen("data.txt","w");
        fprintf(fp,"-----------------------------------------------------------\n");
        fprintf(fp,"-------------------- Student's Records --------------------\n");
        fprintf(fp,"-----------------------------------------------------------\n\n");
        fclose(fp);
    }


    int x;
    printf("\t\t ____ MENU ____\n");
    printf("\t\t|1.Add Records |\n");
    printf("\t\t|2.Edit Records|\n");
    printf("\t\t|3.View Records|\n");
    printf("\t\t|4.Exit        |\n");
    printf("\t\t --------------\n");
    printf("\tSelect any option : ");
    scanf("%d",&x);

    switch(x){
case 1:
    addRecords();
    break;
case 3:
    viewRecords();
    break;
case 4:
    goodBye();
    break;
    }
    return 0;
}
