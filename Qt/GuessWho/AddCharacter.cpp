#include "AddCharacter.h"


AddCharacter::AddCharacter(QWidget* parent) 
{
	createAddCharacter();
}


AddCharacter::~AddCharacter()
{
}

void AddCharacter::createAddCharacter()
{
	this->setMinimumHeight(700);
	this->setWindowTitle("Ajouter un personnage");
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);

	layout = new QVBoxLayout(this);

	buttons = new QHBoxLayout(this);
		cancelButton = new QPushButton("Cancel", this);
		okButton = new QPushButton("Ajouter", this);

	nameBox = new QHBoxLayout(this);
		nameLabel = new QLabel("Nom du personnage", this);
		nameLineEdit = new QLineEdit(this);

	eyesBox = new QGroupBox("Couleur des yeux", this);
	eyesLayout = new QHBoxLayout(this);
		greenEyes = new QRadioButton("Vert",this);
		blueEyes = new QRadioButton("Bleu", this);
		brownEyes = new QRadioButton("Brun", this);
		redEyes = new QRadioButton("Rouge", this);

	hairColorBox = new QGroupBox("Couleur des cheveux", this);
	hairTraitsBox = new QGroupBox("Traits des cheveux", this);
	hairColorLayout = new QHBoxLayout;
	hairTraitsLayout = new QHBoxLayout;
		brownHair = new QRadioButton("Brun", this);
		redhead = new QRadioButton("Roux", this);
		blond = new QRadioButton("Blond", this);
		blackHair = new QRadioButton("Noir", this);
		whiteHair = new QRadioButton("Blanc", this);
		others = new QRadioButton("Autres", this);
		bald = new QRadioButton("Chauve", this);
		shortHair = new QRadioButton("Court", this);
		longHair = new QRadioButton("Long", this);

	accessoriesLayout = new QHBoxLayout;
	accessoriesBox = new QGroupBox("Accesoires*", this);
		glasses = new QCheckBox("Lunettes", this);
		hat = new QCheckBox("Chapeau", this);
		piercing = new QCheckBox("Piercing", this);
		tattoo = new QCheckBox("Tattoo", this);
		max3 = new QLabel("*Un maximum de 3 accessoires peuvent être sélectionnés", this);

	sexeLayout = new QHBoxLayout;
	sexeBox = new QGroupBox("Genre", this);
		man = new QRadioButton("Homme", this);
		woman = new QRadioButton("Femme", this);

	facialHairLayout = new QHBoxLayout;
	facialHairBox = new QGroupBox("Pilosité", this);
		shave = new QRadioButton("Rasé", this);
		beard = new QRadioButton("Barbe", this);
		mustache = new QRadioButton("Moustache", this);
		bouc = new QRadioButton("Bouc", this);

	ageLayout = new QHBoxLayout;
	ageBox = new QGroupBox("Âge", this);
		student = new QRadioButton("Étudiant", this);;
		teacher = new QRadioButton("Personnel", this);;

	skinColorLayout	= new QHBoxLayout;
	skinColorBox = new QGroupBox("Couleur de peau", this);
		blackSkin = new QRadioButton("Noire", this);
		whiteSkin = new QRadioButton("Blanche", this);
		tanned = new QRadioButton("Basanée", this);

	pictureLayout = new QHBoxLayout;
	pictureBox = new QGroupBox("Photo du personnage ", this);
		browse = new QPushButton("Parcourir", this);
		fileName = new QLineEdit(this);
		fileName->setReadOnly(true);

	eyesLayout->addWidget(brownEyes);
	eyesLayout->addWidget(greenEyes);
	eyesLayout->addWidget(blueEyes);
	eyesLayout->addWidget(redEyes);

	hairColorLayout->addWidget(brownHair);
	hairColorLayout->addWidget(redhead);
	hairColorLayout->addWidget(blond);
	hairColorLayout->addWidget(blackHair);
	hairColorLayout->addWidget(whiteHair);
	hairColorLayout->addWidget(others);

	hairTraitsLayout->addWidget(bald);
	hairTraitsLayout->addWidget(shortHair);
	hairTraitsLayout->addWidget(longHair);

	accessoriesLayout->addWidget(piercing);
	accessoriesLayout->addWidget(hat);
	accessoriesLayout->addWidget(glasses);
	accessoriesLayout->addWidget(tattoo);

	sexeLayout->addWidget(man);
	sexeLayout->addWidget(woman);
	
	facialHairLayout->addWidget(shave);
	facialHairLayout->addWidget(beard);
	facialHairLayout->addWidget(mustache);
	facialHairLayout->addWidget(bouc);

	ageLayout->addWidget(student);
	ageLayout->addWidget(teacher);

	skinColorLayout->addWidget(blackSkin);
	skinColorLayout->addWidget(whiteSkin);
	skinColorLayout->addWidget(tanned);

	pictureLayout->addWidget(fileName);
	pictureLayout->addWidget(browse);

	nameBox->addWidget(nameLabel);
	nameBox->addWidget(nameLineEdit);
	eyesBox->setLayout(eyesLayout);
	hairColorBox->setLayout(hairColorLayout);
	hairTraitsBox->setLayout(hairTraitsLayout);
	accessoriesBox->setLayout(accessoriesLayout);
	sexeBox->setLayout(sexeLayout);
	facialHairBox->setLayout(facialHairLayout);
	ageBox->setLayout(ageLayout);
	skinColorBox->setLayout(skinColorLayout);
	pictureBox->setLayout(pictureLayout);

	layout->addLayout(nameBox);
	layout->addWidget(eyesBox);
	layout->addWidget(hairColorBox);
	layout->addWidget(hairTraitsBox);
	layout->addWidget(accessoriesBox);
	layout->addWidget(max3);
	layout->addWidget(sexeBox);
	layout->addWidget(facialHairBox);
	layout->addWidget(ageBox);
	layout->addWidget(skinColorBox);
	layout->addWidget(pictureBox);

	buttons->addWidget(okButton,Qt::AlignRight);
	buttons->addWidget(cancelButton, Qt::AlignRight);
	layout->addLayout(buttons);
	
	this->setLayout(layout);

	connect(browse, SIGNAL(clicked()), this, SLOT(showDialog()));
	connect(okButton, SIGNAL(clicked()), this, SLOT(verifyAddCharacter()));
}

