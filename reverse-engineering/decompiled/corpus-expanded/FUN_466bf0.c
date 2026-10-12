/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x466bf0; label: FUN_00466bf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00466bf0(int param_1,byte param_2)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined2 local_8 [4];
  
  if (param_1 != 0) {
    puVar2 = *(undefined2 **)(param_1 + 0x24);
    if (*(undefined2 **)(param_1 + 0x24) == (undefined2 *)0x0) {
      puVar2 = local_8;
    }
    if (8 < param_2) {
      uVar1 = FUN_00621860();
      *puVar2 = uVar1;
    }
  }
  return;
}

