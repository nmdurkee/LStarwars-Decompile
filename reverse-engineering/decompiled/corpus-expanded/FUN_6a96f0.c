/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a96f0; label: FUN_006a96f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a96f0(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *param_1;
  iVar3 = FUN_006a8f60(param_1,param_2,1);
  iVar7 = 0;
  if (3 < iVar2) {
    iVar4 = iVar3 * iVar2 * 4;
    iVar6 = (iVar2 - 4U >> 2) + 1;
    iVar7 = iVar6 * 4;
    puVar5 = (undefined4 *)(param_2 + 8);
    do {
      puVar1 = (undefined4 *)(iVar4 + param_1[4]);
      iVar4 = iVar4 + 0x10;
      puVar5[-2] = *puVar1;
      iVar6 = iVar6 + -1;
      puVar5[-1] = *(undefined4 *)(param_1[4] + -0xc + iVar4);
      *puVar5 = *(undefined4 *)(param_1[4] + -8 + iVar4);
      puVar5[1] = *(undefined4 *)(param_1[4] + -4 + iVar4);
      puVar5 = puVar5 + 4;
    } while (iVar6 != 0);
  }
  if (iVar7 < iVar2) {
    iVar3 = (iVar3 * iVar2 + iVar7) * 4;
    do {
      iVar7 = iVar7 + 1;
      *(undefined4 *)(param_2 + -4 + iVar7 * 4) = *(undefined4 *)(iVar3 + param_1[4]);
      iVar3 = iVar3 + 4;
    } while (iVar7 < iVar2);
  }
  return;
}

