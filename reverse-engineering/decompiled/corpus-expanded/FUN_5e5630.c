/* Ghidra pseudocode, not original source.
 * ev_f73a5b0c0434a7d5d731dd250707e0e9320a0ad37df46b92dceb71be55e84b93
 * Entry: 0x5e5630; label: FUN_005e5630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e5630(int param_1)

{
  int iVar1;
  
  if (0 < param_1) {
    iVar1 = *(int *)(DAT_0097157c + -4 + param_1 * 4);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x18) < 1)) {
      FUN_005f8ed0(iVar1);
      *(undefined4 *)(DAT_0097157c + -4 + param_1 * 4) = 0;
      return;
    }
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -1;
    }
  }
  return;
}

