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
#ifndef _DIRECTION_H_
#define _DIRECTION_H_

#include "CppHelper.h"

//This is a Value-Type!

class Direction {
public:
	Direction() = default;
	Direction(double deg, double length) { set(deg, length); }
	
	void set(double deg, double length);
	void rotate(double deg);
	void setLength(double length);
	double getX() const { return dx_; }
	double getY() const { return dy_; }
private:
	double dx_{0.0};  // in-class initialization
	double dy_{0.0};  // in-class initialization
};

#endif  // _DIRECTION_H_

