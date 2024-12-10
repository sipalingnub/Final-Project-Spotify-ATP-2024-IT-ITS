#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct song{
    char title[100];
    char singer[100];
    struct song* next;
};



struct playlist {
    char name[100];
    char title[100];
    char singer[100];
    struct playlist* next;
};

// create
struct song* createSong(char title[], char singer[]) 
{
    struct song* newSong = (struct song*) malloc(sizeof(struct song));

    strcpy(newSong -> title, title);
    strcpy(newSong -> singer, singer); 
    newSong -> next = NULL; 

    return newSong;
} 


struct playlist* createPlaylist(char name[], char title[], char singer[]) {
    struct playlist* newPlaylist = (struct playlist*)malloc(sizeof(struct playlist));

    strcpy(newPlaylist-> name, name);
    strcpy(newPlaylist-> title, title);
    strcpy(newPlaylist-> singer, singer); 
    newPlaylist->next = NULL;
    return newPlaylist;
} 
//Playlist;

// Insert
// Insert at End
struct song* insertSongFromUser(struct song* head, char title[], char singer[]) {
    struct song* newSong = createSong(title, singer);
    if (head == NULL) return newSong;

    struct song* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newSong;
    return head;
} 



// insert Song to Playlist
struct playlist* addSongtoPlaylist(struct playlist* head_p, char title[], char singer[]) {
    if (head_p == NULL) {
        printf("Sorry, playlist not found\n");
        return NULL;
    }

    struct playlist* newSong = createPlaylist("-", title, singer);

    struct playlist* temp = head_p;
    while (temp->name != NULL) {
        struct playlist* temp = temp->next;

            while (temp->next->name != NULL) {
                temp = temp->next;
            }
            strcpy(temp->next->name, newSong->name);
            strcpy(temp->next->title, newSong->title);
            strcpy(temp->next->singer, newSong->singer); 
            return head_p; 
        }
        temp = temp->next;
    

    printf("Playlist not found\n");
    return head_p; 
}

void search(struct song* head, char key[]) {
    struct song* current = head;
    int index = 0;
    while (current != NULL) {
        if (strcmp((current->next)->title, key) == 1) {
            printf("%s", current->singer);
            break; // Element found
        }
        current = current->next;
    }
    // printf("elemen tidak ditemukan.\n");
     // Element not found
}


// Delete at Index
struct song* deleteSong(struct song* head, int index) {
    struct song* temp = head;                                       
    struct song* temp_delete; 

    for (int i = 0; i < index - 1 && temp != NULL; i++)
    {        
        temp = temp -> next;                  
    }

    if (temp_delete == NULL) return head;            
    temp_delete = temp -> next;                       
    temp -> next = temp -> next -> next;                    
    free(temp_delete);                                    
    return head;  
}

struct playlist* deletePlaylist(struct playlist* head, int index) {
    struct playlist* temp = head;                                         
    struct playlist* temp_delete;                                  

    for (int i = 0; i < index - 1 && temp != NULL; i++)
    {                                                           
        temp = temp -> next;                                     
    }

    if (temp_delete = NULL) return head;                        
    temp_delete = temp -> next;                                  
    temp -> next = temp -> next -> next;                      
    free(temp_delete);                                        
    return head;  
}



void printSong(struct song *head)                                           
{
    printf("Title \t\t\t\t\b\b| Singer\n");
    printf("============================================================\n");
    struct song* temp = head;                          
    while (temp != NULL)                                               
    {                 
        printf("%-30s| %-30s\n", temp->title, temp->singer);   
        temp = temp -> next;                           
    }
    printf("\n\n");

}

void printPlaylist(struct playlist *head)                                           
{
    struct playlist* temp = head;
    printf("Title \t\t\t\t\b\b| Singer\n");
    printf("============================================================\n");                          
    while (temp != NULL)                                               
    {                 
        printf("%-30s| %-30s\n", temp->title, temp->singer);   
        temp = temp -> next;                           
    }
    printf("\n\n");
}
    
