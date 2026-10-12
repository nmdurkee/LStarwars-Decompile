/* Ghidra pseudocode, not original source.
 * ev_a3dc7e4d451c42d041af92cbf24a16255b1dce01fb5c93e82b55e7bce3880be0
 * Entry: 0x5115d0; label: FUN_005115d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005115d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  if (DAT_00921ea4 == 0) {
    DAT_00921ea4 = FUN_005eb090(param_1,param_2,4,param_5,param_3,param_4);
    if (DAT_00921ea4 != 0) {
      FUN_0050ec40(DAT_00921e8c,DAT_00921ea4);
      *(float *)(DAT_00921ea4 + 0x18) =
           (*(float *)(DAT_00921ea4 + 0x14) / *(float *)(DAT_00921e8c + 0x14)) *
           *(float *)(DAT_00921e8c + 0x18);
    }
  }
  return DAT_00921ea4;
}

