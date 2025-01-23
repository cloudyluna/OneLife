#include "ChatLogPanel.h"
#include "../LivingLifePage.h"
#include "minorGems/game/doublePair.h"
#include <deque>
#include <format>

void ChatLogPanel::draw()
{
    constexpr std::string titleText = "Chat Log";
    setDrawColor(0.72, 0.18, 0.92, 1.0); // bright purple
    this->getFont()->drawString(titleText.c_str(), this->getPosition(), alignCenter);

    this->drawMessages();
}

void ChatLogPanel::drawMessages()
{
    doublePair pos = {this->getPosition().x, this->getPosition().y - 32};
    double initialYOffset = pos.y;
    const size_t MAX_MESSAGES = 10;

    if (this->messages_->size() >= MAX_MESSAGES)
    {
        this->messages_->pop_front();
    }

    for (auto &message : *this->messages_)
    {
        setDrawColor(0.0, 0.0, 0.0, 1.0); // black
        this->getFont()->drawString(message.c_str(), {pos.x, initialYOffset}, alignCenter);
        initialYOffset -= (24.0 * this->getFovScale());
    }
}
