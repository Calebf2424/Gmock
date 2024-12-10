#ifndef COORDINATE_H
#define COORDINATE_H

#include <string>
#include <iostream>
#include "Exceptions.h"

class Coordinate {
 public:
    Coordinate() : x{0}, y{0} {}
    Coordinate(unsigned int x,  unsigned int y) : x{x}, y{y} {}
    /**
    * Create a coordinate using chess notation.
    * @param s A board coordinate in chess notation.
    * @throw invalid_location_error If the coordinate is invalid.
    */
    Coordinate(std::string s);

    virtual ~Coordinate() {}

    unsigned int getX() {
        return x;
    }
    unsigned int getY() {
        return y;
    }

    bool operator==(const Coordinate& c) const {
          return x == c.x && y == c.y;
    }

    bool operator!=(const Coordinate& c) const {
          return x != c.x || y != c.y;
    }

    friend std::ostream& operator<<(std::ostream &output,
        const Coordinate& c ) {
        output << "[" << c.x << "," << c.y << "]";
        return output;
    }

 protected:
    unsigned int x;
    unsigned int y;
};
#endif // COORDINATE_H
