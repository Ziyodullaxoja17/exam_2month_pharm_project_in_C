#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void printlist(int id[], float price[], int number[]) {
    printf(" ID   Dorilar ro'yxati | Narx ($) | Soni\n");
    printf("%d  Paracetamol         $%.2f      %d\n", id[0], price[0], number[0]);
    printf("%d  Amoxicillin         $%.2f      %d\n", id[1], price[1], number[1]);
    printf("%d  Lisinopril          $%.2f      %d\n", id[2], price[2], number[2]);
    printf("%d  Atorvastatin        $%.2f       %d\n", id[3], price[3], number[3]);
    printf("%d  Metformin           $%.2f      %d\n", id[4], price[4], number[4]);
    printf("%d  Omeprazole          $%.2f      %d\n", id[5], price[5], number[5]);
    printf("%d  Losartan            $%.2f      %d\n", id[6], price[6], number[6]);
    printf("%d  Levothyroxine       $%.2f      %d\n", id[7], price[7], number[7]);
    printf("%d  Ibuprofen           $%.2f      %d\n", id[8], price[8], number[8]);
    printf("%d  Albuterol           $%.2f      %d\n", id[9], price[9], number[9]);
    printf("%d  Chiqish\n", id[10]);
}


void buy_dori(int id[], float price[], int number[], int id2, int count, float *sum) {
    if (id2 >= 0 && id2 < 10) {
        if (number[id2] >= count) {
            *sum += count * price[id2];
            number[id2] -= count;
            puts("");
            printf("Mahsulot xarid qilindi.\n");
        } else {
            puts("");
            printf("Mahsulot yetarli emas.\n");
        }
    } else {
        puts("");
        printf("Noto'g'ri ID kiritildi.\n");
    }
}

int main() {
    float price[] = {12.50, 34.75, 32.20, 2.99, 44.60, 77.30, 44.25, 32.80, 52.15, 43.50}; 
    int number[] = {4, 12, 4, 5, 7, 4, 7, 3, 9, 10};
    int id[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int id2, count;
    float sum = 0; 
    char yana;

    do {
        printlist(id, price, number);
        printf("Dorining ID raqamini kiriting (Chiqish uchun 10 ni kiriting):\n ");
        scanf("%d", &id2);

        if (id2 == 10) {
            printf("Xarid yakunlandi.\n");
            break;
        }

        printf("Dorining sonini kiriting: \n");
        scanf("%d", &count);

        buy_dori(id, price, number, id2, count, &sum); 
    puts("");
        printf("Yana boshqa mahsulot olishni xohlaysizmi? (ha/yo'q): \n");
        printf("ha / yoq => h/y\n");
        scanf(" %c", &yana);

        if (yana == 'h') {
            continue;
        } else if (yana == 'y') {
            printf("Jami summa: $%.2f\n", sum); 
            printf("Dastur yakunlandi.\n");
            puts("");
            puts("Omborda qolgan dorilar miqdori \n");
            printlist(id,price,number);
            break;
        } else {
            printf("Noto'g'ri javob kiritildi.\n");
            break;
        }
    } while (1);
    
    return 0;
}
