/* *****************************************************************************
 * A.L.E (Arcade Learning Environment)
 * Copyright (c) 2009-2013 by Yavar Naddaf, Joel Veness, Marc G. Bellemare and 
 *   the Reinforcement Learning and Artificial Intelligence Laboratory
 * Released under the GNU General Public License; see License.txt for details. 
 *
 * Based on: Stella  --  "An Atari 2600 VCS Emulator"
 * Copyright (c) 1995-2007 by Bradford W. Mott and the Stella team
 *
 * *****************************************************************************
 *
 * RomSettings.cpp
 *
 * The interface to describe games as RL environments. It provides terminal and
 *  reward information.
 * *****************************************************************************
 */
#include "RomSettings.hpp"

bool RomSettings::isLegal(const Action& a) const {
  return true;
}

bool RomSettings::isLegalB(const Action& a) const {
  return isLegal(((int)a) - PLAYER_A_MAX);
}


ActionVect RomSettings::getMinimalActionSet() {
  ActionVect actions;
  for (int a = 0; a < PLAYER_A_MAX; a++) {
    if (isMinimal((Action)a) && isLegal((Action)a)) {
      actions.push_back((Action)a);
    }
  }
  return actions;
}

ActionVect RomSettings::getMinimalActionSetB() {
  return ActionVect();
}

ActionVect RomSettings::getAllActions() {
  ActionVect actions;
  for (int a = 0; a < PLAYER_A_MAX; a++) {
    if (isLegal((Action)a)) {
      actions.push_back((Action)a);
    }
  }
  return actions;
}

ActionVect RomSettings::getAllActionsB() {
  return ActionVect();
}

ActionVect RomSettings::getStartingActions() {
  return ActionVect();
}
