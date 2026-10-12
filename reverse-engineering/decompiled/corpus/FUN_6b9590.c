/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b9590; label: FUN_006b9590
 */

void FUN_006b9590(undefined4 *param_1)

{
  for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
      param_1 = (undefined4 *)*param_1) {
    if (param_1[3] - 3 < 0x3d) {
      *(byte *)((int)param_1 + 0x11) =
           *(byte *)((int)param_1 + 0x11) ^
           ((DAT_0081fadc & 1 << ((char)param_1[3] - 3U & 0x1f)) != 0 ^
           *(byte *)((int)param_1 + 0x11)) & 1;
    }
  }
  return;
}

