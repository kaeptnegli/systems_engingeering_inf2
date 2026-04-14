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
#ifndef _STRATEGY_UP_DOWN_H_
#define _STRATEGY_UP_DOWN_H_

#include "Position.h"
#include "CppHelper.h"

#include <string>

class Area;    // forward declaration - sufficient for use as references
class Hoover;  // forward declaration - sufficient for use as references

class StrategyUpDown {
NO_COPY_NO_MOVE(StrategyUpDown);
public:
	StrategyUpDown(const Area &area, Hoover &hoover);
	bool move();
	const std::string& name() const { return name_; }
private:
	void setTarget(double rotateDeg, double length);
	bool targetReached() const;
	bool isUp() const;
	bool isDown() const;
	bool isLeft() const;
	bool isRight() const;

	const std::string name_;
	const Area        &area_;
	Hoover            &hoover_;
	Position          target_;
};

#endif  // _STRATEGY_UP_DOWN_H_

