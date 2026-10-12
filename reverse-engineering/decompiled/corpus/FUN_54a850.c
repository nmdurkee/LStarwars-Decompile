/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54a850; label: FUN_0054a850
 */

void FUN_0054a850(int param_1)

{
  int iVar1;
  float10 extraout_ST0;
  
  if (param_1 != 0) {
    iVar1 = FUN_006e6b90();
    if (0xff < iVar1) {
      iVar1 = 0xff;
    }
    FUN_00698900(param_1,0,iVar1,0,(float)extraout_ST0);
  }
  return;
}

