/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x565c00; label: FUN_00565c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565c00(int param_1)

{
  int iVar1;
  float10 extraout_ST0;
  uint local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  FUN_005d4290(1);
  FUN_005db140();
  if (param_1 != 0) {
    FUN_005ebd80(0x500,0,0x3f800000);
  }
  if (_DAT_00950678 < 1.0) {
    iVar1 = FUN_006e6b90();
    local_10 = iVar1 << 0x18 | 0x808080;
    local_c = local_10;
    local_8 = local_10;
    local_4 = local_10;
    FUN_005dc3f0(DAT_00802f38,DAT_00802f3c,DAT_00802f40,DAT_00802f44,0,0,(float)extraout_ST0,
                 (float)extraout_ST0,&local_10,DAT_00950660);
    FUN_005f3950();
    return;
  }
  FUN_005dba30(DAT_00802f38,DAT_00802f3c,DAT_00802f40,DAT_00802f44,0,0,0x3f800000,0x3f800000,
               0x80808080,DAT_00950660);
  FUN_005f3950();
  return;
}

