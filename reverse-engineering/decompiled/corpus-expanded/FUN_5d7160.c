/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d7160; label: FUN_005d7160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d7160(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1[2] != 0) && (DAT_00973964 != 0)) {
    uVar2 = 0;
    if (*(int *)(param_1[2] + 4) != 0) {
      do {
        iVar1 = param_1[2];
        FUN_005d7060(iVar1,param_1[8],
                     *(int *)(*(int *)(iVar1 + 8) + uVar2 * 4) * 0x20 + *(int *)(iVar1 + 0x18),
                     *param_1,*(undefined4 *)(*(int *)(iVar1 + 0xc) + uVar2 * 4),param_2);
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1[2] + 4));
    }
    param_1[10] = param_1[10] | 8;
    return;
  }
  param_1[10] = param_1[10] & 0xfffffff7;
  return;
}

