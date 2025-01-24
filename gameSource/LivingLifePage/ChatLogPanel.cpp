#include "ChatLogPanel.h"
#include "../LivingLifePage.h"
#include "minorGems/game/doublePair.h"
#include "minorGems/util/stringUtils.h"
#include <deque>
#include <format>
#include <string>
#include <vector>

void ChatLogPanel::draw()
{
    if (this->getIsEnabled())
    {
        this->drawBackground();

        doublePair titlePos = {this->getPosition().x, this->getPosition().y - 5 * this->getFovScale()};
        setDrawColor(0.72, 0.18, 0.92, 1.0); // bright purple
        this->getFont()->drawString(this->getTitle().c_str(), titlePos, alignCenter);

        this->drawMessages();
    }
}

void ChatLogPanel::drawMessages()
{
    doublePair pos = {this->getPosition().x - 390 * this->getFovScale(),
                      this->getPosition().y - 32 * this->getFovScale()};
    double initialYOffset = pos.y;

    setDrawColor(0.0, 0.0, 0.0, 1.0); // black
    for (auto &message : *this->messages_)
    {
        this->getFont()->drawString(message.c_str(), {pos.x, initialYOffset}, alignLeft);
        initialYOffset -= (24.0 * this->getFovScale());
    }
}

void ChatLogPanel::drawBackground()
{
    setDrawColor(1, 1, 1, 0.9);
    doublePair pos = {this->getPosition().x, this->getPosition().y - 64 * this->getFovScale()};
    drawSprite(this->getBackgroundSprite(), pos, this->getFovScale() * 2);
}
