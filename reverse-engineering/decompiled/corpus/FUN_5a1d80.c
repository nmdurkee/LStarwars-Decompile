/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a1d80; label: FUN_005a1d80
 */

void FUN_005a1d80(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x5034) != 0) && (iVar2 = 0, 0 < *(int *)(param_1 + 0x5038))) {
    iVar1 = 0;
    do {
      FUN_005cfc00(*(int *)(param_1 + 0x5034) + iVar1,0);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x18;
    } while (iVar2 < *(int *)(param_1 + 0x5038));
  }
  return;
}

