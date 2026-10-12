/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x402b80; label: FUN_00402b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00402b80(void)

{
  int iVar1;
  float fVar2;
  int unaff_ESI;
  float10 fVar3;
  
  *(undefined4 *)(unaff_ESI + 0x68) = 0;
  *(undefined4 *)(unaff_ESI + 100) = 0;
  iVar1 = unaff_ESI + 100;
  *(undefined4 *)(unaff_ESI + 0x6c) = 0x3f000000;
  FUN_005b3620(iVar1,iVar1,*(undefined2 *)(unaff_ESI + 0x5c));
  FUN_005b37d0(iVar1,iVar1,unaff_ESI + 0x10);
  FUN_0067a6d0();
  fVar3 = (float10)FUN_005506f0(0,iVar1,0x40a00000,0xffffffff);
  fVar2 = (float)fVar3;
  *(float *)(unaff_ESI + 0x68) = fVar2;
  if (fVar2 != 2e+06) {
    *(float *)(unaff_ESI + 0x68) = fVar2 + 0.005;
    FUN_0054fec0(&DAT_0292fdb8,unaff_ESI + 0x70,unaff_ESI + 0x72);
  }
  *(byte *)(unaff_ESI + 0x62) = *(byte *)(unaff_ESI + 0x62) & 0xf3 | 3;
  FUN_005b4670(unaff_ESI + 0x1c,*(undefined2 *)(unaff_ESI + 0x5c));
  FUN_005b4900(unaff_ESI + 0x1c,unaff_ESI + 0x10);
  return;
}

