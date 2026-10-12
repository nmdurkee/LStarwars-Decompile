/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x590c10; label: FUN_00590c10
 */

void FUN_00590c10(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (param_1 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    return;
  }
  if ((param_3 != 0) && (bVar2 = *(byte *)(param_1 + 0x6c), bVar2 != 0)) {
    uVar5 = (uint)*(byte *)(param_1 + 0x6f);
    if (0.5 <= (float)uVar5 / (float)bVar2) {
      if ((float)uVar5 / (float)bVar2 < 0.9) {
        uVar5 = (uint)(bVar2 >> 1);
      }
      goto LAB_00590c71;
    }
  }
  uVar5 = 0;
LAB_00590c71:
  *(ushort *)(param_1 + 0x7a) = *(ushort *)(param_1 + 0x7a) | 2;
  iVar6 = 0;
  if (*(char *)(param_1 + 0x6c) != '\0') {
    do {
      if ((param_2 != 0) && (iVar6 < (int)(uint)*(byte *)(param_1 + 0x6f))) {
        iVar3 = FUN_0054fa60(*(int *)(*(int *)(*(int *)(param_1 + 0x14) + iVar6 * 4) + 0x24) + 0x70)
        ;
        FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),
                     (int)*(short *)(&DAT_00804e38 + (iVar3 / 0x2aab) * 2));
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x6c));
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_005a15e0(*(undefined4 *)(param_1 + 0x10),1);
    uVar4 = uVar5;
    if (uVar5 < *(byte *)(param_1 + 0x6c)) {
      do {
        puVar1 = (uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x14) + uVar4 * 4) + 0x10) + 0x50);
        *puVar1 = *puVar1 & 0xfffffffe;
        iVar6 = *(int *)(*(int *)(param_1 + 0x14) + uVar4 * 4);
        *(undefined4 *)(*(int *)(iVar6 + 0x10) + 0x4c) = *(undefined4 *)(iVar6 + 0x18);
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < (int)(uint)*(byte *)(param_1 + 0x6c));
    }
    *(undefined4 *)(param_1 + 0x48) = 0x3e99999a;
    *(undefined4 *)(param_1 + 0x44) = 0x3e99999a;
  }
  else {
    uVar4 = uVar5;
    if (uVar5 < *(byte *)(param_1 + 0x6c)) {
      do {
        puVar7 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x14) + uVar4 * 4) + 0x24);
        puVar8 = puVar7 + 0x20;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < (int)(uint)*(byte *)(param_1 + 0x6c));
    }
  }
  *(ushort *)(param_1 + 0x7a) = *(ushort *)(param_1 + 0x7a) & 0xfffb;
  *(char *)(param_1 + 0x6f) = (char)uVar5;
  *(undefined1 *)(param_1 + 0x6e) = 0;
  *(undefined1 *)(param_1 + 0x6d) = 0;
  return;
}

