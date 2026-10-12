/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x62f910; label: FUN_0062f910
 */

void FUN_0062f910(int param_1)

{
  DAT_029a99a0 = param_1;
  if (param_1 != 0) {
    DAT_0291310c = *(undefined1 *)(param_1 + 0x168);
    *(undefined4 *)(param_1 + 0x168) = 1;
  }
  return;
}

