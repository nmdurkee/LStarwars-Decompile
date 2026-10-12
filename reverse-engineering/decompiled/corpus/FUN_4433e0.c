/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x4433e0; label: FUN_004433e0
 */

float10 FUN_004433e0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if ((((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
      (iVar1 = *(int *)(**(int **)(param_3 + 0xd0) + 0x10a8), iVar1 != 0)) &&
     ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

