/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55c350; label: FUN_0055c350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055c350(void)

{
  if (DAT_0093b328 == 0) {
    FUN_00565be0(1);
  }
  DAT_0093b328 = 1;
  DAT_00951c80 = 0;
  FUN_005c9130(1);
  FUN_00509830(DAT_00803800,0,0xffffffff);
  FUN_00548fb0(&DAT_00924ff8,0);
  FUN_00694d50(0,0x3f000000);
  FUN_00694100(0x10);
  FUN_00698910();
  _DAT_00925040 = 0;
  FUN_00548fb0(&DAT_00925044,0);
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
                    /* WARNING: Could not recover jumptable at 0x0055c554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0093b330)();
  return;
}

