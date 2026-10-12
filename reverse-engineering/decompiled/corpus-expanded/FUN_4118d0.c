/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x4118d0; label: FUN_004118d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004118d0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 6;
  iVar1 = 0x78;
  while (((DAT_0093d7f0 == 0 || (*(float *)(DAT_0093d7f0 + 0x69c) <= *(float *)(iVar1 + 0x7f127c)))
         && ((DAT_0093d7f4 == 0 ||
             (*(float *)(DAT_0093d7f4 + 0x69c) <= *(float *)(iVar1 + 0x7f127c)))))) {
    iVar1 = iVar1 + -0x14;
    iVar2 = iVar2 + -1;
    if (iVar1 == -0x14) {
      FUN_00652590(0);
      return;
    }
  }
  FUN_00695ef0(2,*(undefined4 *)(iVar2 * 0x14 + 0x7f1280));
  FUN_00695ef0(0x20,*(undefined4 *)(iVar2 * 0x14 + 0x7f1280));
  if (iVar2 == -1) {
    FUN_00652590(0);
  }
  return;
}

