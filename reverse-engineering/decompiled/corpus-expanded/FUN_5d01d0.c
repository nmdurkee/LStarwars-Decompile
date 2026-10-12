/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d01d0; label: FUN_005d01d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d01d0(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_1[1] == 0) {
    iVar1 = param_1[2];
    *(undefined4 *)(iVar1 + 0x80) = *param_2;
    *(undefined4 *)(iVar1 + 0x84) = param_2[1];
    *(undefined4 *)(iVar1 + 0x88) = param_2[2];
    iVar1 = param_1[2];
    *(undefined4 *)(iVar1 + 0x90) = *param_3;
    *(undefined4 *)(iVar1 + 0x94) = param_3[1];
    *(undefined4 *)(iVar1 + 0x98) = param_3[2];
  }
  else {
    iVar1 = *(int *)(*(int *)(*param_1 + 0x18) + *(short *)(*(int *)(param_1[1] + 0x40) + 0x40) * 4)
    ;
    if (iVar1 != 0) {
      do {
        *(undefined4 *)(iVar1 + 0x1c) = *param_2;
        *(undefined4 *)(iVar1 + 0x20) = param_2[1];
        *(undefined4 *)(iVar1 + 0x24) = param_2[2];
        *(undefined4 *)(iVar1 + 0x28) = *param_3;
        *(undefined4 *)(iVar1 + 0x2c) = param_3[1];
        *(undefined4 *)(iVar1 + 0x30) = param_3[2];
        iVar1 = *(int *)(iVar1 + 0x4c);
      } while (iVar1 != 0);
      return;
    }
  }
  return;
}

