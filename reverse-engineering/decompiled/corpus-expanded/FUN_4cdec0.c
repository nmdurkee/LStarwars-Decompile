/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cdec0; label: FUN_004cdec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cdec0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    FUN_005cf5b0(*(undefined4 *)(DAT_00880610 + 0x13c),DAT_00880608 + 0x50,
                 *(undefined4 *)(param_1 + 0x510),1);
  }
  return;
}

