/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c7350; label: FUN_006c7350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c7350(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  uVar2 = 0;
  for (iVar1 = *in_ECX; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
  }
  return uVar2;
}

