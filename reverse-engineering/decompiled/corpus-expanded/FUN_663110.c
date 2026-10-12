/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x663110; label: FUN_00663110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00663110(void)

{
  int iVar1;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    if (DAT_02962b00 != 0) {
      *(undefined4 *)(iVar1 + 0xb0) = *(undefined4 *)(DAT_02962b00 + 0x54);
    }
    if (DAT_02962b04 != 0) {
      *(undefined4 *)(iVar1 + 0xb4) = *(undefined4 *)(DAT_02962b04 + 0x54);
    }
    if (DAT_02962b08 != 0) {
      *(undefined4 *)(iVar1 + 0xb8) = *(undefined4 *)(DAT_02962b08 + 0x54);
    }
    if (DAT_02962b0c != 0) {
      *(undefined4 *)(iVar1 + 0xbc) = *(undefined4 *)(DAT_02962b0c + 0x54);
    }
    FUN_00600260(iVar1);
  }
  return;
}

