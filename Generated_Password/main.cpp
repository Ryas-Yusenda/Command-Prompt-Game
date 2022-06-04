#include <conio.h>
#include <ctime>
#include <iostream>
using namespace std;

const char unik[] = "0123456789"
                    "!@#$%^&*"
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz";

int size = sizeof(unik) - 1;

void name(int length) {
  cout << "-   ";
  for (int i = 0; i < length; i++) {
    cout << unik[rand() % size];
  }
  cout << endl;
}

int main() {
  system("mode 50, 20");

  int pass;

  cout << "Masukan panjang password = ";
  cin >> pass;
  cout << endl;

  srand(time(0));
  name(pass);
  name(pass);
  name(pass);
  name(pass);
  name(pass);

  getch();
  return 0;
}
