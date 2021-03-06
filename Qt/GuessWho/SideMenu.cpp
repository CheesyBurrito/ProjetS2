#include "SideMenu.h"



SideMenu::SideMenu(QWidget *parent, int height, int width) :QWidget(parent)
{
	this->setStyleSheet("background: transparent;");
	menuHeight = height;
	menuWidth = width;

	setupWidgets();
	setupLayouts();

	connect(zoomButton, SIGNAL(clicked()), this, SLOT(switchZoomIcon()));
}


SideMenu::~SideMenu()
{
}

void SideMenu::setupWidgets() {
	background = new QLabel(this);
	cornerBackground = new QLabel(this);
	characteristics = new QLabel(background);
	zoomButton = new QPushButton(this);
	questionMenuBar = new QuestionMenuBar(this);

	//Backgrounds
	QPixmap pix("./Photos/side_menu.png");
	QPixmap pix_corner("./Photos/corner_frame.png");
	background->setPixmap(pix.scaled(300, menuHeight - 100));
	cornerBackground->setPixmap(pix_corner.scaled(300, 100));

	//Characteristics view
	characteristics->setText("");
	characteristics->setMaximumWidth(200);
	characteristics->setWordWrap(true);
	characteristics->setAttribute(Qt::WA_TranslucentBackground);
	characteristics->setAlignment(Qt::AlignLeft);
	characteristics->setStyleSheet("background:transparent; color:white");
	characteristics->setFont(QFont("Walkway Bold", 12));

	//Zoom buton
	QPixmap img = QPixmap();
	img.load("./Photos/zoom.png");
	zoomModeIcon.addPixmap(img.scaled(50, 50));
	img.load("./Photos/cursor.png");
	normalModeIcon.addPixmap(img.scaled(50, 50));
	zoomButton->setIcon(zoomModeIcon);
	zoomButton->setIconSize(QSize(50, 50));
	zoomButton->setFixedSize(50, 50);

	//Score
	nbHiddenCharactersLabel = new QLabel(this);
	nbHiddenCharactersLabel->setText("0/20");
	nbHiddenCharactersLabel->setAttribute(Qt::WA_TranslucentBackground);
	nbHiddenCharactersLabel->setAlignment(Qt::AlignRight);
	nbHiddenCharactersLabel->setAlignment(Qt::AlignBottom);
	nbHiddenCharactersLabel->setStyleSheet("background:transparent; color:white");
	nbHiddenCharactersLabel->setFont(QFont("Walkway Bold", 24));

	infoText = new QLabel(this);
	infoText->setText("Adversaire");
	infoText->setAttribute(Qt::WA_TranslucentBackground);
	infoText->setAlignment(Qt::AlignRight);
	infoText->setAlignment(Qt::AlignTop);
	infoText->setStyleSheet("background:transparent; color:white");
	infoText->setFont(QFont("Walkway Bold", 12));
}

void SideMenu::setupLayouts() {
	layout = new QGridLayout(this);
	scoreLayout = new QVBoxLayout(this);
	hLayout = new QHBoxLayout(this);

	layout->setColumnMinimumWidth(0, menuWidth - 300); //Sets blank space before the actual menubar
	layout->setColumnMinimumWidth(1, 20); //Moves content away from border
	layout->addWidget(background, 0, 1, 2, 2);
	layout->addWidget(cornerBackground, 2, 1, 1, 2);

	questionMenuBar->setMaximumHeight(500);

	hLayout->addWidget(zoomButton);
	scoreLayout->addWidget(nbHiddenCharactersLabel);
	scoreLayout->addWidget(infoText);
	scoreLayout->setAlignment(Qt::AlignHCenter);
	hLayout->addLayout(scoreLayout);

	layout->addWidget(questionMenuBar, 0, 2);
	layout->addWidget(characteristics, 1, 2);
	layout->addLayout(hLayout, 2, 2);

	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	this->setFixedWidth(menuWidth);
	this->setGeometry(0, 0, menuWidth, menuHeight);
	this->setLayout(layout);
}

void SideMenu::setTraits(std::string newTraits) {
	characteristics->setText(QString::fromStdString(newTraits));
}


void SideMenu::switchZoomIcon() {

	emit lowerBarTest("TEST", zoomMode);

	if (zoomMode)
		zoomButton->setIcon(zoomModeIcon);
	else
		zoomButton->setIcon(normalModeIcon);

	zoomMode = !zoomMode;
}