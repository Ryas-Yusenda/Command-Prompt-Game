#include <iostream>
#include <windows.h> //Liblary HANDLE hCon
#include <string.h>
#include <cstdlib> //Liblary rand, pada void dadu
#include <time.h> //Liblary time, pada void dadu
#include <iomanip> //Liblary setw()
#include <fstream> //library file
#include <conio.h> //library file

using namespace std;

struct pemainn{
           char nama[1000];
           int skor=0,tampil=0;
           int posisi=0;
           int batas_H,batas_v,menang=0;
           int right=0,left=0;
};
pemainn *pe = (pemainn *)malloc(10000 * sizeof(pemainn));

void pemain(), dadu(), panel(), posisi(), skor();
void file(), getListNamaUser(), papanSkor(),searching();
void setcolor(unsigned short color)/*Untuk Pemberian Warna di cmd// Selesai*/{
   /*Untuk Pemberian warna pada cmd. dengan memakai hCon, dengan include <windows.h>*/
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hCon,color);
}
void mergeSort(pemainn[], int, int);
void merge(pemainn[], int, int, int);


int daduu=0,urut_pemain=0,sudah_isi=0,menang=0,jumm=0,juara=0;
int warna_pemain[5]={64,32,16,96,80}; //Warna Setiap pemain
int salin[10000];//Tempat salinan Skor

ofstream GetNamaUser; //untuk mengambil file
ifstream ViewNamaUser; //untuk menampilkan file
string DataUser;

int main()/*Jalankan Seluruh Program// */{
string pilih,main_kembali;
   system("mode 79,60"); //ukuran cmd
   system("title Es Nuestro Juego"); //nama aplikasi
do {
system("cls");
setcolor(3);
cout<<"1. Main Game\n2. List skor\n3. Cari Nama\n\n Pilih : ";setcolor(6);cin>>pilih;
if (pilih=="1")/*Main Game*/ {
         daduu=0;urut_pemain=0;sudah_isi=0;menang=0;juara=0;
         for (int i = 0; i < jumm; i++){ //Dikembalikan lagi variabel ke awal biar bisa bermain lagi
            pe[i].tampil=0;pe[i].skor=0;pe[i].posisi=0;
            pe[i].batas_H=0;pe[i].batas_v=0;pe[i].menang=0;
         }
   if (sudah_isi==0){pemain();} //Jika sudah diinputkan, maka tidak diinput lagi
      do {
         panel();
         dadu();
         //getch();
         for (int ll = 0; ll < jumm; ll++) {salin[ll]=pe[ll].skor;}
               menang=pe[0].menang+ pe[1].menang+ pe[2].menang+ pe[3].menang+ pe[4].menang;
            if (menang==jumm) file(); //untuk menyimpan nama pemain
         } while(menang!=jumm);
         system("cls");panel();
}
 else if (pilih=="2")/* List Skor*/ {
	 papanSkor();
    getch();
}
 else if (pilih=="3")/* Cari Nama*/ {
   getListNamaUser();
   searching();
   getch();
}
} while(pilih!="1" && pilih!="2" && pilih!="3");

main();
}

void syarat()/*Peraturan dalam permainan// Selesai*/{
   setcolor(12);
   cout<<"1. Pemain terdiri dari 1 sampai 5\n";
   cout<<"2. Skor betambah 25 jika naik tangga\n";
   cout<<"3. Skor akan berkurang 10 jika kenak ular\n";
   cout<<"4. Jika posisi pemain sama makan pemain yang Maju akan turun ke posisi 0\n";
   cout<<"5. Pemain yang juara akan mendapat mendapat skor tambahan 100/90/80/70/60\n\n";
   //Kalau lewat dari 100 maka dia akan jalan mundur sebnyk jumlah dadu
}

