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
#include "Hoover.h"
#include "Utilities.h"
#include "Area.h"
#include "Position.h"

Hoover::Hoover(const Area &area)
: position_{static_cast<double>(area.getWidth() - 1), static_cast<double>(area.getChargerY() + 1)}
, direction_{}
{
	area.clamp(position_);
}

void Hoover::move(const Area &area) {
	position_ += direction_;
	area.clamp(position_);
}

void Hoover::setDirection(const Direction& direction) {
	direction_ = direction;
}

void Hoover::updateSoc(bool turns) {
	soc_ -= turns ? kCostPerTurn : kCostPerStep;
	if (soc_ < 0.0) soc_ = 0.0;
}

