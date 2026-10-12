/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62b6a0; label: FUN_0062b6a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062b6a0(void)

{
  uint uVar1;
  uint uVar2;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar3;
  ushort local_4;
  
  fVar3 = (float10)FUN_005b9dd0();
  local_4 = (ushort)(int)ROUND(fVar3 * (float10)65536.0);
  uVar2 = (int)ROUND(fVar3 * (float10)65536.0) & 0xffff;
  uVar1 = *(uint *)(unaff_ESI + 0x1fc) >> 1 & 1;
  if ((uVar1 != 0) && ((*(byte *)(unaff_EDI + 0x1fc) & 2) == 0)) {
    *(float *)(unaff_EDI + 0x68) = (float)(&DAT_029899a0)[local_4 >> 1] * 4.0;
    *(float *)(unaff_EDI + 0x70) = (float)(&DAT_029899a0)[(int)(uVar2 + 0x4000) >> 1 & 0x7fff] * 4.0
    ;
    *(undefined4 *)(unaff_EDI + 0x200) = *(undefined4 *)(unaff_EDI + 0x68);
    *(undefined4 *)(unaff_EDI + 0x208) = *(undefined4 *)(unaff_EDI + 0x70);
    *(undefined4 *)(unaff_ESI + 0x200) = *(undefined4 *)(unaff_ESI + 0x68);
    *(undefined4 *)(unaff_ESI + 0x208) = *(undefined4 *)(unaff_ESI + 0x70);
    return;
  }
  if ((uVar1 == 0) && ((*(byte *)(unaff_EDI + 0x1fc) & 2) != 0)) {
    *(float *)(unaff_ESI + 0x68) = (float)(&DAT_029899a0)[local_4 >> 1] * 4.0;
    *(float *)(unaff_ESI + 0x70) = (float)(&DAT_029899a0)[(int)(uVar2 + 0x4000) >> 1 & 0x7fff] * 4.0
    ;
    *(undefined4 *)(unaff_ESI + 0x200) = *(undefined4 *)(unaff_ESI + 0x68);
    *(undefined4 *)(unaff_ESI + 0x208) = *(undefined4 *)(unaff_ESI + 0x70);
  }
  else {
    *(float *)(unaff_ESI + 0x68) = (float)(&DAT_029899a0)[local_4 >> 1] * 2.0;
    *(float *)(unaff_ESI + 0x70) = (float)(&DAT_029899a0)[(int)(uVar2 + 0x4000) >> 1 & 0x7fff] * 2.0
    ;
    *(undefined4 *)(unaff_ESI + 0x200) = *(undefined4 *)(unaff_ESI + 0x68);
    *(undefined4 *)(unaff_ESI + 0x208) = *(undefined4 *)(unaff_ESI + 0x70);
    *(float *)(unaff_EDI + 0x68) = -*(float *)(unaff_ESI + 0x68);
    *(float *)(unaff_EDI + 0x70) = -*(float *)(unaff_ESI + 0x70);
  }
  *(undefined4 *)(unaff_EDI + 0x200) = *(undefined4 *)(unaff_EDI + 0x68);
  *(undefined4 *)(unaff_EDI + 0x208) = *(undefined4 *)(unaff_EDI + 0x70);
  return;
}

