/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x54fec0; label: FUN_0054fec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

