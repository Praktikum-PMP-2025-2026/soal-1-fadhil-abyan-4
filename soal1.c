/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : Dynamic Structures
 *   Hari dan Tanggal    : Rabu, 6 Mei 2026
 *   Nama (NIM)          : Muhammad Fadhil Abyan (13224008)
 *   Nama File           : soal1.c
 *   Deskripsi           : Implementasi Linked List untuk antrean, kemudian hitung total waktu tunggu dari total antrean
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Antrean{
    char id[50];
    int waktu_tunggu;
    struct Antrean* next;
} Antrean;

Antrean* createAntrean(char* id, int waktu_tunggu){
    Antrean* temp = (Antrean*)malloc(sizeof(Antrean));
    strcpy(temp->id, id);
    temp->waktu_tunggu = waktu_tunggu;
    temp->next = NULL;

    if(temp == NULL){
        printf("Alokasi memori gagal!\n");
        exit(1);
    }
    return temp;
}

//Add di akhir node
void addAntrean(Antrean** head, char* id, int waktu_tunggu){
    Antrean* temp = createAntrean(id, waktu_tunggu);

    if(*head == NULL){
        *head = temp;
        return;
    }

    Antrean* current = *head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = temp;
}


int hitungTotalWaktuTunggu(Antrean *head){
    int sebelum = 0;
    int total = 0;
    int sum = 0;
    
    Antrean* current = head;
    int count = 1;

    while(current != NULL){
        total += sebelum;
        sum += total;

        sebelum = current->waktu_tunggu;

        current = current->next;
        count++;
    }

    return sum;
}

void printOrder(Antrean* head){
    Antrean* current = head;

    printf("ORDER ");
    while(current != NULL){
        printf("%s", current->id);
        if(current->next != NULL){
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}
  
 int main(){
    int N;
    scanf("%d", &N);
    char temp_id[50];
    int temp_waktu;
    Antrean* head = NULL;

    for(int i = 0; i < N; i++){
        scanf("%s %d", &temp_id, &temp_waktu);
        addAntrean(&head, temp_id, temp_waktu);
    }

    int total_tunggu = hitungTotalWaktuTunggu(head);

    printOrder(head);
    printf("WAIT %d\n", total_tunggu);


    return 0;
 }
 
