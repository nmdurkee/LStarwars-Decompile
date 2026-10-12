/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ef050; label: FUN_005ef050
 */

void FUN_005ef050(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      if (*(int *)(param_1 + 4) != 0) {
        iVar1 = *(int *)(*(int *)(param_1 + 0xc) + iVar4 * 4);
        uVar2 = FUN_005eef80(param_1,(int)*(short *)(iVar1 + 0x74));
        *(undefined2 *)(*(int *)(*(int *)(param_1 + 0xc) + iVar4 * 4) + 0x74) = uVar2;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0xfc));
        *(undefined4 *)(iVar1 + 0xfc) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0xe8));
        *(undefined4 *)(iVar1 + 0xe8) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0x100));
        *(undefined4 *)(iVar1 + 0x100) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0xec));
        *(undefined4 *)(iVar1 + 0xec) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0x104));
        *(undefined4 *)(iVar1 + 0x104) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0x24c));
        *(undefined4 *)(iVar1 + 0x24c) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0x108));
        *(undefined4 *)(iVar1 + 0x108) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0xb8));
        *(undefined4 *)(iVar1 + 0xb8) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0xbc));
        *(undefined4 *)(iVar1 + 0xbc) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0xc0));
        *(undefined4 *)(iVar1 + 0xc0) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0xc4));
        *(undefined4 *)(iVar1 + 0xc4) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0x10c));
        *(undefined4 *)(iVar1 + 0x10c) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0x110));
        *(undefined4 *)(iVar1 + 0x110) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0x298));
        *(undefined4 *)(iVar1 + 0x298) = uVar3;
        uVar3 = FUN_005eef80(param_1,*(undefined4 *)(iVar1 + 0x29c));
        *(undefined4 *)(iVar1 + 0x29c) = uVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x10));
  }
  FUN_00602480(param_1);
  return;
}

