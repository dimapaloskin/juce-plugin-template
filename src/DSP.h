#pragma once

#include "JuceHeader.h"

class DSP {
public:
  JUCE_BEGIN_IGNORE_WARNINGS_GCC_LIKE("-Wshadow-field-in-constructor")

  explicit DSP(juce::AudioProcessorValueTreeState &parameters)
      : parameters(parameters) {}

  JUCE_END_IGNORE_WARNINGS_GCC_LIKE

  ~DSP() = default;

  void prepareToPlay(double sampleRate, int samplesPerBlock);

  float processSample(int channel, float sample);

private:
  juce::AudioProcessorValueTreeState &parameters;

  float sampleRate = 0.0f;
  float samplesPerBlock = 0.0f;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DSP)
};
