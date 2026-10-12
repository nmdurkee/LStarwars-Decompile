/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6b0910; label: FUN_006b0910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006b0910(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar1 = *(int *)(param_1 + 0x68);
  iVar2 = *(int *)(iVar1 + 0x78);
  iVar6 = 7;
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    piVar4 = (int *)(*(int *)(*(int *)(iVar2 + 0x40) + 0x68) + 0x50);
    iVar3 = *(int *)(iVar2 + 0x68);
    if ((piVar4 != (int *)0x0) && (*piVar4 != 0)) {
      iVar6 = *(int *)(iVar1 + 0x7c);
    }
    uVar5 = FUN_006a3e10(*(undefined4 *)(iVar3 + 0xc + iVar6 * 4));
    *param_2 = uVar5;
    uVar5 = FUN_006a3db0(*(undefined4 *)(iVar3 + 0xc + iVar6 * 4));
    param_2[1] = uVar5;
    param_2[2] = 0;
    param_2[3] = *(undefined4 *)(iVar2 + 0x2c);
    param_2[4] = *(undefined4 *)(iVar2 + 0x30);
    param_2[5] = *(undefined4 *)(iVar2 + 0x34);
    param_2[6] = *(undefined4 *)(iVar2 + 0x38);
    param_2[7] = *(undefined4 *)(iVar2 + 0x3c);
  }
  *(undefined4 *)(iVar1 + 0x78) = 0;
  return 1;
}

