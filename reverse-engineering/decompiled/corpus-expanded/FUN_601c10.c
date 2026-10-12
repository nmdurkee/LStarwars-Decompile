/* Ghidra pseudocode, not original source.
 * ev_fc1ff40c7a3094b1e589789cc6fd4e7c7ceccf6febfdd6935cf97a0e254c7b0e
 * Entry: 0x601c10; label: FUN_00601c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00601c10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  if (param_1 < 4) {
    iVar1 = param_1 * 0x14;
    *(undefined4 *)(&DAT_0280a29c + iVar1) = param_3;
    (&DAT_0280a298)[param_1 * 5] = param_2;
    *(undefined4 *)(&DAT_0280a2a0 + iVar1) = param_4;
    *(undefined4 *)(&DAT_0280a2a4 + iVar1) = param_5;
    *(undefined4 *)(&DAT_0280a2a8 + iVar1) = param_6;
  }
  return;
}

