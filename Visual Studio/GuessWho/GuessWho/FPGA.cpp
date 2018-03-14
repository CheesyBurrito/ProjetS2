#include "stdafx.h"
#include "FPGA.h"

int FPGA::convertDataToPhoneme() {

}

void FPGA::readLoop() {

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
	}

	return true;
}


FPGA::FPGA(int delay)
{
	cardStatus = fpgaCard.estOk();
	readingDelay = 10;
	burstDelay = delay;

}


FPGA::~FPGA()
{
}
