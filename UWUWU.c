#include<stdio.h>
#include<string.h>
char nim[20],nama_depan[64],kelas[20],nama_belakang[64];

int main()
{
    int pilih;

    backMenu:
    printf("\nSistem Pendataan Akun I-Lab Infotech\n\n");
    printf("=== PILIH MENU ===\n\n");
    printf("1.Create data\n");
    printf("2.Show data\n");
    printf("3.Update data\n");
    printf("4.Delete data\n");
    printf("5.Search data\n");
    printf("6.Exit\n");

    printf("MASUKKAN MENU PILIHAN ANDA : ");
    scanf("%d", &pilih);

    system ("cls");

    switch(pilih){
        case 1 : 
        create_data();
        goto backMenu;
        break;

        case 2 : 
        read_data();
        goto backMenu;
        break;

        case 3 :
        update_data();
        goto backMenu;
        break;

        case 4 :
        delete_data();
        goto backMenu;
        break;
        
        case 5 :
        search_data();
        goto backMenu;
        break;

        case 6 :
        goto Exit;
        break;

        default : 
        printf("Pilihan Yang Anda Masukkan Tidak Tersdia, Silahkan Pilih Kembali ");
        goto backMenu;
        break;
    }
    goto backMenu;
Exit:
printf("\nTerima Kasih QAQA ");
}

int create_data()
{
    int q;
    char duplicate[100];
    FILE *read, *create;
    read = fopen("test.txt", "r");
    create = fopen("test.txt", "a");
    printf("Masukkan NIM : ");
    scanf("%s", &nim );
    strupr(nim);
    if (nim[0] > 64 && nim[1] > 64){
        for (q = 2; q  < strlen(nim); q++){
            if ((int)nim[q] > 47  ){
                if ((int)nim[q] <= 58){

                }
               else {
                printf("Ada Karakter Dalam Inputan Anda ");
                return 0;
               }
            }
            
               else {
                printf("Ada Karakter Dalam Inputan Anda ");
                return 0;
            }
        }
    }
    
    else {
         printf("Dua Karakter Awal Harus Menggunakan A-Z ");
         return 0;
    }
    
    while (!feof(read)){
    fscanf(read, "%[^!]!%*[^!]!%*[^!]!%*[^!]!", duplicate);
    if (strcmp(duplicate, nim ) == 0){
        printf("NIM anda sudah pernah di input ");
    fclose(read);
        return 0;
    
    }
    }

printf("MASUKKAN NAMA DEPAN : ");
scanf(" %[^\n]s", &nama_depan);
printf("MASUKKAN NAMA BELAKANG : ");
scanf(" %[^\n]s", &nama_belakang);
printf("KELAS : ");
scanf(" %[^\n]s", &kelas);
strupr(kelas);
fprintf(create, "%s!%s!%s!%s!\n" , nim, nama_depan, nama_belakang, kelas);
fclose(create);
fclose(read);

 }

 int read_data()
 {
     FILE *read; 
     read = fopen("test.txt", "r");

     while (!feof(read)){
         fscanf(read, "%[^!]!%[^!]!%[^!]!%[^!]!\n", nim, nama_depan, nama_belakang, kelas);
         printf("NIM Mahasiswa : %s\n", nim);
         printf("Nama Depan : %s\n", nama_depan);
         printf("Nama Belakang : %s\n", nama_belakang);
         printf("Kelas : %s\n\n", kelas);
    
     }
     fclose(read);
 }

 int search_data()
 {
     char golek[100];
     FILE *read; 
     read = fopen("test.txt", "r");
     printf("Cari NIM Yang Anda Inginkan ");
     scanf("%s", &golek);
     while (!feof(read)){
        fscanf(read, "%[^!]!%[^!]!%[^!]!%[^!]!\n", nim, nama_depan, nama_belakang, kelas);
         if (strcmp(nim, golek) == 0){
         printf("NIM Mahasiswa : %s\n", nim);
         printf("Nama Depan : %s\n", nama_depan);
         printf("Nama Belakang : %s\n", nama_belakang);
         printf("Kelas : %s\n\n", kelas);
         fclose(read);
         return 0;
         }
         
     }
     printf("Data Anda tidak Ditemukan ");
     fclose(read);
    
 }

int update_data()
{
    FILE *read, *ubah;
    read = fopen("test.txt", "r");
    ubah = fopen("File_tumbal.txt", "w");
    char search[100];
    printf("Cari NIM Untuk Di Update : ");
    scanf("%s", search);
    while(!feof(read)){
        fscanf(read, "%[^!]!%[^!]!%[^!]!%[^!]!\n", nim, nama_depan, nama_belakang, kelas);
        if (strcmp(search, nim) == 0)
        {
            printf("Ubah Nama Depan : ");
            scanf(" %[^\n]s", &nama_depan);
            printf("Ubah Nama Belakang : ");
            scanf(" %[^\n]s", &nama_belakang);
            printf("Ubah kelas : ");
            scanf(" %[^\n]s", &kelas);
            fprintf(ubah, "%s!%s!%s!%s!\n" , nim, nama_depan, nama_belakang, kelas);
            
        }
        else {
            fprintf(ubah, "%s!%s!%s!%s!\n" , nim, nama_depan, nama_belakang, kelas);
        }

    }
    fclose(ubah);
    fclose(read);
    remove("test.txt");
    rename("File_tumbal.txt", "test.txt" );
}

int delete_data()
{
    FILE *read, *delete;
    read = fopen("test.txt", "r");
    delete = fopen("File_tumbal.txt", "w");
    char search[100];
    printf("Cari NIM Untuk Di Hapus : ");
    scanf("%s", search);
    while(!feof(read)){
        fscanf(read, "%[^!]!%[^!]!%[^!]!%[^!]!\n", nim, nama_depan, nama_belakang, kelas);
        if (strcmp(search, nim) == 0)
        {
            
        }
        else {
            fprintf(delete, "%s!%s!%s!%s!\n" , nim, nama_depan, nama_belakang, kelas);
        }

    }
    fclose(delete);
    fclose(read);
    remove("test.txt");
    rename("File_tumbal.txt", "test.txt" );
}