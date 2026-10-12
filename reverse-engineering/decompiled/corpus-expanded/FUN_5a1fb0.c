/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a1fb0; label: FUN_005a1fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a1fb0(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_004f9e70(param_1);
  *(undefined1 *)(DAT_00956624 + 4) = uVar1;
  uVar1 = FUN_004f9e70(param_1);
  *(undefined1 *)(DAT_00956624 + 5) = uVar1;
  uVar1 = FUN_004f9e70(param_1);
  *(undefined1 *)(DAT_00956624 + 6) = uVar1;
  uVar1 = FUN_004f9e70(param_1);
  *(undefined1 *)(DAT_00956624 + 7) = uVar1;
  return;
}

