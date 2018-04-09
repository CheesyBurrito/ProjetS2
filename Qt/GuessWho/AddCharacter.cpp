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
	layout = new QVBoxLayout(this);
		title = new QLabel("Ajouter un personnage", this);
		title->setFont(QFont("Walkway Bold", 20));

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
		redEyes = new QRadioButton("Red", this);

	hairColorBox = new QGroupBox("Couleur des cheveux", this);
	hairTraitsBox = new QGroupBox("Traits des cheveux", this);
	hairColor = new QHBoxLayout;
	hairTraits = new QHBoxLayout;
		brownHair = new QRadioButton("Brun", this);
		redhead = new QRadioButton("Roux", this);
		blond = new QRadioButton("Blond", this);
		blackHair = new QRadioButton("Noir", this);
		whiteHair = new QRadioButton("Blanc", this);
		others = new QRadioButton("Autres", this);
		bald = new QRadioButton("Chauve", this);
		shortHair = new QRadioButton("Court", this);
		longHair = new QRadioButton("Long", this);

	accessoriesLayout = new QVBoxLayout;
	accessoriesBox = new QGroupBox("Accesoires", this);
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

	this->setFixedSize(500, 900);
	this->setWindowFlag(Qt::WindowStaysOnTopHint);
	this->setWindowFlag(Qt::FramelessWindowHint);

	eyesLayout->addWidget(brownEyes);
	eyesLayout->addWidget(greenEyes);
	eyesLayout->addWidget(blueEyes);
	eyesLayout->addWidget(redEyes);

	hairColor->addWidget(brownHair);
	hairColor->addWidget(redhead);
	hairColor->addWidget(blond);
	hairColor->addWidget(blackHair);
	hairColor->addWidget(whiteHair);
	hairColor->addWidget(others);

	hairTraits->addWidget(bald);
	hairTraits->addWidget(shortHair);
	hairTraits->addWidget(longHair);

	accessoriesLayout->addWidget(piercing);
	accessoriesLayout->addWidget(hat);
	accessoriesLayout->addWidget(glasses);
	accessoriesLayout->addWidget(tattoo);
	accessoriesLayout->addWidget(max3);

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
	hairColorBox->setLayout(hairColor);
	hairTraitsBox->setLayout(hairTraits);
	accessoriesBox->setLayout(accessoriesLayout);
	sexeBox->setLayout(sexeLayout);
	facialHairBox->setLayout(facialHairLayout);
	ageBox->setLayout(ageLayout);
	skinColorBox->setLayout(skinColorLayout);
	pictureBox->setLayout(pictureLayout);

	layout->addWidget(title);
	layout->addLayout(nameBox);
	layout->addWidget(eyesBox);
	layout->addWidget(hairColorBox);
	layout->addWidget(hairTraitsBox);
	layout->addWidget(accessoriesBox);
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

}