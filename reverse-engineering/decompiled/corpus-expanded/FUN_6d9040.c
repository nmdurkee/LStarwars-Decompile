/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d9040; label: FUN_006d9040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d9040(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = DAT_02975144;
  if (DAT_02975144 != 0) {
    piVar6 = *(int **)(in_ECX + 0x24);
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x20))(piVar6);
      piVar6 = *(int **)(in_ECX + 0x24);
      if (piVar6 != (int *)0x0) {
        (**(code **)(*piVar6 + 8))(piVar6);
        *(undefined4 *)(in_ECX + 0x24) = 0;
      }
    }
    puVar3 = (undefined4 *)(iVar2 + 0x5d10);
    iVar4 = 4;
    do {
      iVar5 = iVar4;
      *puVar3 = 0;
      puVar3 = puVar3 + 0x5f;
      iVar4 = iVar5 + -1;
    } while (iVar4 != 0);
    piVar6 = (int *)(iVar2 + 0x5428);
    iVar5 = iVar5 + 9;
    do {
      piVar1 = (int *)*piVar6;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x20))(piVar1);
        piVar1 = (int *)*piVar6;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *piVar6 = 0;
        }
      }
      piVar6[-1] = 0;
      *(undefined1 *)((int)piVar6 + 0x29) = 0;
      piVar6 = piVar6 + 0x5f;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    piVar6 = *(int **)(in_ECX + 0x20);
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x20))(piVar6);
      (**(code **)(**(int **)(in_ECX + 0x20) + 8))(*(int **)(in_ECX + 0x20));
      *(undefined4 *)(in_ECX + 0x20) = 0;
    }
    piVar6 = *(int **)(in_ECX + 0x30);
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 8))(piVar6);
      *(undefined4 *)(in_ECX + 0x30) = 0;
    }
    iVar2 = DAT_02975144;
    if (DAT_02975144 != 0) {
      *(undefined4 *)(DAT_02975144 + 0x67e4) = 0;
      FUN_006e85b0(iVar2);
    }
  }
  return;
}

