/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2a20; label: FUN_005a2a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a2a20(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_005a2210(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 != -1) {
      *(undefined4 *)(DAT_00956620 + 0x46fc + iVar1 * 4) = *(undefined4 *)(DAT_00956620 + 0x46f8);
    }
  }
  return;
}

