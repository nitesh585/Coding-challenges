/*
On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

 

Example 1:

Input: [[".",".",".",".",".",".",".","."],
  	  [".",".",".","p",".",".",".","."],
	  [".",".",".","R",".",".",".","p"],
	  [".",".",".",".",".",".",".","."],
	  [".",".",".",".",".",".",".","."],
	  [".",".",".","p",".",".",".","."],
	  [".",".",".",".",".",".",".","."],
	  [".",".",".",".",".",".",".","."]]
Output: 3
Explanation: 
In this example the rook is able to capture all the pawns.

*/

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int cnt=0;
        
        int i=0, j=0;
        bool found=false;
        //find position of rook
        for(; i<board.size() ; i++){
            j=0;
            for(; j<board[0].size() ; j++){
                if(board[i][j]=='R'){
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        
        //Right
        for(int a=i+1; a<board.size();a++){

            if(board[a][j]=='p'){
                cnt++;
                break;
            }
            if(board[a][j]=='B') break;    
        }
        
        
        //Left
        for(int a=i-1; a>=0;a--){
            if(board[a][j]=='p'){
                cnt++;
                break;
            }
            if(board[a][j]=='B') break;    
        }
        
        // Down
        for(int a=j+1; a<board[0].size();a++){
            if(board[i][a]=='p'){
                cnt++;
                break;
            }
            if(board[i][a]=='B') break;    
        }
        
        // Top
        for(int a=j-1; a>=0;a--){
            if(board[i][a]=='p'){
                cnt++;
                break;
            }
            if(board[i][a]=='B') break;    
        }
        
        return cnt;
    }
};
