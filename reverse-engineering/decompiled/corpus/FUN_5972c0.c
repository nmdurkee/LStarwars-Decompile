/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x5972c0; label: FUN_005972c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_005972c0(int param_1,short param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  uVar2 = _DAT_00805148;
  puVar3 = &DAT_00955b70;
  do {
    if ((puVar3[0x10e] & 1) == 0) {
      *(undefined **)(param_1 + 0x10ac) = puVar3;
      *(undefined4 *)(puVar3 + 0x108) = uVar2;
      *(ushort *)(puVar3 + 0x10e) = *(ushort *)(puVar3 + 0x10e) | 1;
      iVar5 = 0;
      *(short *)(puVar3 + 0x10c) = param_2;
      if (param_2 != 0) {
        puVar4 = (undefined4 *)(puVar3 + 0x14);
        do {
          uVar1 = *(ushort *)(param_1 + 0x27a);
          puVar4[-2] = 0x4e6e6b28;
          puVar4[-1] = (uint)uVar1;
          *puVar4 = 0;
          iVar5 = iVar5 + 1;
          puVar4 = puVar4 + 6;
        } while (iVar5 < (int)(uint)*(ushort *)(puVar3 + 0x10c));
      }
      return puVar3;
    }
    puVar3 = puVar3 + 0x110;
  } while ((int)puVar3 < 0x955fb0);
  return (undefined *)0x0;
}

