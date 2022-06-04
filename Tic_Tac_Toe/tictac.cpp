#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int player1[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int player2[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int Pemenang = 0;
int gilir = 1;
string nama1, nama2, input = "T";

void nama_pemain();
void pemain();
void system();
void Header();

void x(int x, int y);
void o(int x, int y);

void gotoxy(int x, int y);
void setcolor(unsigned short color);
void baris(int x);
void garis(int x);

int main()
{
   nama_pemain();
   Header();
   system();
   return 0;
}

void nama_pemain()
{
   system("title TicTac");
   system("mode 43,35");

   while (input == "T")
   {
      setcolor(9);
      printf("        --.--o     ");
      setcolor(4);
      printf("--.--          \n");
      setcolor(9);
      printf("          |  .,---.");
      setcolor(4);
      printf("  |  ,---.,---.\n");
      setcolor(9);
      printf("          |  ||    ");
      setcolor(4);
      printf("  |  ,---||    \n");
      setcolor(9);
      printf("          `  ``---'");
      setcolor(4);
      printf("  `  `---^`---'\n\n");
      setcolor(7);

      printf("Nama Player[1] : ");
      getline(cin, nama1);
      printf("Nama Player[2] : ");
      getline(cin, nama2);
      input = "F"; //INI KALAU SUDAH INPUT 2 PEMAIN
   };
}
void pemain()
{
   string pilih;
   int angka;
   do
   {
      setcolor(7);
      gotoxy(1, 31);
      cout << "Pemain[" << gilir << "] :                                  ";
      gotoxy(13, 31);
      cin >> pilih;

      //MERUBAH STIRNG MENJADI INT
      if (pilih == "1" || pilih == "2" || pilih == "3" || pilih == "4" || pilih == "5" || pilih == "6" || pilih == "7" || pilih == "8" || pilih == "9")
      {
         angka = atoi(pilih.c_str());
      }
      else
      {
         angka = 0;
      }

      //CEK JIKA SALAH SATU PLAYER MILIH KOTAK YANG SUDAH DIISI
      if (player1[angka - 1] == 1)
      {
         angka = 0;
      }
      if (player2[angka - 1] == 1)
      {
         angka = 0;
      }

   } while (angka < 1 || angka > 9); //BERULANG JIKA ADA KESALAHAN

   //MEMASUAN KOTAK YANG DIISI KE INT ARRAY
   if (gilir == 1)
   {
      player1[angka - 1] = 1;
      gilir = 2;
   }
   else if (gilir == 2)
   {
      player2[angka - 1] = 1;
      gilir = 1;
   }

   main();
}
void system()
{

   //INI UNTUK MENGECEK PEMENANG GAME
   if ((player1[0] + player1[1] + player1[2]) == 3)
   {
      Pemenang = 1;
   }
   else if ((player1[3] + player1[4] + player1[5]) == 3)
   {
      Pemenang = 1;
   }
   else if ((player1[6] + player1[7] + player1[8]) == 3)
   {
      Pemenang = 1;
   }
   else if ((player1[0] + player1[3] + player1[6]) == 3)
   {
      Pemenang = 1;
   }
   else if ((player1[1] + player1[4] + player1[7]) == 3)
   {
      Pemenang = 1;
   }
   else if ((player1[2] + player1[5] + player1[8]) == 3)
   {
      Pemenang = 1;
   }
   else if ((player1[0] + player1[4] + player1[8]) == 3)
   {
      Pemenang = 1;
   }
   else if ((player1[6] + player1[4] + player1[2]) == 3)
   {
      Pemenang = 1;
   }
   else if ((player2[0] + player2[1] + player2[2]) == 3)
   {
      Pemenang = 2;
   }
   else if ((player2[3] + player2[4] + player2[5]) == 3)
   {
      Pemenang = 2;
   }
   else if ((player2[6] + player2[7] + player2[8]) == 3)
   {
      Pemenang = 2;
   }
   else if ((player2[0] + player2[3] + player2[6]) == 3)
   {
      Pemenang = 2;
   }
   else if ((player2[1] + player2[4] + player2[7]) == 3)
   {
      Pemenang = 2;
   }
   else if ((player2[2] + player2[5] + player2[8]) == 3)
   {
      Pemenang = 2;
   }
   else if ((player2[0] + player2[4] + player2[8]) == 3)
   {
      Pemenang = 2;
   }
   else if ((player2[6] + player2[4] + player2[2]) == 3)
   {
      Pemenang = 2;
   }

   //JIKA BELOM ADA PEMENANG, LANJUT MAIN
   if (Pemenang != 1 && Pemenang != 2)
   {
      pemain();
   }

   //JIKA SUDAH ADA PEMENANG
   gotoxy(1, 31);
   if (Pemenang == 1)
   {
      setcolor(9);
      cout << "Winner, " << nama1 << endl;
      getch();
      exit(0);
   }
   else if (Pemenang == 2)
   {
      setcolor(4);
      cout << "Winner, " << nama2 << endl;
      getch();
      exit(0);
   }
}
void Header()
{
   system("title TicTac");
   system("mode 43,35");
   setcolor(9);
   printf("        --.--o     ");
   setcolor(4);
   printf("--.--          \n");
   setcolor(9);
   printf("          |  .,---.");
   setcolor(4);
   printf("  |  ,---.,---.\n");
   setcolor(9);
   printf("          |  ||    ");
   setcolor(4);
   printf("  |  ,---||    \n");
   setcolor(9);
   printf("          `  ``---'");
   setcolor(4);
   printf("  `  `---^`---'\n\n");
   setcolor(112);

   //MENAMPILKAN TABLE YANG ADA
   cout << char(201);
   garis(13);
   cout << char(203);
   garis(13);
   cout << char(203);
   garis(13);
   cout << char(187) << endl;
   baris(7);
   cout << char(204);
   garis(13);
   cout << char(206);
   garis(13);
   cout << char(206);
   garis(13);
   cout << char(185) << endl;
   baris(7);
   cout << char(204);
   garis(13);
   cout << char(206);
   garis(13);
   cout << char(206);
   garis(13);
   cout << char(185) << endl;
   baris(7);
   cout << char(200);
   garis(13);
   cout << char(202);
   garis(13);
   cout << char(202);
   garis(13);
   cout << char(188) << endl;

   //MENAMPILKAN ANGKA DI SUDUT KIRI ATAS
   gotoxy(1, 6);
   printf("1");
   gotoxy(15, 6);
   printf("2");
   gotoxy(29, 6);
   printf("3");
   gotoxy(1, 14);
   printf("4");
   gotoxy(15, 14);
   printf("5");
   gotoxy(29, 14);
   printf("6");
   gotoxy(1, 22);
   printf("7");
   gotoxy(15, 22);
   printf("8");
   gotoxy(29, 22);
   printf("9");

   //MENAMPILKAN PILIHAN SILANG UNTUK PLAYER1
   if (player1[0] == 1)
   {
      x(3, 9);
   } //#1
   if (player1[1] == 1)
   {
      x(17, 9);
   } //#2
   if (player1[2] == 1)
   {
      x(31, 9);
   } //#3
   if (player1[3] == 1)
   {
      x(3, 17);
   } //#4
   if (player1[4] == 1)
   {
      x(17, 17);
   } //#5
   if (player1[5] == 1)
   {
      x(31, 17);
   } //#6
   if (player1[6] == 1)
   {
      x(3, 25);
   } //#7
   if (player1[7] == 1)
   {
      x(17, 25);
   } //#8
   if (player1[8] == 1)
   {
      x(31, 25);
   } //#9

   //MENAMPILKAN PILIHAN KOTAK UNTUK PLAYER2
   if (player2[0] == 1)
   {
      o(3, 9);
   } //#1
   if (player2[1] == 1)
   {
      o(17, 9);
   } //#2
   if (player2[2] == 1)
   {
      o(31, 9);
   } //#3
   if (player2[3] == 1)
   {
      o(3, 17);
   } //#4
   if (player2[4] == 1)
   {
      o(17, 17);
   } //#5
   if (player2[5] == 1)
   {
      o(31, 17);
   } //#6
   if (player2[6] == 1)
   {
      o(3, 25);
   } //#7
   if (player2[7] == 1)
   {
      o(17, 25);
   } //#8
   if (player2[8] == 1)
   {
      o(31, 25);
   } //#9
}

