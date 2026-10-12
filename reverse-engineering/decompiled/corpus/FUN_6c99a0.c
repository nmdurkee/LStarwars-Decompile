/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c99a0; label: FUN_006c99a0
 */

void FUN_006c99a0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  
  piVar1 = *(int **)(in_ECX + 0x24);
  while (piVar1 != (int *)0x0) {
    if ((*(int *)(in_ECX + 0x34) == piVar1[3]) && (*(int *)(in_ECX + 0x38) == piVar1[4])) {
      *(undefined4 *)(in_ECX + 0x30) = 0;
      *(undefined4 *)(in_ECX + 0x34) = 0;
    }
    iVar2 = piVar1[3];
    piVar3 = *(int **)(piVar1[2] + 0x14);
    DAT_02973e91 = 1;
    if (iVar2 != 0) {
      iVar4 = piVar3[1];
      iVar5 = 0;
      if (0 < DAT_02973bbc) {
        do {
          (**(code **)(**(int **)(DAT_02973b98 + iVar5 * 4) + 4))(iVar2,iVar4,0,0);
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_02973bbc);
      }
      (**(code **)(*piVar3 + 0x1c))(iVar2,0);
    }
    DAT_02973e91 = 0;
    if (*piVar1 == 0) {
      *(int *)(in_ECX + 0x28) = piVar1[1];
    }
    else {
      *(int *)(*piVar1 + 4) = piVar1[1];
    }
    if ((int *)piVar1[1] == (int *)0x0) {
      *(int *)(in_ECX + 0x24) = *piVar1;
    }
    else {
      *(int *)piVar1[1] = *piVar1;
    }
    *piVar1 = 0;
    piVar1[1] = 0;
    *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + -1;
    FUN_006334d0(piVar1,0x14);
    piVar1 = *(int **)(in_ECX + 0x24);
  }
  return;
}

