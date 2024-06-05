#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node *address;
typedef struct mahasiswa{
    int nim;
    char nama[50];
    float ipk;
} mahasiswa;

typedef struct Node{
    mahasiswa data;
    address next;
} Node;

address first=NULL;

// fungsi untuk mengalokasikan memori node baru

address alokasikan(int nim,char*nama,float ipk){
    address newNode=(address)malloc(sizeof(Node));
    strcpy(newNode->data.nama,nama);
    newNode->data.nim=nim;
    newNode->data.ipk=ipk;
    newNode->next=NULL;
}

// fungsi untuk menambah mahasiswa diawal
void insertfirst(address p){
    p->next=first;
    first=p;
}

// fungsi untuk menambahkan mahasiswa diakhir

void insertlast(address p){
    if (first==NULL)
    {
        first=p;
    }else
    {
        address temp=first;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
      temp->next=p;  
    } 
}

// fungsi untuk menghapus mahasiwa diawal
void deletfrist(){
    if (first!=NULL)
    {
        address temp=first;
        first=first->next;
        free(temp);
    }
}
// fungsi untuk menghapus diakhir
void deletlast(){
    if (first==NULL)
    {
        printf("kosong,gabisa dihapus\n");
        return;
    }
    if (first->next==NULL)
    {
        free(first);
        first=NULL;
        return;
    }
    address current = first;
    address prev = NULL;
    while (current->next!=NULL)
    {
        prev=current;
        current=current->next;
    }
    prev->next=NULL;
    free(current);
}

// fungsi untuk menampilkan semua data mahasiswa
void cetak(){
    address temp=first;
    while (temp != NULL)
    {
        printf("nim : %d,Nama : %s,ipk : %2f \n",temp->data.nim,temp->data.nama,temp->data.ipk);
        temp=temp->next;
    }   
}

// Fungsi untuk memasukkan mahasiswa secara ascending berdasarkan NIM
void insertAscending(address p) {
    if (first == NULL || first->data.nim >= p->data.nim) {
        p->next = first;
        first = p;
    } else {
        address current = first;
        while (current->next != NULL && current->next->data.nim < p->data.nim) {
            current = current->next;
        }
        p->next = current->next;
        current->next = p;
    }
}

void swapdata(address node1,address node2){
    mahasiswa temp =node1->data;
    node1->data=node2->data;
    node2->data=temp;
}

// fungsi sortir
void sortlist(){
    if (first==NULL || first->next==NULL)
    {
        return;
    }
    int swapped;
    address ptr1;
    address lptr = NULL;
    
    
}
// fungsi untuk mencetak mahasiswa secara ascending berdasarkan nim
void cetaksort(){
    sortlist();
    cetak();
}


 
int main(){
    address current;
    current=alokasikan(125,"Budi",3.5);
    insertfirst(current);
    current=alokasikan(128,"Siti",3.7);
    insertlast(current);
    current=alokasikan(126,"andi",3.8);
    insertlast(current);
    current=alokasikan(130,"desi",3.2);
    insertfirst(current);
    current=alokasikan(127,"dedi",3.9);
    insertlast(current);
    current=alokasikan(129,"saki",3.4);
    insertfirst(current);
    deletlast();
    printf("setelah dihapus satu dari belakang\n");
    cetak();
    printf("\nsetelah data diurutkan berdasarkan nim:\n");
    cetakBerdasarkanNIM();
    return;
}