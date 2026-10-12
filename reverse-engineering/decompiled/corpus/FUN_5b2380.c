/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b2380; label: FUN_005b2380
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b2380(undefined4 param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = FUN_004fc860(param_1);
  if (iVar1 == 0) {
    FUN_005b2350(param_1);
    return;
  }
  uVar2 = *param_2 + 3 & 0xfffffffc;
  *param_2 = uVar2;
  DAT_0095e430 = 0;
  _DAT_0095e438 = uVar2;
  iVar3 = FUN_004fc5b0(iVar1);
  while (iVar3 != 0) {
    FUN_004f7fb0(iVar1);
    iVar3 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"movie");
    if (((iVar3 == 0) && (iVar3 = FUN_004f7fb0(iVar1), iVar3 != 0)) &&
       (iVar3 = FUN_004f1ff0(*(undefined4 *)(iVar1 + 0x510)), iVar3 < 0x20)) {
      FUN_004f1f10(uVar2,*(undefined4 *)(iVar1 + 0x510));
      uVar2 = uVar2 + 0x20;
      DAT_0095e430 = DAT_0095e430 + 1;
    }
    iVar3 = FUN_004fc5b0(iVar1);
  }
  FUN_004fa300(iVar1);
  if (DAT_0095e430 < 1) {
    _DAT_0095e438 = 0;
    FUN_005b2350(param_1);
    return;
  }
  *param_2 = uVar2;
  return;
}

