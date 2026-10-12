/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a97a0; label: FUN_006a97a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a97a0(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *param_1;
  iVar4 = 0;
  if (3 < iVar1) {
    iVar5 = (iVar1 - 4U >> 2) + 1;
    iVar4 = iVar5 * 4;
    iVar2 = iVar1 * param_2 * 4;
    puVar3 = (undefined4 *)(param_3 + 8);
    do {
      puVar3[-2] = *(undefined4 *)(iVar2 + param_1[4]);
      iVar5 = iVar5 + -1;
      puVar3[-1] = *(undefined4 *)(iVar2 + 4 + param_1[4]);
      *puVar3 = *(undefined4 *)(iVar2 + 8 + param_1[4]);
      puVar3[1] = *(undefined4 *)(iVar2 + 0xc + param_1[4]);
      iVar2 = iVar2 + 0x10;
      puVar3 = puVar3 + 4;
    } while (iVar5 != 0);
  }
  if (iVar4 < iVar1) {
    iVar2 = (iVar1 * param_2 + iVar4) * 4;
    do {
      iVar4 = iVar4 + 1;
      *(undefined4 *)(param_3 + -4 + iVar4 * 4) = *(undefined4 *)(iVar2 + param_1[4]);
      iVar2 = iVar2 + 4;
    } while (iVar4 < iVar1);
  }
  if ((-1 < param_2) && (param_2 < *(int *)(param_1[3] + 4))) {
    FUN_006a3570(param_4,*(undefined4 *)(param_1[5] + param_2 * 4),
                 *(undefined4 *)(*(int *)(param_1[3] + 8) + param_2 * 4));
    return *(undefined4 *)(*(int *)(param_1[3] + 8) + param_2 * 4);
  }
  return 0;
}

