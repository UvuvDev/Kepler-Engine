#include "Audio.hpp"

AudioController::AudioController() {
	InitAudioDevice();
}


void AudioController::update() {

}

void AudioController::playSound(Sound soundToPlay) {
	PlaySound(soundToPlay);
}

void AudioController::stopAllSound() {

}