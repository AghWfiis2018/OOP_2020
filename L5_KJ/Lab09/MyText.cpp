#include "MyText.h"

MyText::MyText(const std::string& str, const AttFormat::Attribute& format, const AttColor::Attribute& color)
: AttFormat(format), AttColor(color), m_text(str)
{}

std::string MyText::rawString() const
{    return m_text; }

void MyText::setText(const std::string& str)
{    m_text = str; }

