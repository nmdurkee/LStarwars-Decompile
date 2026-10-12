/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x475850; label: FUN_00475850
 */

int FUN_00475850(undefined4 *param_1)

{
  if (DAT_0093b324 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = 0;
    }
    return -1;
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)(&DAT_007fa138 + DAT_007fa190 * 0xc);
  }
  return (int)DAT_007fa190;
}

