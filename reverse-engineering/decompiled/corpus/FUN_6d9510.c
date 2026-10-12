/* Ghidra analysis pseudocode, not original source.
 * ev_ce999f6f93348d1bea0c268e5ec4785c76bf2f100732e1944453dc4f4dda8e73
 * Entry: 0x6d9510; label: FUN_006d9510
 */

int FUN_006d9510(int param_1,int param_2)

{
  if ((9 < param_1) && (param_1 < 0xe)) {
    if (param_2 != *(int *)(DAT_02975144 + 0x6608)) {
      param_1 = param_1 + 1;
    }
    if (-1 < param_2) {
      param_1 = param_1 + param_2 * 2;
    }
  }
  return param_1;
}

