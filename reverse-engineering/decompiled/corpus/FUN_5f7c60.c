/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f7c60; label: FUN_005f7c60
 */

void FUN_005f7c60(int param_1,byte param_2,uint *param_3,uint *param_4)

{
  *param_3 = *(ushort *)(param_1 + 4) >> (param_2 & 0x1f) & 0xfffffffe;
  *param_4 = *(ushort *)(param_1 + 6) >> (param_2 & 0x1f) & 0xfffffffe;
  return;
}

