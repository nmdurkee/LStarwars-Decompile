/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0bd0; label: FUN_004f0bd0
 */

int FUN_004f0bd0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  FUN_004ffaa0(DAT_0088ab48);
  uVar1 = DAT_0088ab48;
  iVar3 = 0;
  piVar2 = &DAT_0297dc84;
  do {
    if (*piVar2 == 0) {
      (&DAT_0297dc84)[iVar3 * 0xc] = 1;
      FUN_004ffac0(uVar1);
      return iVar3;
    }
    piVar2 = piVar2 + 0xc;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x297e044);
  FUN_004ffac0(DAT_0088ab48);
  return -1;
}