void pemain()/*Untuk Input Para Pemain// Selesai*/{
string jum;
int panjang;

   do {

      system("cls");

      setcolor(3);cout<<"Masukan Jumlah Pemain(Max.5) : ";setcolor(6);cin>>jum;
      setcolor(3);cout<<"(Max.huruf 6)\n";
      if (jum=="1")jumm=1;
      else if (jum=="2")jumm=2;
      else if (jum=="3")jumm=3;
      else if (jum=="4")jumm=4;
      else if (jum=="5")jumm=5;
   } while(jum!="1" && jum!="2" && jum!="3" && jum!="4" && jum!="5");//Batas Pemain Hanya 5 Pemain

      cin.ignore();
      for (int i = 0; i < jumm; i++) {
         do{//Agar inputny kalau False. tidak membuat baris input baru
            system("cls");
            if (panjang<=7 || panjang>0) {
               syarat();
               setcolor(3);cout<<"Masukan Jumlah Pemain(Max.5) : ";setcolor(6);cout<<jumm;
               setcolor(3);cout<<"\n(Max.huruf 6)\n";
               for (int j = 0; j < jumm; j++) {
                  if (pe[j].tampil==1){ //Mengecek jika input sudah berhasil dilakukan, dan ditampilkan ulang
                     setcolor(9);cout<<"  Nickname P."<<j+1<<" : ";setcolor(6);cout<<pe[j].nama<<endl;
                     }
               }
            }
            setcolor(9);
            cout<<"  Nickname P."<<i+1<<" : ";setcolor(6);cin.getline(pe[i].nama, sizeof(pe[i].nama));
            panjang=strlen(pe[i].nama);//Menghitung panjang dari (pe[i].nama)

         }while(panjang>=7 && panjang>0);//Batas Panjang nama dari 1-6
            pe[i].tampil=1; //Menset jika Inputan Berhasil


      }

sudah_isi=1;
}

