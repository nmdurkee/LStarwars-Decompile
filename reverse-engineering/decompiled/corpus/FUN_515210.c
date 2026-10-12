/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x515210; label: FUN_00515210
 */

float10 FUN_00515210(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if ((((param_3 != 0) && (*(int *)(param_3 + 0xe4) != 0)) && (*(int *)(param_3 + 0x158) != 0)) &&
     ((iVar1 = *(int *)(*(int *)(param_3 + 0xe4) + 4), iVar1 != 0 &&
      (*(int *)(param_3 + 0x158) == *(int *)(iVar1 + 0x158))))) {
    return (float10)1;
  }
  return (float10)0;
}

