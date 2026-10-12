/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f8f10; label: FUN_004f8f10
 */

void FUN_004f8f10(undefined1 *param_1,int param_2,int param_3,int param_4,undefined *param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  int local_48;
  char local_44;
  char local_43 [63];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_48;
  local_48 = param_3;
  if (((param_2 != 0) && (param_3 != 0)) && (param_1 != (undefined1 *)0x0)) {
    FUN_004f1f10(&local_44,&DAT_0075e948);
    FUN_004f1e80(&local_44,&DAT_0075ebb0);
    FUN_004f1e80(&local_44,param_3);
    iVar2 = 0;
    while (local_44 != '\0') {
      local_44 = local_43[iVar2];
      iVar2 = iVar2 + 1;
    }
    uVar6 = FUN_004f1ff0(param_2);
    if ((int)((ulonglong)uVar6 >> 0x20) < (int)uVar6) {
      uVar1 = FUN_004f1ff0(&local_44);
      uVar6 = FUN_004f1ff0(param_2,&local_44,uVar1);
      iVar2 = FUN_004f8b80((int)uVar6 + (param_2 - (int)((ulonglong)uVar6 >> 0x20)));
      if (iVar2 == 0) {
        FUN_004f1f10(param_1,param_2);
        __security_check_cookie(local_4 ^ (uint)&local_48);
        return;
      }
    }
    FUN_004f1f10(param_1,param_2);
    puVar3 = (undefined1 *)FUN_004f1fc0(param_1,0x2e);
    puVar4 = (undefined1 *)FUN_004f1fc0(param_1,0x2f);
    puVar5 = (undefined1 *)FUN_004f1fc0(param_1,0x5c);
    if (puVar4 < puVar5) {
      puVar4 = puVar5;
    }
    if (puVar4 < puVar3) {
      *puVar3 = 0;
      FUN_004f1e80(puVar3,&DAT_0075cff4);
      if (param_5 == (undefined *)0x0) {
        param_5 = &DAT_0075e948;
      }
      FUN_004f1e80(puVar3,param_5);
      FUN_004f1e80(puVar3,&DAT_0075ebb0);
    }
    else {
      FUN_004f1e80(param_1,&DAT_0075cff4);
      if (param_5 == (undefined *)0x0) {
        param_5 = &DAT_0075e948;
      }
      FUN_004f1e80(param_1,param_5);
      FUN_004f1e80(param_1,&DAT_0075ebb0);
      puVar3 = param_1;
    }
    FUN_004f1e80(puVar3,local_48);
    iVar2 = FUN_004f1ff0(param_1);
    if (param_4 + -1 < iVar2) {
      FUN_004ef790();
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_48);
  return;
}