void posisi()/*Untuk Memeberika lokasi pemain untuk tampil di panel// Selesai*/{
int skor_menang[5]={100,90,80,70,60};
   for (int i = 0; i <jumm; i++)/*Memberika Lokasi pemain sesuai nomor*/ {
      if (pe[i].posisi==0) {pe[i].batas_H=100; pe[i].batas_v=100;
      }else if (pe[i].posisi==1) {pe[i].batas_H=6; pe[i].batas_v=39;
      }else if (pe[i].posisi==2) {pe[i].batas_H=12; pe[i].batas_v=39;
      }else if (pe[i].posisi==3) {pe[i].batas_H=18; pe[i].batas_v=39;
      }else if (pe[i].posisi==4) {pe[i].batas_H=24; pe[i].batas_v=39;
      }else if (pe[i].posisi==5) {pe[i].batas_H=30; pe[i].batas_v=39;
      }else if (pe[i].posisi==6) {pe[i].batas_H=36; pe[i].batas_v=39;
      }else if (pe[i].posisi==7) {pe[i].batas_H=42; pe[i].batas_v=39;
      }else if (pe[i].posisi==8) {pe[i].batas_H=48; pe[i].batas_v=39;
      }else if (pe[i].posisi==9) {pe[i].batas_H=54; pe[i].batas_v=39;
      }else if (pe[i].posisi==10) {pe[i].batas_H=60; pe[i].batas_v=39;
      }else if (pe[i].posisi==20) {pe[i].batas_H=6; pe[i].batas_v=35;
      }else if (pe[i].posisi==19) {pe[i].batas_H=12; pe[i].batas_v=35;
      }else if (pe[i].posisi==18) {pe[i].batas_H=18; pe[i].batas_v=35;
      }else if (pe[i].posisi==17) {pe[i].batas_H=24; pe[i].batas_v=35;
      }else if (pe[i].posisi==16) {pe[i].batas_H=30; pe[i].batas_v=35;
      }else if (pe[i].posisi==15) {pe[i].batas_H=36; pe[i].batas_v=35;
      }else if (pe[i].posisi==14) {pe[i].batas_H=42; pe[i].batas_v=35;
      }else if (pe[i].posisi==13) {pe[i].batas_H=48; pe[i].batas_v=35;
      }else if (pe[i].posisi==12) {pe[i].batas_H=54; pe[i].batas_v=35;
      }else if (pe[i].posisi==11) {pe[i].batas_H=60; pe[i].batas_v=35;
      }else if (pe[i].posisi==21) {pe[i].batas_H=6; pe[i].batas_v=31;
      }else if (pe[i].posisi==22) {pe[i].batas_H=12; pe[i].batas_v=31;
      }else if (pe[i].posisi==23) {pe[i].batas_H=18; pe[i].batas_v=31;
      }else if (pe[i].posisi==24) {pe[i].batas_H=24; pe[i].batas_v=31;
      }else if (pe[i].posisi==25) {pe[i].batas_H=30; pe[i].batas_v=31;
      }else if (pe[i].posisi==26) {pe[i].batas_H=36; pe[i].batas_v=31;
      }else if (pe[i].posisi==27) {pe[i].batas_H=42; pe[i].batas_v=31;
      }else if (pe[i].posisi==28) {pe[i].batas_H=48; pe[i].batas_v=31;
      }else if (pe[i].posisi==29) {pe[i].batas_H=54; pe[i].batas_v=31;
      }else if (pe[i].posisi==30) {pe[i].batas_H=60; pe[i].batas_v=27;
      }else if (pe[i].posisi==40) {pe[i].batas_H=6; pe[i].batas_v=27;
      }else if (pe[i].posisi==39) {pe[i].batas_H=12; pe[i].batas_v=27;
      }else if (pe[i].posisi==38) {pe[i].batas_H=18; pe[i].batas_v=27;
      }else if (pe[i].posisi==37) {pe[i].batas_H=24; pe[i].batas_v=27;
      }else if (pe[i].posisi==36) {pe[i].batas_H=30; pe[i].batas_v=27;
      }else if (pe[i].posisi==35) {pe[i].batas_H=36; pe[i].batas_v=27;
      }else if (pe[i].posisi==34) {pe[i].batas_H=42; pe[i].batas_v=27;
      }else if (pe[i].posisi==33) {pe[i].batas_H=48; pe[i].batas_v=27;
      }else if (pe[i].posisi==32) {pe[i].batas_H=54; pe[i].batas_v=27;
      }else if (pe[i].posisi==31) {pe[i].batas_H=60; pe[i].batas_v=27;
      }else if (pe[i].posisi==41) {pe[i].batas_H=6; pe[i].batas_v=23;
      }else if (pe[i].posisi==42) {pe[i].batas_H=12; pe[i].batas_v=23;
      }else if (pe[i].posisi==43) {pe[i].batas_H=18; pe[i].batas_v=23;
      }else if (pe[i].posisi==44) {pe[i].batas_H=24; pe[i].batas_v=23;
      }else if (pe[i].posisi==45) {pe[i].batas_H=30; pe[i].batas_v=23;
      }else if (pe[i].posisi==46) {pe[i].batas_H=36; pe[i].batas_v=23;
      }else if (pe[i].posisi==47) {pe[i].batas_H=42; pe[i].batas_v=23;
      }else if (pe[i].posisi==48) {pe[i].batas_H=48; pe[i].batas_v=23;
      }else if (pe[i].posisi==49) {pe[i].batas_H=54; pe[i].batas_v=23;
      }else if (pe[i].posisi==50) {pe[i].batas_H=60; pe[i].batas_v=23;
      }else if (pe[i].posisi==60) {pe[i].batas_H=6; pe[i].batas_v=19;
      }else if (pe[i].posisi==59) {pe[i].batas_H=12; pe[i].batas_v=19;
      }else if (pe[i].posisi==58) {pe[i].batas_H=18; pe[i].batas_v=19;
      }else if (pe[i].posisi==57) {pe[i].batas_H=24; pe[i].batas_v=19;
      }else if (pe[i].posisi==56) {pe[i].batas_H=30; pe[i].batas_v=19;
      }else if (pe[i].posisi==55) {pe[i].batas_H=36; pe[i].batas_v=19;
      }else if (pe[i].posisi==54) {pe[i].batas_H=42; pe[i].batas_v=19;
      }else if (pe[i].posisi==53) {pe[i].batas_H=48; pe[i].batas_v=19;
      }else if (pe[i].posisi==52) {pe[i].batas_H=54; pe[i].batas_v=19;
      }else if (pe[i].posisi==51) {pe[i].batas_H=60; pe[i].batas_v=19;
      }else if (pe[i].posisi==61) {pe[i].batas_H=6; pe[i].batas_v=15;
      }else if (pe[i].posisi==62) {pe[i].batas_H=12; pe[i].batas_v=15;
      }else if (pe[i].posisi==63) {pe[i].batas_H=18; pe[i].batas_v=15;
      }else if (pe[i].posisi==64) {pe[i].batas_H=24; pe[i].batas_v=15;
      }else if (pe[i].posisi==65) {pe[i].batas_H=30; pe[i].batas_v=15;
      }else if (pe[i].posisi==66) {pe[i].batas_H=36; pe[i].batas_v=15;
      }else if (pe[i].posisi==67) {pe[i].batas_H=42; pe[i].batas_v=15;
      }else if (pe[i].posisi==68) {pe[i].batas_H=48; pe[i].batas_v=15;
      }else if (pe[i].posisi==69) {pe[i].batas_H=54; pe[i].batas_v=15;
      }else if (pe[i].posisi==70) {pe[i].batas_H=60; pe[i].batas_v=15;
      }else if (pe[i].posisi==80) {pe[i].batas_H=6; pe[i].batas_v=11;
      }else if (pe[i].posisi==79) {pe[i].batas_H=12; pe[i].batas_v=11;
      }else if (pe[i].posisi==78) {pe[i].batas_H=18; pe[i].batas_v=11;
      }else if (pe[i].posisi==77) {pe[i].batas_H=24; pe[i].batas_v=11;
      }else if (pe[i].posisi==76) {pe[i].batas_H=30; pe[i].batas_v=11;
      }else if (pe[i].posisi==75) {pe[i].batas_H=36; pe[i].batas_v=11;
      }else if (pe[i].posisi==74) {pe[i].batas_H=42; pe[i].batas_v=11;
      }else if (pe[i].posisi==73) {pe[i].batas_H=48; pe[i].batas_v=11;
      }else if (pe[i].posisi==72) {pe[i].batas_H=54; pe[i].batas_v=11;
      }else if (pe[i].posisi==71) {pe[i].batas_H=60; pe[i].batas_v=11;
      }else if (pe[i].posisi==81) {pe[i].batas_H=6; pe[i].batas_v=7;
      }else if (pe[i].posisi==82) {pe[i].batas_H=12; pe[i].batas_v=7;
      }else if (pe[i].posisi==83) {pe[i].batas_H=18; pe[i].batas_v=7;
      }else if (pe[i].posisi==84) {pe[i].batas_H=24; pe[i].batas_v=7;
      }else if (pe[i].posisi==85) {pe[i].batas_H=30; pe[i].batas_v=7;
      }else if (pe[i].posisi==86) {pe[i].batas_H=36; pe[i].batas_v=7;
      }else if (pe[i].posisi==87) {pe[i].batas_H=42; pe[i].batas_v=7;
      }else if (pe[i].posisi==88) {pe[i].batas_H=48; pe[i].batas_v=7;
      }else if (pe[i].posisi==89) {pe[i].batas_H=54; pe[i].batas_v=7;
      }else if (pe[i].posisi==90) {pe[i].batas_H=60; pe[i].batas_v=7;
      //}else if (pe[i].posisi==100) {pe[i].batas_H=6; pe[i].batas_v=3; //Kalau udah 100 tidak ditampilkan lagi
      }else if (pe[i].posisi==99) {pe[i].batas_H=12; pe[i].batas_v=3;
      }else if (pe[i].posisi==98) {pe[i].batas_H=18; pe[i].batas_v=3;
      }else if (pe[i].posisi==97) {pe[i].batas_H=24; pe[i].batas_v=3;
      }else if (pe[i].posisi==96) {pe[i].batas_H=30; pe[i].batas_v=3;
      }else if (pe[i].posisi==95) {pe[i].batas_H=36; pe[i].batas_v=3;
      }else if (pe[i].posisi==94) {pe[i].batas_H=42; pe[i].batas_v=3;
      }else if (pe[i].posisi==93) {pe[i].batas_H=48; pe[i].batas_v=3;
      }else if (pe[i].posisi==92) {pe[i].batas_H=54; pe[i].batas_v=3;
      }else if (pe[i].posisi==91) {pe[i].batas_H=60; pe[i].batas_v=3;
      }
   }
   if (pe[urut_pemain].posisi==100 && pe[urut_pemain].menang==0) {//Jika posisi sudah menang //Skor tambahan jika juara 1 -6
      pe[urut_pemain].skor=pe[urut_pemain].skor+skor_menang[juara];
      juara=juara+1;
      pe[urut_pemain].menang=1;

   }
}

