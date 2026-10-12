/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c3790; label: FUN_005c3790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c3790(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = DAT_009737e0;
  if (DAT_009737e0 != 0) {
    *(undefined4 *)(DAT_009737e0 + 0x120) = param_2;
    *(undefined4 *)(iVar1 + 0x11c) = param_1;
    *(undefined4 *)(iVar1 + 0x124) = param_3;
    iVar1 = DAT_009737ec;
    if (DAT_009737ec != 0) {
      *(undefined4 *)(DAT_009737ec + 0x20) = param_3;
      *(undefined4 *)(iVar1 + 0x18) = param_1;
      *(undefined4 *)(iVar1 + 0x1c) = param_2;
      return;
    }
  }
  return;
}

