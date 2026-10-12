/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x443340; label: FUN_00443340
 */

float10 FUN_00443340(void)

{
  int iVar1;
  short *psVar2;
  int in_stack_00000014;
  
  if (in_stack_00000014 == 0) {
    return (float10)0;
  }
  iVar1 = 0;
  if (0 < DAT_0093d500) {
    psVar2 = (short *)(DAT_0093d504 + 0x1064);
    do {
      if (*psVar2 == in_stack_00000014) {
        return (float10)1;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0x86c;
    } while (iVar1 < DAT_0093d500);
  }
  return (float10)0;
}

