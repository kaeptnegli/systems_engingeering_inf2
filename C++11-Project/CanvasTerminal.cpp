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

#include <iostream>
#include <iomanip>   // << setw, setprecision, etc.

#include "CanvasTerminal.h"
#include "Timing.h"
#include "Area.h"
#include "State.h"
#include "Hoover.h"
#include "Utilities.h"

CanvasTerminal::CanvasTerminal(const Area &area, const Timing &timing, State &state)
: area_{area}
, timing_{timing}
, state_{state}
{
	clear();
}

void CanvasTerminal::render(double elapsed, const Hoover &hoover, const std::string& strategyName, bool isStop) {
    std::cout << "\033[H";  // move cursor to top-left
	state_.evaluateState();
    for (size_t y = 0; y < Area::getHeight(); ++y) {
        renderAreaRow(y);
		// additional text
		renderState(y, elapsed, hoover, strategyName, isStop);
        // terminate line
		std::cout << "\n";
    }
    flush();
}

CanvasTerminal::~CanvasTerminal() {
	std::cout << "\033[?25h";  // show cursor
        DEBUG_TRACE(true) << "executing ~CanvasTerminal()\n";
}

void CanvasTerminal::flush() {
	std::cout.flush();
}
	
void CanvasTerminal::renderAreaRow(size_t y) {
	const auto& row = state_.getRow(y);
	std::cout.write(row.data(), row.size());
}

void CanvasTerminal::renderState(size_t y, double elapsed, const Hoover &hoover, const std::string& strategyName, bool isStop) {
	// additional text
    if (y == Area::getChargerY()) std::cout << "-Charger";
    if (y == 0) std::cout << " \033[1;4mHoovering Dust\033[0m (" << strategyName << ")";
	if (y == 1) std::cout << " time    = "
	                      << std::setw(7) << std::fixed << std::setprecision(2) << elapsed
						  << "s";
    if (y == 2) std::cout << " cleaned = "
	                      << std::setw(7) << std::fixed << std::setprecision(2) << state_.getCleaned()
						  << "%";
    if (y == 3) std::cout << " rate    = "
	                      << std::setw(7) << std::fixed << std::setprecision(2) << (state_.getCleaned() / elapsed)
	                      << "%";
    if (y == 4) std::cout << " battery = "
	                      << std::setw(7) << std::fixed << std::setprecision(2) << (100.0 * hoover.getSoc())
	                      << "%";
    if (y == 5) std::cout << " "
	                      << std::setw(5) << state_.getSteps()
						  << " steps (cost=" << std::setw(4) << (100.0 * hoover.getCostPerStep())
						  << "%)";
    if (y == 6) std::cout << " "
	                      << std::setw(5) << state_.getTurns()
						  << " turns (cost=" << std::setw(4) << (100.0 * hoover.getCostPerTurn())
						  << "%)";
	if (y == 7 && isStop) {
		int points  = state_.calcPoints(timing_);
		int bonus   = state_.calcBonus();
		int penalty = state_.calcPenalty(hoover);
		std::cout << " \033[1mSCORE: " << (points + bonus - penalty)
		          << " (points = " << points
		          << " bonus = " << bonus << " penalty = " << penalty << ")\033[0m";
	}
}

void CanvasTerminal::clear() {
	std::cout << "\033[2J";    // clear screen
    std::cout << "\033[?25l";  // hide cursor    
}

