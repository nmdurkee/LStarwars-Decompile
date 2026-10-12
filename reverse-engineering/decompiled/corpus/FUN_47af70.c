/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x47af70; label: FUN_0047af70
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047af70(undefined4 param_1)

{
  undefined4 uVar1;
  int unaff_ESI;
  float local_48;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_48;
  uVar1 = FUN_006e6b90();
  if (unaff_ESI == 0) {
    FUN_0050d910(&DAT_00755ba8,0,_DAT_007f92ec,0x3f800000,_DAT_007f92f0,_DAT_007f92f0,_DAT_007f92f0,
                 0,DAT_007f92f4,DAT_007f92f8,DAT_00879b1c,0x3fd9999a,1,0,0,uVar1);
    __security_check_cookie(local_4 ^ (uint)&local_48);
    return;
  }
  FUN_0050d910(*(undefined4 *)(DAT_00926c20 + *(short *)(unaff_ESI + 0x78) * 4),0,_DAT_007f92ec,
               0x3f800000,_DAT_007f92f0,_DAT_007f92f0,_DAT_007f92f0,0,DAT_007f92f4,DAT_007f92f8,
               DAT_00879b1c,0x3fd9999a,1,0,0,uVar1);
  if ((&DAT_0086e0f5)[(uint)*(byte *)(unaff_ESI + 0x7c) * 0xc] != '\0') {
    local_48 = _DAT_007f92e4 + 0.125;
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_008806f4 * 4),0,local_48,0x3f800000,
                 _DAT_007f92e8,_DAT_007f92e8,_DAT_007f92e8,0,0xbf,0,0x7f,0x3f333333,1,0,0,uVar1);
    FUN_0054bbc0((&DAT_0086e0fc)[(uint)*(byte *)(unaff_ESI + 0x7c) * 3],1,1,1,local_44);
    FUN_0050c780(local_44,0,_DAT_007f92e4,0x3f800000,_DAT_007f92f0,_DAT_007f92f0,_DAT_007f92f0,0,
                 0xff,0xff,0xff,uVar1);
    if (DAT_0093b318 != 0) {
      local_48 = _DAT_007f92e4 + 0.125;
      FUN_00478d20(0xd3,0,local_48,param_1,0xffffffff,0xffffffff);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_48);
  return;
}

