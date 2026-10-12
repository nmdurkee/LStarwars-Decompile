/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e2170; label: FUN_006e2170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e2170(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(in_ECX + 0x6b0);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(in_ECX + 0x6b0) = 0;
  }
  piVar3 = *(int **)(in_ECX + 0x6ec);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(in_ECX + 0x6ec) = 0;
  }
  piVar3 = *(int **)(in_ECX + 0x690);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(in_ECX + 0x690) = 0;
  }
  piVar3 = *(int **)(in_ECX + 0x694);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(in_ECX + 0x694) = 0;
  }
  piVar3 = *(int **)(in_ECX + 0x698);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(in_ECX + 0x698) = 0;
  }
  piVar3 = *(int **)(in_ECX + 0x688);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(in_ECX + 0x688) = 0;
  }
  piVar3 = (int *)(in_ECX + 0x6c4);
  iVar2 = 4;
  do {
    piVar1 = (int *)*piVar3;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *piVar3 = 0;
    }
    FUN_005f7b40(piVar3[-4]);
    piVar3[-4] = 0;
    piVar3[0xb] = 0;
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

