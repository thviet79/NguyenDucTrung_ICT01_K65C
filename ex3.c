#include"student.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    int option;
    Student class[100]; //danh sach sinh vien

    while(1){
        int i = 1;
        char curGrade[5];
        FILE * fpointer = fopen("SV2021.dat", "r");

        fscanf(fpointer, "%[^:]:%s", class[0].name, curGrade);//Doc dong dau của file SV2021.dat
        class[0].grade = atof(curGrade);

        while(i < 100){ //Doc cac dong tiep theo cua file SV2021.dat va luu vao class
            if(fscanf(fpointer, "%*c%[^:]:%s", class[i].name, curGrade) != EOF)//%*c dung de loai bo '\n' o dau dong
                class[i].grade = atof(curGrade);
            else class[i].name[0] = '\0';
            i++;
        }
        fclose(fpointer);

        printf("Chuong trinh quan ly sinh vien\n");
        printf("------------------------------\n");
        printf("1. Xem danh sach sinh vien\n");
        printf("2. Nhap them sinh vien\n");
        printf("3. Tim sinh vien theo ten\n");
        printf("4. Thoat\n");
        scanf("%d", &option);

        if(option == 1){
            printf("=======================\n");
            printf("Ho va ten         |Diem\n");
            printf("------------------|----\n");
            int j = 0;
            while(class[j].name[0] != '\0'){
                printf("%-18s|%.1f\n", class[j].name, class[j].grade);
                j++;
            }
            printf("=======================\n");
            printf("\n\n");
        }
        if(option == 2){
            FILE * fpointer = fopen("SV2021.dat", "a");
            char newName[50];
            char newGrade[5];
            printf("Nhap ten sinh vien moi: ");
            scanf(" %[^\n]", newName);
            printf("Nhap diem: ");
            scanf("%s", newGrade);
            fprintf(fpointer,"\n%s:%s", newName, newGrade);
            fclose(fpointer);
            printf("\n");
        }
        if(option == 3){
            int k = 0;
            char nameSearched[50];
            printf("Nhap ten can tim: ");
            scanf(" %[^\n]", nameSearched);

            FILE * fpointer = fopen("output.txt", "w");
            fflush(fpointer);  //Clear file output.txt
            fclose(fpointer);

            while(class[k].name[0] != '\0'){
                if(strstr(class[k].name, nameSearched) != NULL){
                    printf("%-18s|%.1f\n", class[k].name, class[k].grade); //In ra man hinh
                
                    fpointer = fopen("output.txt", "a");
                    fprintf(fpointer, "%s:%.1f\n", class[k].name, class[k].grade);//Viet vao output.txt
                    fclose(fpointer);
                }
                k++;
            }
            printf("\n\n");
        }
        if(option == 4){
            break;
        }
    }
}