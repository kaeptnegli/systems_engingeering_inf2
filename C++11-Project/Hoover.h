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
#ifndef _HOOVER_H_
#define _HOOVER_H_

#include "Position.h"
#include "Direction.h"
#include "CppHelper.h"

class Area;  // forward declaration - sufficient for use as reference

class Hoover {
NO_COPY_NO_MOVE(Hoover);
public:
	explicit Hoover(const Area &area);
	void move(const Area &area);
	void setDirection(const Direction& direction);
	void updateSoc(bool turns);
	
	const Position&  getPosition()  const { return position_;  }
	const Direction& getDirection() const { return direction_; }
	double           getSoc()       const { return soc_;       }
	
	static constexpr double getCostPerStep()     { return kCostPerStep;     }
	static constexpr double getCostPerTurn()     { return kCostPerTurn;     }
	static constexpr double getBatteryLowLimit() { return kBatteryLowLimit; }
	
private:
	Position    position_;
	Direction   direction_;
	double      soc_{1.0};  // in-class initialization: battery state-of- charge, 100%

	static constexpr double kCostPerStep     = 0.0001;  // 0.01%
	static constexpr double kCostPerTurn     = 0.005;   // 0.50%
	static constexpr double kBatteryLowLimit = 0.01;    // 1.00%
};

#endif  // _HOOVER_H_

