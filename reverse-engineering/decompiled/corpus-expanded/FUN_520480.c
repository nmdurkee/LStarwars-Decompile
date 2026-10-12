/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x520480; label: FUN_00520480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00520480(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  
  if (DAT_009220ec < 8) {
    iVar1 = (int)DAT_009220ec;
    DAT_009220ec = DAT_009220ec + 1;
    FUN_004f1f10(&DAT_00921f6c + iVar1 * 0x30,param_1);
    (&DAT_00921f8c)[iVar1 * 0xc] = param_2;
    (&DAT_00921f94)[iVar1 * 0xc] = param_4;
    (&DAT_00921f90)[iVar1 * 0xc] = param_3;
    (&DAT_00921f98)[iVar1 * 0xc] = param_5;
    return iVar1;
  }
  iVar1 = FUN_00512850();
  return iVar1;
}

