#include "MediaPlayer.h"


MediaPlayer::MediaPlayer(QWidget* parent) : QWidget(parent)
{
	play = true;
	layout_mediaPlayer = new QHBoxLayout(this);
	setLayout(layout_mediaPlayer);
	setStyleSheet("background: transparent;");
	layout_mediaPlayer->setSpacing(0);
	layout_mediaPlayer->setContentsMargins(0, 0, 0, 0);
	layout_mediaPlayer->setAlignment(Qt::AlignTop);

	mute = new QPushButton(this);
	mute->setFlat(true);
	mute->setStyleSheet("background-image: url(./Photos/soundon.png);");
	mute->setCursor(Qt::PointingHandCursor);
	mute->setFixedSize(60, 60);

	next = new QPushButton(this);
	next->setFlat(true);
	next->setStyleSheet("background-image: url(./Photos/next.png);");
	next->setCursor(Qt::PointingHandCursor);
	next->setFixedSize(60, 60);

	activeSongLabel = new QLabel(this);
	activeSongLabel->setFont(QFont("Walkway Bold", 15));
	activeSongLabel->setStyleSheet("background: transparent; color : white;");
	activeSongLabel->setAlignment(Qt::AlignCenter);
	activeSongLabel->setFixedWidth(400);

	prev = new QPushButton(this);
	prev->setFlat(true);
	prev->setStyleSheet("background-image: url(./Photos/prev.png);");
	prev->setCursor(Qt::PointingHandCursor);
	prev->setFixedSize(60, 60);

	layout_mediaPlayer->addWidget(mute);
	layout_mediaPlayer->addWidget(prev);
	layout_mediaPlayer->addWidget(activeSongLabel);
	layout_mediaPlayer->addWidget(next);

	connect(mute, SIGNAL(clicked()), this, SLOT(playPause()));
}

MediaPlayer::~MediaPlayer()
{
}

void MediaPlayer::playPause()
{
	if (play == true)
	{
		mute->setStyleSheet("background-image: url(./Photos/soundoff.png);");
		play = false;
	}
	else 
	{
		mute->setStyleSheet("background-image: url(./Photos/soundon.png);");
		play = true;
	}
}
