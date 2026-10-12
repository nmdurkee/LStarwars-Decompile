/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x496da0; label: FUN_00496da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496da0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (DAT_00921d24 == 0) {
    uVar1 = 0xff;
    uVar2 = 0xbf;
    if (DAT_009213e4 != 0) {
      uVar2 = 0x8f;
      uVar1 = 0xbf;
    }
    FUN_00511560(*(undefined4 *)(DAT_00926c20 + DAT_00880fa4 * 4),0,_DAT_007fc310,0x3f800000,
                 0x3f800000,0x3f800000,0x3f800000,0,uVar1,uVar2,0,0x3fd9999a,1);
  }
  return;
}

