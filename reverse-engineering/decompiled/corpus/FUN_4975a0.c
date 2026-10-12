/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x4975a0; label: FUN_004975a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004975a0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float10 fVar3;
  float local_28;
  undefined1 local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_28;
  if (DAT_00921d24 == 0) {
    if (*(char *)((int)DAT_009553d4 + 0x1d) == '\x02') {
      fVar3 = (float10)FUN_005b7d30(_DAT_0092505c,0x3e99999a);
      if (fVar3 < (float10)0.20000000298023224) {
        local_28 = (float)*(ushort *)
                           (*DAT_009553d4 + 0x10 + *(char *)(DAT_009553d4[1] + 0x12) * 0x18) -
                   _DAT_00925008;
        if (local_28 < 0.0) {
          local_28 = 0.0;
        }
        FUN_0054bbc0(local_28,0,1,1,local_24);
        FUN_00511500(local_24,0,_DAT_007fc310,0x3f800000,0x3f19999a,0x3f19999a,0x3f19999a,0,0xff,
                     0xbf,0);
        __security_check_cookie(local_4 ^ (uint)&local_28);
        return;
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
  }
  __security_check_cookie(local_4 ^ (uint)&local_28);
  return;
}

