#include "header.h"
using namespace std;

//Properties->Debugging->Args: 192.168.0.10 255.255.255.255

bool validateIP(const string& ip) {
	// Wzorzec wyra¿enia regularnego dla adresu IPv4
	regex ipPattern("^((25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)$");
	return regex_match(ip, ipPattern);
}

bool validateMask(const string& mask) {
	// Wzorzec wyra¿enia regularnego dla maski sieciowej IPv4
	regex maskPattern("^((255|254|252|248|240|224|192|128|0+)\\.){3}(255|254|252|248|240|224|192|128|0+)$");
	//("^((255\\.){3}(255|254|252|248|240|224|192|128|0+)\\.)|(0+\\.){3}(0+)$");
	return regex_match(mask, maskPattern);
}

void WypiszAdresMaskeWierszaPolecen(int argc, char* argv[]) {

	if (argc == 3) {
		if (validateIP(argv[1]) && validateMask(argv[2])) {
			//Przypisanie danych
			string ipAddress = argv[1];
			string subnetMask = argv[2];
			int ipArray[4];
			int maskArray[4];

			//Przypisanie adresu IP do tablicy
			istringstream ipStreamAdress(ipAddress);
			string temporary_part_1;

			for (int i = 0; i < 4; i++) {
				getline(ipStreamAdress, temporary_part_1, '.');
				ipArray[i] = stoi(temporary_part_1);
			}

			//Przypisanie maski podsieci do tablicy
			istringstream ipStreamMask(subnetMask);
			string temporary_part_2;

			for (int i = 0; i < 4; i++) {
				getline(ipStreamMask, temporary_part_2, '.');
				maskArray[i] = stoi(temporary_part_2);
			}

			//Dla ka¿dego elementu tablicy ipArray i maskArray:
			int ipBinary[4];
			int maskBinary[4];
			int subnetBinary[4];

			for (int i = 0; i < 4; i++) {
				//Konwersja adresu IP i maski na postaæ binarn¹
				bitset<8> ipOctet(ipArray[i]);
				bitset<8> maskOctet(maskArray[i]);

				ipBinary[i] = ipOctet.to_ulong();
				maskBinary[i] = maskOctet.to_ulong();

				//Generowanie adresu podsieci
				bitset<32> adressMaskOctet(ipBinary[i] & maskBinary[i]);
				subnetBinary[i] = adressMaskOctet.to_ulong();
			}

			//System dwojkowy
			cout << "\nAdres IP w systemie dwojkowym: ";
			for (int i = 0; i < 4; i++) {
				cout << bitset<8>(ipBinary[i]) << " ";
			}
			cout << "\nMaska podsieci w systemie dwojkowym: ";
			for (int i = 0; i < 4; i++) {
				cout << bitset<8>(maskBinary[i]) << " ";
			}
			cout << "\nAdres podsieci w systemie dwojkowym: ";
			for (int i = 0; i < 4; i++) {
				cout << bitset<8>(subnetBinary[i]) << " ";
			}

			//System dziesietny
			cout << "\nAdres IP w systemie dziesietnym: ";
			for (int i = 0; i < 4; i++) {
				cout << ipBinary[i] << ".";
			}
			cout << "\nMaska podsieci w systemie dziesietnym: ";
			for (int i = 0; i < 4; i++) {
				cout << maskBinary[i] << ".";
			}
			cout << "\nAdres podsieci w systemie dziesietnym: ";
			for (int i = 0; i < 4; i++) {
				cout << subnetBinary[i] << ".";
			}

			//System szesnastkowy
			cout << "\nAdres IP w systemie szesnastkowym: ";
			for (int i = 0; i < 4; i++) {
				cout << hex << ipBinary[i] << ".";
			}
			cout << "\nMaska podsieci w systemie szesnastkowym: ";
			for (int i = 0; i < 4; i++) {
				cout << hex << maskBinary[i] << ".";
			}
			cout << "\nAdres podsieci w systemie szesnastkowym: ";
			for (int i = 0; i < 4; i++) {
				cout << hex << subnetBinary[i] << ".";
			}

			//Wyœwietlanie wyników
			/*	Adres IP w systemie dwojkowym: 11000000 10101000 00000000 00001010
				Maska podsieci w systemie dwojkowym: 11111111 11111111 11111111 11111111
				Adres podsieci w systemie dwojkowym: 11000000 10101000 00000000 00001010
				Adres IP w systemie dziesietnym: 192.168.0.10.
				Maska podsieci w systemie dziesietnym: 255.255.255.255.
				Adres podsieci w systemie dziesietnym: 192.168.0.10.
				Adres IP w systemie szesnastkowym: c0.a8.0.a.
				Maska podsieci w systemie szesnastkowym: ff.ff.ff.ff.
				Adres podsieci w systemie szesnastkowym: c0.a8.0.a.
			*/
		}
		else {
			cout << "Niepoprawny typ danych. Uruchom program jeszcze raz.";
			return;
		}
	}
	else {
		cout << "Niepoprawna ilosc argumentow. Uruchom program jeszcze raz.";
		return;
	}
}

int main(int argc, char* argv[]) {
	//::testing::InitGoogleTest(&argc, argv);
	//WypiszAdresMaskeWierszaPolecen(argc, argv);
	//return RUN_ALL_TESTS();
	return 0;
}