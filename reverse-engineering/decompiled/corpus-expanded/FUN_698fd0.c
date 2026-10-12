/* Ghidra pseudocode, not original source.
 * ev_4289758b99e4c7501e635d810a16af61d296f1bd933ef263ce76cab568b7549e
 * Entry: 0x698fd0; label: FUN_00698fd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00698fd0(void)

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

