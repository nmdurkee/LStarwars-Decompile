/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4f9a60; label: FUN_004f9a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f9a60(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)FUN_004f98c0(param_1);
  if ((piVar1 != (int *)0x0) && (*piVar1 == 1)) {
    uVar2 = FUN_006dee20(*(char *)(param_1 + 2) + -0x30,*(char *)(param_1 + 3) + -0x30);
    return uVar2;
  }
  return 0;
}

