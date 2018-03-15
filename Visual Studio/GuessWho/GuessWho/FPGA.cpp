#include "stdafx.h"
#include "FPGA.h"

int FPGA::convertDataToPhoneme() {
	return 0;
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
			printRead();
			phonemeDetected = true;
		}

		Sleep(500); //Time before trying to see if button pressed
	}

	if (!cardStatus) //If loop was exited because of communication error, print so user can know
		cout << "ERREUR COMMUNICATION FPGA" << endl;
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

		Sleep(burstDelay);
	}

	return true;
}


FPGA::FPGA(int delay)
{
	cardStatus = fpgaCard.estOk();
	readingDelay = 10;
	burstDelay = delay;
	phonemeDetected = false;
}


FPGA::~FPGA()
{
}
