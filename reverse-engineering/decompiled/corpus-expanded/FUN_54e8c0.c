/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54e8c0; label: FUN_0054e8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054e8c0(void)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  int unaff_ESI;
  
  if ((0.0 < *(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28)) ||
     ((*(float *)(unaff_ESI + 0x68) == 0.0 && (*(float *)(unaff_ESI + 0x70) == 0.0)))) {
    *(undefined2 *)(unaff_ESI + 0x7a6) = *(undefined2 *)(unaff_ESI + 0x5a);
  }
  else {
    uVar2 = FUN_005be2d0(*(undefined4 *)(unaff_ESI + 0x68),*(undefined4 *)(unaff_ESI + 0x70));
    *(undefined2 *)(unaff_ESI + 0x7a6) = uVar2;
  }
  if (DAT_00802450 == 1) {
    iVar1 = *(int *)(unaff_ESI + 0x798);
    uVar3 = FUN_00550040(*(undefined2 *)(unaff_ESI + 0x7a6),*(short *)(iVar1 + 0x20) + 0x4000);
    if ((int)((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f)) < 0x4001) {
      *(short *)(unaff_ESI + 0x7a6) = *(short *)(iVar1 + 0x20) + 0x4000;
      return;
    }
    *(short *)(unaff_ESI + 0x7a6) = *(short *)(iVar1 + 0x20) + -0x4000;
  }
  return;
}

