/* Ghidra analysis pseudocode, not original source.
 * ev_bdb17253d8eceafb8feb22cd0a23bb82c1f6b43d5fe47ab3712e26b834ea25e8
 * Entry: 0x4f48e0; label: FUN_004f48e0
 */

undefined4 FUN_004f48e0(int param_1)

{
  if ((&DAT_0297e048)[param_1 * 3] != 0) {
    return (&DAT_0297e044)[param_1 * 3];
  }
  return 0xffffffff;
}

