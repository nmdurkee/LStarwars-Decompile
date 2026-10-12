/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6ba790; label: FUN_006ba790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ba790(undefined4 param_1)

{
  if (DAT_02973a60 != 0) {
    if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
      FUN_006009c0();
    }
    DAT_02973a60 = 0;
  }
  FUN_006ba6a0(0);
  DAT_02973a68 = param_1;
  return;
}

