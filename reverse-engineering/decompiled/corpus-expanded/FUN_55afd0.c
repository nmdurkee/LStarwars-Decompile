/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55afd0; label: FUN_0055afd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0055afd0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                undefined4 *param_6)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if (param_4 == -1) {
    if (param_5 == 0) {
      return 0;
    }
    param_4 = FUN_00559e20(param_1,param_5);
    if (param_4 == -1) {
      return 0;
    }
  }
  iVar3 = param_4 * 0x9c + *(int *)(DAT_0093b268 + 8);
  iVar2 = *(int *)(iVar3 + 0x98);
  if (((iVar2 == 0) || (param_3 < 0)) || (*(int *)(DAT_0093b268 + 4) <= param_3)) {
    *param_6 = 0;
  }
  else {
    *param_6 = *(undefined4 *)(iVar2 + param_3 * 4);
  }
  sVar1 = *(short *)(iVar3 + 0x28);
  if (sVar1 == -1) {
    FUN_00559570();
    return 0;
  }
  return (int)sVar1;
}

