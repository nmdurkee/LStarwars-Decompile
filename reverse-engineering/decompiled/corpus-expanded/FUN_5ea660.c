/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ea660; label: FUN_005ea660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ea660(int *param_1)

{
  int iVar1;
  
  if ((((param_1 != (int *)0x0) && (param_1[2] != 0)) && (*param_1 != 0)) &&
     ((iVar1 = *(int *)(*param_1 + 0x110), iVar1 != 0 && ((*(byte *)(iVar1 + 0x76) & 1) != 0)))) {
    *(uint *)(param_1[2] + 0xb8) = *(uint *)(param_1[2] + 0xb8) | 0x400;
    FUN_005df480();
    return;
  }
  return;
}

