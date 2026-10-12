/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x696170; label: FUN_00696170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00696170(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((in_ECX != 0) && (DAT_02962b8c != 0)) {
    uVar1 = FUN_00694320(param_1,param_2);
    uVar1 = FUN_00694240(param_1,uVar1);
    return uVar1;
  }
  return 0;
}

