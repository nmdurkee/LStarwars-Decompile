/* Ghidra pseudocode, not original source.
 * ev_57ca11fd66234800334e5f23d40b47e1bf5f9001c22ff37fd2f45222df4b5a02
 * Entry: 0x6033f0; label: FUN_006033f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006033f0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x60)) {
    iVar2 = 0;
    do {
      FUN_005e0f90(*(undefined4 *)(iVar2 + 4 + *(int *)(param_1 + 100)),PTR_PTR_0080e794);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x24;
    } while (iVar1 < *(int *)(param_1 + 0x60));
  }
  return;
}

