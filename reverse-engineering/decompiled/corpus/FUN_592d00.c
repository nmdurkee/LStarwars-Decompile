/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x592d00; label: FUN_00592d00
 */

void FUN_00592d00(int param_1,int param_2,int param_3)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined *local_8c;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  iVar2 = (int)*(char *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0x111);
  if (((param_1 != 0) && (iVar2 != -1)) &&
     (*(int *)(*(int *)(param_2 + 0x50) + 0x14 + iVar2 * 4) != 0)) {
    uVar4 = (uint)(*(short *)(param_2 + 0x1064) != *(short *)(param_1 + 0x6c));
    iVar5 = 0;
    local_8c = &DAT_00955634 + uVar4 * 0x120;
    do {
      if ((((0 < *(int *)(param_1 + 0x48 + iVar5 * 4)) && (iVar5 != 2)) &&
          ((iVar5 != 0 ||
           (((puVar1 = (ushort *)(*(int *)(param_1 + 0x174) + uVar4 * 0x38),
             (*(byte *)(*(int *)(param_1 + 0x24) + 0x12 + (uint)*puVar1 * 0x28) & 0x20) == 0 &&
             ((*(byte *)(*(int *)(param_1 + 0x28) + 0x12 + (uint)puVar1[1] * 0x28) & 1) == 0)) &&
            (*(char *)(param_2 + 0x1082) == '\0')))))) &&
         (iVar3 = FUN_005cfac0(local_8c), iVar3 != 0)) {
        if (param_3 == 0) {
          puVar6 = (undefined4 *)(iVar2 * 0x40 + 0x804 + param_2);
        }
        else {
          puVar6 = (undefined4 *)(iVar2 * 0x40 + param_3);
        }
        puVar7 = local_80;
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        FUN_005f33b0(local_8c,local_80);
        if ((*(char *)(param_2 + 0x107c) != '\0') &&
           (iVar3 = FUN_00550490(local_80,*(undefined1 *)(param_2 + 0x107b),
                                 *(undefined4 *)(param_2 + 0x1014),
                                 *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),local_40
                                ), iVar3 != 0)) {
          FUN_005d4690(0);
          FUN_005f33b0(local_8c,local_40);
          FUN_005d46b0();
        }
      }
      local_8c = local_8c + 0x20;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 9);
  }
  return;
}

