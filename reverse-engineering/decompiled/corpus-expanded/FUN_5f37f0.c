/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f37f0; label: FUN_005f37f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f37f0(int param_1,undefined4 param_2)

{
  if (DAT_009738cc < 0x10) {
    *(undefined4 *)(&DAT_0096d870 + DAT_009738cc * 4) = DAT_009738c4;
    DAT_009738cc = DAT_009738cc + 1;
  }
  DAT_009738c4 = 4;
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    FUN_005eb250(param_1,param_2,4);
  }
  if (0 < DAT_009738cc) {
    DAT_009738c4 = *(undefined4 *)(&DAT_0096d86c + DAT_009738cc * 4);
    DAT_009738cc = DAT_009738cc + -1;
  }
  return;
}

