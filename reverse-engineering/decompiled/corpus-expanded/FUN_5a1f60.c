/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a1f60; label: FUN_005a1f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a1f60(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_004f9e70(param_1);
  *DAT_00956624 = uVar1;
  uVar1 = FUN_004f9e70(param_1);
  DAT_00956624[1] = uVar1;
  uVar1 = FUN_004f9e70(param_1);
  DAT_00956624[2] = uVar1;
  uVar1 = FUN_004f9e70(param_1);
  DAT_00956624[3] = uVar1;
  return;
}

