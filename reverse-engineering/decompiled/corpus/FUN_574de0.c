/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x574de0; label: FUN_00574de0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00574de0(int param_1,undefined4 param_2)

{
  if (DAT_0093b328 != 0) {
    DAT_00921db4 = DAT_00951378;
    *(undefined4 *)(param_1 + 0x94) = _DAT_0095137c;
  }
  FUN_0050f740(param_1,param_2,DAT_00921d60);
  return;
}

