/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55b570; label: FUN_0055b570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055b570(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = FUN_0055b520(param_1,param_2);
  if (iVar1 != 0) {
    if (param_3 != 0) {
      FUN_005f33b0(iVar1,param_3);
    }
    if (param_4 != 0) {
      FUN_005f33b0(iVar1,param_4);
    }
  }
  return;
}

