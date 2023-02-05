#include "header.h"

/*************************************************************
 * Function: openFile ()                  	
 * Date Created: 1/31/23                  	        
 * Date Last Modified: 2/4/23                        
 * Description: This function opens a file in way
 *              depending on if its for reading
 *              or writing.                     	
 * Input parameters: fstream, file name, and the openmode (in/out for reading/writing).    	
 * Returns: Void           	
 * Pre: NA      	
 * Post: The file specified when called is opened.      
 *************************************************************/

void openFile(fstream &File, string fileName, ios_base::openmode mode = ios::in | ios::out) {
    File.open(fileName, mode);
    if (!File.is_open()) {
        cout << "Failed to open File";
        exit(-1);
    }
}

/*************************************************************
 * Function: countLines ()                  	
 * Date Created: 1/31/23                  	        
 * Date Last Modified: 2/2/23                        
 * Description: This function counts the number of lines
 *              in the input file specified when called.                     	
 * Input parameters: fstream.    	
 * Returns: The number of lines in the input file.           	
 * Pre: The input file needs to be open.      	
 * Post: The number of lines in input file is returned.      
 *************************************************************/

int countLines(fstream &inFile) {
    int size = 0;
    string line;
    while (getline(inFile, line)) {
        size++;
    }
    inFile.clear();
    inFile.seekg(0);
    return size;
}

/*************************************************************
 * Function: storeLines ()                  	
 * Date Created: 1/31/23                  	        
 * Date Last Modified: 1/31/23                        
 * Description: This function stores the lines of an input file
 *              into an array.                     	
 * Input parameters: fstream, and an array for the lines in
 *                   the input file.    	
 * Returns: Void.           	
 * Pre: the file specified when called must be open.      	
 * Post: They array lines is full of the lines from the
 *       input file.      
 *************************************************************/

void storeLines(fstream &inFile, string lines[]) {
    string line;
    int counter = 0;
    while (getline(inFile, line)) {
        lines[counter] = line;
        counter++;
    }
}

/*************************************************************
 * Function: displayOriginal ()                  	
 * Date Created: 2/2/23                  	        
 * Date Last Modified: 2/2/23                        
 * Description: This function displays the text from the
 *              input file.                     	
 * Input parameters: The size of the array lines, and the
 *                   array lines.    	
 * Returns: Void.           	
 * Pre: The array lines must be populated.      	
 * Post: The original input message is displayed.      
 *************************************************************/

void displayOriginal(int size, string lines[]) {
    cout << "You entered:" << endl;
    for (int i = 0; i < size; i++) {
        cout << lines[i] << endl;
    }
    cout << endl << endl; // To make the output look pretty
}

/*************************************************************
 * Function: translateToMorse ()                  	
 * Date Created: 1/31/23                  	        
 * Date Last Modified: 2/4/23                        
 * Description: This function translates the english
 *              from the input file into morse code and
 *              writes it to the output file.                     	
 * Input parameters: array of alphabet letters, array of
 *                   morse code symbols, array of lines in
 *                   the input file, the size of the array lines,
 *                   fstream.    	
 * Returns: Void           	
 * Pre: The input file must be filled along with the array lines.
 *      The function countLines must be called on the array lines.      	
 * Post: The translated morse code is written to the output file.      
 *************************************************************/

void translateToMorse(char alphabet[], string morseSymbols[], string lines[], int size, fstream &outFile) {
    string word;
    int charsTranslated = 0;
    cout << "Your translation to Morse Code: " << endl;
    for (int i = 0; i < size; i++) {
        istringstream iss(lines[i]);
        while (iss >> word) {
            for (int j = 0; j < word.size(); j++) {
                for (int k = 0; k < 26; k++) {  // 26 is the size of the alphabet
                    if (toupper(word[j]) == alphabet[k]) {
                        outFile << morseSymbols[k];
                        cout << morseSymbols[k];
                        charsTranslated++;
                        outFile << " ";
                        cout << " ";
                    }
                }
            }
            outFile << "   ";
            cout << "   ";
        }
        outFile << endl;
        cout << endl;
    }
    cout << "Number of English characters translated: " << charsTranslated << endl;
}

/*************************************************************
 * Function: translateToEnglish ()                  	
 * Date Created: 2/1/23                  	        
 * Date Last Modified: 2/4/23                        
 * Description: This function translates the morse code from
 *              the input file into english and writes it
 *              to the output file.                     	
 * Input parameters: array of alphabet letters, array of
 *                   morse code symbols, array of lines in
 *                   the input file, the size of the array lines,
 *                   fstream.    	
 * Returns: Void           	
 * Pre: The input file must be filled along with the array lines.
 *      The function countLines must be called on the array lines.      	
 * Post: The translated english is written in the output file.      
 *************************************************************/

void translateToEnglish(char alphabet[], string morseSymbols[], string lines[], int size, fstream &outFile) {
    string symbol;
    int symbolsTranslated = 0;
    bool endword = false;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            if (lines[i][j] != ' ') {
                symbol += lines[i][j];
            } else {
                for (int k = 0; k < 26; k++) {
                    if (symbol == morseSymbols[k]) {
                        outFile << alphabet[k];
                        cout << alphabet[k];
                        symbolsTranslated++;
                        symbol = "";
                    }
                }
                if (j + 1 < lines[i].size() && lines[i][j + 1] == ' ' && !endword) {
                    endword = true;
                    outFile << " ";
                    cout << " ";
                } else if (endword) {
                    endword = false;
                }
            }
        }
        if (i != size - 1) {                    // This section probably is not the most efficient.
            outFile << endl;                    // Couldn't think of a way to work it into the main
            cout << endl;                       // body of the function.  This section is responsible
        }                                       // for returning end lines at the end of each line
    }                                           // and returning the last letter of the input message.
    for (int g = 0; g < 26; g++) {              //
        if (symbol == morseSymbols[g]) {        //
            outFile << alphabet[g];             //
            cout << alphabet[g];                //
            symbolsTranslated++;                //
        }                                       //
    }                                           //
    outFile << endl;                            
    cout << endl;
    cout << "Number of Morse Code symbols translated: " << symbolsTranslated << endl;
}