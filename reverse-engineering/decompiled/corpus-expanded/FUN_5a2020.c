/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2020; label: FUN_005a2020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a2020(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00956624 + 0xc) = (float)fVar1;
  return;
}