void AddCharacter::showDialog()
{
	QString selfilter = tr("PNG (*.PNG)");
	QString fileDialog = QFileDialog::getOpenFileName(this, "Choisir une photos du personnage", "./Photos", tr("PNG (*.PNG)"), &selfilter);
	if (fileDialog != "")
	{
		picturePath = fileDialog;
	}
	fileName->setText(picturePath);
}

void AddCharacter::verifyAddCharacter()
{
	bool characterOk = true;
	int num_accessories = 0;

	nameLabel->setStyleSheet("color : black");
	eyesBox->setStyleSheet("QGroupBox {color : black} ");
	hairColorBox->setStyleSheet("QGroupBox {color : black} ");
	hairTraitsBox->setStyleSheet("QGroupBox {color : black} ");
	accessoriesBox->setStyleSheet("QGroupBox {color : black} ");
	sexeBox->setStyleSheet("QGroupBox {color : black} ");
	facialHairBox->setStyleSheet("QGroupBox {color : black} ");
	ageBox->setStyleSheet("QGroupBox {color : black} ");
	skinColorBox->setStyleSheet("QGroupBox {color : black} ");
	pictureBox->setStyleSheet("QGroupBox {color : black} ");

	//Find ID in the Documents
	// ID = setID();

	if (nameLineEdit->text() == "")
	{
		nameLabel->setStyleSheet("color : red");
		characterOk = false;
	}
	else
		name = nameLineEdit->text();

	if (brownEyes->isChecked())
		eyes = 0;
	else if (greenEyes->isChecked())
		eyes = 1;
	else if (blueEyes->isChecked())
		eyes = 2;
	else if (redEyes->isChecked())
		eyes = 3;
	else
	{
		eyesBox->setStyleSheet("QGroupBox {color : red} ");
		characterOk = false;
	}

	if (brownHair->isChecked())
		hairColor = 0;
	else if (redhead->isChecked())
		hairColor = 4;
	else if (blond->isChecked())
		hairColor = 5;
	else if (blackHair->isChecked())
		hairColor = 6;
	else if (whiteHair->isChecked())
		hairColor = 7;
	else if (others->isChecked())
		hairColor = 9;
	else
	{
		hairColorBox->setStyleSheet("QGroupBox {color : red} ");
		characterOk = false;
	}

	if (bald->isChecked())
		hairCharacteristics = 1;
	else if (shortHair->isChecked())
		hairCharacteristics = 2;
	else if (longHair->isChecked())
		hairCharacteristics = 3;
	else
	{
		hairTraitsBox->setStyleSheet("QGroupBox {color : red} ");
		characterOk = false;
	}

	if (piercing->isChecked())
		num_accessories++;
	if (hat->isChecked())
		num_accessories++;
	if (glasses->isChecked())
		num_accessories++;
	if (tattoo->isChecked())
		num_accessories++;

	if (num_accessories == 0)
		accessories.push_back(0);
	else if (num_accessories == 4)
	{
		accessoriesBox->setStyleSheet("QGroupBox {color : red} ");
	}
	else
	{
		if (piercing->isChecked())
			accessories.push_back(4);
		if (hat->isChecked())
			accessories.push_back(5);
		if (glasses->isChecked())
			accessories.push_back(6);
		if (tattoo->isChecked())
			accessories.push_back(7);
	}

	if (man->isChecked())
		gender = 12;
	else if (woman->isChecked())
		gender = 13;
	else
	{
		sexeBox->setStyleSheet("QGroupBox {color : red} ");
		characterOk = false;
	}

	if (shave->isChecked())
		gender = 8;
	else if (beard->isChecked())
		gender = 9;
	else if (mustache->isChecked())
		gender = 10;
	else if (bouc->isChecked())
		gender = 11;
	else
	{
		facialHairBox->setStyleSheet("QGroupBox {color : red} ");
		characterOk = false;
	}

	if (student->isChecked())
		age = 14;
	else if (teacher->isChecked())
		age = 15;
	else
	{
		ageBox->setStyleSheet("QGroupBox {color : red} ");
		characterOk = false;
	}

	if (blackSkin->isChecked())
		skinColor = 6;
	else if (whiteSkin->isChecked())
		skinColor = 7;
	else if (tanned->isChecked())
		skinColor = 8;
	else
	{
		skinColorBox->setStyleSheet("QGroupBox {color : red} ");
		characterOk = false;
	}

	if (picturePath == "")
	{
		pictureBox->setStyleSheet("QGroupBox {color : red} ");
		characterOk = false;
	}
	else
	{
		//Implement copie picture and change name for ID.png
	}
	
	if (!characterOk)
		QMessageBox::warning(NULL, "Formulaire incomplet", "Il manque des informations pour la création du personnage!", QMessageBox::Ok);
	else if(num_accessories == 4)
		QMessageBox::warning(NULL, "Trop d'accessoires", "Il y a trop d'accessoires! Le maximum est de 3!", QMessageBox::Ok);
	else
	{
		this->close();
		emit characterIsOk();
	}

}
