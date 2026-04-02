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

#include "Timing.h"
#include <thread>

Timing::Timing()
: start_{clock::now()}
, nextFrame_{start_}
{
}

void Timing::waitForNextFrame()
{
    using namespace std::chrono;
    nextFrame_ += milliseconds(static_cast<int>(1000.0 / kFramesPerSecond));
    std::this_thread::sleep_until(nextFrame_);
}

double Timing::elapsedSeconds() const
{
    using namespace std::chrono;
	// duration<double>(...) returns seconds as double value
    return duration<double>(clock::now() - start_).count();
}
