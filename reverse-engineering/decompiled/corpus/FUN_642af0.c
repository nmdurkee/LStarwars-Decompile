/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x642af0; label: FUN_00642af0
 */

void FUN_00642af0(int param_1,undefined4 *param_2)

{
  (&DAT_0291f7a8)[param_1 * 0x1b] = *param_2;
  (&DAT_0291f7ac)[param_1 * 0x1b] = param_2[1];
  (&DAT_0291f7b0)[param_1 * 0x1b] = param_2[2];
  (&DAT_0291f7d4)[param_1 * 0x36] = (undefined2)DAT_02920a40;
  (&DAT_0291f7d6)[param_1 * 0x36] = (undefined2)DAT_02920a44;
  (&DAT_0291f7d8)[param_1 * 0x36] = (undefined2)DAT_02920a48;
  return;
}

