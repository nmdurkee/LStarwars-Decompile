/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42d220; label: FUN_0042d220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042d220(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00956298 == 0) {
    return;
  }
  iVar2 = 0;
  if (0 < DAT_00956294) {
    iVar1 = 0;
    do {
      *(undefined1 *)(iVar1 + 8 + DAT_00956298) = 1;
      if (*(int *)(iVar1 + 4 + DAT_00956298) == 0) {
        *(undefined4 *)(iVar1 + 4 + DAT_00956298) = 0x12d680;
      }
      if (*(float *)(iVar1 + DAT_00956298) <= 0.0) {
        *(undefined4 *)(iVar1 + DAT_00956298) = 0x4560ec29;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xc;
    } while (iVar2 < DAT_00956294);
  }
  FUN_0042b080();
  return;
}

