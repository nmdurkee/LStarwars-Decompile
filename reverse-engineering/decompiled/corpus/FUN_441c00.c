/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441c00; label: FUN_00441c00
 */

float10 FUN_00441c00(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
     (iVar1 = **(int **)(param_3 + 0xd0), iVar1 != 0)) {
    FUN_005b3800(&local_c,iVar1 + 0x80,PTR_DAT_008021b4 + 0x11c);
    if (*(float *)(PTR_DAT_008021b4 + 0x118) * local_4 +
        *(float *)(PTR_DAT_008021b4 + 0x110) * local_c +
        *(float *)(PTR_DAT_008021b4 + 0x114) * local_8 < 0.0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

