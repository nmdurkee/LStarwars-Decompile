/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x421410; label: FUN_00421410
 */

undefined4 FUN_00421410(int param_1)

{
  if (param_1 < 0) {
    return 0xffffffff;
  }
  return *(undefined4 *)(&DAT_007f295c + param_1 * 4);
}

