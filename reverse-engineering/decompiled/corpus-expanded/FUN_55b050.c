/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55b050; label: FUN_0055b050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055b050(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_4 != -1) ||
     ((param_5 != 0 && (param_4 = FUN_00559e20(param_1,param_5), param_4 != -1)))) {
    iVar1 = *param_1;
    iVar2 = param_4 * 0x9c + *(int *)(DAT_0093b268 + 8);
    if ((*(int *)(iVar2 + 0x98) == 0) || ((param_3 < 0 || (*(int *)(DAT_0093b268 + 4) <= param_3))))
    {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(*(int *)(iVar2 + 0x98) + param_3 * 4);
    }
    if (*(code **)(iVar2 + 0x7c) != (code *)0x0) {
      (**(code **)(iVar2 + 0x7c))(param_2,uVar3);
    }
    if (*(code **)(iVar2 + 0x80) != (code *)0x0) {
      (**(code **)(iVar2 + 0x80))(param_2,*(undefined4 *)(iVar1 + param_4 * 0x14 + 0x10),uVar3);
    }
  }
  return;
}

