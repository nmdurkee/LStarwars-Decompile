/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ea5d0; label: FUN_005ea5d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ea5d0(int *param_1,undefined4 *param_2)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (param_1[1] != 0) {
      *(undefined4 *)(*(int *)(param_1[1] + 0x40) + 0x30) = *param_2;
      *(undefined4 *)(*(int *)(param_1[1] + 0x40) + 0x34) = param_2[1];
      *(undefined4 *)(*(int *)(param_1[1] + 0x40) + 0x38) = param_2[2];
      return;
    }
    *(undefined4 *)(param_1[2] + 0x70) = *param_2;
    *(undefined4 *)(param_1[2] + 0x74) = param_2[1];
    *(undefined4 *)(param_1[2] + 0x78) = param_2[2];
    if ((*(byte *)(*(int *)(*param_1 + 0x110) + 0x76) & 1) != 0) {
      FUN_005df480(param_1);
      *(uint *)(param_1[2] + 0xb8) = *(uint *)(param_1[2] + 0xb8) | 0x400;
    }
  }
  return;
}

