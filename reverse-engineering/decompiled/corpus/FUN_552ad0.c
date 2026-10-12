/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x552ad0; label: FUN_00552ad0
 */

undefined4
FUN_00552ad0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,float param_7,float param_8,float param_9,undefined4 param_10)

{
  undefined4 uVar1;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [64];
  
  if (param_2 == -1) {
    return 1;
  }
  if ((param_1 == 0) && (param_1 = FUN_0055f450(), param_1 == 0)) {
    return 1;
  }
  if ((*(char *)(*(int *)(param_1 + 0x2ac0) + 0xe + param_2 * 0x10) != '\0') &&
     (((param_7 != 0.0 || (param_8 != 0.0)) || (param_9 != 0.0)))) {
    local_4c = param_7;
    local_48 = param_8;
    local_44 = param_9;
    FUN_005b45a0(local_40,&local_4c);
    FUN_00550330(local_40,param_10,param_4,param_5,param_6);
    FUN_005b4900(local_40,param_3);
    uVar1 = FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + param_2 * 0x10,local_40);
    return uVar1;
  }
  return 0;
}

