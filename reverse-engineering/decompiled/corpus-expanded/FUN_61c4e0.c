/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61c4e0; label: FUN_0061c4e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061c4e0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 8) == 0xf) {
    iVar1 = 0;
    piVar2 = (int *)(param_1 + 0x50);
    while (*piVar2 != 0) {
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
      if (7 < iVar1) {
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x50 + iVar1 * 4) = param_2;
  }
  return;
}

