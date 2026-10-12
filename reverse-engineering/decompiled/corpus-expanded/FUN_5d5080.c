/* Ghidra pseudocode, not original source.
 * ev_e5677de9d32ba70c3e7679a2013183581fdac6be8f175158264fecd59db3931d
 * Entry: 0x5d5080; label: FUN_005d5080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d5080(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  _DAT_00971980 = 1;
  puVar2 = &DAT_009719c8;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}

