/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441b00; label: FUN_00441b00
 */

float10 FUN_00441b00(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  float fVar1;
  int iVar2;
  
  if (((((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
       (iVar2 = **(int **)(param_3 + 0xd0), iVar2 != 0)) &&
      ((param_5 != -1 && ((*(char *)(iVar2 + 0x281) != '\0' || (*(char *)(iVar2 + 0x282) != '\0'))))
      )) && ((*(short *)(iVar2 + 0x27e) == param_5 &&
             (fVar1 = *(float *)(*(int *)(*(short *)(iVar2 + 0x27e) * 0x6c + 0x40 +
                                         *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
             fVar1 < *(float *)(iVar2 + 0x60) != (fVar1 == *(float *)(iVar2 + 0x60)))))) {
    return (float10)1;
  }
  return (float10)0;
}

