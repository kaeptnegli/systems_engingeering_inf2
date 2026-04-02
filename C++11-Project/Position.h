/*
 * ------------------------------------------------------------------
 * --    _       _ _______                                         --
 * --   | |     | |__   __|                                        --
 * --   | |_ __ | |  | |      InIT Institut fuer Informatik        --
 * --   | | '_ \| |  | |      Zuercher Hochschule Winterthur       --
 * --   | | | | | |  | |      (University of Applied Sciences)     --
 * --   |_|_| |_|_|  |_|      8401 Winterthur, Switzerland         --
 * ------------------------------------------------------------------
 * -- Project     : INF2 - Labs                                    --
 * -- Autor       : giei                                           --
 * -- Datum       : 2026-02-13                                     --
 * ------------------------------------------------------------------
 */
#ifndef _POSITION_H_
#define _POSITION_H_

class Direction;    // forward declaration - sufficient for use as references

class Position {
public:
	Position(double x, double y);
	bool operator==(const Position &rhs) const;
	Position& operator+=(const Direction& rhs);
	double getX() const { return x_; }
	double getY() const { return y_; }

private:
	double x_{0.0};  // in-class initialization
	double y_{0.0};  // in-class initialization
};

#endif  // _POSITION_H_

