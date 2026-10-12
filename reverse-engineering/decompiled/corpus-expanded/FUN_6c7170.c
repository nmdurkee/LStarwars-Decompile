/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c7170; label: FUN_006c7170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_006c7170(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = FUN_00633440(0xd0,1);
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_006c6d60();
    if (piVar2 != (int *)0x0) {
      piVar2[0xb] = 0;
      piVar2[0xc] = *(int *)(in_ECX + 0x9c);
      if (*(int *)(in_ECX + 0x9c) != 0) {
        *(int **)(*(int *)(in_ECX + 0x9c) + 0x2c) = piVar2;
      }
      *(int **)(in_ECX + 0x9c) = piVar2;
      if (*(int *)(in_ECX + 0x98) == 0) {
        *(int **)(in_ECX + 0x98) = piVar2;
      }
      *(int *)(in_ECX + 0xa0) = *(int *)(in_ECX + 0xa0) + 1;
      (**(code **)(*piVar2 + 0x10))("object");
    }
    return piVar2;
  }
  return (int *)0x0;
}

