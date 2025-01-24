#include "../LivingLifePage.h"
#include "minorGems/game/doublePair.h"
#include <format>
#include <memory>
#include <string>

class ChatLogPanel
{
    // defaults to "CHAT LOG"
    std::string title_;
    Font *font_;
    doublePair position_;
    std::shared_ptr<std::deque<std::string>> messages_;
    double fovScale_;
    bool isEnabled_;
    unsigned char toggleKey_;
    SpriteHandle backgroundSprite_;

  public:
    std::string getTitle()
    {
        return this->title_;
    }
    void setTitle(std::string title)
    {
        this->title_ = title;
    }
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
    bool getIsEnabled()
    {
        return this->isEnabled_;
    }
    void setIsEnabled(bool isEnabled)
    {
        this->isEnabled_ = isEnabled;
    }
    unsigned char getToggleKey()
    {
        return this->toggleKey_;
    }
    SpriteHandle getBackgroundSprite()
    {
        return this->backgroundSprite_;
    }
    void setBackgroundSprite(SpriteHandle backgroundSprite)
    {
        this->backgroundSprite_ = backgroundSprite;
    }

    ChatLogPanel(auto messages, auto toggleKey)
    {
        this->title_ = "CHAT LOG";
        this->messages_ = messages;
        this->toggleKey_ = toggleKey;
        this->isEnabled_ = false;
    }

    void draw();

  private:
    void drawMessages();
    void drawBackground();
};
