/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5eb710; label: FUN_005eb710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005eb710(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (DAT_009738cc < 0x10) {
    *(undefined4 *)(&DAT_0096d870 + DAT_009738cc * 4) = DAT_009738c4;
    DAT_009738cc = DAT_009738cc + 1;
  }
  DAT_009738c4 = 2;
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    FUN_005d10e0(0,param_1,param_2,param_3,param_4);
  }
  if (0 < DAT_009738cc) {
    DAT_009738c4 = *(undefined4 *)(&DAT_0096d86c + DAT_009738cc * 4);
    DAT_009738cc = DAT_009738cc + -1;
  }
  return;
}