void x(int x, int y)
{
   //MENAMPILKAN SILANG
   setcolor(112);
   gotoxy(x, y - 2);
   printf("#       #");
   gotoxy(x, y - 1);
   printf("  #   #");
   gotoxy(x, y);
   printf("    #");
   gotoxy(x, y + 1);
   printf("  #   #");
   gotoxy(x, y + 2);
   printf("#       #");
}
void o(int x, int y)
{
   //MENAMPILKAN KOTAK
   setcolor(112);
   gotoxy(x, y - 2);
   printf("#########");
   gotoxy(x, y - 1);
   printf("#       #");
   gotoxy(x, y);
   printf("#       #");
   gotoxy(x, y + 1);
   printf("#       #");
   gotoxy(x, y + 2);
   printf("#########");
}

void gotoxy(int x, int y) {
  // UNUTK MENAMPILKAN TEXT DI KORDINAT YANG TELAH DITENTUKAN
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setcolor(unsigned short color)
{
   /*Untuk Pemberian warna pada cmd. dengan memakai hCon, dengan include <windows.h>*/
   HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hCon, color);
}
void baris(int x)
{
   //UNTUK MEMBUAT BARIS KOTAK(ISI)
   for (int i = 0; i < x; i++)
   {
      cout << char(186) << "             " << char(186) << "             " << char(186) << "             " << char(186) << endl;
   }
}
void garis(int x)
{
   //UNTUK MEMBUAT GARIS PADA KOTAK(SISI)
   for (int i = 0; i < x; i++)
   {
      cout << char(205);
   }
}
