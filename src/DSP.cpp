#include "DSP.h"

void DSP::prepareToPlay(double _sampleRate, int _samplesPerBlock) {
  this->sampleRate = static_cast<float>(_sampleRate);
  this->samplesPerBlock = static_cast<float>(_samplesPerBlock);
}

float DSP::processSample(int channel, float sample) {
  juce::ignoreUnused(channel);

  float gainParam = parameters.getRawParameterValue("GAIN")->load();
  float bypassParam = parameters.getRawParameterValue("BYPASS")->load();
  float gain = gainParam * (1.0f - bypassParam);

  return juce::Random::getSystemRandom().nextFloat() * gain * sample;
}
