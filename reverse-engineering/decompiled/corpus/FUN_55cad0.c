/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55cad0; label: FUN_0055cad0
 */

void FUN_0055cad0(int param_1)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined8 uVar5;
  
  if (param_1 != 0) {
    iVar3 = 0;
    if (0 < DAT_0093d500) {
      puVar4 = (uint *)(DAT_0093d504 + 0x2a8);
      do {
        uVar2 = *(uint *)(param_1 + 0x1ec);
        puVar4[-0x2e] = puVar4[-0x2e] & ~*(uint *)(param_1 + 0x1e8);
        puVar4[-0x2d] = puVar4[-0x2d] & ~uVar2;
        uVar5 = __allshl();
        *puVar4 = *puVar4 & ~(uint)uVar5;
        puVar4[1] = puVar4[1] & ~(uint)((ulonglong)uVar5 >> 0x20);
        uVar5 = __allshl();
        puVar4[0x302] = puVar4[0x302] & ~(uint)uVar5;
        puVar4[0x303] = puVar4[0x303] & ~(uint)((ulonglong)uVar5 >> 0x20);
        uVar5 = __allshl();
        puVar4[0x304] = puVar4[0x304] & ~(uint)uVar5;
        puVar4[0x305] = puVar4[0x305] & ~(uint)((ulonglong)uVar5 >> 0x20);
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 0x436;
      } while (iVar3 < DAT_0093d500);
    }
    if (*(int *)(param_1 + 0xca4) != 0) {
      puVar1 = (ushort *)(*(int *)(param_1 + 0xca4) + 0x5a);
      *puVar1 = *puVar1 & 0xfffe;
    }
    FUN_00597350(param_1);
    FUN_0062a910(*(undefined4 *)(PTR_DAT_00802c54 + 0x298c),param_1);
    FUN_0055c980();
    if (DAT_0087a7f0 == param_1) {
      DAT_0087a7f0 = 0;
    }
    if (DAT_0087a7f4 == param_1) {
      DAT_0087a7f4 = 0;
    }
    if (DAT_0087a7f8 == param_1) {
      DAT_0087a7f8 = 0;
    }
    if (DAT_0087a7fc == param_1) {
      DAT_0087a7fc = 0;
    }
    if (DAT_0087a800 == param_1) {
      DAT_0087a800 = 0;
    }
    if (DAT_0087a804 == param_1) {
      DAT_0087a804 = 0;
    }
    if (DAT_0087a808 == param_1) {
      DAT_0087a808 = 0;
    }
    if (DAT_0087a80c == param_1) {
      DAT_0087a80c = 0;
    }
  }
  return;
}

