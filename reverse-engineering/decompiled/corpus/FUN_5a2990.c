/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a2990; label: FUN_005a2990
 */

void FUN_005a2990(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    iVar2 = 0;
    if (*(short *)(param_1 + 2) != 0) {
      do {
        if (iVar1 != 0) {
          FUN_005a2830(iVar1);
          iVar1 = *(int *)(iVar1 + 0x78);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)*(ushort *)(param_1 + 2));
    }
  }
  return;
}

