#include "Attributes.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
AttFormat::AttFormat(const AttFormat::Attribute& format) : m_currentFormat(format)
{}

AttFormat::Attribute AttFormat::getFormat() const
{   return m_currentFormat; }

void AttFormat::setFormat(const AttFormat::Attribute& format)
{   m_currentFormat = format; }


////////////////////////////////////////////////////////////////////////////////////////////////////
AttColor::AttColor(const AttColor::Attribute& color) : m_currentColor(color)
{}

AttColor::Attribute AttColor::getColor() const
{   return m_currentColor; }


void AttColor::setColor(const AttColor::Attribute& color)
{   m_currentColor = color; }
