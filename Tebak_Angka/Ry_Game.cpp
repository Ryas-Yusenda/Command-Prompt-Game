#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

//LEVEL 1
int  a[5][5]={{9,1,5,4,3},{1,6,4,2,8},{5,4,9,4,1},{6,5,9,6,1},{8,4,4,3,7}};
int at[5][5]={{9,1,5,4,3},{1,6,4,2,8},{5,4,9,4,1},{6,5,9,6,1},{8,4,4,3,7}};
int ya[8]={17,19,18,16,9,0,0,0};
int xa[8]={18,16,9,20,16,0,0,2};
//LEVEL 2
int  b[6][6]={{5,7,6,8,4,7},{6,3,9,7,1,2},{2,8,3,8,8,3},{7,1,9,8,9,5},{4,9,5,1,3,9},{9,8,7,1,5,2}};
int bt[6][6]={{5,7,6,8,4,7},{6,3,9,7,1,2},{2,8,3,8,8,3},{7,1,9,8,9,5},{4,9,5,1,3,9},{9,8,7,1,5,2}};
int yb[8]={13,33,27,32,24,14,0,0};
int xb[8]={30,13,29,27,27,17,0,0};
//LEVEL 3
int  c[7][7]={{2,9,8,7,4,6,9},{9,2,8,9,9,1,1},{2,2,6,5,7,6,4},{3,5,3,5,8,4,8},{3,4,3,3,7,9,8},{1,5,3,5,4,7,1},{1,5,1,9,9,9,8}};
int ct[7][7]={{2,9,8,7,4,6,9},{9,2,8,9,9,1,1},{2,2,6,5,7,6,4},{3,5,3,5,8,4,8},{3,4,3,3,7,9,8},{1,5,3,5,4,7,1},{1,5,1,9,9,9,8}};
int yc[8]={19,30,25,22,28,26,26,0};
int xc[8]={25,19,20,31,30,19,32,0};
//LEVEL 4
int  d[8][8]={{6,8,4,3,4,7,1,7},{3,5,7,5,8,5,6,2},{7,2,5,6,3,3,1,4},{7,9,3,8,8,7,4,8},{5,8,8,1,8,1,4,2},{6,7,8,9,1,2,6,6},{1,9,4,3,5,1,7,6},{2,2,2,2,7,5,2,7}};
int dt[8][8]={{6,8,4,3,4,7,1,7},{3,5,7,5,8,5,6,2},{7,2,5,6,3,3,1,4},{7,9,3,8,8,7,4,8},{5,8,8,1,8,1,4,2},{6,7,8,9,1,2,6,6},{1,9,4,3,5,1,7,6},{2,2,2,2,7,5,2,7}};
int yd[8]={34,36,21,34,28,30,26,34};
int xd[8]={36,27,22,46,23,37,25,27};
//NETRAL
int  y[8]={0,0,0,0,0,0,0,0};
int  x[8]={0,0,0,0,0,0,0,0};
int  hapus=0,lvl=5,ll=0;

void setcolor(unsigned short color) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hCon,color);
    }

void banner(){
system("cls");
cout<<"               __\n";
cout<<"    ..=====.. |==|\t        HAVEFUN .By @ryasy_d!\n";
cout<<"    ||     || |= |\t======================================\n";
cout<<" _  ||     || |^*| _\n";
cout<<"|=| o=,===,=o |__||=|\n";
cout<<"|_|  _______)~`)  |_|\n";
cout<<"    [=======]  ()    \n";
cout<<endl;
}

