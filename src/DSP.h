#pragma once

#include "JuceHeader.h"

class DSP {
public:
  explicit DSP(juce::AudioProcessorValueTreeState &parameters)
      : parameters(parameters) {}

  ~DSP() = default;

  void prepareToPlay(double sampleRate, int samplesPerBlock);

  float processSample(int channel, float sample);

private:
  juce::AudioProcessorValueTreeState &parameters;

  float sampleRate = 0.0f;
  float samplesPerBlock = 0.0f;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DSP)
};
