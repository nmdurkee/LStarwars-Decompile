/* Ghidra analysis pseudocode, not original source.
 * ev_32b79db0f23450a9ff94a1f71da0489d6fe83df38c9fcaa5c40c5fee2e58dea2
 * Entry: 0x698b80; label: FUN_00698b80
 */

void FUN_00698b80(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  FUN_00697eb0();
  piVar3 = (int *)(in_ECX + 0xc);
  iVar2 = 0x40;
  do {
    piVar1 = (int *)*piVar3;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 0xd;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (0 < DAT_02972bfc) {
    iVar4 = 0;
    iVar2 = 0;
    do {
      piVar3 = *(int **)(*(int *)(in_ECX + 0xd0c) + iVar4);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(*(undefined4 *)(*(int *)(in_ECX + 0xd0c) + iVar4));
        *(undefined4 *)(iVar4 + *(int *)(in_ECX + 0xd0c)) = 0;
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x40c;
    } while (iVar2 < DAT_02972bfc);
  }
  if (DAT_02972c34 != (int *)0x0) {
    (**(code **)(*DAT_02972c34 + 8))(DAT_02972c34);
    DAT_02972c34 = (int *)0x0;
  }
  piVar3 = *(int **)(in_ECX + 0xd80);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(in_ECX + 0xd80) = 0;
  }
  piVar3 = *(int **)(in_ECX + 0xd18);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(in_ECX + 0xd18) = 0;
  }
  return;
}

