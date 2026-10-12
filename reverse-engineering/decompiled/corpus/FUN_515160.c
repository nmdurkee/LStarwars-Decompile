/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x515160; label: FUN_00515160
 */

float10 FUN_00515160(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  
  if ((((param_3 != 0) && (iVar1 = *(int *)(param_3 + 0xe4), iVar1 != 0)) &&
      (*(int *)(param_3 + 0xd0) != 0)) &&
     (((param_5 != 0 || (param_5 = *(int *)(param_2 + 0xa0), param_5 != 0)) &&
      ((*(int *)(param_5 + 0x38) != 0 &&
       (uVar2 = 1 << ((byte)(param_5 - *(int *)(*(int *)(param_5 + 0x38) + 0x38) >> 6) & 0x1f),
       (uVar2 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
       ((int)uVar2 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)))))) {
    return (float10)1;
  }
  return (float10)0;
}

