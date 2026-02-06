#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);

    // Add menu bar
    addAndMakeVisible (menuBar);
    menuBar.setModel (this);  // We'll need to implement MenuBarModel

    // Add label with name
    addAndMakeVisible (label);
    label.setText ("Student Name: Johnny Garciga", juce::dontSendNotification);
    label.setFont (juce::FontOptions().withHeight(16.0f).withStyle("Bold"));
    label.setColour (juce::Label::textColourId, juce::Colours::white);

    // Add text editor
    addAndMakeVisible (textEditor);
    textEditor.setText ("Enter your text here...");
    textEditor.setMultiLine (true);
    textEditor.setReturnKeyStartsNewLine (true);

    // Add button
    addAndMakeVisible (button);
    button.setButtonText ("Click Me!");
    button.onClick = [this] { juce::AlertWindow::showMessageBoxAsync (juce::AlertWindow::InfoIcon,
                                                                       "Button Clicked",
                                                                       "You clicked the button!"); };
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    auto area = getLocalBounds();

    menuBar.setBounds (area.removeFromTop (30));

    label.setBounds (area.removeFromTop (50).reduced (10));

    button.setBounds (area.removeFromBottom (50).reduced (10));

    textEditor.setBounds (area.reduced (10));
}

// MenuBarModel methods
juce::StringArray MainComponent::getMenuBarNames()
{
    return { "File", "Edit", "Help" };
}

juce::PopupMenu MainComponent::getMenuForIndex (int menuIndex, const juce::String& menuName)
{
    juce::ignoreUnused (menuIndex);

    juce::PopupMenu menu;

    if (menuName == "File")
    {
        menu.addItem (1, "New");
        menu.addItem (2, "Open");
        menu.addSeparator();
        menu.addItem (3, "Exit");
    }
    else if (menuName == "Edit")
    {
        menu.addItem (4, "Cut");
        menu.addItem (5, "Copy");
        menu.addItem (6, "Paste");
    }
    else if (menuName == "Help")
    {
        menu.addItem (7, "About");
    }

    return menu;
}

void MainComponent::menuItemSelected (int menuItemID, int topLevelMenuIndex)
{
    juce::ignoreUnused (topLevelMenuIndex);
    if (menuItemID == 1) // New
    {
        textEditor.setText ("");
    }
    else if (menuItemID == 3) // Exit
    {
        juce::JUCEApplication::getInstance()->systemRequestedQuit();
    }
    else if (menuItemID == 7) // About
    {
        juce::AlertWindow::showMessageBoxAsync (juce::AlertWindow::InfoIcon,
                                                "About",
                                                "CSE360 Project by John Doe");
    }
}