/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a29d0; label: FUN_005a29d0
 */

void FUN_005a29d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x46f8)) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(iVar3 + 0x24 + *(int *)(param_1 + 0x46f4));
      if (iVar1 != 0) {
        FUN_005e5630((int)*(short *)(iVar1 + 0x74));
        FUN_005e50e0(*(undefined4 *)(iVar3 + 0x24 + *(int *)(param_1 + 0x46f4)));
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x28;
    } while (iVar2 < *(int *)(param_1 + 0x46f8));
  }
  return;
}

