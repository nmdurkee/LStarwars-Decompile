/* Ghidra pseudocode, not original source.
 * ev_e5677de9d32ba70c3e7679a2013183581fdac6be8f175158264fecd59db3931d
 * Entry: 0x5d51f0; label: FUN_005d51f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d51f0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00971a6c;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_005b5a40(&DAT_00971a6c,&DAT_00971a6c);
  return;
}

