/* Ghidra analysis pseudocode, not original source.
 * ev_67a1dd79f1152a4a8dc944803f9da200f64b6e45b6a6754633c37085e261482d
 * Entry: 0x410170; label: FUN_00410170
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00410170(void)

{
  int in_EAX;
  int unaff_ESI;
  bool bVar1;
  
  _DAT_00855e40 = 0x40800000;
  _DAT_00855e44 = 0x40800000;
  bVar1 = *(int *)(in_EAX + 0x128) == DAT_0087b0f8;
  _DAT_00855e48 = 0x40800000;
  _DAT_00855e4c = 0x3f800000;
  *(undefined4 *)(unaff_ESI + 0x34a0) = 0xc30d0000;
  *(undefined4 *)(unaff_ESI + 0x34a4) = 0xc2f20000;
  *(undefined4 *)(unaff_ESI + 0x34a8) = 0xc4814000;
  *(undefined4 *)(unaff_ESI + 0x34ac) = 0x3f800000;
  if (bVar1) {
    *(undefined4 *)(unaff_ESI + 0x34b0) = 0;
  }
  else {
    *(undefined **)(unaff_ESI + 0x34b0) = &DAT_007f1558;
  }
  if (((undefined4 *)(unaff_ESI + 0x636d0) != (undefined4 *)0x0) &&
     (*(int *)(unaff_ESI + 0x636d4) != 0)) {
    _memset(*(void **)(unaff_ESI + 0x636d0),0,*(int *)(unaff_ESI + 0x636d4) * 0x60);
    *(undefined4 *)(unaff_ESI + 0x636d8) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x34b4) = 0;
  *(undefined4 *)(unaff_ESI + 0x34b8) = 0;
  *(undefined4 *)(unaff_ESI + 0x34bc) = 4;
  *(int *)(unaff_ESI + 0x34cc) = unaff_ESI;
  *(undefined4 *)(unaff_ESI + 0x6372c) = 0x3f800000;
  *(undefined4 *)(unaff_ESI + 0x63730) = 0x3f800000;
  return;
}

