/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62c6d0; label: FUN_0062c6d0
 */

undefined4 FUN_0062c6d0(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined1 local_40 [64];
  
  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 4))) &&
      (*(int *)(param_2 * 0x14 + *(int *)(param_1 + 8)) != -1)) && (0 < param_4)) {
    FUN_005b45f0(local_40,0x4000);
    FUN_005b5700(local_40,local_40,param_5);
    FUN_00656dc0(*(undefined4 *)(*(int *)(param_1 + 8) + param_2 * 0x14),param_3,&DAT_0095e5c8,
                 param_4,local_40,&DAT_00806680);
    return 1;
  }
  return 0;
}

