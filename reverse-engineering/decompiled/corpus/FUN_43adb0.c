/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x43adb0; label: FUN_0043adb0
 */

bool FUN_0043adb0(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = FUN_0055bc80(param_1,0);
  if (((iVar2 == 0) && (sVar1 = *(short *)(param_1 + 0x1064), sVar1 != DAT_007f1968)) &&
     (sVar1 != DAT_007f187c)) {
    return sVar1 == DAT_007f1878;
  }
  return true;
}

