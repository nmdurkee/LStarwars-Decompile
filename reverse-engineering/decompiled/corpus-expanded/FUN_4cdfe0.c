/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cdfe0; label: FUN_004cdfe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cdfe0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    FUN_0055aa60(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),PTR_DAT_007fd1e4,
                 *(undefined4 *)(param_1 + 0x510),DAT_00880608,0x40);
  }
  return;
}

