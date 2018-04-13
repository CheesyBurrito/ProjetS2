#include "MediaPlayer.h"


MediaPlayer::MediaPlayer(QWidget* parent) : QWidget(parent)
{
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
	mute->setFixedSize(55, 55);

	next = new QPushButton(this);
	next->setFlat(true);
	next->setStyleSheet("background-image: url(./Photos/next.png);");
	next->setCursor(Qt::PointingHandCursor);
	next->setFixedSize(55, 55);

	activeSongLabel = new QLabel(this);
	activeSongLabel->setFont(QFont("Walkway Bold", 16));
	activeSongLabel->setStyleSheet("background: transparent; color : white;");
	activeSongLabel->setAlignment(Qt::AlignCenter);
	activeSongLabel->setFixedWidth(400);

	prev = new QPushButton(this);
	prev->setFlat(true);
	prev->setStyleSheet("background-image: url(./Photos/prev.png);");
	prev->setCursor(Qt::PointingHandCursor);
	prev->setFixedSize(55, 55);

	layout_mediaPlayer->addWidget(mute);
	layout_mediaPlayer->addWidget(prev);
	layout_mediaPlayer->addWidget(activeSongLabel);
	layout_mediaPlayer->addWidget(next);
}

MediaPlayer::~MediaPlayer()
{
}

