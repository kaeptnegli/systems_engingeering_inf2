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
#include "Random.h"
#include "Timing.h"
#include "Area.h"
#include "Hoover.h"
#include "State.h"
#include "CanvasTerminal.h"
#include "StrategyRandomAngle.h"
#include "StrategyUpDown.h"
#include "Input.h"

int main(void) {
	Timing         timing{};                                                      // time keeping
	Area           area{};                                                        // where to hoover
	Hoover         hoover{area};                                                  // hoover roboter
	State          state{};                                                       // book keeping
	CanvasTerminal canvas{area, timing, state};                                   // visualizing progress

	StrategyRandomAngle strategy{area, hoover};                                   // moving strategy
//	StrategyUpDown strategy{area, hoover};                                        // moving strategy

        Input input{};	
	state.addTrace(hoover.getPosition());                                         // before first move
	bool isStop = false;                                                          // manage stopping
    while (!isStop) {
                input.evalRequest();
    	        bool turns = strategy.move();                                             // strategy specific moving
		state.update(turns);                                                      // update book keeping
		isStop = state.isStopCondition(hoover) || input == 'q';                                   // evaluate stop condition
		if (isStop) state.clearTraces();                                          // update final state
		state.addTrace(hoover.getPosition());                                     // mark hoover position
                canvas.render(timing.elapsedSeconds(), hoover, strategy.name(), isStop);  // update GUI
		timing.waitForNextFrame();                                                // wait for next frame
    }
    //canvas.end();                                                                 // enable cursor
    return 0;
}
// Woche 6 ~Input() und ~CanvasTerminal() werden hier implizit aufgerufen.
