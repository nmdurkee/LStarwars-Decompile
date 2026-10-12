/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4ab350; label: FUN_004ab350
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ab350(void)

{
  undefined4 uVar1;
  float fVar2;
  int unaff_ESI;
  
  if (*(char *)(unaff_ESI + 0x280) != -1) {
    if ((((*(uint *)(unaff_ESI + 0xe20) & 0x20) != 0) || (*(char *)(unaff_ESI + 0x285) != '\x14'))
       || (_DAT_007fc18c <= *(float *)(unaff_ESI + 0x17c) - *(float *)(unaff_ESI + 0x21c))) {
      *(uint *)(unaff_ESI + 0xe20) = *(uint *)(unaff_ESI + 0xe20) & 0xfffffffe;
      if ((0.0 < *(float *)(unaff_ESI + 0x1038)) &&
         (fVar2 = *(float *)(unaff_ESI + 0x1038) - _DAT_00925018,
         *(float *)(unaff_ESI + 0x1038) = fVar2, fVar2 < 0.0)) {
        *(undefined4 *)(unaff_ESI + 0x1038) = 0;
      }
    }
    else {
      FUN_0054a8a0(**(undefined4 **)(unaff_ESI + 0xca4),0x3dcccccd,0);
      FUN_0054a850(**(undefined4 **)(unaff_ESI + 0xca4),0x3f000000,0);
      uVar1 = _DAT_007fc188;
      if (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087b014) {
        uVar1 = _DAT_007fc180;
      }
      *(undefined4 *)(unaff_ESI + 0xc44) = uVar1;
      *(undefined4 *)(unaff_ESI + 0x1038) = 0x3f800000;
      if ((*(byte *)(unaff_ESI + 0xe20) & 1) == 0) {
        FUN_00681f40("PodX_Booster",unaff_ESI + 0x80);
        *(uint *)(unaff_ESI + 0xe20) = *(uint *)(unaff_ESI + 0xe20) | 1;
      }
    }
    if (1.0 < *(float *)(unaff_ESI + 0xc44)) {
      FUN_0054a850(**(undefined4 **)(unaff_ESI + 0xca4),*(float *)(unaff_ESI + 0xc44) - 1.0,0);
    }
  }
  return;
}

