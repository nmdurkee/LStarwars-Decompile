/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5eedf0; label: FUN_005eedf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005eedf0(int param_1)

{
  uint *puVar1;
  short *psVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + iVar6 * 4);
      uVar4 = FUN_005eed30(param_1,(int)*(short *)(iVar3 + 0x74));
      *(undefined2 *)(*(int *)(*(int *)(param_1 + 0xc) + iVar6 * 4) + 0x74) = uVar4;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0xfc));
      *(undefined4 *)(iVar3 + 0xfc) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0xe8));
      *(undefined4 *)(iVar3 + 0xe8) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0x100));
      *(undefined4 *)(iVar3 + 0x100) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0xec));
      *(undefined4 *)(iVar3 + 0xec) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0x104));
      *(undefined4 *)(iVar3 + 0x104) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0x24c));
      *(undefined4 *)(iVar3 + 0x24c) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0x108));
      *(undefined4 *)(iVar3 + 0x108) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0xb8));
      *(undefined4 *)(iVar3 + 0xb8) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0xbc));
      *(undefined4 *)(iVar3 + 0xbc) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0xc0));
      *(undefined4 *)(iVar3 + 0xc0) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0xc4));
      *(undefined4 *)(iVar3 + 0xc4) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0x10c));
      *(undefined4 *)(iVar3 + 0x10c) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0x110));
      *(undefined4 *)(iVar3 + 0x110) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0x298));
      *(undefined4 *)(iVar3 + 0x298) = uVar5;
      uVar5 = FUN_005eed30(param_1,*(undefined4 *)(iVar3 + 0x29c));
      *(undefined4 *)(iVar3 + 0x29c) = uVar5;
      puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 0xc) + iVar6 * 4) + 0x44);
      *puVar1 = *puVar1 & 0xffbfffff;
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + iVar6 * 4);
      FUN_00601030(iVar3);
      psVar2 = (short *)(iVar3 + 0x2c0);
      *psVar2 = *psVar2 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x10));
  }
  FUN_006023b0(param_1);
  return;
}

