/* Ghidra pseudocode, not original source.
 * ev_36c567c8b03fa9be6305a90618e5976b2395159d59c428aaf9f1abc99d465ca0
 * Entry: 0x65b700; label: FUN_0065b700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065b700(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  if (param_1 == 0) {
    DAT_02962218 = 0;
  }
  else {
    FUN_004f1f10(&DAT_02962218,param_1);
  }
  if (param_2 == 0) {
    DAT_02962318 = 0;
  }
  else {
    FUN_004f1f10(&DAT_02962318,param_2);
  }
  if (param_3 == 0) {
    DAT_02962418 = 0;
  }
  else {
    FUN_004f1f10(&DAT_02962418,param_3);
  }
  if (param_4 == 0) {
    DAT_02962518 = 0;
  }
  else {
    FUN_004f1f10(&DAT_02962518,param_4);
  }
  if (param_5 == 0) {
    DAT_02962618 = 0;
  }
  else {
    FUN_004f1f10(&DAT_02962618,param_5);
  }
  if (param_6 != 0) {
    FUN_004f1f10(&DAT_02962718,param_6);
    return;
  }
  DAT_02962718 = 0;
  return;
}

