#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

class atm //class atm
{
private:	//private member variabel
	long int nomer_akun;
	string nama;
	int pin;
	double saldo;
	string no_mobile;
	
public:	//public member variabel
	
	//data mengatur private member variabel
	void data(long int nomer_akun_a, string nama_a, int pin_a, double saldo_a, string no_mobile_a)
	{
		nomer_akun = nomer_akun_a;		//menetapkan argumen formal kepada member variabel pribadi
		nama = nama_a;
		pin = pin_a;
		saldo = saldo_a;
		no_mobile = no_mobile_a; 
	}
	
	long int getnomerakun() //fungsi untuk kembali user akun nomer
	{
		return nomer_akun;
	}
	
	string getname()
	{
		return nama;
	}
	
	int getpin()
	{
		return pin;
	}
	
	double getsaldo()
	{
		return saldo;
	}
	
	
	string getnomobile()
	{
		return no_mobile;
	}
	
	
	void setmobile(string mob_lama, string mob_baru) // fungsi untuk updating no mobile user
	{
		if (mob_lama == no_mobile) //akan mengecek no mobile lama ketemu
		{
			no_mobile = mob_baru; //update dengan baru jika no mobile lama
			cout << endl << "Berhasil Updated No Mobile.";
			_getch(); //menjaga layar (sampai user menekan tombol apapun)
			
		}
		
		else //tidak update jika no mobile lama tidak sama atau tidak ketemu
		{
			cout << endl << "Incorrect !!! no mobile lama";
			_getch();
		}
	}
	
	void tariktunai(int jumlah_a) //fungsi digunakan untuk penarikan uang dari atm
	{
		if(jumlah_a > 0 && jumlah_a < saldo) //mengecek jika inputan jumlah lebih dari 0 dan jumlah lebih dari saldo
		{
			saldo -= jumlah_a;
			cout << endl << " Masukan Jumlah yang ingin di tarik";
			cout << endl << "Saldo tersedia  :" << saldo;
			_getch();
		}
		
		else
		{
			cout << endl << "Invalid input atau saldo tidak cukup";
			_getch();
		}
	}
	
};

int main()
{
	long int enternomer_akun;
	int enterpin;
	int pilihan = 0;
	
	//membuat user (object)
	atm user1;
		
	//user details 
	user1.data(1234567,"Catur Angga Adiyaksa", 1122, 45998.89,"0987654321");
		
	do
	{	
	
		// START TAMPILAN UTAMA
		system("cls");

		cout << "========================= SELAMAT DATANG DI ATM ===========================" << endl;
		cout << "|                                                                         |" << endl;
		cout << "|                                                                         |" << endl;
		cout << "|                   Masukan Nomer Akun Anda\t:                            |" << endl;
		cin >> enternomer_akun;
		cout << "|                                                                         |" << endl;
		cout << "|                   Masukan Pin\t:                                        |" << endl;
		cin >> enterpin;	
		cout << "|                                                                         |" << endl;
		cout << "|                                                                         |" << endl;
		cout << "==========================================================================|" << endl;
		//AKHIR TAMPILAN AKHIR
		
		//Untuk Mengecek Jika USER menginputkan nilai user 
		if ((enternomer_akun == user1.getnomerakun()) && (enterpin ==user1.getpin()))
		{
			do
			{
				int jumlah = 0;
				string nomobilelama, nomobilebaru;
				
				system("cls");
				cout << "SELAMAT DATANG DI ATM\n";
				cout << "Silahkan Pilih Menu \n";
				cout << "[1] Periksa Saldo \n";
				cout << "[2] Tarik Tunai \n";
				cout << "[3] Tampilkan Detail Info User\n";
				cout << "[4] Edit No Mobile\n" << endl;
				cin >> pilihan;
				
				switch (pilihan)
				{
					case 1:
						cout << "Saldo ATM Anda sebesar:" << user1.getsaldo();
						
						
						_getch();
						break;
						
						
					case 2:
						cout << "Masukan Jumlah :" ;
						cin >> jumlah;
						user1.tariktunai(jumlah);
						break;
						
						
						
					case 3:
						cout << "Detail Info User :" << endl;
						cout << "Akun No:" << user1.getnomerakun();
						cout << "Name :" << user1.getname();
						cout << "Balance :" << user1.getsaldo();
						cout << "Mobile No." << user1.getnomobile();
						
						_getch();
						break;
						
					case 4:
						cout << "Masukan Mobile No Lama\t\t\t:\n";
						cin >> nomobilelama;
						
						cout << "Masukan No Mobile Baru\t\t\t:\n";
						cin >> nomobilebaru;
						
						user1.setmobile(nomobilelama, nomobilebaru);
						
						break;
						
					case 5:
					exit(0);
					
					default :
						cout << "Masukan Data Yang Valid!!!";
						_getch();
						
				}
			} while (1);
		}
	} while (1);
	
	
	return 0;
}
