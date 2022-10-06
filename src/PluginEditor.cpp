#include "PluginProcessor.h"
#include "PluginEditor.h"

AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor &p)
    : AudioProcessorEditor(&p), processorRef(p) {
  juce::ignoreUnused(processorRef);
  setResizable(true, true);
  setSize(800, 600);

  gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
  gainSlider.setRange(0.0f, 1.0f);
  gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);

  gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
      processorRef.processorState,
      "GAIN",
      gainSlider);

  bypassButtonAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(
      processorRef.processorState,
      "BYPASS",
      bypassButton);

  addAndMakeVisible(gainSlider);
  addAndMakeVisible(bypassButton);

}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() = default;

void AudioPluginAudioProcessorEditor::paint(juce::Graphics &g) {
  g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

  g.setColour(juce::Colours::white);
  g.setFont(15.0f);
  g.drawFittedText("Hello there!", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized() {
  gainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 + 25, 100, 100);
  bypassButton.setBounds(getWidth() / 2 - 25, getHeight() / 2 + 150, 100, 50);
}
