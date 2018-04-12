#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

class MediaPlayer : public QWidget
{
	Q_OBJECT

public slots:
	void playPause();

private:
	QHBoxLayout * layout_mediaPlayer;
	QPushButton *next;
	QPushButton *prev;
	QPushButton *mute;
	QLabel *activeSongLabel;
	bool play;

public:
	MediaPlayer(QWidget* parent);
	~MediaPlayer();
	
	QPushButton* getNextButton() { return next; }
	QPushButton* getPrevButton() { return prev; }
	QPushButton * getMuteButton() { return mute; }
	QLabel* getActiveSongLabel() { return activeSongLabel; }
};
