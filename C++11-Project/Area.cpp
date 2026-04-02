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
#include "Area.h"

void Area::clamp(Position &position) const {
	auto x = position.getX();
	auto y = position.getY();
	
	if (x <= 1)           x = 1;
    if (x >= kWidth - 2)  x = kWidth - 2;
	if (y <= 1)           y = 1;
    if (y >= kHeight - 2) y = kHeight - 2;
    
    position = Position(x, y);
}

