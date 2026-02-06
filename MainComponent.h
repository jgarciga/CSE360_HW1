#pragma once

#include <juce_gui_extra/juce_gui_extra.h>

//==============================================================================
class MainComponent final : public juce::Component, public juce::MenuBarModel
{
public:
    //==============================================================================
    MainComponent();

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    // MenuBarModel methods
    juce::StringArray getMenuBarNames() override;
    juce::PopupMenu getMenuForIndex (int menuIndex, const juce::String& menuName) override;
    void menuItemSelected (int menuItemID, int topLevelMenuIndex) override;

private:
    //==============================================================================
    juce::TextButton button;
    juce::Label label;
    juce::TextEditor textEditor;
    juce::MenuBarComponent menuBar;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};