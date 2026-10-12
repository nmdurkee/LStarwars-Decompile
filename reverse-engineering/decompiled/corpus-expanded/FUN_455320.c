/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x455320; label: FUN_00455320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00455320(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  if (param_3 != 0) {
    if (param_6 != 0) {
      iVar3 = 0;
      *(undefined4 *)(param_3 + 0x180) = 0x3f800000;
      if (0 < param_5) {
        do {
          if ((DAT_009238b0 == (code *)0x0) ||
             (iVar2 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar3 * 4),param_3 + 0x13f),
             iVar2 == 0)) {
            fVar4 = (float10)FUN_00514920(param_3,param_2,*(undefined4 *)(param_4 + iVar3 * 4));
            *(float *)(param_3 + 0x180) = (float)fVar4;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_5);
      }
    }
    iVar3 = *(int *)(param_3 + 0xe4);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      iVar3 = *(int *)(iVar3 + 4);
      iVar2 = **(int **)(param_3 + 0xd0);
      FUN_0052fcb0(param_3,iVar3 + 0x170,*(undefined4 *)(iVar3 + 0x120),iVar3 + 0x158,2,
                   *(undefined4 *)(param_3 + 0x180));
      puVar1 = (uint *)(iVar2 + 0xef0);
      *puVar1 = *puVar1 | 0x8000;
      *(undefined1 *)(iVar2 + 0x407) = 1;
    }
    return 0;
  }
  return 1;
}

