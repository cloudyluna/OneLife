#include "../LivingLifePage.h"
#include "minorGems/game/doublePair.h"
#include <format>
#include <memory>
#include <string>

class ChatLogPanel
{
    Font *font_;
    doublePair position_;
    std::shared_ptr<std::deque<std::string>> messages_;
    double fovScale_;

  public:
    Font *getFont()
    {
        return this->font_;
    }
    void setFont(Font *font)
    {
        this->font_ = font;
    }
    doublePair getPosition()
    {
        return this->position_;
    }
    void setPosition(doublePair position)
    {
        this->position_ = position;
    }
    double getFovScale()
    {
        return this->fovScale_;
    }
    void setFovScale(double fovScale)
    {
        this->fovScale_ = fovScale;
    }

    ChatLogPanel(auto m)
    {
        messages_ = m;
    }

    void draw();

  private:
    void drawMessages();
};
