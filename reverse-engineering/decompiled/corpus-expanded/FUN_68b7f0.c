/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68b7f0; label: FUN_0068b7f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068b7f0(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_02921884 != -1) {
    iVar1 = *(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14);
    if (iVar1 != DAT_02962a10) {
      *(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14) = iVar1 + 1;
      FUN_0068b220(iVar1,param_1);
    }
  }
  return;
}

