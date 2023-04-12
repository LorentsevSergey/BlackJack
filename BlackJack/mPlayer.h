#pragma once
#include <QtMultimedia>

class mPlayer
{
	std::vector<QString> url;
	QMediaPlayer mediaPlayer;
	QAudioOutput audioOutput;

public:
	mPlayer(std::vector<QString> file_url);
	mPlayer(std::vector<QString> file_url, int vol);

	void play();
	void stop();
	void pause();
	void next();
};

