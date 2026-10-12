/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x662590; label: FUN_00662590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00662590(undefined4 param_1,int param_2)

{
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    *(undefined4 *)
     (*(int *)(DAT_0296209c +
              *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4) * 4) +
     0x140) = *(undefined4 *)(param_2 + 0x54);
  }
  return;
}

