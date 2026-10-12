/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54ffc0; label: FUN_0054ffc0
 */

void FUN_0054ffc0(undefined4 *param_1,short *param_2,ushort *param_3)

{
  short sVar1;
  short sVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = *param_1;
  local_14 = param_1[1];
  local_10 = param_1[2];
  sVar1 = FUN_005be2d0(local_10,local_18);
  FUN_005b3620(&local_c,&local_18,-(uint)(ushort)-sVar1);
  sVar2 = FUN_005be2d0(local_c,local_8);
  *param_2 = -sVar2;
  *param_3 = -sVar1;
  return;
}

