/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54d1d0; label: FUN_0054d1d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054d1d0(void)

{
  float fVar1;
  int unaff_ESI;
  
  FUN_0054d100(unaff_ESI + 0x10,*(undefined1 *)(unaff_ESI + 0x1c));
  if (((*(float *)(unaff_ESI + 0x28) != 2e+06) &&
      (fVar1 = *(float *)(unaff_ESI + 0x34) - (*(float *)(unaff_ESI + 0x28) + 0.1),
      fVar1 < *(float *)(unaff_ESI + 0x50))) && (*(float *)(unaff_ESI + 0x50) = fVar1, fVar1 < 0.7))
  {
    *(undefined4 *)(unaff_ESI + 0x50) = 0x3f333333;
  }
  FUN_0054d000();
  *(undefined4 *)(unaff_ESI + 0x5c) = *(undefined4 *)(unaff_ESI + 0xa4);
  *(undefined4 *)(unaff_ESI + 0x60) = *(undefined4 *)(unaff_ESI + 0xa8);
  *(undefined4 *)(unaff_ESI + 100) = *(undefined4 *)(unaff_ESI + 0xac);
  *(undefined4 *)(unaff_ESI + 0x68) = *(undefined4 *)(unaff_ESI + 0xb0);
  *(undefined4 *)(unaff_ESI + 0x6c) = *(undefined4 *)(unaff_ESI + 0xb4);
  *(undefined4 *)(unaff_ESI + 0x70) = *(undefined4 *)(unaff_ESI + 0xb8);
  *(undefined4 *)(unaff_ESI + 0x74) = *(undefined4 *)(unaff_ESI + 0xbc);
  *(undefined4 *)(unaff_ESI + 0x78) = *(undefined4 *)(unaff_ESI + 0xc0);
  *(undefined4 *)(unaff_ESI + 0x7c) = *(undefined4 *)(unaff_ESI + 0xc4);
  *(undefined4 *)(unaff_ESI + 0x80) = *(undefined4 *)(unaff_ESI + 200);
  *(undefined4 *)(unaff_ESI + 0x84) = *(undefined4 *)(unaff_ESI + 0xcc);
  *(undefined4 *)(unaff_ESI + 0x88) = *(undefined4 *)(unaff_ESI + 0xd0);
  *(undefined4 *)(unaff_ESI + 0x8c) = *(undefined4 *)(unaff_ESI + 0xd4);
  *(undefined4 *)(unaff_ESI + 0x90) = *(undefined4 *)(unaff_ESI + 0xd8);
  *(undefined4 *)(unaff_ESI + 0x94) = *(undefined4 *)(unaff_ESI + 0xdc);
  *(undefined4 *)(unaff_ESI + 0x98) = *(undefined4 *)(unaff_ESI + 0xe0);
  *(undefined4 *)(unaff_ESI + 0x9c) = *(undefined4 *)(unaff_ESI + 0xe4);
  *(undefined4 *)(unaff_ESI + 0xa0) = *(undefined4 *)(unaff_ESI + 0xe8);
  *(undefined4 *)(unaff_ESI + 0x58) = 0;
  *(byte *)(unaff_ESI + 0x1e) = *(byte *)(unaff_ESI + 0x1e) | 3;
  *(undefined1 *)(unaff_ESI + 0x1c) = 0;
  return;
}

