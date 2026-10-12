/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61eee0; label: FUN_0061eee0
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

