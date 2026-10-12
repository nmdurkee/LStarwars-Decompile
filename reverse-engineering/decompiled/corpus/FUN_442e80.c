/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x442e80; label: FUN_00442e80
 */

float10 FUN_00442e80(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  float10 fVar1;
  undefined1 local_c [12];
  
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) && (param_5 != 0)) {
    fVar1 = (float10)FUN_005becc0(param_5 + 0x5c,*(int *)(param_3 + 0xd0) + 0x5c,local_c);
    return fVar1;
  }
  return (float10)(float)0x4e6e6b28;
}

