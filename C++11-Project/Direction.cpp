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

#include "Direction.h"
#include "Utilities.h"

void Direction::set(double deg, double length) {
	double angle = -Utilities::deg_to_rad(deg);  // minus to respect coordinates: 0/0 top ledt to 0/0 bottom-left
    dx_ = std::cos(angle) * length;
    dy_ = std::sin(angle) * length;
}

void Direction::rotate(double deg) {
	double angle = -Utilities::deg_to_rad(deg);  // minus to respect coordinates: 0/0 top ledt to 0/0 bottom-left
	double dx = dx_ * std::cos(angle) - dy_ * std::sin(angle);
	double dy = dx_ * std::sin(angle) + dy_ * std::cos(angle);
    dx_ = dx;
    dy_ = dy;
}

void Direction::setLength(double length) {
	double len = sqrt(dx_ * dx_ + dy_ * dy_);
	if (len > 0.0) {
		double scale = length / len;
	    dx_ *= scale;
	    dy_ *= scale;
	}
}

