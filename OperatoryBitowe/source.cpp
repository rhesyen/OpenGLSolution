#include "header.h"
using namespace std;

//Properties->Debugging->Args: 192.168.0.10 255.255.255.255
void WypiszAdresMaskeWierszaPolecen(int argc, char* argv[]);

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

int main(int argc, char* argv[]) {
	WypiszAdresMaskeWierszaPolecen(argc, argv);
	return 0;
}

void WypiszAdresMaskeWierszaPolecen(int argc, char* argv[]) {
	
	if (argc == 3) {
		if (validateIP(argv[1]) && validateMask(argv[2])) {
			//Przypisanie danych
			string ipAddress = argv[1];
			string subnetMask = argv[2];

			//Konwersja adresu IP i maski na postaæ binarn¹
			bitset<32> ipBinary(bitset<32>(stoul(ipAddress, nullptr, 0)));
			bitset<32> maskBinary(bitset<32>(stoul(subnetMask, nullptr, 0)));

			//Generowanie adresu podsieci
			bitset<32> subnetBinary = ipBinary & maskBinary;

			//Wyœwietlanie wyników
			cout << "Adres IP: " << ipAddress << endl;
			cout << "Maska podsieci: " << subnetMask << endl;

			cout << "\nAdres IP w systemie dwojkowym: " << ipBinary << endl;
			cout << "Maska podsieci w systemie dwojkowym: " << maskBinary << endl;
			cout << "Adres podsieci w systemie dwojkowym: " << subnetBinary << endl;
			
			cout << "\nAdres IP w systemie dziesietnym: " << ipBinary.to_ulong() << endl;
			cout << "Maska podsieci w systemie dziesietnym: " << maskBinary.to_ulong() << endl;
			cout << "Adres podsieci w systemie dziesietnym: " << subnetBinary.to_ulong() << endl;

			cout << "\nAdres IP w systemie szesnastkowym: " << hex << ipBinary.to_ulong() << endl;
			cout << "Maska podsieci w systemie szesnastkowym: " << hex << maskBinary.to_ulong() << endl;
			cout << "Adres podsieci w systemie szesnastkowym: " << hex << subnetBinary.to_ulong() << endl;
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