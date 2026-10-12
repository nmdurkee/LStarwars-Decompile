/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x68dc70; label: FUN_0068dc70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068dc70(undefined4 param_1,int param_2)

{
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    *(undefined4 *)
     (*(int *)(DAT_0296209c +
              *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4) * 4) +
     0x24) = *(undefined4 *)(param_2 + 0x54);
    FUN_0068cfd0();
  }
  return;
}

