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
#ifndef _RANDOM_H_
#define _RANDOM_H_

#include "CppHelper.h"

class Random {
NO_COPY_NO_MOVE(Random);
public:
	static Random& getInstance() { return inst_; }
	double getAngle() const;
private:
	Random();
	static Random inst_;
};

#endif  // _RANDOM_H_

