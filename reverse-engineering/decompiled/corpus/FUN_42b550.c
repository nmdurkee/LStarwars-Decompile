/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x42b550; label: FUN_0042b550
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b550(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float10 fVar3;
  float local_48;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_48;
  if (DAT_00921d24 == 0) {
    if (DAT_00856c08 == 2) {
      fVar3 = (float10)FUN_005b7d30(_DAT_0092505c,0x3e99999a);
      if (fVar3 < (float10)0.20000000298023224) {
        local_48 = (float)*(ushort *)
                           (*(int *)(PTR_DAT_00802c54 + 0x120) * 0x9c + 0x84 + DAT_00951354) -
                   _DAT_0085ea64;
        if (local_48 < 0.0) {
          local_48 = 0.0;
        }
        FUN_0054bbc0(local_48,0,1,1,local_44);
        FUN_00511500(local_44,0,_DAT_007fc310,0x3f800000,0x3f19999a,0x3f19999a,0x3f19999a,0,0xff,
                     0xbf,0);
      }
    }
    else {
      uVar1 = 0xff;
      uVar2 = 0x3f;
      if (DAT_009213e4 != 0) {
        uVar1 = 0xbf;
        uVar2 = 0x1f;
      }
      FUN_00511560(*(undefined4 *)(DAT_00926c20 + DAT_008806d4 * 4),0,_DAT_007fc310,0x3f800000,
                   0x3f800000,0x3f800000,0x3f800000,0,uVar1,uVar2,0,0x3fd9999a,1);
    }
    FUN_0059a1e0(_DAT_0087b99c,_DAT_00955fc0,DAT_00951244,10);
  }
  __security_check_cookie(local_4 ^ (uint)&local_48);
  return;
}

