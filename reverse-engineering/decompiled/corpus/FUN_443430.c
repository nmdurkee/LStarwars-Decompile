/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x443430; label: FUN_00443430
 */

float10 FUN_00443430(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if ((param_5 != 0) && (*(int *)(param_2 + 0xa4) != 0)) {
    iVar1 = *(int *)(param_2 + 0xa4) - *(int *)(param_1 + 0x28);
    iVar2 = 0;
    if (0 < *(char *)(param_5 + 0x10)) {
      do {
        if ((char)(((char)(iVar1 / 0x3c) + (char)(iVar1 >> 0x1f)) -
                  (char)((longlong)iVar1 * 0x88888889 >> 0x3f)) ==
            *(char *)(*(int *)(param_5 + 0x14) + iVar2)) {
          return (float10)1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(char *)(param_5 + 0x10));
    }
  }
  return (float10)0;
}

