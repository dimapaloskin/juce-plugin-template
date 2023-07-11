#pragma once

#include "JuceHeader.h"

class PluginParameters {
public:
  static juce::AudioProcessorValueTreeState::ParameterLayout createParameters() {
    juce::AudioProcessorValueTreeState::ParameterLayout params;

    params.add(std::make_unique<juce::AudioParameterFloat>(
        "GAIN",
        "Gain",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.001f, 0.5f),
        0.5f));

    params.add(std::make_unique<juce::AudioParameterBool>(
        "BYPASS",
        "Bypass",
        false));

    return params;
  }
};
