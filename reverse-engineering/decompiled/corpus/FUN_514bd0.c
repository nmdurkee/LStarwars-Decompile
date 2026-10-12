/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x514bd0; label: FUN_00514bd0
 */

float10 FUN_00514bd0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  
  if ((((param_3 != 0) && (iVar1 = *(int *)(param_3 + 0xd0), iVar1 != 0)) &&
      ((param_5 != 0 || (param_5 = *(int *)(param_2 + 0xa0), param_5 != 0)))) &&
     ((*(int *)(param_5 + 0x38) != 0 &&
      (uVar2 = 1 << ((byte)(param_5 - *(int *)(*(int *)(param_5 + 0x38) + 0x38) >> 6) & 0x1f),
      (uVar2 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
      ((int)uVar2 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)))) {
    return (float10)1;
  }
  return (float10)0;
}

