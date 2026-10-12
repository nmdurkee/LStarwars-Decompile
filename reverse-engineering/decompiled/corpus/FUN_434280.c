/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x434280; label: FUN_00434280
 */

void FUN_00434280(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_1 != 0) && ((*(uint *)(param_1 + 0xeec) & 0x100000) == 0)) &&
     (iVar3 = 0, 0 < DAT_0093d500)) {
    iVar2 = 0;
    do {
      iVar1 = DAT_0093d504 + iVar2;
      if (((iVar1 != 0) && ((*(uint *)(iVar1 + 0x1fc) & 1) != 0)) &&
         (((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0 && (*(int *)(iVar1 + 0xcd4) == param_1)))) {
        *(undefined4 *)(iVar1 + 0xcd4) = 0;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10d8;
    } while (iVar3 < DAT_0093d500);
  }
  return;
}

