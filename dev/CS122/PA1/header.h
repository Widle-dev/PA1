/*
 Name: Jacob Alfonso
 Class: CSPC 122, 2023
 Date: February 4, 2023
 Programming Assignment: PA1                                                                      
 Description: This program translates morse code to english and vice versa.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <streambuf>

using namespace std;

#ifndef HEADER_H
#define HEADER_H

void openFile(fstream &, string, ios_base::openmode); // Got the openmode idea while reading about fstream
int countLines(fstream &);
void storeLines(fstream &, string[]);
void displayOriginal(int, string[]);
void translateToMorse(char[], string[], string[], int, fstream &);
void translateToEnglish(char[], string[], string[], int, fstream &);

#endif