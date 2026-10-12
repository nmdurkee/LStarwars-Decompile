/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55b830; label: FUN_0055b830
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055b830(int param_1,undefined4 param_2,undefined4 param_3,float param_4,undefined4 param_5
                 ,int param_6,undefined4 param_7,undefined4 param_8,int param_9,undefined4 *param_10
                 )

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_0055f450();
  if (DAT_00951bb8 == 0) {
    return;
  }
  if (iVar1 == 0) {
    return;
  }
  if (DAT_0093b28c == 0) {
    local_c = *(undefined4 *)(*(int *)(iVar1 + 0x2ac0) + param_6 * 0x10);
    iVar2 = *(int *)(iVar1 + 0x2ac0) + param_6 * 0x10;
    local_8 = *(undefined4 *)(iVar2 + 4);
    local_4 = *(undefined4 *)(iVar2 + 8);
  }
  else {
    FUN_005cf5b0(DAT_00924880,&local_c,*(undefined4 *)(DAT_00951bb8 + 4 + param_6 * 8),1);
  }
  iVar2 = FUN_005cfac0(&local_c);
  if (iVar2 != 0) {
    FUN_00552c10(param_2,param_3,param_4 + 1.0,param_5,param_5,param_5,0,0,0,&local_c,0,param_8);
  }
  if (param_9 == 0) {
    _DAT_00802924 = 0xffffffff;
    DAT_0093b28c = 0;
    return;
  }
  if ((param_10 != (undefined4 *)0x0) && (iVar2 = FUN_005cfac0(param_10), iVar2 != 0))
  goto LAB_0055ba7c;
  iVar2 = DAT_00803b94;
  if (param_1 != -1) {
    iVar2 = (int)*(short *)(param_1 * 0x4c + 0x42 + DAT_0093b274);
    if (iVar2 == -1) {
      _DAT_00802924 = 0xffffffff;
      DAT_0093b28c = 0;
      return;
    }
    if ((*(char *)(param_1 * 0x120 + 0x116 + DAT_0093b284) == '\0') && (iVar2 != DAT_00803b98)) {
      iVar2 = iVar2 + 1;
    }
  }
  if (iVar2 == -1) {
    _DAT_00802924 = 0xffffffff;
    DAT_0093b28c = 0;
    return;
  }
  if (DAT_0093b28c == 0) {
    local_c = *(undefined4 *)(*(int *)(iVar1 + 0x2ac0) + iVar2 * 0x10);
    iVar1 = *(int *)(iVar1 + 0x2ac0) + iVar2 * 0x10;
    local_8 = *(undefined4 *)(iVar1 + 4);
    local_4 = *(undefined4 *)(iVar1 + 8);
  }
  else {
    if (param_1 != -1) {
      uVar3 = FUN_0055b6c0(param_1);
      iVar2 = (int)((ulonglong)uVar3 >> 0x20);
      if ((int)uVar3 != 0) {
        FUN_005cf5b0((int)uVar3,&local_c,*(undefined4 *)(DAT_00951bb8 + 4 + iVar2 * 8),1);
        goto LAB_0055ba31;
      }
    }
    FUN_005cf5b0(DAT_00924880,&local_c,*(undefined4 *)(DAT_00951bb8 + 4 + iVar2 * 8),1);
  }
LAB_0055ba31:
  iVar1 = FUN_005cfac0(&local_c);
  if (iVar1 == 0) {
    _DAT_00802924 = 0xffffffff;
    DAT_0093b28c = 0;
    return;
  }
  param_10 = &local_c;
LAB_0055ba7c:
  FUN_00552c10(param_2,param_3,param_4 + 1.0,param_5,param_5,param_5,0,0,0,param_10,0,param_7);
  DAT_0093b28c = 0;
  _DAT_00802924 = 0xffffffff;
  return;
}

