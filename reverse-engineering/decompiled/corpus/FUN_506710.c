/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x506710; label: FUN_00506710
 */

void FUN_00506710(float param_1)

{
  uint uVar1;
  int unaff_ESI;
  undefined4 uVar2;
  
  if (*(byte *)(unaff_ESI + 0xdf) == *(byte *)(*(int *)(unaff_ESI + 0x5c) + 0x40)) {
    *(float *)(unaff_ESI + 0x90) = *(float *)(*(int *)(unaff_ESI + 0x58) + 8) - 1.0;
  }
  *(float *)(unaff_ESI + 0x90) =
       *(float *)(unaff_ESI + 0x90) - *(float *)(unaff_ESI + 0x98) * param_1;
  if (DAT_00921378 == 0) {
    if ((uint)*(byte *)(unaff_ESI + 0xdf) == *(byte *)(*(int *)(unaff_ESI + 0x5c) + 0x40) - 1) {
      if ((*(byte *)(unaff_ESI + 0x8c) & 0x80) == 0) {
        if (*(int *)(unaff_ESI + 0xec) == 0) {
          uVar1 = *(uint *)(unaff_ESI + 0x88);
          if ((uVar1 & 0x10000000) == 0) {
            *(uint *)(unaff_ESI + 0x88) = uVar1 | 0x10000000;
            *(undefined4 *)(unaff_ESI + 0xec) = *(undefined4 *)(unaff_ESI + 0xbc);
          }
          else {
            *(uint *)(unaff_ESI + 0x88) = uVar1 & 0xefffffff;
            *(undefined4 *)(unaff_ESI + 0xec) = *(undefined4 *)(unaff_ESI + 0xc0);
          }
          uVar2 = *(undefined4 *)(*(int *)(unaff_ESI + 0x58) + 0x2c);
        }
        else {
          uVar2 = *(undefined4 *)(*(int *)(unaff_ESI + 0x58) + 0x2c);
        }
      }
      else {
        uVar2 = *(undefined4 *)(*(int *)(unaff_ESI + 0x58) + 0x2c);
      }
      FUN_004fff20(uVar2);
      if (DAT_00800890 < 2) {
        FUN_00500830(*(undefined4 *)(unaff_ESI + 0x58),
                     *(undefined4 *)
                      (unaff_ESI + 0xbc + (*(int *)(unaff_ESI + 0x88) * 8 >> 0x1f & 1U) * 4));
      }
      else {
        FUN_00500600();
      }
      *(undefined1 *)(unaff_ESI + 0xdf) = *(undefined1 *)(*(int *)(unaff_ESI + 0x58) + 0x40);
      FUN_00505f20();
      *(float *)(unaff_ESI + 0x90) = *(float *)(*(int *)(unaff_ESI + 0x58) + 8) - 1.0;
      return;
    }
    *(char *)(unaff_ESI + 0xdf) = *(char *)(*(int *)(unaff_ESI + 0x58) + 0x40) + -1;
    if ((*(uint *)(unaff_ESI + 0x88) & 0x10000000) != 0) {
      *(undefined4 *)(unaff_ESI + 0xec) = *(undefined4 *)(unaff_ESI + 0xbc);
      DAT_00921378 = unaff_ESI;
      return;
    }
    *(undefined4 *)(unaff_ESI + 0xec) = *(undefined4 *)(unaff_ESI + 0xc0);
    DAT_00921378 = unaff_ESI;
  }
  return;
}

