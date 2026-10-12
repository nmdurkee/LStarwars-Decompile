/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55acd0; label: FUN_0055acd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0055acd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            ,int param_6,int param_7)

{
  int iVar1;
  
  iVar1 = FUN_005cf5b0(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    return 1;
  }
  if (((param_5 != 0) && (*(int *)(param_5 + 4) != 0)) && ((*(byte *)(param_5 + 8) & 4) != 0)) {
    FUN_0055ac80(param_5);
    if (param_6 != 0) {
      FUN_0055ac80(param_5);
      FUN_0055ac80(param_5);
    }
    if (param_7 != 0) {
      FUN_0055ac80(param_5);
      FUN_0055ac80(param_5);
    }
    FUN_0055ac80(param_5);
  }
  return 0;
}

