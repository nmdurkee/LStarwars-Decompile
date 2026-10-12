/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x6639f0; label: FUN_006639f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006639f0(undefined4 param_1,int param_2)

{
  FUN_006279f0(param_1);
  DAT_02947c18 = 0;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    *(char *)(*(int *)(DAT_0296209c +
                      *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4
                                ) * 4) + 0x2d) = *(char *)(param_2 + 0xc) + -1;
    *(undefined **)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x1c4 + DAT_029620a4) =
         (&PTR_FUN_00810940)[*(int *)(param_2 + 0xc)];
  }
  return;
}

