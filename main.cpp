//SD9 to WAV Converter for Beatmania IIDX
//Converts SD9 files to WAV... by removing the first 0x20 bytes...
//Tested on IIDX 20 Tricoro and IIDX 21 SPADA

//Usage: sd92wav.exe *.sd9 [*.wav]
//*.wav is optional. If omitted, ".wav" would be added to the original file.

//By @iDestyKK

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	//Get file data...
	if (argc == 1 || argc > 3) {
		cerr << "SD9 to WAV Converter for Beatmania IIDX by @iDestyKK\n";
		cerr << "Usage: " << argv[0] << " *.sd9 [*.wav]\n";
		return -1;
	}

	cout << "Converting...";

	string input = argv[1];
	string output;

	if (argc == 2) {
		//We specified no output name, so just add to the original name.
		output = input + ".wav";
	}

	ifstream fp(input.c_str(), ios::binary);

	unsigned int size;

	char* bytes;
	fp.seekg(0, ios::end);
	size = (int)fp.tellg() - 0x20;

	fp.seekg(0x20, ios::beg);

	//Create new array with the size of the file... - 0x20
	bytes = new char[size];

	//Read bytes into file
	fp.read(bytes,size);

	fp.close();

	//Write to new file
	ofstream op(output.c_str(), ios::binary);
	op.write(bytes, size);
	op.close();

	//Save the day
	cout << " Done!\n";
	return 1;
}