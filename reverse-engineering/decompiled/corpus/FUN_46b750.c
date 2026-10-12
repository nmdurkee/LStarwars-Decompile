/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46b750; label: FUN_0046b750
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046b750(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 *local_50 [4];
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_2a;
  int local_28;
  code *local_14;
  undefined1 *local_8;
  undefined1 local_3;
  
  if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xcee) == '\0') {
    return;
  }
  local_5c = _DAT_0080525c;
  local_58 = _DAT_00805270 + _DAT_00805260;
  local_54 = 0x3f800000;
  iVar1 = *(int *)(PTR_DAT_00802c54 + 0x120);
  puVar3 = &DAT_00802cd8;
  ppuVar4 = local_50;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar4 = (undefined4 *)*puVar3;
    puVar3 = puVar3 + 1;
    ppuVar4 = ppuVar4 + 1;
  }
  local_50[3] = (undefined4 *)DAT_00950f60;
  local_40 = _DAT_0080526c;
  local_34 = 0x3f800000;
  local_50[1] = (undefined4 *)param_1;
  local_38 = 0x2112d;
  local_2a = 0xce;
  local_28 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xce0;
  local_14 = FUN_0059a420;
  local_8 = &LAB_0059a4c0;
  local_3 = 1;
  local_50[2] = &local_5c;
  FUN_00560b60(local_50);
  _DAT_0087b934 = 0x40000000;
  if ((iVar1 != -1) && ((byte)(&DAT_0086e0f9)[iVar1 * 0xc] < 10)) {
    iVar1 = FUN_004f1ff0(param_2);
    if (iVar1 < 9) {
      FUN_004f1f10(&DAT_00955fd0 + DAT_00951234 * 0xc,param_2);
    }
    else {
      (&DAT_00955fd0)[DAT_00951234 * 0xc] = 0;
    }
    DAT_00951230 = DAT_00951230 + 1;
    bVar5 = DAT_0093b338 != 0;
    iVar1 = DAT_00951234 * 6;
    DAT_00951234 = DAT_00951234 + 1;
    (&DAT_00955fd8)[iVar1] = *(undefined2 *)(PTR_DAT_00802c54 + 0x11c);
    if (bVar5) {
      if (DAT_00951230 == 1) {
        uVar6 = 0x26d;
      }
      else {
        if (DAT_00951230 != 10) goto LAB_0046b8cb;
        uVar6 = 0x26e;
      }
      FUN_00576910(uVar6,0,0);
    }
  }
LAB_0046b8cb:
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x13,param_1);
  uVar6 = FUN_00650dc0("MK-Pickup",param_1,3,0);
  FUN_005478a0(uVar6);
  return;
}

