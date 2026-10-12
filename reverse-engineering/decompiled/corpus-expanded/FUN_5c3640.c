/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c3640; label: FUN_005c3640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c3640(undefined4 param_1)

{
  int *piVar1;
  
  if (DAT_009737e4 != 0) {
    piVar1 = (int *)(DAT_009737e4 + 0x54);
    *(undefined4 *)(DAT_009737e4 + 0x58 + *(int *)(DAT_009737e4 + 0x54) * 4) = param_1;
    *piVar1 = *piVar1 + 1;
  }
  return;
}

