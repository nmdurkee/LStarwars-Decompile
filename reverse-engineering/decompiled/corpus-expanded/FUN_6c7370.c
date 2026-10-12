/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c7370; label: FUN_006c7370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c7370(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *in_ECX;
  undefined4 *puVar2;
  
  iVar1 = *in_ECX;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1 < *(int *)(iVar1 + 0x10)) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  puVar2 = (undefined4 *)(param_1 * 0x10 + *(int *)(iVar1 + 0x14));
  *param_2 = *puVar2;
  param_2[1] = puVar2[1];
  param_2[2] = puVar2[2];
  param_2[3] = puVar2[3];
  return 1;
}

