#include "header.h"

int main () {
    int size = 0;
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                        'H', 'I', 'J', 'K', 'L', 'M', 'N',
                        'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                        'V', 'W', 'X', 'Y', 'Z'};
    string morseSymbols[26] = {"._", "_...", "_._.", "_..",
                            ".", ".._.", "__.", "....", "..",
                            ".___", "_._", "._..", "__", "_.",
                            "___", ".__.", "__._", "._.", "...",
                            "_", ".._", "..._", ".__", "_.._",
                            "_.__", "__.."};

    fstream inFile;
    fstream outFile;
    string inputFile = "Input.txt";
    string outputFile = "Output.txt";
    char answer;

    cout << "What is the input file written in?" << endl;
    cout << "A) English" << endl;
    cout << "B) Morse Code" << endl;
    cin >> answer;
    cout << endl;
    if (toupper(answer) == 'A') {

        openFile(inFile, inputFile, ios::in);
        size = countLines(inFile);
        string lines[size];

        storeLines(inFile, lines);
        inFile.close();
        displayOriginal(size, lines);

        openFile(outFile, outputFile, ios::out);
        translateToMorse(alphabet, morseSymbols, lines, size, outFile);
        outFile.close();
    }
    if (toupper(answer) == 'B') {

        openFile(inFile, inputFile, ios::in);
        size = countLines(inFile);
        cout << "size: " << size << endl;
        string lines[size];

        storeLines(inFile, lines);
        inFile.close();
        displayOriginal(size, lines);

        openFile(outFile, outputFile, ios::out);
        translateToEnglish(alphabet, morseSymbols, lines, size, outFile);
        outFile.close();
    }

    cout << endl << endl;
    cout << "You can also see your output message in the Output.txt file" << endl;

}