void panel5(){
	cout<<" ";
	for (int i = 0; i < 5; i++){
			cout<<" |";
	if (x[i]==xa[i]){

		if(xa[i]<10){
		setcolor(4);
		cout<<"  "<<xa[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<" "<<xa[i];
		setcolor(3);
		}
	}
	else {
		if(xa[i]<10){
			cout<<"  "<<xa[i];
		}
		else{
			cout<<" "<<xa[i];
			}
		}
	}
	cout<<" |"<<endl;
//====================================================================//
	for (int i = 0; i < 5; i++){
		cout<<"--+----+----+----+----+----+--"<<endl;
//PANEL KIRI
	if (y[i]==ya[i]){

		if(ya[i]<10){
		setcolor(4);
		cout<<" "<<ya[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<""<<ya[i];
		setcolor(3);
		}
	}
	else {
		if(ya[i]<10){
			cout<<" "<<ya[i];
		}
		else{
			cout<<""<<ya[i];
			}
		}

	for (int j = 0; j< 5; j++){//PANEL ISI
			cout<<"|  ";
			if (a[j][i]==0)
			{
				setcolor(6);
				cout<<a[j][i]<<" ";
				setcolor(3);
			}
			else
			{
				cout<<a[j][i]<<" ";
			}
		}
//PANEL KANAN
	if (y[i]==ya[i]){

		if(ya[i]<10){
		cout<<"|";
		setcolor(4);
		cout<<ya[i];
		setcolor(3);
			}
		else{
		cout<<"|";
		setcolor(4);
		cout<<ya[i];
		setcolor(3);
		}
	}
	else {
		if(ya[i]<10){
			cout<<"|"<<ya[i];
		}
		else{
			cout<<"|"<<ya[i];
			}
		}
		cout<<endl;
	}
//====================================================================//
//PANEL BAWAH
	cout<<"--+----+----+----+----+----+--"<<endl;
	cout<<" ";
	for (int i = 0; i < 5; i++){
			cout<<" |";
	if (x[i]==xa[i]){

		if(xa[i]<10){
		setcolor(4);
		cout<<"  "<<xa[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<" "<<xa[i];
		setcolor(3);
	}
	}
	else
		if(xa[i]<10){
			cout<<"  "<<xa[i];
		}
		else{
			cout<<" "<<xa[i];
			}
	}
	cout<<" |";
	cout<<endl;
}

void panel6(){
	cout<<" ";
	for (int i = 0; i < 6; i++){
			cout<<" |";
	if (x[i]==xb[i]){

		if(xb[i]<10){
		setcolor(4);
		cout<<"  "<<xb[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<" "<<xb[i];
		setcolor(3);
		}
	}
	else {
		if(xb[i]<10){
			cout<<"  "<<xb[i];
		}
		else{
			cout<<" "<<xb[i];
			}
		}
	}
	cout<<" |"<<endl;
//====================================================================//
	for (int i = 0; i < 6; i++){
		cout<<"--+----+----+----+----+----+----+--"<<endl;
	if (y[i]==yb[i]){

		if(yb[i]<10){
		setcolor(4);
		cout<<" "<<yb[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<""<<yb[i];
		setcolor(3);
		}
	}
	else {
		if(yb[i]<10){
			cout<<" "<<yb[i];
		}
		else{
			cout<<""<<yb[i];
			}
		}

		for (int j = 0; j< 6; j++){
			cout<<"|  ";
			if (b[j][i]==0)
			{
				setcolor(6);
				cout<<b[j][i]<<" ";
				setcolor(3);
			}
			else
			{
				cout<<b[j][i]<<" ";
			}
		}
		if (y[i]==yb[i]){

		if(yb[i]<10){
		cout<<"|";
		setcolor(4);
		cout<<yb[i];
		setcolor(3);
			}
		else{
		cout<<"|";
		setcolor(4);
		cout<<yb[i];
		setcolor(3);
		}
	}
	else {
		if(yb[i]<10){
			cout<<"|"<<yb[i];
		}
		else{
			cout<<"|"<<yb[i];
			}
		}
		cout<<endl;
	}
//====================================================================//
	cout<<"--+----+----+----+----+----+----+--"<<endl;
	cout<<" ";
	for (int i = 0; i < 6; i++){
			cout<<" |";
	if (x[i]==xb[i]){

		if(xb[i]<10){
		setcolor(4);
		cout<<"  "<<xb[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<" "<<xb[i];
		setcolor(3);
	}
	}
	else
		if(xb[i]<10){
			cout<<"  "<<xb[i];
		}
		else{
			cout<<" "<<xb[i];
			}
	}
	cout<<" |";
	cout<<endl;
	}

void panel7(){
cout<<" ";
	for (int i = 0; i < 7; i++){
			cout<<" |";
	if (x[i]==xc[i]){

		if(xc[i]<10){
		setcolor(4);
		cout<<"  "<<xc[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<" "<<xc[i];
		setcolor(3);
		}
	}
	else {
		if(xc[i]<10){
			cout<<"  "<<xc[i];
		}
		else{
			cout<<" "<<xc[i];
			}
		}
	}
	cout<<" |"<<endl;
//====================================================================//
	for (int i = 0; i < 7; i++){
		cout<<"--+----+----+----+----+----+----+----+--"<<endl;
	if (y[i]==yc[i]){

		if(yc[i]<10){
		setcolor(4);
		cout<<" "<<yc[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<""<<yc[i];
		setcolor(3);
		}
	}
	else {
		if(yc[i]<10){
			cout<<" "<<yc[i];
		}
		else{
			cout<<""<<yc[i];
			}
		}

		for (int j = 0; j< 7; j++){
			cout<<"|  ";
			if (c[j][i]==0)
			{
				setcolor(6);
				cout<<c[j][i]<<" ";
				setcolor(3);
			}
			else
			{
				cout<<c[j][i]<<" ";
			}
		}
		if (y[i]==yc[i]){

		if(yc[i]<10){
		cout<<"|";
		setcolor(4);
		cout<<yc[i];
		setcolor(3);
			}
		else{
		cout<<"|";
		setcolor(4);
		cout<<yc[i];
		setcolor(3);
		}
	}
	else {
		if(yc[i]<10){
			cout<<"|"<<yc[i];
		}
		else{
			cout<<"|"<<yc[i];
			}
		}
		cout<<endl;
	}
//====================================================================//
	cout<<"--+----+----+----+----+----+----+----+--"<<endl;
	cout<<" ";
	for (int i = 0; i < 7; i++){
			cout<<" |";
	if (x[i]==xc[i]){

		if(xc[i]<10){
		setcolor(4);
		cout<<"  "<<xc[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<" "<<xc[i];
		setcolor(3);
	}
	}
	else
		if(xc[i]<10){
			cout<<"  "<<xc[i];
		}
		else{
			cout<<" "<<xc[i];
			}
	}
	cout<<" |";
	cout<<endl;
}

void panel8(){
cout<<" ";
	for (int i = 0; i < 8; i++){
			cout<<" |";
	if (x[i]==xd[i]){

		if(xd[i]<10){
		setcolor(4);
		cout<<"  "<<xd[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<" "<<xd[i];
		setcolor(3);
		}
	}
	else {
		if(xd[i]<10){
			cout<<"  "<<xd[i];
		}
		else{
			cout<<" "<<xd[i];
			}
		}
	}
	cout<<" |"<<endl;
//====================================================================//
	for (int i = 0; i < 8; i++){
		cout<<"--+----+----+----+----+----+----+----+----+--"<<endl;
	if (y[i]==yd[i]){

		if(yd[i]<10){
		setcolor(4);
		cout<<" "<<yd[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<""<<yd[i];
		setcolor(3);
		}
	}
	else {
		if(yd[i]<10){
			cout<<" "<<yd[i];
		}
		else{
			cout<<""<<yd[i];
			}
		}

		for (int j = 0; j< 8; j++){
			cout<<"|  ";
			if (d[j][i]==0)
			{
				setcolor(6);
				cout<<d[j][i]<<" ";
				setcolor(3);
			}
			else
			{
				cout<<d[j][i]<<" ";
			}
		}
		if (y[i]==yd[i]){

		if(yd[i]<10){
		cout<<"|";
		setcolor(4);
		cout<<yd[i];
		setcolor(3);
			}
		else{
		cout<<"|";
		setcolor(4);
		cout<<yd[i];
		setcolor(3);
		}
	}
	else {
		if(yd[i]<10){
			cout<<"|"<<yd[i];
		}
		else{
			cout<<"|"<<yd[i];
			}
		}
		cout<<endl;
	}
//====================================================================//
	cout<<"--+----+----+----+----+----+----+----+----+--"<<endl;
	cout<<" ";
	for (int i = 0; i < 8; i++){
			cout<<" |";
	if (x[i]==xd[i]){

		if(xd[i]<10){
		setcolor(4);
		cout<<"  "<<xd[i];
		setcolor(3);
			}
		else{
		setcolor(4);
		cout<<" "<<xd[i];
		setcolor(3);
	}
	}
	else
		if(xd[i]<10){
			cout<<"  "<<xd[i];
		}
		else{
			cout<<" "<<xd[i];
			}
	}
	cout<<" |";
	cout<<endl;
	}

int main(){

int xq=0,yq=0,zq=50;
int selesai=1;

system("mode 65,30");
system("title Ryas.Game");

setcolor(3);

while (xq<=zq){

	xq=xq+1;
	yq=((xq*10)/zq);

	cout<<"LOADING .... | "<<endl;
		for (int i = 0; i < yq; i++){cout<<"*";}
	system("cls");
	cout<<"LOADING .... / "<<endl;
		for (int i = 0; i < yq; i++){cout<<"*";}
	system("cls");
	cout<<"LOADING .... \\"<<endl;
		for (int i = 0; i < yq; i++){cout<<"*";}
	system("cls");
	cout<<"LOADING .... - "<<endl;
		for (int i = 0; i < yq; i++){cout<<"*";}
	system("cls");
continue;
}

banner();

do{//5X5

banner();
int qwq=1;

//PENGENDALIAN PENGHAPUSAN
	for (int i=0; i<lvl; i++){
	for (int j=0; j<lvl; j++)
	{
		if(hapus==qwq)
		{
			if(a[j][i]==0){a[j][i]=at[j][i]; qwq=qwq+1;}
			else {a[j][i]=0; qwq=qwq+1;}
		}
		else{qwq=qwq+1;}
	}
}

//TOTAL KANAN
	for (int i=0; i<lvl; i++){x[i]=0;
	for (int j=0; j<lvl; j++){x[i]=x[i]+a[i][j];}
	}

//TOTAL BAWAH
	for (int i=0; i<lvl; i++){y[i]=0;
	for (int j=0; j<lvl; j++){y[i]=y[i]+a[j][i];}
	}

//CEK SELESAI
	for (int i = 0; i < 1; i++){
			if (x[0]==xa[0] && x[1]==xa[1] && x[2]==xa[2] && x[3]==xa[3] && x[4]==xa[4] && x[5]==xa[5] && x[6]==xa[6] && x[7]==xa[7] && y[0]==ya[0] && y[1]==ya[1] && y[2]==ya[2] && y[3]==ya[3] && y[4]==ya[4] && y[5]==ya[5] && y[6]==ya[6] && y[7]==ya[7])
			ll=1;
}

panel5();

//TRY
{
	if (ll==1)
	{
		cout<<"\nSELAMAT ANDA TELAH MEMENANGKAN GAME INI !";
		cin>>selesai;
		selesai=0;
		for (int i = 0; i < 7; i++)
		{
			y[i]=0;
		}
		for (int i = 0; i < 7; i++)
		{
			x[i]=0;
		}
		ll=0;
		lvl=lvl+1;
		hapus=999;
	}
	else if(ll==0){

		cout<<"\nMasukan Yang Mau Dihapus : ";cin>>hapus;
	}
}
}while (selesai==1);

do{//6X6
selesai=1;
banner();
int qwq=1;

//PENGENDALIAN PENGHAPUSAN
	for (int i=0; i<lvl; i++){
	for (int j=0; j<lvl; j++)
	{
		if(hapus==qwq)
		{
			if(b[j][i]==0){b[j][i]=bt[j][i]; qwq=qwq+1;}
			else {b[j][i]=0; qwq=qwq+1;}
		}
		else{qwq=qwq+1;}
	}
}

//TOTAL KANAN
	for (int i=0; i<lvl; i++){x[i]=0;
	for (int j=0; j<lvl; j++){x[i]=x[i]+b[i][j];}
	}

//TOTAL BAWAH
	for (int i=0; i<lvl; i++){y[i]=0;
	for (int j=0; j<lvl; j++){y[i]=y[i]+b[j][i];}
	}

//CEK SELESAI
	for (int i = 0; i < 1; i++){
			if (x[0]==xb[0] && x[1]==xb[1] && x[2]==xb[2] && x[3]==xb[3] && x[4]==xb[4] && x[5]==xb[5] && x[6]==xb[6] && x[7]==xb[7] && y[0]==yb[0] && y[1]==yb[1] && y[2]==yb[2] && y[3]==yb[3] && y[4]==yb[4] && y[5]==yb[5] && y[6]==yb[6] && y[7]==yb[7])
			ll=1;
}

panel6();

//TRY
{
	if (ll==1)
	{
		cout<<"\nSELAMAT ANDA TELAH MEMENANGKAN GAME INI !";
		cin>>selesai;
		selesai=0;
		for (int i = 0; i < 7; i++)
		{
			y[i]=0;
		}
		for (int i = 0; i < 7; i++)
		{
			x[i]=0;
		}
		ll=0;
		lvl=lvl+1;
		hapus=999;
	}
	else if(ll==0){

		cout<<"\nMasukan Yang Mau Dihapus : ";cin>>hapus;
	}
}
}while (selesai==1);

do{//7X7
selesai=1;
banner();
int qwq=1;

//PENGENDALIAN PENGHAPUSAN
	for (int i=0; i<lvl; i++){
	for (int j=0; j<lvl; j++)
	{
		if(hapus==qwq)
		{
			if(c[j][i]==0){c[j][i]=ct[j][i]; qwq=qwq+1;}
			else {c[j][i]=0; qwq=qwq+1;}
		}
		else{qwq=qwq+1;}
	}
}

//TOTAL KANAN
	for (int i=0; i<lvl; i++){x[i]=0;
	for (int j=0; j<lvl; j++){x[i]=x[i]+c[i][j];}
	}

//TOTAL BAWAH
	for (int i=0; i<lvl; i++){y[i]=0;
	for (int j=0; j<lvl; j++){y[i]=y[i]+c[j][i];}
	}

//CEK SELESAI
	for (int i = 0; i < 1; i++){
			if (x[0]==xc[0] && x[1]==xc[1] && x[2]==xc[2] && x[3]==xc[3] && x[4]==xc[4] && x[5]==xc[5] && x[6]==xc[6] && x[7]==xc[7] && y[0]==yc[0] && y[1]==yc[1] && y[2]==yc[2] && y[3]==yc[3] && y[4]==yc[4] && y[5]==yc[5] && y[6]==yc[6] && y[7]==yc[7])
			ll=1;
}

panel7();

//TRY
{
	if (ll==1)
	{
		cout<<"\nSELAMAT ANDA TELAH MEMENANGKAN GAME INI !";
		cin>>selesai;
		selesai=0;
		for (int i = 0; i < 7; i++)
		{
			y[i]=0;
		}
		for (int i = 0; i < 7; i++)
		{
			x[i]=0;
		}
		ll=0;
		lvl=lvl+1;
		hapus=999;
	}
	else if(ll==0){

		cout<<"\nMasukan Yang Mau Dihapus : ";cin>>hapus;
	}
}
}while (selesai==1);

do{//8X8
selesai=1;
banner();
int qwq=1;

//PENGENDALIAN PENGHAPUSAN
	for (int i=0; i<lvl; i++){
	for (int j=0; j<lvl; j++)
	{
		if(hapus==qwq)
		{
			if(d[j][i]==0){d[j][i]=dt[j][i]; qwq=qwq+1;}
			else {d[j][i]=0; qwq=qwq+1;}
		}
		else{qwq=qwq+1;}
	}
}

//TOTAL KANAN
	for (int i=0; i<lvl; i++){x[i]=0;
	for (int j=0; j<lvl; j++){x[i]=x[i]+d[i][j];}
	}

//TOTAL BAWAH
	for (int i=0; i<lvl; i++){y[i]=0;
	for (int j=0; j<lvl; j++){y[i]=y[i]+d[j][i];}
	}

//CEK SELESAI
	for (int i = 0; i < 1; i++){
			if (x[0]==xd[0] && x[1]==xd[1] && x[2]==xd[2] && x[3]==xd[3] && x[4]==xd[4] && x[5]==xd[5] && x[6]==xd[6] && x[7]==xd[7] && y[0]==yd[0] && y[1]==yd[1] && y[2]==yd[2] && y[3]==yd[3] && y[4]==yd[4] && y[5]==yd[5] && y[6]==yd[6] && y[7]==yd[7])
			ll=1;
}

panel8();

//TRY
{
	if (ll==1)
	{
		cout<<"\nSELAMAT ANDA TELAH MEMENANGKAN SEMUA GAME INI DARI LV1-LV4 !";
		cin>>selesai;
		selesai=0;
		for (int i = 0; i < 7; i++)
		{
			y[i]=0;
		}
		for (int i = 0; i < 7; i++)
		{
			x[i]=0;
		}
		ll=0;
		lvl=lvl+1;
		hapus=999;
	}
	else if(ll==0){

		cout<<"\nMasukan Yang Mau Dihapus : ";cin>>hapus;
	}
}
}while (selesai==1);


}
