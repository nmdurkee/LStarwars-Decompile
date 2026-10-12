/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x442790; label: FUN_00442790
 */

float10 FUN_00442790(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) && (DAT_0093d810 != 0)) {
    iVar1 = **(int **)(param_3 + 0xd0);
    if ((*(char *)(DAT_0093d810 + 0x671) != -1) &&
       (*(char *)(DAT_0093d810 + 0x671) == *(char *)(iVar1 + 0x671))) {
      fVar2 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),DAT_0093d810 + 0x670)
      ;
      fVar3 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar1 + 0x670);
      return (float10)(float)((float10)(double)fVar2 - fVar3);
    }
  }
  return (float10)0;
}

