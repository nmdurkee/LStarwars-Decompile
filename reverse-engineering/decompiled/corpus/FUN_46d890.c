/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46d890; label: FUN_0046d890
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

