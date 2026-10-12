/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x5204e0; label: FUN_005204e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005204e0(short param_1)

{
  short sVar1;
  
  sVar1 = DAT_009220ee;
  DAT_009220ee = param_1;
  if ((DAT_009238e4 != 0) && (sVar1 != param_1)) {
    if (*(int *)(DAT_009238e4 + 0x4868) != 0) {
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = 0;
    }
    *(undefined4 *)(DAT_009238e4 + 0x371b0) = 0;
    *(undefined4 *)(DAT_009238e4 + 0x383c8) = 0;
    *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = 0;
    *(undefined4 *)(DAT_009238e4 + 0x4381c) = 0;
  }
  return;
}