// }
void bubbleSortSongs(struct song* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct song* current;
    struct song* last = NULL;
    int swapped;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (strcmp(current->title, current->next->title) > 0) {
                char tempTitle[100];
                char tempSinger[100];

                strcpy(tempTitle, current->title);
                strcpy(tempSinger, current->singer);

                strcpy(current->title, current->next->title);
                strcpy(current->singer, current->next->singer);

                strcpy(current->next->title, tempTitle);
                strcpy(current->next->singer, tempSinger);

                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}


void menu(struct playlist* head_p, struct song* head);
void header(struct playlist* head_p, struct song* head);
void tambahkan_lagu(struct playlist* head_p, struct song* head);
void munculkan_lagu(struct playlist* head_p, struct song* head);
void munculkan_playlist(struct playlist* head_p, struct song* head);
void urutkan_lagu(struct playlist* head_p, struct song* head);
void song_to_playlist(struct playlist* head_p, struct song* head);
void nol(struct playlist* head_p, struct song* head);
void kredit(struct playlist* head_p, struct song* head);
void kredit(struct playlist* head_p, struct song* head);
// --------------------------------- I N T   M A I N ------------------------------------

int main()
{
    struct song* head = createSong("Hymne ITS", "Sri Amiranti");
    head -> next = createSong("Sialan", "Juicy Luicy & Adrian Khalif");
    head -> next -> next = createSong("Aku yang jatuh Cinta", "Dudy Oris");
    struct playlist* head_p = createPlaylist("Ini Playlist", "-", "-");

    menu(head_p, head);


}

// -------------------------------- F U N G S I   U I -----------------------------------

void menu(struct playlist* head_p, struct song* head)
{
    header(head_p, head);
    printf("           Selamat datang di Spotify Mantappu Jiwa         \n\n");

    printf("1. Munculkan lagu\n");
    printf("2. Munculkan playlist\n");
    printf("3. Tambahkan lagu\n");
    printf("4. Tambahkan lagu ke playlist\n");
    printf("5. Kredit\n");
    printf("0. Keluar\n");

    
    printf("\n Silahkan masukkan input angka : ");
    int n; scanf("%d", &n);

    switch (n)
    {
        case 1:
            system("cls");
            munculkan_lagu(head_p, head);
            break;
        case 2:
            system("cls");
            munculkan_playlist(head_p, head);
            break;

        case 3:
            system("cls");
            tambahkan_lagu(head_p, head);
            break;
   
        case 4:
            system("cls");
            song_to_playlist(head_p,head);
            break;
        
        case 5:
            system("cls");
            kredit(head_p, head);
            break;
                    
        case 0:
            exit(1);
            break;

        default:
            // system("cls");
            // delay(5);
            printf("Maaf, input yang anda masukkan salah");


    }

}
void header(struct playlist* head_p, struct song* head)
{
    printf("============================================================\n");
    printf("======================= S P O T I F Y ======================\n");
    printf("============================================================\n\n");
    


}

void tambahkan_lagu(struct playlist* head_p, struct song* head)
{
    header(head_p, head);
    char title[30], singer [30];
    int n;
    printf("Masukkan judul lagu : ");
    scanf("%s", &title);
    
    printf("Masukkan penyanyi : ");
    scanf("%s", &singer);

    insertSongFromUser(head, title, singer);

    printf("\n\nApakah ingin ditambahkan ke playlist?\n");
    printf("  1. Ya\n");
    printf("  0. Tidak\n");

    scanf("%d", &n);

    switch (n)
    {
        // case 1:
        //     system("cls");
        //     tambahkan_lagu(head_p, head);
        //     break;            
        case 0:
            system("cls");
            menu(head_p, head);
            break;
    }

}
void munculkan_lagu(struct playlist* head_p, struct song* head)
{
    header(head_p, head);
    printf("                      L I S T   L A G U                     \n\n");
    printSong(head);
    printf("Input Angka\n");
    printf("  1. Tambahkan lagu\n");
    printf("  2. Munculkan playlist\n");
    printf("  3. Tambahkan lagu ke playlist\n");
    printf("  4. urutkan lagu (berdasarkan judul lagu)\n");
    printf("  0. Kembali ke menu\n");
    printf("\n Silahkan masukkan input angka : ");
    int n; scanf("%d", &n);

    switch (n)
    {
        case 1:
            system("cls");
            tambahkan_lagu(head_p, head);
            break;

        case 2:
            system("cls");
            munculkan_playlist(head_p, head);
            break;
        case 4:
            system("cls");
            urutkan_lagu(head_p, head);
            break;

        case 0:
            system("cls");
            menu(head_p, head);
            break;

        default:
            // system("cls");
            // delay(5);
            printf("Maaf, input yang anda masukkan salah");


    }
    bubbleSortSongs(head);
}

void munculkan_playlist(struct playlist* head_p, struct song* head)
{
    header(head_p, head);
    printf("                  L I S T   P L A Y L I S T                 \n\n");

    char title[100];
    char singer[100];
    
    printPlaylist(head_p);

    printf("Tekan 0 (enter) untuk kembali ke menu : \n");
    int n; scanf("%d", &n);

    switch (n)
    {
        case 0:
            system("cls");
            menu(head_p, head);
            break;
        default:
            // system("cls");
            // delay(5);
            printf("Maaf, input yang anda masukkan salah");
    }
}

void urutkan_lagu(struct playlist* head_p, struct song* head)
{
    bubbleSortSongs(head);
    printf("Lagu sudah diurutkan\n");
    printf("Tekan 0 (enter) untuk kembali ke menu");
    int n; scanf("%d", &n);

    switch (n)
    {
        case 0:
            system("cls");
            menu(head_p, head);
            break;
        default:
            // system("cls");
            // delay(5);
            printf("Maaf, input yang anda masukkan salah");
    }
}

void song_to_playlist(struct playlist* head_p, struct song* head)
{
    header(head_p, head);
    char title[30], singer [30];
    int bisa = 0;

    printf("Masukkan judul lagu : ");
    scanf("%s", &title);

    struct song* temp = head;
    while (temp ->next != NULL)
    {
        // printf("%d", strcmp(temp->title, title));
        if (strcmp(temp->title, title) == 0)
        {
            
            strcmp(singer, temp->singer);
            addSongtoPlaylist(head_p, title, singer);
            nol(head_p,head);
            bisa = 1;
            break;
        }
        if (bisa != 1) temp = temp -> next;


    }

    if (bisa == 1)
    {
        
        system("cls");
        menu(head_p, head);
    }
    else
    {
        printf("Maaf, lagu tidak ditemukan.\n\n");
        nol(head_p,head);
    }

    
}

void nol(struct playlist* head_p, struct song* head)
{
    printf("Tekan 0 (enter) untuk kembali ke menu : \n");
        int n; scanf("%d", &n);

        switch (n)
        {
            case 0:
                system("cls");
                menu(head_p, head);
                break;
            default:
                // system("cls");
                // delay(5);
                printf("Maaf, input yang anda masukkan salah");
        }
}
void kredit(struct playlist* head_p, struct song* head)
{
    header(head_p, head);
    printf("Anggota:\n");
    printf("1. Balqis Sani Sabillah (5027241002)\n");
    printf("2. Muhammad Khairul Yahya (5027241092)\n");
    printf("3. Jofanka Al-kautsar Pangestu Abady (5027241107)\n");
    printf("4. Putri Joselina Silitonga (5027241116)\n\n");

    printf("Tekan 0 (enter) untuk kembali ke menu : ");
    int n; scanf("%d", &n);

    switch (n)
    {
        case 0:
            system("cls");
            menu(head_p, head);
            break;
        default:
            // system("cls");
            // delay(5);
            printf("Maaf, input yang anda masukkan salah");
    }

}



