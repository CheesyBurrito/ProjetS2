/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

FPGA.cpp
*****************************************/

#include "stdafx.h"
#include "FPGA.h"
#include <fstream>

/*Loops until button is pushed, then returns the detected phoneme
Returns -1 if no phoneme is detected
Returns -2 if there was a card error (You shouldn't phoneme methods once -2 was returned it won't work until software and hardware reset)
*/
int FPGA::getPhoneme() {
	readLoop();

	if (cardStatus)
		return convertDataToPhoneme();

	return FPGA_READING_ERROR;

}

void FPGA::readSlot() {
	if (readMode) {
		if (cardStatus) {
			if (readData()) {
				int phoneme = convertDataToPhoneme();
				if (phoneme != lastPhoneme) { //New phoneme detected

					lastPhoneme = phoneme;
					switch (phoneme) {
					case 0 :
						emit detectedPhoneme1();
						break;
					case 1:
						emit detectedPhoneme2();
						break;
					case 2:
						emit detectedPhoneme3();
						break;
					case 3:
						emit detectedPhoneme4();
						break;

					}
				}
			}
			else
				emit cardFailed();
		}
		else {
			emit cardFailed();
		}
	}
}

//Returns the position of a phoneme in the vector if detected, if not, returns -1
int FPGA::convertDataToPhoneme() {

	for (int i = 0; i < phonemes.size(); i++) { //foreach phoneme
		if (phonemes[i].isPhoneme(rawData))
			return i;
	}
	return FPGA_NO_READING;
}

void FPGA::printRead() {
	for (int i = 0; i < READINGS_PER_BURST; ++i) {
		cout << rawData[i][0] << '\t' << rawData[i][1] << '\t'
			<< rawData[i][2] << '\t' << rawData[i][3] << '\t' << endl;
	}
}

void FPGA::readLoop() {
	//TODO : CHANGE LOOP TO INFINITE LOOP WHEN THREADED
	phonemeDetected = false;
	int btnValue = 0;
	while(!phonemeDetected && cardStatus){
		if (cardStatus)
			cardStatus = fpgaCard.lireRegistre(nreg_lect_stat_btn, btnValue); //Reading buttons

		if (cardStatus && (btnValue & 1)) { //If button 1 was pressed read value from DAC
			readData();
			convertDataToPhoneme();
			//printRead();
			phonemeDetected = true;
		}

		Sleep(100); //Time before trying to see if button pressed
	}

	if (!cardStatus) //If loop was exited because of communication error, print so user can know
		cout << "ERREUR COMMUNICATION FPGA" << endl;
}

void FPGA::addPhoneme(int min[4], int max[4], float percentage){
	phonemes.push_back(Phoneme(min, max, percentage));
}

bool FPGA::switchToConnected() {
	fpgaCard.ecrireRegistre(nreg_ecri_led, 1); //Sets card to connected mode
	return fpgaCard.estOk();
}

bool FPGA::readData() {
	for (int i = 0; i < READINGS_PER_BURST; ++i) {

		if (cardStatus)
			cardStatus = fpgaCard.lireRegistre(nreg_lect_can0, rawData[i][0]);
		else
			return false;

		if (cardStatus)
			cardStatus = fpgaCard.lireRegistre(nreg_lect_can1, rawData[i][1]);
		else
			return false;

		if (cardStatus)
			cardStatus = fpgaCard.lireRegistre(nreg_lect_can2, rawData[i][2]);
		else
			return false;

		if (cardStatus)
			cardStatus = fpgaCard.lireRegistre(nreg_lect_can3, rawData[i][3]);
		else
			return false;

		Sleep(readingDelay);
	}

	return true;
}

bool FPGA::loadPhonemesFromFile(string filename) {
	ifstream file(filename);
	if (!file.is_open())
		return 0;

	int min[4];
	int max[4];
	float percentage;

	string line;
	getline(file, line); //Read header line

	for (int i = 0; i < 4; i++) { //For each phoneme
		for (int j = 0; j < 4; j++) {//For each channel
			getline(file, line, ';'); //Channel#

			getline(file, line, ';'); //Min
			min[j] = stoi(line);			

			if (j == 0) {
				getline(file, line, ';'); //Max
				max[j] = stoi(line);

				getline(file, line);//Percentage
				percentage = stof(line);
			}
			else {
				getline(file, line); //Max
				max[j] = stoi(line);
			}
		}

		this->addPhoneme(min, max, percentage);

	}

	file.close();
}

void FPGA::toggleReadMode() {
	if (cardStatus) {
		readMode = !readMode;
		if (readMode)
			emit cardOn();
		else
			emit cardOff();
	}
	else {
		emit cardFailed();
	}
}

void FPGA::checkCardStatus() {
	if(!cardStatus)
		emit cardFailed();
}

FPGA::FPGA(int delay)
{
	cardStatus = fpgaCard.estOk();

	//cardStatus = switchToConnected();

	readingDelay = 10;
	burstDelay = delay;
	phonemeDetected = false;
}

FPGA::~FPGA()
{
}
