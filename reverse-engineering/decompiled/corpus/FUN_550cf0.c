/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x550cf0; label: FUN_00550cf0
 */

undefined4
FUN_00550cf0(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6)

{
  if (0.0 <= (param_2 - param_4) * (param_3 - param_5) + (param_1 - param_3) * (param_6 - param_4))
  {
    return 1;
  }
  return 0;
}

