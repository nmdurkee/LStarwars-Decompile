/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55c120; label: FUN_0055c120
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055c120(undefined4 param_1)

{
  undefined4 uVar1;
  
  DAT_0093b328 = 1;
  FUN_005c9130(1);
  FUN_00694d50(0,0x3f000000);
  FUN_00694100(0x10);
  FUN_00698910();
  uVar1 = DAT_008037fc;
  if ((DAT_00921e58 != 0) && (DAT_00921dfc != 0)) {
    uVar1 = 0x3f3;
  }
  FUN_00509830(uVar1,0,0xffffffff);
  FUN_00548fb0(&DAT_00924ff8,0);
  FUN_00547930(0x36,0,0,0);
  _DAT_00925040 = 0;
  FUN_00548fb0(&DAT_00925044,0);
  DAT_00802af8 = param_1;
  FUN_006d6340(param_1);
  if (DAT_0093d7f0 != 0) {
    *(undefined4 *)(DAT_0093d7f0 + 0xd60) = 0;
    *(undefined4 *)(DAT_0093d7f0 + 0xda4) = _DAT_00802be8;
    *(undefined4 *)(DAT_0093d7f0 + 0xee8) = 0;
  }
  if (DAT_0093d7f4 != 0) {
    *(undefined4 *)(DAT_0093d7f4 + 0xd60) = 0;
    *(undefined4 *)(DAT_0093d7f4 + 0xda4) = _DAT_00802be8;
    *(undefined4 *)(DAT_0093d7f4 + 0xee8) = 0;
  }
  if (DAT_0093d7f8 != 0) {
    *(undefined4 *)(DAT_0093d7f8 + 0xd60) = 0;
    *(undefined4 *)(DAT_0093d7f8 + 0xda4) = _DAT_00802be8;
    *(undefined4 *)(DAT_0093d7f8 + 0xee8) = 0;
  }
  if (DAT_0093d7fc != 0) {
    *(undefined4 *)(DAT_0093d7fc + 0xd60) = 0;
    *(undefined4 *)(DAT_0093d7fc + 0xda4) = _DAT_00802be8;
    *(undefined4 *)(DAT_0093d7fc + 0xee8) = 0;
  }
  if (DAT_0093d800 != 0) {
    *(undefined4 *)(DAT_0093d800 + 0xd60) = 0;
    *(undefined4 *)(DAT_0093d800 + 0xda4) = _DAT_00802be8;
    *(undefined4 *)(DAT_0093d800 + 0xee8) = 0;
  }
  if (DAT_0093d804 != 0) {
    *(undefined4 *)(DAT_0093d804 + 0xd60) = 0;
    *(undefined4 *)(DAT_0093d804 + 0xda4) = _DAT_00802be8;
    *(undefined4 *)(DAT_0093d804 + 0xee8) = 0;
  }
  if (DAT_0093d808 != 0) {
    *(undefined4 *)(DAT_0093d808 + 0xd60) = 0;
    *(undefined4 *)(DAT_0093d808 + 0xda4) = _DAT_00802be8;
    *(undefined4 *)(DAT_0093d808 + 0xee8) = 0;
  }
  if (DAT_0093d80c != 0) {
    *(undefined4 *)(DAT_0093d80c + 0xd60) = 0;
    *(undefined4 *)(DAT_0093d80c + 0xda4) = _DAT_00802be8;
    *(undefined4 *)(DAT_0093d80c + 0xee8) = 0;
  }
  if (DAT_0093b330 == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0055c343. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0093b330)();
  return;
}

