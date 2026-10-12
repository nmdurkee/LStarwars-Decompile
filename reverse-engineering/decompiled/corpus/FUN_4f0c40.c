/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0c40; label: FUN_004f0c40
 */

int FUN_004f0c40(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  FUN_004ffaa0(DAT_0088ab48);
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x34);
  do {
    if (*piVar2 == -1) {
      *(undefined4 *)(iVar1 * 0x10 + 0x34 + param_1) = param_2;
      FUN_004ffac0(DAT_0088ab48);
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 4;
  } while (iVar1 < 8);
  FUN_004ffac0(DAT_0088ab48);
  return -1;
}

