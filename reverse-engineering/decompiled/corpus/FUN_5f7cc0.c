/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f7cc0; label: FUN_005f7cc0
 */

void FUN_005f7cc0(int param_1,uint param_2,uint param_3)

{
  *(uint *)(param_1 + 0x20) =
       (param_3 & 0xf) << 4 | *(uint *)(param_1 + 0x20) & 0xffffff00 | param_2 & 0xf;
  return;
}

