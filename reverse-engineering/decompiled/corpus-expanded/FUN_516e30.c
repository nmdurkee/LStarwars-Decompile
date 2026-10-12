/* Ghidra pseudocode, not original source.
 * ev_8db479debe006dcb1d0ae53ec943fbf75b60233db5d397d4c7fbd4646b77bfb6
 * Entry: 0x516e30; label: FUN_00516e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00516e30(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4,int param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_6 != 0) && (param_2 != 0)) {
    iVar2 = 0;
    if (*(int *)(param_2 + 8) != 0) {
      iVar2 = *(int *)(param_2 + 8);
    }
    iVar3 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(param_4[iVar3],"state");
        if ((iVar1 != 0) &&
           (iVar2 = FUN_00512fc0(iVar1 + 6,*(undefined4 *)(param_2 + 4)), iVar2 == 0)) {
          if (DAT_00922248 == 0) {
            FUN_00512850(*param_4,*(undefined4 *)(*(int *)(param_2 + 4) + 8),
                         *(undefined4 *)(*(int *)(param_2 + 8) + 0x18));
          }
          else {
            FUN_00512860(*param_4,*(undefined4 *)(*(int *)(param_2 + 4) + 8),
                         *(undefined4 *)(*(int *)(param_2 + 8) + 0x18));
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
    *(int *)(param_2 + 0xc0) = iVar2;
  }
  return 1;
}