void skor()/*Berisi sistem skor dan +25Poin kalau naik tangga dan -20poin kalau kenak ular// Selesai*/{
	GetNamaUser.open("DataUser.txt", ios::app);

pe[urut_pemain].posisi=pe[urut_pemain].posisi+daduu;//Posisi Pemain Setelah dapat dadu
if (pe[urut_pemain].posisi>100) {//Jika lebih dari posisi 100
   pe[urut_pemain].posisi=100-(pe[urut_pemain].posisi-100);
}

   if (true)/*Perubahan kalau posisi pemain di tangga atau ular*/{
    /*SNAKE1*/if (pe[urut_pemain].posisi==17) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi-10;
      pe[urut_pemain].skor=pe[urut_pemain].skor-10;
   }/*SNAKE2*/else if (pe[urut_pemain].posisi==62) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi-43;
      pe[urut_pemain].skor=pe[urut_pemain].skor-10;
   }/*SNAKE3*/else if (pe[urut_pemain].posisi==87) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi-63;
      pe[urut_pemain].skor=pe[urut_pemain].skor-10;
   }/*SNAKE4*/else if (pe[urut_pemain].posisi==54) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi-20;
      pe[urut_pemain].skor=pe[urut_pemain].skor-10;
   }/*SNAKE5*/else if (pe[urut_pemain].posisi==64) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi-4;
      pe[urut_pemain].skor=pe[urut_pemain].skor-10;
   }/*SNAKE6*/else if (pe[urut_pemain].posisi==93) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi-20;
      pe[urut_pemain].skor=pe[urut_pemain].skor-10;
   }/*SNAKE7*/else if (pe[urut_pemain].posisi==95) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi-20;
      pe[urut_pemain].skor=pe[urut_pemain].skor-10;
   }/*SNAKE8*/else if (pe[urut_pemain].posisi==99) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi-21;
      pe[urut_pemain].skor=pe[urut_pemain].skor-10;
   }/*STAIR1*/else if (pe[urut_pemain].posisi==4) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi+10;
      pe[urut_pemain].skor=pe[urut_pemain].skor+25;
   }/*STAIR2*/else if (pe[urut_pemain].posisi==9) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi+22;
      pe[urut_pemain].skor=pe[urut_pemain].skor+25;
   }/*STAIR3*/else if (pe[urut_pemain].posisi==20) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi+18;
      pe[urut_pemain].skor=pe[urut_pemain].skor+25;
   }/*STAIR4*/else if (pe[urut_pemain].posisi==28) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi+56;
      pe[urut_pemain].skor=pe[urut_pemain].skor+25;
   }/*STAIR5*/else if (pe[urut_pemain].posisi==40) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi+19;
      pe[urut_pemain].skor=pe[urut_pemain].skor+25;
   }/*STAIR6*/else if (pe[urut_pemain].posisi==51) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi+16;
      pe[urut_pemain].skor=pe[urut_pemain].skor+25;
   }/*STAIR7*/else if (pe[urut_pemain].posisi==63) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi+18;
      pe[urut_pemain].skor=pe[urut_pemain].skor+25;
   }/*STAIR8*/else if (pe[urut_pemain].posisi==71) {
      pe[urut_pemain].posisi=pe[urut_pemain].posisi+20;
      pe[urut_pemain].skor=pe[urut_pemain].skor+25;
   }
   }
   if (pe[urut_pemain].skor<0   ) pe[urut_pemain].skor=0;//Agar Skor tidak kurang dari 0
   if (pe[urut_pemain].skor>1000) pe[urut_pemain].skor=1000;//Agar Skor tidak lebih dari 1000


