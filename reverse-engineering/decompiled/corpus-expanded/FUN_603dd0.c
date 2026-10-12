/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x603dd0; label: FUN_00603dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00603dd0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_009736e8;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  *param_2 = DAT_00973728;
  *param_3 = DAT_0097372c;
  *param_4 = DAT_00973730;
  *param_5 = DAT_00973734;
  *param_6 = _DAT_00973750;
  return;
}

