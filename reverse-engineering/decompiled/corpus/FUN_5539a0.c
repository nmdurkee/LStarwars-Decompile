/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x5539a0; label: FUN_005539a0
 */

void FUN_005539a0(void)

{
  int iVar1;
  int unaff_ESI;
  float local_30 [2];
  float local_28;
  float local_24 [2];
  float local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  FUN_005d0130(unaff_ESI + 0x50,local_24,local_30);
  iVar1 = FUN_005d0450(&DAT_0093b118,unaff_ESI + 0x50);
  if (iVar1 != 0) {
    FUN_005d0130(&DAT_0093b10c,local_18,local_c);
    FUN_005b37d0(local_24,local_24,local_18);
    FUN_005b37d0(local_30,local_30,local_c);
  }
  local_28 = local_28 - local_1c;
  if (local_28 < local_30[0] - local_24[0]) {
    local_28 = local_30[0] - local_24[0];
  }
  *(float *)(unaff_ESI + 0x94) = local_28;
  *(uint *)(unaff_ESI + 0x84) = *(uint *)(unaff_ESI + 0x84) | 8;
  *(undefined4 *)(unaff_ESI + 0x78) = 0x3f800000;
  *(undefined1 *)(unaff_ESI + 0x8b) = 4;
  *(undefined4 *)(unaff_ESI + 0x2dc) = 0x3f800000;
  *(undefined2 *)(unaff_ESI + 0x8c) = 0;
  *(undefined2 *)(unaff_ESI + 0x7c) = *(undefined2 *)(unaff_ESI + 0x82);
  *(undefined1 *)(unaff_ESI + 0xa4) = 1;
  *(float *)(unaff_ESI + 0x9c) = *(float *)(unaff_ESI + 0x94) * 0.5;
  *(float *)(unaff_ESI + 0x94) = *(float *)(unaff_ESI + 0x94) * 0.4;
  *(undefined4 *)(unaff_ESI + 0x98) = 0;
  return;
}

