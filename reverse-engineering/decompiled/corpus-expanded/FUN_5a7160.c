/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a7160; label: FUN_005a7160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_005a7160(int *param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 <= (int)(uint)*(byte *)(*param_1 + 0xd2))) {
    if (param_2 == 0) {
      return "Any Complete";
    }
    FUN_004f2860(param_2,s_Any_Complete_00805a88,10);
    FUN_004f1e80(s_Any_Complete_00805a88," Complete");
    return s_Any_Complete_00805a88;
  }
  return (char *)0x0;
}

