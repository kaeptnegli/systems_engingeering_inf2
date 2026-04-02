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
#ifndef _TIMING_H_
#define _TIMING_H_

#include <chrono>

class Timing {
public:
    Timing();

    void waitForNextFrame();
    double elapsedSeconds() const;

    static constexpr double getSpeed() { return kSpeed; }

private:
    using clock = std::chrono::steady_clock;
    using time_point = clock::time_point;

    time_point start_;
    time_point nextFrame_;

    static constexpr double kSpeed{0.5};
    static constexpr double kFramesPerSecond{30.0};
};

#endif  // _TIMING_H_
