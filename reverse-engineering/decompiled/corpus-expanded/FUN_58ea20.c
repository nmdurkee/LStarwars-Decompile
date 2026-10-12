/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x58ea20; label: FUN_0058ea20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0058ea20(void)

{
  int iVar1;
  float10 extraout_ST0;
  undefined1 local_c [12];
  
  FUN_005b3b30(local_c);
  FUN_005b39e0(local_c,&DAT_00802500);
  iVar1 = FUN_006e6b90();
  return (float10)(float)((float10)1 -
                         (float10)(float)(((float10)1 -
                                          (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff]) *
                                         extraout_ST0));
}

