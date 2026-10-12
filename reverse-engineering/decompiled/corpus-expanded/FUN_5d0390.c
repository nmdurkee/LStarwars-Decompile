/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0390; label: FUN_005d0390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0390(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (((param_1 != (int *)0x0) && (*param_1 != 0)) && (param_1[1] != 0)) {
    puVar2 = *(undefined4 **)(param_1[1] + 0x40);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  return;
}

