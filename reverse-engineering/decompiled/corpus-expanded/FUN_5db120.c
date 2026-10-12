/* Ghidra pseudocode, not original source.
 * ev_64ab134b4afd9c8d0a163dd8f67d256d98012891aab565beeb69ac94b847fa54
 * Entry: 0x5db120; label: FUN_005db120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005db120(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = &DAT_00971620;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *puVar2;
      puVar2 = puVar2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}

