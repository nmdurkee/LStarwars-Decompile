/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61eee0; label: FUN_0061eee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061eee0(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_2 + 0x80);
  while (iVar1 != 0) {
    piVar2 = *(int **)(param_2 + 0x80);
    iVar1 = *piVar2;
    (*(code *)piVar2[0x11])(param_1,piVar2);
    *(int *)(param_2 + 0x80) = iVar1;
  }
  FUN_0061e9d0(param_1,param_2);
  return;
}

