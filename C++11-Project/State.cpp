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
#include "State.h"
#include "Utilities.h"
#include "Timing.h"
#include "Position.h"
#include "Hoover.h"


namespace {
constexpr char kDust   = '*';
constexpr char kClean  = ' ';
constexpr char kHoover = 'O';
}  // namespace

State::State() {
	clearState();
	setBoundary();
}

int State::calcPoints(const Timing &timing) const {
	return (10000 / timing.getSpeed()) * (cleaned_ / timing.elapsedSeconds());
}
int State::calcBonus() const {
	return (cleaned_ >= kCleanEnough) ? 50000 : 0;
}
int State::calcPenalty(const Hoover &hoover) const {
	return (hoover.getSoc() <= hoover.getBatteryLowLimit()) ? 30000 : 0;
}

bool State::isStopCondition(const Hoover &hoover) const {
	return (hoover.getSoc() <= hoover.getBatteryLowLimit()) || (cleaned_ >= kCleanEnough);
}

void State::clearTraces() {
	for (auto& row : positions_) {
		for (auto& cell : row) {
			if (cell == kHoover) cell = kClean;
		}
	}
}

void State::evaluateState() {
	size_t count = 0;
	for (const auto& row : positions_) {
		for (const auto& cell : row) {
			if (cell != kDust) ++count;
		}
	}
	cleaned_ = 100.0 * count / Area::getHeight() / Area::getWidth(); // [%]
}

void State::addTrace(const Position &position) {
	if (position.getX() >= 0.0 && position.getY() >= 0.0) {
		auto row = static_cast<size_t>(position.getY());
		auto col = static_cast<size_t>(position.getX());
		positions_[row][col] = kHoover;
	}
}

void State::update(bool atBoundary) {
	if (atBoundary) {
		turns_++;
		clearTraces();
    } else {
    	steps_++;
	}
}

void State::clearState() {
	for (auto& row : positions_) row.fill(kDust);
}

void State::setBoundary() {
	size_t w = positions_[0].size();
	size_t h = positions_.size();
	// top & bottom borders
	for (size_t x = 1; x + 1 < w; ++x) {
	    positions_    [0][x] = '-';
	    positions_[h - 1][x] = '-';
	}
	// left & right borders
	for (size_t y = 1; y + 1 < h; ++y) {
	    positions_[y][0]     = '|';
        positions_[y][w - 1] = y == Area::getChargerY() ? 'X' : '|';
	}
	// corners
	positions_    [0][0]     = '+';
	positions_    [0][w - 1] = '+';
	positions_[h - 1][0]     = '+';
	positions_[h - 1][w - 1] = '+';
}


