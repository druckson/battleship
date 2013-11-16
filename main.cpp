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
        cout << " ";
        for (int i=0; i<width; i++) {
            cout << (char)(i+65);
        }

        // Print a newline to go to the next row
        cout << endl;

        for (int y=0; y<height; y++) {
            // Print the row numbers
            cout << (char)(y+65);

            // Print the row
            for (int x=0; x<width; x++) {
                if (getCell(x, y))
                    cout << "X";
                else
                    cout << "O";
            }

            // Print a newline to go to the next row
            cout << endl;
        }
    }
};

int main(int argc, char **argv) {
    int x;
    Board b = Board(10, 10);
    b.setCell(1, 1, true);
    b.setCell(10, 1, true);
    b.print();
    delete b;
    
    return 0;
}