for (int i = 0; i < jumm; i++)/*Jika Pemain yang maju ke posisi yang sudah ada pemainnya*/ {
   if (pe[i].posisi!=0 //tidak !=0 karena posisi awaldr semua itu 0
      && pe[urut_pemain].posisi==pe[i].posisi //ini kalau posisi sama
      && i!=urut_pemain //ini biar dia tidak membandingkan dengan posisinya sendiri
      && pe[i].posisi!=100
   ) {pe[urut_pemain].posisi=0;
   }
}

   posisi();
   GetNamaUser.close();

}

void dadu()/*Untuk pergerakan pemain// Selesai*/{
   string lanjut;
do {
   if (pe[urut_pemain].menang==0){
   cout << "\nSilahkan Lempar dadu P"<<urut_pemain+1<<endl;
   cout << "Lempar dadu? (y/n) : ";cin>>lanjut;
      if(lanjut == "y"||lanjut == "Y"){
         srand(time(0));//Agar angkannya acak dari sebelumnya,
         daduu=1 + (rand() % 6);
         skor();
         cout << daduu << endl;
         getch();
         urut_pemain=urut_pemain+1; //Lanjut ke pemain berikutnya
         if (urut_pemain==jumm)urut_pemain=0; //Jika pemain sudah yang ke total main, maka kembali ke0
      }else if(lanjut == "n"||lanjut == "N"){
         urut_pemain=urut_pemain+1; //Lanjut ke pemain berikutnya
         if (urut_pemain==jumm)urut_pemain=0; //Jika pemain sudah yang ke total main, maka kembali ke0
      }else{
         cout << "Warning!! MASUKIN Y/N DONG AH....!!"<<endl;
      }
   }else{
      urut_pemain=urut_pemain+1; //Lanjut ke pemain berikutnya
      if (urut_pemain==jumm)urut_pemain=0;} //Jika pemain sudah yang ke5, maka kembali ke1
   } while(lanjut!="Y" && lanjut!="y" && lanjut!="N" && lanjut!="n"); //Jika user salah input
}

