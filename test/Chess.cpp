#ifndef CHESS_TEST_H_INCLUDED
#define CHESS_TEST_H_INCLUDED

#include "../include/Chess.h"
#include "MockBoard.h"
#include "MockChessUI.h"

#include <string>
#include <vector>

#include "gmock/gmock.h"

using ::testing::_;
using ::testing::Action;
using ::testing::Expectation;
using ::testing::Return;
using ::testing::Throw;

TEST(ChessTest, play) {
    MockBoard board;
    MockChessUI UI;
    Chess game(&UI, &board);

    EXPECT_CALL(board, placePiece(_, _)).Times(10);
    EXPECT_CALL(UI, getLocation(_, "of piece to move: "))
    .WillOnce(Return("a1")) // move 1
    .WillOnce(Return("b5")) // move 2
    .WillOnce(Return("a3")) // move 3
    .WillOnce(Return("a5")) // move 4
    .WillOnce(Return("c1")) // move 5
    .WillOnce(Return("b4")) // move 6
    .WillOnce(Return("d1")) // move 7
    .WillOnce(Return("c3")) // move 8
    .WillOnce(Return("b1")) // move 9
    .WillOnce(Return("d2")) // move 10
    .WillOnce(Return("b3")) // move 11
    .WillOnce(Return("c5")); // move 12

    EXPECT_CALL(UI, getLocation(_, " of destination: "))
    .WillOnce(Return("a3")) // move 1
    .WillOnce(Return("b4")) // move 2
    .WillOnce(Return("b4")) // move 3
    .WillOnce(Return("b4")) // move 4
    .WillOnce(Return("c3")) // move 5
    .WillOnce(Return("c3")) // move 6
    .WillOnce(Return("d2")) // move 7
    .WillOnce(Return("d2")) // move 8
    .WillOnce(Return("b3")) // move 9
    .WillOnce(Return("e1")) // move 10
    .WillOnce(Return("b4")) // move 11
    .WillOnce(Return("b4")); // move 12

    EXPECT_CALL(board, movePiece(_, _, _))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true));

    EXPECT_CALL(board, isWinner(_))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(true));

    EXPECT_CALL(UI, gameOver(_)).Times(1);
    EXPECT_CALL(board, draw()).Times(12);
    // Call
    game.playGame();
}

ACTION(NoPieceException) { throw no_piece_error("No piece at that location."); }

TEST(ChessTest, illegalMove) {
    MockBoard board;
    MockChessUI UI;
    Chess game(&UI, &board);

    EXPECT_CALL(board, placePiece(_, _)).Times(10);
    EXPECT_CALL(UI, getLocation(_, "of piece to move: "))
    .WillOnce(Return("a1")) // move 1
    .WillOnce(Return("b5")) // move 2
    .WillOnce(Return("a3")) // move 3
    .WillOnce(Return("a5")) // move 4
    .WillOnce(Return("c1")) // move 5
    .WillOnce(Return("b4")) // move 6
    .WillOnce(Return("d1")) // move 7
    .WillOnce(Return("c3")) // move 8
    .WillOnce(Return("b1")) // move 9
    .WillOnce(Return("d2")) // move 10
    .WillOnce(Return("b3")) // move 11
    .WillOnce(Return("e5")) // move 12
    .WillOnce(Return("c5")); // move 13

    EXPECT_CALL(UI, getLocation(_, " of destination: "))
    .WillOnce(Return("a3")) // move 1
    .WillOnce(Return("b4")) // move 2
    .WillOnce(Return("b4")) // move 3
    .WillOnce(Return("b4")) // move 4
    .WillOnce(Return("c3")) // move 5
    .WillOnce(Return("c3")) // move 6
    .WillOnce(Return("d2")) // move 7
    .WillOnce(Return("d2")) // move 8
    .WillOnce(Return("b3")) // move 9
    .WillOnce(Return("e1")) // move 10
    .WillOnce(Return("b4")) // move 11
    .WillOnce(Return("e6")) // move 12
    .WillOnce(Return("b4")); // move 13

    EXPECT_CALL(board, movePiece(_, _, _))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Return(true))
    .WillOnce(Throw(std::runtime_error("Invalid Move")))
    .WillOnce(Return(true));

    EXPECT_CALL(board, isWinner(_))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(true));

    EXPECT_CALL(UI, invalidMove(_)).Times(1);
    EXPECT_CALL(UI, gameOver(_)).Times(1);
    EXPECT_CALL(board, draw()).Times(13);
    // Call
    game.playGame();
}

#endif
