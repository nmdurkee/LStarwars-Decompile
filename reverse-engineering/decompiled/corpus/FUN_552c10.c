/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x552c10; label: FUN_00552c10
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00552c10(float param_1,float param_2,undefined4 param_3,float param_4,float param_5,
            float param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,int param_10,
            undefined4 param_11,float param_12)

{
  int iVar1;
  undefined4 uVar2;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [48];
  float local_10;
  float local_c;
  undefined4 local_8;
  
  if ((((0.0 < param_12) && (param_10 != 0)) && (iVar1 = FUN_005cfac0(param_10), iVar1 != 0)) &&
     (((param_4 != 0.0 || (param_5 != 0.0)) || (param_6 != 0.0)))) {
    local_4c = param_4;
    local_48 = param_5;
    local_44 = param_6;
    FUN_005b45a0(local_40,&local_4c);
    FUN_00550330(local_40,param_11,param_7,param_8,param_9);
    local_10 = _DAT_0087b938 * param_1;
    local_c = _DAT_0087b998 * param_2;
    local_8 = param_3;
    uVar2 = FUN_005d6170();
    FUN_005c0500(local_40,local_40,uVar2);
    FUN_005ff7a0(param_10,local_40,param_12);
    return 0;
  }
  return 0;
}

