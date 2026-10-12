/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x624ee0; label: FUN_00624ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00624ee0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_00624e20(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 8) = 0xb;
    *(code **)(iVar1 + 0x3c) = FUN_0061b060;
    *(code **)(iVar1 + 0x40) = FUN_0061bb10;
  }
  return;
}

