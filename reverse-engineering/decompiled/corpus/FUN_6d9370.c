/* Ghidra analysis pseudocode, not original source.
 * ev_ce999f6f93348d1bea0c268e5ec4785c76bf2f100732e1944453dc4f4dda8e73
 * Entry: 0x6d9370; label: FUN_006d9370
 */

undefined1 FUN_006d9370(int param_1)

{
  if (param_1 - 10U < 4) {
    return 0;
  }
  return *(undefined1 *)(param_1 * 0x17c + 0x4e50 + DAT_02975144);
}

