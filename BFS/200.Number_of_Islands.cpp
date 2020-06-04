Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3


class Solution {
public:

	int numIslands(vector<vector<char>>& grid) {
		    
	  int numberOfIslands(0);
	  
	  // iterate elements in grid to find islands
	  for (int i = 0; i < grid.size(); i++)
	  {
		for (int j = 0; j < grid[i].size(); j++)
		{
		    if(grid[i][j]=='1'){
		        
		        // if we find an island, increment numberOfIslands
		        numberOfIslands++;
		        
		        // merge all adjacent elements to the actual island
		        mergeIsland(grid, i, j);
		    }
		}
	  }
	  
	  return numberOfIslands;
	}

	void mergeIsland(vector<vector<char>>& grid, int row, int col) {
		  
		if ( row<0 || row>=grid.size() || col<0 || col>=grid[row].size() || grid[row][col]!='1' )
		return;

		grid[row][col]='X';

		mergeIsland(grid, row-1, col);
		mergeIsland(grid, row+1, col);
		mergeIsland(grid, row, col-1);
		mergeIsland(grid, row, col+1);
	    }
};
