/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0260; label: FUN_005d0260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0260(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_1[1] != 0) {
    *param_3 = *(undefined4 *)
                (*(int *)(*(int *)(*param_1 + 0x18) +
                         *(short *)(*(int *)(param_1[1] + 0x40) + 0x40) * 4) + 0x40);
    iVar1 = *(int *)(*(int *)(*param_1 + 0x18) + *(short *)(*(int *)(param_1[1] + 0x40) + 0x40) * 4)
    ;
    *param_2 = *(undefined4 *)(iVar1 + 0x34);
    param_2[1] = *(undefined4 *)(iVar1 + 0x38);
    param_2[2] = *(undefined4 *)(iVar1 + 0x3c);
    return;
  }
  iVar1 = param_1[2];
  *param_2 = *(undefined4 *)(iVar1 + 0xa0);
  param_2[1] = *(undefined4 *)(iVar1 + 0xa4);
  param_2[2] = *(undefined4 *)(iVar1 + 0xa8);
  *param_3 = *(undefined4 *)(param_1[2] + 0xac);
  return;
}

