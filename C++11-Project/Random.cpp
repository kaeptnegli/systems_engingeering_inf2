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

#include <cstdlib>   // std::srand, std::rand
#include <ctime>     // std::time

#include "Random.h"
#include "Utilities.h"

Random Random::inst_{};

Random::Random() {
	std::srand(std::time(nullptr));
}

double Random::getAngle() const {
    return Utilities::rad_to_deg(static_cast<double>(std::rand()) / RAND_MAX * 2.0 * Utilities::kPi);
}

