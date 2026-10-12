/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c7580; label: FUN_006c7580
 */

void FUN_006c7580(void)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int *piVar3;
  
  piVar2 = *(int **)(in_ECX + 0x30);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  while (piVar2 != (int *)0x0) {
    piVar1 = piVar2 + 1;
    if (*piVar2 == 0) {
      piVar3 = (int *)*piVar1;
    }
    else {
      *(int *)(*piVar2 + 4) = *piVar1;
      piVar3 = piVar2;
    }
    if ((int *)*piVar1 != (int *)0x0) {
      *(int *)*piVar1 = *piVar2;
    }
    *piVar1 = 0;
    *piVar2 = 0;
    *piVar1 = *(int *)(in_ECX + 0x30);
    if (*(undefined4 **)(in_ECX + 0x30) != (undefined4 *)0x0) {
      **(undefined4 **)(in_ECX + 0x30) = piVar2;
    }
    *(int **)(in_ECX + 0x30) = piVar2;
    if (*(int *)(in_ECX + 0x2c) == 0) {
      *(int **)(in_ECX + 0x2c) = piVar2;
    }
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 1;
    piVar2 = piVar3;
  }
  FUN_006c23f0();
  return;
}

