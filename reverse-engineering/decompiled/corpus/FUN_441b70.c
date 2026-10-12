/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441b70; label: FUN_00441b70
 */

float10 FUN_00441b70(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if ((((((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) && (DAT_0093d810 != 0)) &&
       ((iVar1 = **(int **)(param_3 + 0xd0), *(char *)(iVar1 + 0x281) != '\0' ||
        (*(char *)(iVar1 + 0x282) != '\0')))) &&
      ((*(char *)(DAT_0093d810 + 0x281) != '\0' || (*(char *)(DAT_0093d810 + 0x282) != '\0')))) &&
     ((*(short *)(iVar1 + 0x27e) != -1 &&
      (*(short *)(iVar1 + 0x27e) == *(short *)(DAT_0093d810 + 0x27e))))) {
    return (float10)1;
  }
  return (float10)0;
}

