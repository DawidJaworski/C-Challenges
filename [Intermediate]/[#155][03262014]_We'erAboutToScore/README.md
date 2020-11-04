# (Intermediate): [We're about to score!](https://www.reddit.com/r/dailyprogrammer/comments/21ejqz/2632014_challenge_155_intermediate_were_about_to/)

## Description

One of the ways that chess games are tracked during play is to assign values to each piece and then look at the pieces that remain on the board for each player. After several moves where pieces have been taken, one can quickly determine who has an advantage.

Pieces are assigned standard valuations:
* pawns are worth one point each.
* Knights and bishops 3 points each
* A Rook is worth 5
* The Queen is worth 9 points.
* The Kings true value is infinite but you shouldn't need to worry about this

More info on chess values can be seen [HERE](https://en.wikipedia.org/wiki/Chess_piece_relative_value)

## Input Description

Each line of input will be given in standard chess algebraic notation:
Here's a picture of the notation to give you an idea : Image
* columns are given a-h and rows are given 1-8 (starting with white's back row). For reference the queens are on d1 (white) and d8 (black).
* Pieces (except for pawns) have a capital letter associated with them:

King = K; Knight = N; Queen = Q; Rook = R; Bishop = B; None = pawns, they are just specified by their file.
* Captures are marked with an "x":

e.g. "Qxe5" for "queen captures the piece on square e5"; pawn captures are given by file, for example "exd5".
* Castling is indicated as such: O-O for kingside, O-O-O Queenside. Check is indicated by a "+" and checkmate is given by "mate" or "#".

For more help on chess notation see ~~HERE~~

## Formal Input Description

Three values per line: move number, then white's move, then black's move using chess algebraic notation.

### Example:

1. e4 e5 <-- White's pawn to e4, Black's pawn moves to e5
1. Nf3 Nc6 <-- White's Knight moves to f3, Black's Knight moves to c6
1. Bb5 Nf6 <-- White's Bishop moves to b5, Black's Knight moves to f6
1. d3 Bc5 <-- White's Pawn moves to d3, Black's Bishop moves to c5

etc...

## Formal Output Description

Your program should emit two values, one for white and one for black, at the end of the series of moves (for an incomplete game).

## Sample Input

This is actually Anand v Carlsen from the Zurich Chess Challenge 2014, round 5 play.
1. e4 e5
1. Nf3 Nc6
1. Bb5 Nf6
1. d3 Bc5
1. Bxc6 dxc6
1. h3 Nd7
1. Be3 Bd6
1. Nbd2 O-O
1. O-O Re8
1. Nc4 Nf8
1. d4 exd4
1. Qxd4 c5
1. Qd3 b6
1. Nxd6 Qxd6
1. Qxd6 cxd6
1. Rfd1 Bb7
1. Rxd6 Bxe4
1. Ne1 Rad8
1. Rad1 Ne6
1. Rxd8 Rxd8
1. Rxd8+ Nxd8
1. f3 Bd5
1. a3 Nc6
1. Kf2 f6
1. Nd3 Kf8
1. Ke2 Ke7
1. Kd2 Kd7
1. Nf4 Bf7
1. b3 Ne7
1. h4 Nd5

## Sample output

12-12

## Challenge Input

This is actually Aronian vs So from the 2014 76th Tata Steel Masters round 6. Aronian would go on to win.
1. c4 Nf6
1. Nf3 g6
1. Nc3 d5
1. cxd5 Nxd5
1. e4 Nxc3
1. bxc3 Bg7
1. Be2 c5
1. O-O Nc6
1. Qa4 Bd7
1. Qa3 Qa5
1. Rd1 O-O
1. Rb1 b6
1. d4 Qxa3
1. Bxa3 Bg4
1. dxc5 Bxc3
1. Ba6 Rab8
1. Rdc1 Bxf3
1. gxf3 Bd2
1. Rd1 Bc3
1. Kg2 bxc5
1. Bxc5 Bb4
1. Be3 Bd6
1. Rbc1 Nb4
1. Bc4 Rfc8
1. f4 Kf8
1. a3 Nc6
1. Ba6 Bxa3