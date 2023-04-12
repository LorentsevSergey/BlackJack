#pragma once
#include "mPlayer.h"
#include "Global.h"

mPlayer::mPlayer(std::vector<QString> file_url) :
    url( file_url )
{
    mediaPlayer.setAudioOutput(&audioOutput);
    for(QString s : url)
        mediaPlayer.setSource(QUrl::fromLocalFile(s));
    audioOutput.setVolume(SOUND_VOLUME);
}

mPlayer::mPlayer(std::vector<QString> file_url, int vol) : mPlayer(file_url)
{
    audioOutput.setVolume(vol);
}

void mPlayer::play()
{
    mediaPlayer.play();
}

void mPlayer::stop()
{
    mediaPlayer.stop();
}

void mPlayer::pause()
{
    mediaPlayer.pause();
}

void mPlayer::next()
{
    int track = mediaPlayer.activeAudioTrack() + 1;
    if (track == mediaPlayer.audioTracks().size())
        track = 0;
    mediaPlayer.setActiveAudioTrack(track);
    //mediaPlayer.play();
}
