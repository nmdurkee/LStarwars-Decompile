/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63c710; label: FUN_0063c710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063c710(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_1;
  puVar3 = param_2;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_0063c2a0(param_1,param_2 + 9,param_2 + 5,param_2 + 7,param_3,param_4);
  return;
}

