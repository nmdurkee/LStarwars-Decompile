/* Ghidra analysis pseudocode, not original source.
 * ev_528f0eafdf60551b868e0e925a842777892bdaf44669a30da4d03ef81027d70b
 * Entry: 0x6dec10; label: FUN_006dec10
 */

int FUN_006dec10(int param_1,int param_2)

{
  param_1 = param_1 + -0x80;
  if (param_2 < param_1) {
    return ((param_1 - param_2) * 0x7f) / (0x7f - param_2);
  }
  if (param_1 < -param_2) {
    return ((param_1 + param_2) * 0x7f) / (0x7f - param_2);
  }
  return 0;
}