void panel()/*Untuk Menamplkan Tabel, pemain, skor (Realtime)// Selesai*/{
system("cls");

int label=100;
int label1=81;
int urut[2]={0,0};

int urut_stair[16]={8,7,4,8,7,6,5,6,5,3,2,4,3,1,1,2}; //urutan tangga
int urut_snake[16]={8,7,6,3,8,7,6,2,5,5,4,4,3,2,1,1}; //urutan ular

setcolor(12);cout<<"__|_";
setcolor(3);cout<<"Skor";
setcolor(12);cout<<"_|__";
setcolor(6);cout<<"Nama";
setcolor(12);cout<<"__|_";
setcolor(2);cout<<"Posisi";
setcolor(12);cout<<"_|_";
setcolor(4);cout<<"Keterangan";
setcolor(12);cout<<"_|\n";

for (int i = 0; i < jumm; i++)/*Menampilkan data yang sedang bermain*/ {
   setcolor(12);cout<<"P"<<i+1<<". ";
   setcolor(3);cout<< setw(4)<<pe[i].skor;
   setcolor(12);cout<<" | ";
   setcolor(6);cout<< setw(6)<<pe[i].nama;
   setcolor(12);cout<<" | ";
   setcolor(2);cout<<setw(6)<<pe[i].posisi;
   if (pe[i].menang==1) { //Menampilkan Pemain kalau menang
      setcolor(12);cout<<" |   ";
      setcolor(warna_pemain[i]);cout<<"MENANG";
      setcolor(12);cout<<"   |";
   }
   else{// ini kalau belum menang
      setcolor(12);cout<<" |            |";}
   cout<<endl;
}

for (int j = 1; j <=41; j++) { //J atas bawah
   for (int i = 1; i <=71; i++) { //I kiri kanan
      if ((i-1)%6==0 && j!=((j-1)%6==0) && i<=61) {// unutk membuat tabel
         setcolor(3);
         cout << "|";
      }
      if (((j-1)%4==0 && i<=60) || j==1) {//untuk membuat tabel
         setcolor(3);
         cout <<"_";
      }
      else{//untuk yang didalam kotak
         if (i<=60){//untuk yang didalam kotak, 6(panjang didalam kotak)*10(jumlah setiap baris)=60.
            if (j%2==0 && i%6==0 && j%4!=0){// untuk meletakkan nomor disudut kanan atas kotak

               //100,80,60,40,20 maka selisihny 20, mereka satu kelompok karena label++
               //81,61,41,21,1  ,maka selisihny 20, mereka satu kelompok karena label--
               //selisih setiap dari baris itu 20 maka,
               //label dikurangi pada baris 131 sebanyk 10. lalu dikurangi lagi dibaris 127
               //label1 dikurang 30 pada baris 132, karena dibaris ke 110 label1 telah ditambah 126

               if (j==6 || j==14 || j==22 || j==30 || j==38) {//ini untuk menampilkan angka yang dihitung tambah (81,61,41,21,1)
                  setcolor(6);
                  cout<<setw(6)<<label1;
                  label1=label1+1;//tambah10
                     if (i==6) {label=label-10;} //untuk mengurangi nilai yang dibawah(label)
               }
               else{// ini untuk menampilkan angka yang dihitung kurang (100,80,60,40,20)
                  setcolor(6);
                  cout<<setw(6)<<label;
                  label=label-1;//kurang10
                     if (i==6 && j>6) {label1=label1-30;} //untuk mengurangi nilai yang diatas(label1)
               }
            }
            else{ //Meletakan lokasi ular dan tangga
            if (j%4==0 && i%6==0) {//J =X4, i=X6
               if ( (j==4 && i==60) //Tempat Lokasi Tangga
                 || (j==8 && i==24) || (j==8 && i==6)
                 || (j==12 && i==60)
                 || (j==16 && i==18) || (j==16 && i==42)
                 || (j==20 && i==60) || (j==20 && i==12)
                 || (j==28 && i==6) || (j==28 && i==18) || (j==28 && i==60)
                 || (j==32 && i==48)
                 || (j==36 && i==6) || (j==36 && i==42)
                 || (j==40 && i==24)  || (j==40 && i==54)) {
                  setcolor(252);
                  cout<<setw(5)<<"STAIR"<<urut_stair[urut[0]];
                  urut[0]=urut[0]+1;
               }if ( (j==4 && i==12) || (j==4 && i==36) || (j==4 && i==48) //Tempat Lokasi Ular
                  || (j==8 && i==42)
                  || (j==12 && i==18) || (j==12 && i==36) || (j==12 && i==48)
                  || (j==16 && i==8) || (j==16 && i==12) || (j==16 && i==24)
                  || (j==20 && i==6) || (j==20 && i==42)
                  || (j==28 && i==42)
                  || (j==32 && i==24)
                  || (j==36 && i==12) || (j==36 && i==24)
                  || (j==40 && i==42)) {
                  setcolor(207);
                  cout<<setw(5)<<"SNAKE"<<urut_snake[urut[1]];
                  urut[1]=urut[1]+1;
               }
            }
            else{
               if (j%2!=0 || j%4==0) {
                  cout <<setw(7);
               }
            }
             }
            for (int k = 0; k < jumm; k++) {// Untuk Meletakan posisi pemain Realtime
               if (j==pe[k].batas_v && i==pe[k].batas_H) {
                  if (pe[k].menang==0){// ini buat yang belum menang, kalau sudah menang tidak perlu ditampilkan lagi
                  setcolor(warna_pemain[k]); cout<< setw(5)<<"P"<<k+1;}
               }
            }
         }
      }
   }
cout<<endl;
}
}

