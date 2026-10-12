/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49b7f0; label: FUN_0049b7f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049b7f0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x7b5) == '*') {
    FUN_0049b150(param_1,param_2);
  }
  else if (*(char *)(param_1 + 0x7b5) == ':') {
    FUN_006e6b90();
    iVar1 = FUN_006e6b90();
    if (*(char *)(param_1 + 0x7b3) == '\0') {
      FUN_005b5240(param_2,iVar1);
    }
    else {
      FUN_005b5240(param_2,-iVar1);
    }
  }
  if (*(short *)(param_1 + 0x1064) == DAT_007f1afc) {
    FUN_005b4dd0(param_2,0xffffc000);
    FUN_005b5060(param_2,0x8000);
  }
  return;
}

