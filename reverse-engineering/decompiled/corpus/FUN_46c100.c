/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46c100; label: FUN_0046c100
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046c100(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  float10 fVar3;
  undefined2 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)(param_1 + 0x30);
  local_8 = *(undefined4 *)(param_1 + 0x34);
  local_4 = *(undefined4 *)(param_1 + 0x38);
  fVar3 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
  uVar1 = (uint)ROUND(fVar3 * (float10)0.25 * (float10)65536.0);
  local_10 = (undefined2)uVar1;
  *(undefined2 *)(param_1 + 0x13a) = local_10;
  FUN_005b4670(param_1,uVar1 & 0xffff);
  FUN_005b4900(param_1,&local_c);
  uVar2 = FUN_0055f450(&local_c);
  FUN_0046a8d0(uVar2);
  FUN_00681f40("Grv_GuardWeaponLp",&local_c);
  return;
}