void merge(pemainn data[], int kiri, int tengah, int kanan)/*Sudah Terdapat Pointer dan sorting// Selesai*/{
   /* Menggabungkan dua subarrays dari ANGKA [].
      Subarray pertama adalah ANGKA [l..m]
      Subarray kedua adalah ANGKA [m + 1..r]
*/
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;
    int i,j,k;
    /* MMEMBUAT ARRAY SEMENTARA(TEMP) */
    pemainn KIRI[n1], KANAN[n2];

    /* SALIN DATA ANGKA[] KE TEMP L[] DAN R[] */
    for (i = 0; i < n1; i++)
        KIRI[i] = data[kiri + i];
    for (j = 0; j < n2; j++)
        KANAN[j] = data[tengah + 1+ j];

    /* Gabungkan data temp kembali ke data[l..r]*/
    i = 0; // INDEKS AWAL SUBDATA PERTAMA
    j = 0; // INDEKS AWAL SUBDATA KEDUA
    k = kiri; // INDEKS AWAL SUBDATAAY GABUNGAN
    while (i < n1 && j < n2)
    {
        if (KIRI[i].skor >= KANAN[j].skor)
        {
            data[k] = KIRI[i];
            i++;
        }
        else
        {
            data[k] = KANAN[j];
            j++;
        }
        k++;
    }

    /* SALIN ELEMEN L[] YANG TERSISA, JIKA ADA */
      while (i < n1)
      {
         data[k] = KIRI[i];
         i++;
         k++;
      }

    /* SALIN ELEMEN R[] YANG TERSISA, JIKA ADA */
      while (j < n2)
      {
         data[k] = KANAN[j];
         j++;
         k++;
      }
}

