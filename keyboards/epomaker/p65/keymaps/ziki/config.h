/* Tap-hold behaviour ported from ~/.config/kmonad/apple.kbd */
#pragma once

#define TAPPING_TERM 200

/* kmonad `tap-hold-next-release` (a / d / k) == QMK permissive hold */
#define PERMISSIVE_HOLD_PER_KEY

/* kmonad `tap-next` (caps -> esc / nav): any other key press = hold,
 * releasing alone = tap no matter how long it was held. */
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define RETRO_TAPPING_PER_KEY
