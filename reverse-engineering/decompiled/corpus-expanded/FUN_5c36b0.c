/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c36b0; label: FUN_005c36b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c36b0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = DAT_009737e4;
  if (DAT_009737e4 != 0) {
    *(undefined4 *)(DAT_009737e4 + 0x44) = *param_1;
    *(undefined4 *)(iVar1 + 0x48) = param_1[1];
    *(undefined4 *)(iVar1 + 0x4c) = param_1[2];
    *(undefined4 *)(iVar1 + 0x50) = param_1[3];
  }
  return;
}

