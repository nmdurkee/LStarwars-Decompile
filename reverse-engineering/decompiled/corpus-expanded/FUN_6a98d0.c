/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a98d0; label: FUN_006a98d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006a98d0(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = *(int *)(param_1 + 0x28);
  iVar2 = FUN_006a3980(param_2,*(undefined4 *)(param_1 + 0x24));
  if (iVar2 < 0) {
    iVar2 = *(int *)(param_1 + 8);
    uVar7 = 0;
  }
  else {
    uVar4 = *(uint *)(*(int *)(param_1 + 0x20) + iVar2 * 4);
    if (-1 < (int)uVar4) {
      FUN_006a3b10(param_2,(int)*(char *)(*(int *)(param_1 + 0x1c) + -1 + uVar4));
      return uVar4 - 1;
    }
    uVar7 = (int)uVar4 >> 0xf & 0x7fff;
    iVar2 = *(int *)(param_1 + 8) - (uVar4 & 0x7fff);
  }
  iVar3 = FUN_006a3980(param_2,iVar6);
  do {
    if (-1 < iVar3) {
LAB_006a9961:
      uVar4 = FUN_006a9870();
      iVar3 = iVar2 - uVar7;
      if (1 < iVar3) {
        do {
          uVar5 = iVar3 >> 1;
          uVar1 = (uint)(uVar4 < *(uint *)(*(int *)(param_1 + 0x14) + (uVar5 + uVar7) * 4));
          iVar2 = iVar2 - (-uVar1 & uVar5);
          uVar7 = uVar7 + (uVar1 - 1 & uVar5);
          iVar3 = iVar2 - uVar7;
        } while (1 < iVar3);
      }
      iVar2 = (int)*(char *)(*(int *)(param_1 + 0x1c) + uVar7);
      if (iVar6 < iVar2) {
        FUN_006a3b10(param_2,iVar6);
        return 0xffffffff;
      }
      FUN_006a3b10(param_2,iVar2);
      return uVar7;
    }
    if (iVar6 < 2) {
      if (iVar3 < 0) {
        return 0xffffffff;
      }
      goto LAB_006a9961;
    }
    iVar6 = iVar6 + -1;
    iVar3 = FUN_006a3980(param_2,iVar6);
  } while( true );
}

