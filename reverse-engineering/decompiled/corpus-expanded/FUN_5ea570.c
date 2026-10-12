/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ea570; label: FUN_005ea570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ea570(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    iVar1 = 0x10;
    if (param_1[1] != 0) {
      puVar2 = *(undefined4 **)(param_1[1] + 0x40);
      for (; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_2;
        param_2 = param_2 + 1;
        puVar2 = puVar2 + 1;
      }
      return;
    }
    puVar2 = (undefined4 *)(param_1[2] + 0x40);
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
    if ((*(byte *)(*(int *)(*param_1 + 0x110) + 0x76) & 1) != 0) {
      FUN_005df480(param_1);
      *(uint *)(param_1[2] + 0xb8) = *(uint *)(param_1[2] + 0xb8) | 0x400;
    }
  }
  return;
}

