/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f3790; label: FUN_005f3790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f3790(undefined4 param_1,undefined4 param_2)

{
  if (DAT_009738cc < 0x10) {
    *(undefined4 *)(&DAT_0096d870 + DAT_009738cc * 4) = DAT_009738c4;
    DAT_009738cc = DAT_009738cc + 1;
  }
  DAT_009738c4 = 2;
  FUN_005f3510(param_1,param_2);
  if (0 < DAT_009738cc) {
    DAT_009738c4 = *(undefined4 *)(&DAT_0096d86c + DAT_009738cc * 4);
    DAT_009738cc = DAT_009738cc + -1;
  }
  return;
}

