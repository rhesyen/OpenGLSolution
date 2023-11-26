#include "pch.h"
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
	return regex_match(mask, maskPattern);
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
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

			//Strumien:
			ostringstream ipBinaryOS;
			ostringstream maskBinaryOS;
			ostringstream subnetBinaryOS;

			//Adres IP w systemie dwojkowym: ;
			ipBinaryOS << bitset<8>(ipBinary[0]);
			for (int i = 1; i < 4; i++) {
				ipBinaryOS << '.' << bitset<8>(ipBinary[i]);
			}
			//Maska podsieci w systemie dwojkowym: ;
			maskBinaryOS << bitset<8>(maskBinary[0]);
			for (int i = 1; i < 4; i++) {
				maskBinaryOS << '.' << bitset<8>(maskBinary[i]);
			}
			//Adres podsieci w systemie dwojkowym: ;
			subnetBinaryOS << bitset<8>(subnetBinary[0]);
			for (int i = 1; i < 4; i++) {
				subnetBinaryOS << '.' << bitset<8>(subnetBinary[i]);
			}

			string ipBinaryStr = ipBinaryOS.str();
			string maskBinaryStr = maskBinaryOS.str();
			string subnetBinaryStr = subnetBinaryOS.str();

			//Czyszczenie strumienia:
			ipBinaryOS.str("");
			maskBinaryOS.str("");
			subnetBinaryOS.str("");

			//Adres IP w systemie dziesietnym: ;
			ipBinaryOS << ipBinary[0];
			for (int i = 1; i < 4; i++) {
				ipBinaryOS << '.' << ipBinary[i];
			}
			//Maska podsieci w systemie dziesietnym: ;
			maskBinaryOS << maskBinary[0];
			for (int i = 1; i < 4; i++) {
				maskBinaryOS << '.' << maskBinary[i];
			}
			//Adres podsieci w systemie dziesietnym: ;
			subnetBinaryOS << subnetBinary[0];
			for (int i = 1; i < 4; i++) {
				subnetBinaryOS << '.' << subnetBinary[i];
			}

			string ipDecimalStr = ipBinaryOS.str();
			string maskDecimalStr = maskBinaryOS.str();
			string subnetDecimalStr = subnetBinaryOS.str();

			//Czyszczenie strumienia:
			ipBinaryOS.str("");
			maskBinaryOS.str("");
			subnetBinaryOS.str("");

			//Adres IP w systemie szesnastkowym: ;
			ipBinaryOS << hex << ipBinary[0];
			for (int i = 1; i < 4; i++) {
				ipBinaryOS << '.' << hex << ipBinary[i];
			}
			//Maska podsieci w systemie szesnastkowym: ;
			maskBinaryOS << hex << maskBinary[0];
			for (int i = 1; i < 4; i++) {
				maskBinaryOS << '.' << hex << maskBinary[i];
			}
			//Adres podsieci w systemie szesnastkowym: ;
			subnetBinaryOS << hex << subnetBinary[0];
			for (int i = 1; i < 4; i++) {
				subnetBinaryOS << '.' << hex << subnetBinary[i];
			}

			string ipHexStr = ipBinaryOS.str();
			string maskHexStr = maskBinaryOS.str();
			string subnetHexStr = subnetBinaryOS.str();

			//Wyœwietlanie wyników
			/*	11000000.10101000.00000000.00001010
				11111111.11111111.11111111.11111111
				11000000.10101000.00000000.00001010
				192.168.0.10
				255.255.255.255
				192.168.0.10
				c0.a8.0.a
				ff.ff.ff.ff
				c0.a8.0.a
			*/
			cout << ipBinaryStr << endl;
			cout << maskBinaryStr << endl;
			cout << subnetBinaryStr << endl;
			cout << ipDecimalStr << endl;
			cout << maskDecimalStr << endl;
			cout << subnetDecimalStr << endl;
			cout << ipHexStr << endl;
			cout << maskHexStr << endl;
			cout << subnetHexStr << endl;

			return RUN_ALL_TESTS();
		}
		else {
			cout << "Niepoprawny typ danych. Uruchom program jeszcze raz.";
			return 0;
		}
	}
	else {
		cout << "Niepoprawna ilosc argumentow. Uruchom program jeszcze raz.";
		return 0;
	}

}


TEST(Testy, Regex) {
	bool isIP = validateIP("192.168.0.10");
	EXPECT_TRUE(isIP);
	bool isMask = validateMask("255.255.255.255");
	EXPECT_TRUE(isMask);
}


