#include <iostream>
using namespace std;


class Board {
    int width, height;
    bool *cells;
public:
    Board(int width, int height) {
        this->width = width;
        this->height = height;
        cells = new bool[width*height];
    }

    ~Board() {
        delete[] cells;        
    }

    bool getCell(int x, int y) {
        return cells[y*width + x];
    }

    void setCell(int x, int y, bool value) {
        cells[y*width + x] = value;
    }

    void print() {
        // Print the column numbers
        cout << "  ";
        for (int i=0; i<width; i++) {
            cout << i << ' ';
        }

        // Print a newline to go to the next row
        cout << endl;

        for (int y=0; y<height; y++) {
            // Print the row numbers
            cout << (char)(y+65) << ' ';

            // Print the row
            for (int x=0; x<width; x++) {
                if (getCell(x, y))
                    cout << "X ";
                else
                    cout << "O ";
            }

            // Print a newline to go to the next row
            cout << endl;
        }
    }
    void userFill(int shipSize) {
		string startCoord;
		string direction;

		// prompting
		cout << "Starting Coordinate (i.e. A1, F7): ";
		cin >> startCoord;
		cout << "Direction to Fill (i.e. UP, DOWN): ";
		cin >> direction;
		
		// convert startCoord to integers: row, col
		int row = startCoord[1] - 48;
        int col = toupper(startCoord[0]) - 65;
		
		cout << "Starting Coord: " << startCoord << endl;
		
		// flag; direction validity
		bool fillCheck = false;
		
		// fill logic;  #FIXME add all directions
		while(fillCheck == false)
			if(direction == "UP") {
				for(int i = 0; i < shipSize; i++) {
					if(getCell(row, col - i)) {
						fillCheck = false;
					}
					else
						fillCheck = true;   // #FIXME prompt new direction
				}

				for(int j = 0; j < shipSize; j++) {
					setCell(row, col - j, true);
					fillCheck = true;
				}
			}

		// display changes
		print();
    }	
};

int main(int argc, char **argv) {
    int x;
    Board b = Board(8, 8);
    b.setCell(0, 0, true);
    b.setCell(1, 1, true);
	b.setCell(2, 2, true);
	b.setCell(7, 0, true);
	b.setCell(7, 7, true);
    b.print();
	
	// arbitrary shipSize
	b.userFill(3);
    
    return 0;
}
