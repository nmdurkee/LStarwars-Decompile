/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x590690; label: FUN_00590690
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00590690(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  undefined4 *puVar6;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 *local_110 [5];
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 *local_ec;
  undefined4 local_e4;
  code *local_d4;
  code *local_c4;
  code *local_bc;
  undefined4 local_84;
  undefined1 local_4c;
  undefined4 local_48 [17];
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x10) != 0)) {
    local_11c = DAT_0093b0cc;
    local_118 = DAT_0093b0d0;
    local_114 = DAT_0093b0d4;
    for (puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x10) + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      puVar4 = &DAT_00810210;
      ppuVar5 = local_110;
      for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppuVar5 = (undefined4 *)*puVar4;
        puVar4 = puVar4 + 1;
        ppuVar5 = ppuVar5 + 1;
      }
      puVar4 = (undefined4 *)(puVar1[9] + 0x40);
      puVar6 = local_48;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      local_fc = 0x3e4ccccd;
      local_f8 = 0x3e4ccccd;
      local_f4 = 0xc0800000;
      local_110[0] = local_48;
      local_110[2] = &local_11c;
      local_ec = puVar1 + 1;
      local_e4 = 0x90;
      local_4c = 1;
      local_c4 = FUN_00571c50;
      local_bc = FUN_00571c80;
      local_d4 = FUN_00571ba0;
      local_84 = _DAT_00925018;
      iVar3 = FUN_0064d270(local_110);
      if (iVar3 != 0) {
        iVar2 = FUN_0054fa60();
        *(float *)(iVar3 + 0x100) =
             (float)iVar2 * 1.5259022e-05 + (float)iVar2 * 1.5259022e-05 + 7.0;
      }
    }
  }
  return;
}