void mergeSort(pemainn data[], int kiri, int kanan)/*Sorting dengan Merge// Selesai*/{
   /* kiri ADALAH UNTUK INDEKS KIRI DAN kakan ADALAH INDEKS KANAN DARI
       SUB-ARRAY ANGKA YANG AKAN DISORTIR
*/
    if (kiri < kanan)
    {
      // SAMA SEPERTI (L+R)/ 2, TETAPI HINDARI OVERFLOW UNTUK
      // BESAR L DAN R
        int tengah = kiri+(kanan-kiri)/2;

        // URUTKAN BAGIAN PERTAMA DAN KEDUA
        mergeSort(data, kiri, tengah);
        mergeSort(data, tengah+1, kanan);
        merge(data, kiri, tengah, kanan);
    }
}

void searching()/*untuk Seaching jelas// SeLesai*/{
   	bool found=false;
   	string nama;

      setcolor(9);cout<< "Nama yang dicari : ";
      setcolor(6);cin.ignore(); getline(cin,nama);
   			cout<<endl;
   		   	for (int i = 0; (i < 100 && !found); ++i)
   		   	{
   		   		if (nama == pe[i].nama)
   		   		{
   	   			found = true;

   	   			 setcolor(12); cout<<"User name\t: "<<pe[i].nama<<endl;
   	   			 setcolor(12); cout<<"dengan skor\t: "<<pe[i].skor<<endl;

   		   		}
   		   	}
   		   	if (!found)
   		   	{
   		   		setcolor(12);cout<< "\t" << nama << " tidak ada "<< endl ;
   		   	}
   	}

void file()/*Untuk menyimpan data pepain setelah selesai main// Selesai*/{
   //void file
	GetNamaUser.open("DataUser.txt", ios::app); //dataUser adalah file txt
	for (int i = 0; i < jumm; i++)
	{
		GetNamaUser << pe[i].nama <<endl;	//ini untuk menyimpan nama pemain yang diinputkan ke dalam file
		GetNamaUser << salin[i] <<endl;
	}
	GetNamaUser.close();
	}

void getListNamaUser()/*Untuk mendapatkan nama dan skor dr file bagi selesai main// Selesai*/{
   //void ini untuk menampilkan list nama pemain yang sudah pernah main dan sekornya
	int i=0;
	jumm=0;
	string DataUser= "DataUser.txt";
	ViewNamaUser.open(DataUser.c_str());
	while(true)
	{
		ViewNamaUser.ignore();
		ViewNamaUser.getline(pe[i].nama, sizeof(pe[i].nama));
		if (ViewNamaUser.eof())
		{
			break;
		}
		ViewNamaUser >> salin[i];
		i++;
		jumm++;
	}
   for (int i = 0; i < 10; i++) {
      pe[i].skor=salin[i];
   }
	}

void papanSkor()/*Untuk Menampilkan Skor yang main dan yang sudah pernah main// Selesai*/{
   	cout<<"\n==========Papan Skor================\n";
      getListNamaUser();
      mergeSort(pe, 0, 1000); //1000 adalah banyk data
   		cout<<"\nNo"<<"   Nama   SKor \n";
   		for (int i = 0; i < 50; i++)
   		{
            if (i<9) cout<<"0"<<i+1;
            else cout<<i+1;


         cout<<setw(8)<<pe[i].nama;

         if (pe[i].skor==0)cout<<endl;
          else cout<<setw(5)<<pe[i].skor<<endl;
   		}
   	ViewNamaUser.close();

      }
