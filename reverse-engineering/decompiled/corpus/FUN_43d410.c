/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43d410; label: FUN_0043d410
 */

bool FUN_0043d410(int param_1,int param_2)

{
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0xef4) & 0x2000) == 0) {
      return true;
    }
    if (*(byte *)(param_1 + 0x1084) != 0xff) {
      return (&DAT_0093d7f0)[*(byte *)(param_1 + 0x1084)] == param_2;
    }
  }
  return false;
}

