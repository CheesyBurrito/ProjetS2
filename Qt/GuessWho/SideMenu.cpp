#include "SideMenu.h"



SideMenu::SideMenu(QWidget *parent, int windowHeight, int windowWidth) :QWidget(parent)
{
	image = new QLabel(this);
	image2 = new QLabel(this);
	characteristics = new QLabel(image);
	layout = new QGridLayout(this);
	scoreLayout = new QVBoxLayout(this);

	QPixmap pix("./Photos/side_menu.png");
	image->setPixmap(pix.scaled(300, windowHeight-100));
	QPixmap pix_corner("./Photos/corner_frame.png");
	image2->setPixmap(pix_corner.scaled(300, 100));
	layout->addWidget(image, 0, 0, 6, 10);
	layout->addWidget(image2, 6, 0,1,10);

	questionMenuBar = new QuestionMenuBar(parent);
	layout->addWidget(questionMenuBar, 0, 1, 5, 9);
	
	characteristics->setText("");
	characteristics->setMaximumWidth(200);
	characteristics->setWordWrap(true);
	characteristics->setAttribute(Qt::WA_TranslucentBackground);
	characteristics->setAlignment(Qt::AlignLeft);
	characteristics->setStyleSheet("background:transparent; color:white");
	characteristics->setFont(QFont("Walkway Bold", 12));
	layout->addWidget(characteristics, 5, 1,2,9);

	QPixmap img = QPixmap();
	img.load("./Photos/zoom.png");
	zoomModeIcon.addPixmap(img.scaled(50, 50));
	img.load("./Photos/cursor.png");
	normalModeIcon.addPixmap(img.scaled(50, 50));

	zoomButton = new QPushButton(this);
	zoomButton->setIcon(zoomModeIcon);
	zoomButton->setIconSize(QSize(50, 50));
	zoomButton->setFixedSize(50, 50);
	layout->addWidget(zoomButton, 6, 1, 1, 3);

	nbHiddenCharactersLabel = new QLabel(this);
	nbHiddenCharactersLabel->setText("5/20");
	nbHiddenCharactersLabel->setAttribute(Qt::WA_TranslucentBackground);
	nbHiddenCharactersLabel->setAlignment(Qt::AlignRight);
	nbHiddenCharactersLabel->setAlignment(Qt::AlignBottom);
	nbHiddenCharactersLabel->setStyleSheet("background:transparent; color:white");
	nbHiddenCharactersLabel->setFont(QFont("Walkway Bold", 24));
	scoreLayout->addWidget(nbHiddenCharactersLabel);

	QLabel* infoText = new QLabel(this);
	infoText->setText("Adversaire");
	infoText->setAttribute(Qt::WA_TranslucentBackground);
	infoText->setAlignment(Qt::AlignRight);
	infoText->setAlignment(Qt::AlignTop);
	infoText->setStyleSheet("background:transparent; color:white");
	infoText->setFont(QFont("Walkway Bold", 12));
	scoreLayout->addWidget(infoText);

	layout->addLayout(scoreLayout, 6, 4, 1, 5);


	this->setFixedWidth(300);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	this->setLayout(layout);
	this->setGeometry(0, 0, 300, windowHeight);

	connect(zoomButton, SIGNAL(clicked()), this, SLOT(switchZoomIcon()));
}


SideMenu::~SideMenu()
{
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