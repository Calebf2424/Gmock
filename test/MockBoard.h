#include <gmock/gmock.h>
#include <vector>
#include "../include/Board.h"

class MockBoard : public Board {
 public:
    MOCK_METHOD(bool, movePiece, (Colour side, Coordinate* start,
                         Coordinate* destination));
    MOCK_METHOD(void, placePiece, (Piece* p, Coordinate* c));
    MOCK_METHOD(void, emptySpace, (Coordinate* c));
    MOCK_METHOD(Piece*, getPiece, (Coordinate* c));
    MOCK_METHOD(bool, isWinner, (Colour side));
    MOCK_METHOD(void, draw, ());
    MOCK_METHOD(std::vector<std::vector<Piece*>>*, getBoard, ());
};
