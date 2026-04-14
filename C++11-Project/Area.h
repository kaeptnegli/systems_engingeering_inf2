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
#ifndef _AREA_H_
#define _AREA_H_

#include <cstddef>

#include "Position.h"
#include "CppHelper.h"

class Area {
NO_COPY_NO_MOVE(Area);
public:
	bool atLeft  (double x) const { return x <= 1; }            // is it inside one unit around the area
	bool atRight (double x) const { return x >= kWidth - 2; }   // is it inside one unit around the area
	bool atTop   (double y) const { return y <= 1; }            // is it inside one unit around the area
	bool atBottom(double y) const { return y >= kHeight - 2; }  // is it inside one unit around the area
	bool atBoundary(const Position &position) const {           // is it inside one unit around the area
		return atLeft(position.getX()) || atRight(position.getX())
	         || atTop(position.getY()) || atBottom(position.getY());
	}
	void clamp(Position &position) const;  // makes sure the position is within the in area
	
	static constexpr size_t getHeight()   { return kHeight; }
	static constexpr size_t getWidth()    { return kWidth; }
	static constexpr size_t getChargerY() { return kChargerY; }
private:
	static constexpr size_t kWidth{25};
	static constexpr size_t kHeight{10};             // note: do not go below this value (non-sense if smaler)
	static constexpr size_t kChargerY{kHeight - 2};  // the position of the battery charger on the right boundary (start point)
};

#endif  // _AREA_H_

