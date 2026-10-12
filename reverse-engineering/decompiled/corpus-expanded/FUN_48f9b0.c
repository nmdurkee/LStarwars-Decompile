/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48f9b0; label: FUN_0048f9b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048f9b0(void)

{
  DAT_00876584 = 0;
  _DAT_00876588 = 0;
  if ((((DAT_007f39e4 == 0) || (PTR_DAT_00802c54 == (undefined *)0x0)) ||
      (*(int *)(PTR_DAT_00802c54 + 300) == 0)) ||
     (*(char *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x86) < '\0')) {
LAB_0048fc10:
    if (DAT_0093b324 == 0) {
      _DAT_00802d94 = 0x3f400000;
      goto LAB_0048fa10;
    }
  }
  else {
    if ('\x02' < *(char *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x86)) {
      _DAT_00876588 = 1;
      goto LAB_0048fc10;
    }
    DAT_00876584 = 1;
  }
  _DAT_00802d94 = 0x3f91eb85;
LAB_0048fa10:
  FUN_0048f740(DAT_00803784,0);
  if ((*(int *)(PTR_DAT_00802c54 + 0x130) != 0) &&
     ((*(byte *)((int)*(void **)(PTR_DAT_00802c54 + 0x130) + 0x2800) & 1) == 0)) {
    _memcpy(*(void **)(PTR_DAT_00802c54 + 0x130),PTR_DAT_00802c54 + 0x15c,0x2800);
    *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x130) + 0x2800) =
         *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x130) + 0x2800) | 1;
  }
  FUN_00573630(DAT_00803784);
  FUN_0048a430();
  DAT_0093d518 = DAT_00802bd4;
  if (DAT_0093d7f0 != 0) {
    *(undefined1 *)(DAT_0093d7f0 + 0x107f) = *(undefined1 *)(DAT_0093d7f0 + 0x107e);
  }
  DAT_0093d528 = DAT_00802bd4;
  if (DAT_0093d7f4 != 0) {
    *(undefined1 *)(DAT_0093d7f4 + 0x107f) = *(undefined1 *)(DAT_0093d7f4 + 0x107e);
  }
  DAT_0093d538 = DAT_00802bd4;
  if (DAT_0093d7f8 != 0) {
    *(undefined1 *)(DAT_0093d7f8 + 0x107f) = *(undefined1 *)(DAT_0093d7f8 + 0x107e);
  }
  DAT_0093d548 = DAT_00802bd4;
  if (DAT_0093d7fc != 0) {
    *(undefined1 *)(DAT_0093d7fc + 0x107f) = *(undefined1 *)(DAT_0093d7fc + 0x107e);
  }
  DAT_0093d558 = DAT_00802bd4;
  if (DAT_0093d800 != 0) {
    *(undefined1 *)(DAT_0093d800 + 0x107f) = *(undefined1 *)(DAT_0093d800 + 0x107e);
  }
  DAT_0093d568 = DAT_00802bd4;
  if (DAT_0093d804 != 0) {
    *(undefined1 *)(DAT_0093d804 + 0x107f) = *(undefined1 *)(DAT_0093d804 + 0x107e);
  }
  DAT_0093d578 = DAT_00802bd4;
  if (DAT_0093d808 != 0) {
    *(undefined1 *)(DAT_0093d808 + 0x107f) = *(undefined1 *)(DAT_0093d808 + 0x107e);
  }
  DAT_0093d588 = DAT_00802bd4;
  if (DAT_0093d80c != 0) {
    *(undefined1 *)(DAT_0093d80c + 0x107f) = *(undefined1 *)(DAT_0093d80c + 0x107e);
  }
  FUN_00548fb0(&DAT_0092507c,0);
  _memcpy(&DAT_0086e720,&DAT_008668c8,0x7e4c);
  FUN_005489a0();
  _DAT_0087b8b8 = 0;
  FUN_0059f970();
  DAT_0086e714 = DAT_00856bf0;
  DAT_0086e718 = DAT_00856bf4;
  DAT_0085ea74 = 0;
  DAT_009513b0 = 0;
  FUN_00575450();
  DAT_00876df4 = 0;
  DAT_00876df8 = 0;
  DAT_00951ba4 = 1;
  DAT_00882a70 = 1;
  return;
}

