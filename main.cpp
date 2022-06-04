#include "iostream"
#include "windows.h"

using namespace std;

int main(int argc, char const *argv[]) {
  system("mode 50, 20");
  int Pilih;

  printf("1. Batu Gunting Kertas\n");
  printf("2. Generated Password\n");
  printf("3. Snake\n");
  printf("4. Tebak Angka (Fav)\n");
  printf("5. Tic Tac Toe\n");
  printf("6. Ular Tangga (Fav)\n\n");
  printf("Pilih : ");
  cin >> Pilih;

  switch (Pilih) {
  case 1:
    system(" start Batu_Gunting_Kertas\\BatuGuntingKertas.exe ");
    break;
  case 2:
    system(" start Generated_Password\\main.exe ");
    break;
  case 3:
    system(" start Snake\\Snake.exe ");
    break;
  case 4:
    system(" start Tebak_Angka\\Ry_Game.exe ");
    break;
  case 5:
    system(" start Tic_Tac_Toe\\tictac.exe ");
    break;
  case 6:
    system(" start Ular_Tangga\\UlarTangga.exe ");
    break;
  default:
    exit(0);
  };

  return 0;
}
