#pragma once

#include "Attributes.h"
#include "MyPrintable.h"


class MyText : public AttFormat, public AttColor, public MyPrintable
{
public:
    MyText(const std::string&, const AttFormat::Attribute&, const AttColor::Attribute&);      // sets color in AttFormat base class,
                                                                                              // format of text in AttFormat
    ~MyText() = default;
    
    std::string rawString() const;                                              // return unchangable m_text string
    void setText(const std::string&);                                           // sets m_text
    
private:
    std::string m_text;                                                         // text holder
};