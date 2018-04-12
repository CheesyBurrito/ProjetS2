#include "OptionsMenu.h"

OptionsMenu::OptionsMenu(QWidget* parent) : QWidget(parent)
{
	createOptionsMenu();
}

OptionsMenu::~OptionsMenu()
{
}

void OptionsMenu::createOptionsMenu()
{
	layout = new QFormLayout;
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignCenter);
	setLayout(layout);

	addCharacter = new MenuButton(this, " Ajouter un personnage");
	addCharacter->setToolTip("Le personnage sera ajouté à la liste active");

	createNewList = new MenuButton(this, " Créer une nouvelle liste");
	createNewList->setToolTip("La nouvelle liste deviendra la liste active");

	changeList = new MenuButton(this, " Changer de liste");
	changeList->setToolTip("La liste choisie deviendra la liste active");

	back = new MenuButton(this, " Retour");
	back->setToolTip(" Retourner au menu principal");

	active_List = new QLineEdit(this);
	active_List->setStyleSheet("background: white;");
	active_List->setFont(QFont("Walkway Bold", 20));
	active_List->setText(activeList);
	active_List->setReadOnly(true);

	emptySpace = new QLabel("", this);
	emptySpace->setFont(QFont("Walkway Bold", 20));
	emptySpace->setStyleSheet("background: transparent");

	list = new QLabel("Liste Active:", this);
	list->setFont(QFont("Walkway Bold", 20));
	list->setStyleSheet("background: transparent; color : white");

	mediaPlayer = new QHBoxLayout(this);

	music = new QLabel("Musique", this);
	music->setFont(QFont("Walkway Bold", 20));
	music->setStyleSheet("background: transparent; color : white");

	next = new QPushButton(this);
	next->setFlat(true);
	next->setStyleSheet("background-image: url(./Photos/next.png);");
	next->setCursor(Qt::PointingHandCursor);
	next->setFixedSize(52, 52);

	activeSong = new QLabel("Electro Cabello - Kevin MacLeod", this);
	activeSong->setFont(QFont("Walkway Bold", 20));
	activeSong->setStyleSheet("background: transparent; color : white");
	activeSong->setFixedWidth(450);

	prev = new QPushButton(this);
	prev->setFlat(true);
	prev->setStyleSheet("background-image: url(./Photos/prev.png);");
	prev->setCursor(Qt::PointingHandCursor);
	prev->setFixedSize(52,52);

	mediaPlayer->addWidget(prev);
	mediaPlayer->addWidget(activeSong);
	mediaPlayer->addWidget(next);

	layout->addRow(addCharacter);
	layout->addRow(createNewList);
	layout->addRow(changeList);
	layout->addRow(back);
	layout->addRow(emptySpace);
	layout->addRow(list);
	layout->addRow(active_List);
	layout->addRow(emptySpace);
	layout->addRow(music);
	layout->addRow(mediaPlayer); 

	hide();
}

void OptionsMenu::addCharacters()
{
	AddCharacterWindow = new AddCharacter(this);
	AddCharacterWindow->show();
	connect(AddCharacterWindow->getCancelButton(), SIGNAL(clicked()), AddCharacterWindow, SLOT(close()));
	connect(AddCharacterWindow->getCancelButton(), SIGNAL(clicked()), this, SLOT(activateOptionsMenu()));
	connect(AddCharacterWindow, SIGNAL(characterIsOk()), this, SLOT(activateOptionsMenu()));
	this->setDisabled(true);
}

void OptionsMenu::activateOptionsMenu()
{
	setDisabled(false);
}

void OptionsMenu::showDialog()
{
	QString selfilter = tr("GuessWho Files (*.gw)");
	QString fileDialog = QFileDialog::getOpenFileName(this, "Ouvrir une liste de personnages", "./Photos", tr("GuessWho Files (*.gw)"), &selfilter);
	if (fileDialog != "")
	{
		activeList = fileDialog;
	}
	active_List->setText(activeList);
}