/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54fec0; label: FUN_0054fec0
 */

void FUN_0054fec0(int param_1,ushort *param_2,short *param_3)

{
  short sVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_0092b0c4 = FUN_005be2d0(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 4));
  if (param_2 != (ushort *)0x0) {
    *param_2 = DAT_0092b0c4;
  }
  FUN_005b35a0(&local_c,param_1,-(uint)DAT_0092b0c4);
  sVar1 = FUN_005be2d0(local_c,local_8);
  if (param_3 != (short *)0x0) {
    *param_3 = -sVar1;
  }
  DAT_0092b0c0 = -sVar1;
  return;
}

