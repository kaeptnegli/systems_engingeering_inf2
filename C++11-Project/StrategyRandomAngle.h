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
#ifndef _STRATEGY_RANDOM_ANGLE_H_
#define _STRATEGY_RANDOM_ANGLE_H_

#include <string>
#include "CppHelper.h"

class Random;  // forward declaration - sufficient for use as references
class Area;    // forward declaration - sufficient for use as references
class Hoover;  // forward declaration - sufficient for use as references

class StrategyRandomAngle {
NO_COPY_NO_MOVE(StrategyRandomAngle);
public:
	StrategyRandomAngle(const Area &area, Hoover &hoover);
	bool move();
	const std::string& name() const { return name_; }
private:
	void setDirection();

	const std::string name_;
	const Area        &area_;
	Hoover            &hoover_;
};

#endif  // _STRATEGY_RANDOM_ANGLE_H_

