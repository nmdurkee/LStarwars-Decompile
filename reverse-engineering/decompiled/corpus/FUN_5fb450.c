/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5fb450; label: FUN_005fb450
 */

void FUN_005fb450(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  DAT_0080e188 = param_1;
  if (0x1ff < param_1) {
    DAT_0080e188 = 0x200;
  }
  DAT_0080e18c = param_2;
  if (0x1ff < param_2) {
    DAT_0080e18c = 0x200;
  }
  if (((DAT_0297660c & 2) != 0) || ((DAT_0297660c & 0x100) != 0)) {
    uVar3 = 1;
    uVar2 = 1;
    while( true ) {
      uVar1 = param_1;
      if (0x1ff < param_1) {
        uVar1 = 0x200;
      }
      if (uVar1 < uVar3) break;
      uVar3 = uVar3 * 2;
    }
    DAT_0080e188 = uVar3 >> 1;
    while( true ) {
      uVar3 = param_2;
      if (0x1ff < param_2) {
        uVar3 = 0x200;
      }
      if (uVar3 < uVar2) break;
      uVar2 = uVar2 * 2;
    }
    DAT_0080e18c = uVar2 >> 1;
  }
  FUN_005f8470(DAT_0097382c,DAT_0080e188,DAT_0080e18c,0xffffffff);
  FUN_005f8470(DAT_02854c2c,DAT_0080e188,DAT_0080e18c,0xffffffff);
  if (DAT_00973828 != 0) {
    FUN_005f8470(DAT_00973828,0xffffffff,0xffffffff,0xffffffff);
  }
  return;
}

