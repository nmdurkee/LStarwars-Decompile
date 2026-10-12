/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x508d50; label: FUN_00508d50
 */

void FUN_00508d50(void)

{
  uint uVar1;
  int unaff_ESI;
  
  uVar1 = *(uint *)(unaff_ESI + 0x88);
  if ((((uVar1 & 0x800) == 0) && ((uVar1 & 2) != 0)) && ((uVar1 & 0x400) != 0)) {
    if ((uVar1 & 0x40000) == 0) {
      if ((DAT_00800898 != 0) && (*(int *)(unaff_ESI + 0xa0) != 0)) {
        FUN_00507f20();
      }
      if ((DAT_0080089c != 0) && (*(int *)(unaff_ESI + 0xa4) != 0)) {
        FUN_00502c30();
      }
      if (((((*(byte *)(unaff_ESI + 0x8c) & 0x40) == 0) ||
           (*(float *)(*(int *)(unaff_ESI + 0x58) + 8) - 1.0 != *(float *)(unaff_ESI + 0x90))) &&
          ((*(uint *)(unaff_ESI + 0x88) & 0x40000000) == 0)) &&
         ((DAT_008008a0 != 0 && (*(int *)(unaff_ESI + 0xa8) != 0)))) {
        FUN_00508c30();
      }
    }
    else {
      if ((DAT_00800898 != 0) && (*(int *)(unaff_ESI + 0xa0) != 0)) {
        FUN_00507f20();
      }
      if ((DAT_0080089c != 0) && (*(int *)(unaff_ESI + 0xa4) != 0)) {
        FUN_00502c30();
      }
      if (((((*(byte *)(unaff_ESI + 0x8c) & 0x40) == 0) ||
           (*(float *)(*(int *)(unaff_ESI + 0x58) + 8) - 1.0 != *(float *)(unaff_ESI + 0x90))) &&
          ((*(uint *)(unaff_ESI + 0x88) & 0x40000000) == 0)) &&
         ((DAT_008008a0 != 0 && (*(int *)(unaff_ESI + 0xa8) != 0)))) {
        FUN_00508c30();
        return;
      }
    }
  }
  return;
}

