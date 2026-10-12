/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x496650; label: FUN_00496650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496650(void)

{
  undefined4 uVar1;
  
  if ((DAT_00921d24 == 0) && (DAT_0087b748 == 0)) {
    uVar1 = _DAT_007fc2d8;
    if (DAT_0087b6c8 != '\0') {
      uVar1 = 0x3f800000;
    }
    FUN_0055b830((int)DAT_0087b6c4,-_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa6,uVar1,uVar1,1,0
                );
    uVar1 = _DAT_007fc2d8;
    if (DAT_0087b6c9 != '\0') {
      uVar1 = 0x3f800000;
    }
    FUN_0055b830((int)DAT_0087b6c6,_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa5,uVar1,uVar1,1,0)
    ;
    FUN_004c7750();
    return;
  }
  return;
}

