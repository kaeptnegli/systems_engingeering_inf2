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
#include "StrategyRandomAngle.h"
#include "Random.h"
#include "Timing.h"
#include "Direction.h"
#include "Position.h"
#include "Area.h"
#include "Hoover.h"

StrategyRandomAngle::StrategyRandomAngle(const Area &area, Hoover &hoover)
: name_{"random-angle strategy"}
, area_{area}
, hoover_{hoover}
{
	setDirection();
}

bool StrategyRandomAngle::move() {
	hoover_.move(area_);
	bool atBoundary = area_.atBoundary(hoover_.getPosition());
	hoover_.updateSoc(atBoundary);
	if (atBoundary) setDirection();
	return atBoundary;
}

void StrategyRandomAngle::setDirection() {
	hoover_.setDirection(Direction{Random::getInstance().getAngle(), Timing::getSpeed()});
}

