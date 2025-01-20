#include "../LivingLifePage.h"
#include "minorGems/game/doublePair.h"
#include <format>
#include <memory>
#include <string>

extern void drawChatLogPanel(std::unique_ptr<std::deque<std::string>> &, Font *, doublePair &);
void drawChatLog(std::unique_ptr<std::deque<std::string>> &, Font *handwritingFont, doublePair &);
