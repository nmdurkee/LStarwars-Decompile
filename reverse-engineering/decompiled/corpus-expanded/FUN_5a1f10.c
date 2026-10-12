/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a1f10; label: FUN_005a1f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a1f10(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 < 0x10) {
      FUN_004f1f10(DAT_00956624 + 0x14,*(undefined4 *)(param_1 + 0x510));
    }
  }
  return;
}

