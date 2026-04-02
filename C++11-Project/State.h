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
#ifndef _STATE_H_
#define _STATE_H_

#include <array>
#include "Area.h"   // height, width

class Timing;    // forward declaration - sufficient for use as reference
class Position;  // forward declaration - sufficient for use as reference
class Hoover;    // forward declaration - sufficient for use as reference

class State {
public:
	using ColT    = std::array<char, Area::getWidth()>;
	using MatrixT = std::array<ColT, Area::getHeight()>;

	State();
	size_t getSteps()   const { return steps_;   }
	size_t getTurns()   const { return turns_;   }
	double getCleaned() const { return cleaned_; }

	const ColT& getRow(size_t row) const { return positions_[row]; }
	
	int calcPoints(const Timing &timing) const;
	int calcBonus() const;
	int calcPenalty(const Hoover &hoover) const;
	bool isStopCondition(const Hoover &hoover) const;
	void clearTraces();
	void evaluateState();
	void addTrace(const Position &position);
	void update(bool atBoundary);

	static constexpr double getCleanEnough() { return kCleanEnough; }

private:

	void clearState();
	void setBoundary();
	
	size_t  steps_{0};
	size_t  turns_{0};
	double  cleaned_{0.0};  // [%]
	MatrixT positions_;  // position_[row][col]
	
	static constexpr double kCleanEnough = 99.9;  // [%]
};

#endif  // _STATE_H_

