#include "ChatLogPanel.h"
#include "../LivingLifePage.h"
#include "minorGems/game/doublePair.h"
#include <deque>
#include <format>

void drawChatLogPanel(std::unique_ptr<std::deque<std::string>> &messages, Font *handwritingFont, doublePair &panelPos,
                      double gui_fov_scale)
{
    constexpr std::string titleText = "Chat Log";
    setDrawColor(0.72, 0.18, 0.92, 1.0); // bright purple
    handwritingFont->drawString(titleText.c_str(), panelPos, alignCenter);

    drawChatLog(messages, handwritingFont, panelPos, gui_fov_scale);
}

void drawChatLog(std::unique_ptr<std::deque<std::string>> &messages, Font *handwritingFont, doublePair &titlePos,
                 double gui_fov_scale)
{
    doublePair pos = {titlePos.x, titlePos.y - 32};
    double initialYOffset = pos.y;
    const size_t MAX_MESSAGES = 10;

    if (messages->size() >= MAX_MESSAGES)
    {
        messages->pop_front();
    }

    for (auto &message : *messages)
    {
        setDrawColor(0.0, 0.0, 0.0, 1.0); // black
        handwritingFont->drawString(message.c_str(), {pos.x, initialYOffset}, alignCenter);
        initialYOffset -= (24.0 * gui_fov_scale);
    }
}
