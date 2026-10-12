/* Ghidra pseudocode, not original source.
 * ev_92748b398136944cd3b8ebaa69598612f81b868998f444146461847577bf6b2d
 * Entry: 0x6deb50; label: FUN_006deb50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006deb50(float *param_1,float *param_2)

{
  *param_1 = param_2[2] * _DAT_0297ad08 + _DAT_0297acf8 * param_2[1] + *param_2 * _DAT_0297ace8 +
             _DAT_0297ad18;
  param_1[1] = param_2[2] * _DAT_0297ad0c + _DAT_0297acfc * param_2[1] + *param_2 * _DAT_0297acec +
               _DAT_0297ad1c;
  param_1[2] = param_2[2] * _DAT_0297ad10 + _DAT_0297ad00 * param_2[1] + *param_2 * _DAT_0297acf0 +
               _DAT_0297ad20;
  return;
}

