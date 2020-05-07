#pragma once

class AttFormat
{
public:
    enum Attribute                                          // enum let's user pick options of formatted text
    {
        BOLD,
        DIM,
        UNDERLINED,
        NORMAL
    };
    
    AttFormat(const AttFormat::Attribute&);                 // constructor sets m_currentFormat 
                                                            // variable with given Attribute
    virtual ~AttFormat() = default;                         // no allocated memory - default constructor is ok
    
    AttFormat::Attribute getFormat() const;                 // function returns m_currentFormat that can't be changed
    virtual void setFormat(const AttFormat::Attribute&);    // sets m_currentFormat
    
protected:
    AttFormat::Attribute m_currentFormat;
};


class AttColor
{
public:
    enum Attribute                                          // enum let's user pick options of color
    {
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        GRAY,
        WHITE
    };
    
    AttColor(const AttColor::Attribute&);                   // constructor sets m_currentColor 
                                                            // variable with given Attribute
    virtual ~AttColor() = default;                          // no allocated memory - default constructor is ok
    
    AttColor::Attribute getColor() const;                   // function returns m_currentColor that can't be changed
    virtual void setColor(const AttColor::Attribute&);      // sets m_currentColor
    
protected:
    AttColor::Attribute m_currentColor;
};