/****************************************************************************
**                        SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				     BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**					   PROGRAMLAMAYA GİRİŞ DERSİ
**						2024-2025 GÜZ DÖNEMİ
**
**				ÖDEV NUMARASI..........: PROJE ÖDEVİ
**				ÖĞRENCİ ADI............: MUHAMMED EMİN BARKOÇ
**				ÖĞRENCİ NUMARASI.......: G231210452
**				DERSİN ALINDIĞI GRUP...: İKİNCİ ÖĞRETİM A GRUBU
**
*****************************************************************************/

#include <iostream>
#include <fstream>  // Dosya işlemleri için fstream kütüphanesi
#include <vector>


using namespace std;

// Başlangıçta sitemiz 20 daireden, 1 yüzme havuzundan ve 1 fitness salonundan oluşacaktır. 



class Daire
{
public:

	int daireNumarası;

	Daire(int numara) : daireNumarası(numara) {};

	void yazdir(ofstream& dosya) const
	{
		dosya << "Daire No: " << daireNumarası << endl;
	}
};

class Fitness
{
public:

	string isim;

	Fitness(const string& isim) : isim(isim) {};

	void yazdir(ofstream& dosya) const
	{
		dosya << "Fitness Salonu: " << isim << endl;
	}
};

class Havuz
{
public:

	string isim;

	Havuz(const string& isim) : isim(isim) {};

	void yazdir(ofstream& dosya) const
	{
		dosya << "Havuz: " << isim << endl;
	}

};

class Mekan
{
private:

	Fitness fitness;        // Fitness Salonu
	Havuz havuz;            // Yüzme Havuzu


public:
	vector<Daire> daireler; // Dairelerin listesi

	Mekan() : fitness("Ana Fitness Salonu"), havuz("Ana Yüzme Havuzu")
	{
		// 20 daire oluşturalım.
		for (int i = 1; i <= 20; ++i)
		{
			daireler.push_back(Daire(i));
		}
	}

	void mekanDosyasinaKaydet(const string& dosyaAdi) const
	{
		ofstream dosya(dosyaAdi); // Dosyayı açıyoruz.

		if (dosya.is_open())
		{
			// Fitness ve Havuz bilgilerini yazıyoruz.
			fitness.yazdir(dosya);
			havuz.yazdir(dosya);

			// Daire bilgilerini yazıyoruz.
			dosya << "\nDaireler: \n";
			for (const Daire& daire : daireler)
			{
				daire.yazdir(dosya);
			}

			dosya.close(); // Dosyayı kapatıyoruz.
		}

		else
		{
			cout << "Dosya acilirken bir hata olustu." << endl;
		}
	}
};


class AileReisi
{
public:

	string isim;
	int odenenDaire;

	AileReisi(int odenenDaireNo) : odenenDaire(odenenDaireNo) {};

	void yazdir(ofstream& dosya) const
	{
		cout << "Ödenen Daire No:" << odenenDaire << endl;
	}

};


class Oturan
{
private:

	vector<Oturan> oturanlar; // Oturanların listesi 
	vector<AileReisi> ailereisleri; // Aile Reislerinin listesi


public:
	int kullaniciID;

	Oturan(int kullaniciIdNumara) : kullaniciID(kullaniciIdNumara) {};

	void yazdir(ofstream& dosya) const
	{
		dosya << "Kullanıcı No: " << kullaniciID << endl;
	}


	Oturan()
	{
		for (int i = 1; i <= 10; ++i)
		{
			oturanlar.push_back(Oturan(i));
		}
	}

	void dataDosyasinaKaydet(const string& dosyaAdi) const
	{
		ofstream dosya(dosyaAdi);

		if (dosya.is_open())
		{
			dosya << "Oturanlar: \n";

			for (const Oturan& oturan : oturanlar)
			{
				oturan.yazdir(dosya);
			}

			dosya.close();
		}
		else
		{
			cout << "Dosya acilirken bir hata olustu." << endl;
		}
	}

	void odemeDosyasinaKaydet(const string& dosyaAdi) const
	{
		ofstream dosya(dosyaAdi);

		if (dosya.is_open())
		{
			dosya << "Ödemeler:\n";

			for (const AileReisi& ailereisleri : ailereisleri)
			{
				ailereisleri.yazdir(dosya);
			}

			dosya.close();
		}
		else
		{
			cout << "Dosya açılırken bir hata oluştu." << endl;
		}
	}
};



void mekanlariListele(const Mekan& mekan)
{
	int secim;
	system("cls"); //Ekranı temizler
	cout << "************** MEKANLARIN LISTESI **************" << endl;
	cout << "Daireler: \n\n";

	for (const Daire& d : mekan.daireler)
	{
		cout << d.daireNumarası << " Nolu Daire" << endl;
	}

	cout << "Ortak Alanlar: \n\n";


	system("pause"); // Kullanıcının devam etmesini bekler

}

void mekanIslemlerıMenusu(const Mekan& mekan)
{
	while (true)
	{
		int secim;
		system("cls"); //Ekranı temizler
		cout << "************** MEKAN ISLEMLERI **************" << endl;
		cout << "\n1 - Mekanlari Listele\n";
		cout << "2 - Yeni Mekan Ekle\n";
		cout << "3 - Mekan Silme\n";
		cout << "4 - Mekan Duzeltme\n";
		cout << "\n0 - Islem Menusune Don\n\n";
		cout << "Yapmak istediginiz islemi seciniz: ";
		cin >> secim;

		if (secim == 0)
		{
			return;
		}

		else if (secim == 1)
		{
			mekanlariListele(mekan);
		}
	}
}

void anaMenu(Mekan& mekan)
{
	while (true)
	{
		int secim;
		system("cls"); //Ekranı temizler
		cout << "************** KONUT SITE YONETIM PROGRAMINA HOSGELDINIZ **************" << endl;
		cout << "\nISLEM MENUSU\n" << endl;
		cout << "1 - Mekan Islemleri" << endl;
		cout << "\n";
		cout << "\nGitmek istediginiz menunun numarasini giriniz: ";
		cin >> secim;

		if (secim == 1)
		{
			mekanIslemlerıMenusu(mekan);
		}
	}
}




int main()
{
	Mekan mekan; // Mekan sınıfını oluşturuyoruz.
	mekan.mekanDosyasinaKaydet("Mekan.txt"); // Verileri Mekan.txt dosyasına kaydediyoruz. 

	Oturan oturan;
	oturan.dataDosyasinaKaydet("Data.txt");
	oturan.odemeDosyasinaKaydet("Odeme.txt");


	anaMenu(mekan);





	return 0;
}
