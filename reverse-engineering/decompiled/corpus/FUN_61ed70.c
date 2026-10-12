/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61ed70; label: FUN_0061ed70
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

