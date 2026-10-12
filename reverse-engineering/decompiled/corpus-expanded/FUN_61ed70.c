/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61ed70; label: FUN_0061ed70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061ed70(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (*(undefined4 **)(param_2 + 0x50) != (undefined4 *)0x0) {
    **(undefined4 **)(param_2 + 0x50) = 0;
  }
  iVar1 = *(int *)(param_2 + 0x4c);
  while (iVar1 != 0) {
    piVar2 = *(int **)(param_2 + 0x4c);
    iVar1 = *piVar2;
    (*(code *)piVar2[0x11])(param_1,piVar2);
    *(int *)(param_2 + 0x4c) = iVar1;
  }
  return;
}

