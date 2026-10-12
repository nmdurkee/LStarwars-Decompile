/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55c560; label: FUN_0055c560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055c560(int param_1)

{
  DAT_0093b328 = 0;
  DAT_0093b32c = 0;
  FUN_005c9130(0);
  FUN_005097d0(&DAT_00921440 + DAT_00800944 * 0x38);
  FUN_00509760();
  FUN_00694d50(0x3f800000,0x3f000000);
  FUN_006941a0(0x10);
  if (param_1 != 0) {
    FUN_00547930(0x37,0,0,0);
  }
  if (DAT_0093b334 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0055c5db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_0093b334)();
    return;
  }
  return;
}

