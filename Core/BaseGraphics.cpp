#include "BaseGraphics.h"

BaseGraphics::BaseGraphics()
    : m_gl20(nullptr),
      m_gl30(nullptr),
      m_gl_version(nullptr),
      m_deltatime(0),
      m_width(0),
      m_height(0),
      m_back_buffer_width(0),
      m_back_buffer_height(0)
{
}

float BaseGraphics::GetRawDeltaTime()
{
    return this->m_deltatime;
}

float BaseGraphics::GetDensity()
{
    return this->GetPpiX() * 160.0f;
}

float BaseGraphics::GetBackBufferScale()
{
    return this->m_back_buffer_width / this->m_width;
}

