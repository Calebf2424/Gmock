#include <gmock/gmock.h>
#include <string>
#include <stdexcept>
#include "../include/ChessUI.h"

class MockChessUI : public ChessUI {
 public:
    MOCK_METHOD(std::string, getLocation,
    (Colour side, const std::string desc));
    MOCK_METHOD(void, invalidMove, (const std::runtime_error& e));
    MOCK_METHOD(void, gameOver, (Colour side));
};
