/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x746950; label: FUN_00746950
 */

char * FUN_00746950(undefined4 param_1,int param_2)

{
  switch(param_1) {
  case 0:
    if (param_2 == 1) {
      return &DAT_007e95e0;
    }
    if (param_2 == 2) {
      return &DAT_007e95dc;
    }
    if (param_2 == 3) {
      return &DAT_007e95d4;
    }
    if (param_2 == 4) {
      return ".xyzw";
    }
    break;
  case 1:
    if (param_2 == 1) {
      return &DAT_007e95c8;
    }
    if (param_2 == 2) {
      return (char *)&PTR_u_TEM_ONLY_007a7904_0x2a_007e95c4;
    }
    if (param_2 == 3) {
      return &DAT_007e95bc;
    }
    break;
  case 2:
    if (param_2 == 1) {
      return &DAT_007e95b8;
    }
    if (param_2 == 2) {
      return (char *)&PTR_s_Force4_MX_440SE_with_AGP8X_00777a2c_2_007e95b4;
    }
    break;
  case 3:
    if (param_2 == 1) {
      return &DAT_007e95b0;
    }
    break;
  default:
    return "??????";
  }
  return &DAT_007532a0;
}

