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

#include "StrategyUpDown.h"
#include "Timing.h"
#include "Direction.h"
#include "Area.h"
#include "Hoover.h"

StrategyUpDown::StrategyUpDown(const Area &area, Hoover &hoover)
: name_{"up-down strategy"}
, area_{area}
, hoover_{hoover}
, target_{Area::getWidth() - 1, 1}  // 1st move: right border up to the top
{
	hoover_.setDirection(Direction{90, Timing::getSpeed()});  // up-wards
	area_.clamp(target_);
}

bool StrategyUpDown::move() {
	hoover_.move(area_);
	bool isAtTarget = targetReached();
	hoover_.updateSoc(isAtTarget);
	if (isAtTarget) {
		const auto& position = hoover_.getPosition();
		if (area_.atTop(position.getY())) {
			if (isUp())   setTarget(+90.0, 1);
			else          setTarget(+90.0, Area::getHeight() - 2);
		} else if (area_.atBottom(position.getY())) {
			if (isDown()) setTarget(-90.0, 1);
			else          setTarget(-90.0, Area::getHeight() - 2);
		}
	}
	return isAtTarget;
}

void StrategyUpDown::setTarget(double rotateDeg, double length) {
	Direction rotated{hoover_.getDirection()};
	rotated.rotate(rotateDeg);
	rotated.setLength(length);
	target_ += rotated;
	area_.clamp(target_);
	rotated.setLength(Timing::getSpeed());
	hoover_.setDirection(rotated);
}

bool StrategyUpDown::targetReached() const {
	return hoover_.getPosition() == target_;
}

bool StrategyUpDown::isUp() const {
	const auto& dir = hoover_.getDirection();
	return std::fabs(dir.getX()) < std::fabs(dir.getY()) &&  dir.getY() < 0.0;  // 0/0 top-left
}

bool StrategyUpDown::isDown() const {
	const auto& dir = hoover_.getDirection();
	return std::fabs(dir.getX()) < std::fabs(dir.getY()) &&  dir.getY() > 0.0;  // 0/0 top-left
}

bool StrategyUpDown::isLeft() const {
	const auto& dir = hoover_.getDirection();
	return std::fabs(dir.getX()) > std::fabs(dir.getY()) &&  dir.getX() < 0.0;  // 0/0 top-left
}

bool StrategyUpDown::isRight() const {
	const auto& dir = hoover_.getDirection();
	return std::fabs(dir.getX()) > std::fabs(dir.getY()) &&  dir.getX() > 0.0;  // 0/0 top-left
}

