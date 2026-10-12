/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5ec6b0; label: FUN_005ec6b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ec6b0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00973ff4;
  DAT_00973ff4 = 0x16;
  if (DAT_00973924 == 0) {
    iVar2 = FUN_005e4b20(0);
    DAT_00973924 = iVar2;
    *(uint *)(iVar2 + 0x40) = *(uint *)(iVar2 + 0x40) & 0xff9fbff2 | 0x108002;
    FUN_00601030(iVar2);
    *(short *)(iVar2 + 0x2c0) = *(short *)(iVar2 + 0x2c0) + 1;
  }
  if (DAT_00973928 == 0) {
    DAT_00973928 = FUN_005e4b20(0);
    *(uint *)(DAT_00973928 + 0x44) = *(uint *)(DAT_00973928 + 0x44) & 0xfffffffc;
    *(uint *)(DAT_00973928 + 0x40) = *(uint *)(DAT_00973928 + 0x40) & 0x806fbff2 | 0x608002;
  }
  if ((0x17 < iVar1) || (iVar1 < 0)) {
    FUN_005c12e0();
  }
  DAT_00973ff4 = iVar1;
  FUN_005db310();
  return;
}

