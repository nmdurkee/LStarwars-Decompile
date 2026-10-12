/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x574de0; label: FUN_00574de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

