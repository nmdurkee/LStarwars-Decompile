/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55b0e0; label: FUN_0055b0e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055b0e0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 2;
  if (param_4 != 0) {
    uVar3 = 6;
  }
  if ((((param_2 != 0) && (DAT_0093b268 != 0)) &&
      (pcVar1 = *(code **)((uint)*(byte *)(param_2 + 6) * 0x9c + 0x58 + *(int *)(DAT_0093b268 + 8)),
      pcVar1 != (code *)0x0)) &&
     ((iVar2 = (*pcVar1)(param_2,param_3,uVar3 | 1), iVar2 != 0 &&
      ((**(code **)((uint)*(byte *)(param_2 + 6) * 0x9c + 0x58 + *(int *)(DAT_0093b268 + 8)))
                 (param_2,param_3,uVar3), param_4 != 0)))) {
    FUN_0055a2b0(param_1,param_2,param_3 == 0,1);
  }
  return;
}

