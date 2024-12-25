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

		vector<Daire> daireler; // Dairelerin listesi
		Fitness fitness;        // Fitness Salonu
		Havuz havuz;            // Yüzme Havuzu

	public:
		
		Mekan() : fitness("Ana Fitness Salonu"), havuz("Ana Yüzme Havuzu")
		{
			// 20 daire oluşturalım.
			for (int i = 1; i <= 20; ++i)
			{
				daireler.push_back(Daire(i));
			}
		}

		void dosyayaKaydet(const string& dosyaAdi) const
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
				cout << "Veriler basariyla " << dosyaAdi << " dosyasina kaydedildi." << endl;
			}

			else
			{
				cout << "Dosya acilirken bir hata olustu." << endl;
			}
		}
};



class Oturan {
public:
	class AileReisi {};
	class Misafir {};
};

int main()
{
	Mekan mekan; // Mekan sınıfını oluşturuyoruz.
	mekan.dosyayaKaydet("Mekan.txt"); // Verileri Mekan.txt dosyasına kaydediyoruz. 

	return 0;
}
