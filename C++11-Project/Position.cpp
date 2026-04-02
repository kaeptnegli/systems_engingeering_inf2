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
#include <cmath>

#include "Position.h"
#include "Direction.h"

namespace {
constexpr double kEpsilon = 0.01;
}  // namespace

Position::Position(double x, double y) : x_{x}, y_{y} { }

bool Position::operator==(const Position &rhs) const {
	return (std::fabs(x_ - rhs.x_) < kEpsilon) && (std::fabs(y_ - rhs.y_) < kEpsilon);
}

Position& Position::operator+=(const Direction& rhs) {
	x_ += rhs.getX();
	y_ += rhs.getY();
	return *this;
}
	

