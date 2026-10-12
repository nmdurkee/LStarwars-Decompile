/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46d890; label: FUN_0046d890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046d890(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(int **)(param_1 + 0x5070) != (int *)0x0) && (iVar1 = 0, 0 < **(int **)(param_1 + 0x5070)))
  {
    iVar2 = 0;
    do {
      *(undefined2 *)(*(int *)(*(int *)(param_1 + 0x5070) + 4) + 0x86 + iVar2) = 0xffff;
      FUN_0046d820();
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x90;
    } while (iVar1 < **(int **)(param_1 + 0x5070));
  }
  return;
}

