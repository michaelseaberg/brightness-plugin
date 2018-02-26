/*
  ==============================================================================

    BoostKnobLookAndFeel.cpp
    Created: 25 Feb 2018 9:21:46pm
    Author:  Michael Seaberg

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"


class BoostKnobLookAndFeel : public LookAndFeel_V4
{
public:
    Image myBackgroundImage;
    BoostKnobLookAndFeel()
    {
        setColour (Slider::thumbColourId, Colours::red);
        File f = File("/Users/michaelseaberg/Documents/development/plugins/brightness-plugin/Air\ Booster/resources/boostknob.png");
        myBackgroundImage = ImageFileFormat::loadFrom(f);
    }
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        const float radius = jmin (width / 2, height / 2) - 4.0f;
        const float centreX = x + width * 0.5f;
        const float centreY = y + height * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        const float rw = radius * 2.0f;
        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        // fill
        g.drawImageAt(myBackgroundImage, x-57.5,y-57.5);
        //g.setColour (Colours::orange);
        //g.fillEllipse (rx, ry, rw, rw);
        
        // outline
        //g.setColour (Colours::red);
        //g.drawEllipse (rx, ry, rw, rw, 1.0f);
        
        Path p;
        const float pointerLength = radius * 0.11f;
        const float pointerThickness = 2.0f;
        p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY));
        
        // pointer
        g.setColour (Colours::white);
        g.fillPath (p);
    }
};

