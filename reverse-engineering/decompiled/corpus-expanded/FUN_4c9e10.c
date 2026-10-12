/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4c9e10; label: FUN_004c9e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c9e10(void)

{
  if (DAT_007f39e4 != 0) {
    PTR_s_save_icon_007f44fc = PTR_s_mem_card_007fabf8;
    DAT_00924888 = FUN_005ef7f0(&DAT_00924878,DAT_0092487c,"stuff\\pc_bits.gsc");
    return;
  }
  DAT_00924888 = FUN_005ef7f0(&DAT_00924878,DAT_0092487c,"stuff\\save_icon.gsc");
  return;
}

