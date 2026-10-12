/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4f99e0; label: FUN_004f99e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f99e0(int param_1)

{
  int iVar1;
  
  if (0xfff < param_1) {
    FUN_006dee70(param_1 + -0x1000,0);
    return;
  }
  if (param_1 < 0x400) {
    param_1 = param_1 + -1;
    iVar1 = FUN_004ff380(param_1);
    while (iVar1 < 0) {
      FUN_004ef790();
      iVar1 = FUN_004ff380(param_1);
    }
    if (*(undefined4 **)(&DAT_008ceb88 + param_1 * 0x40) != (undefined4 *)0x0) {
      **(undefined4 **)(&DAT_008ceb88 + param_1 * 0x40) = 0;
    }
    _memset(&DAT_008ceb50 + param_1 * 0x40,0,0x40);
    return;
  }
  FUN_004f6bc0(param_1);
  return;
}

