/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x564570; label: FUN_00564570
 */

void FUN_00564570(void)

{
  DAT_009506fc = FUN_005e4d00(1);
  *(uint *)(DAT_009506fc + 0x40) = *(uint *)(DAT_009506fc + 0x40) | 0xc000;
  *(uint *)(DAT_009506fc + 0x40) = *(uint *)(DAT_009506fc + 0x40) & 0xffffffdf | 0x10;
  *(uint *)(DAT_009506fc + 0x40) = *(uint *)(DAT_009506fc + 0x40) & 0xfffeffff | 0x20000;
  *(uint *)(DAT_009506fc + 0x40) = *(uint *)(DAT_009506fc + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(DAT_009506fc + 0x40) = *(uint *)(DAT_009506fc + 0x40) & 0xfffff7ff | 0x400;
  *(uint *)(DAT_009506fc + 0x40) = *(uint *)(DAT_009506fc + 0x40) | 0x40000;
  *(uint *)(DAT_009506fc + 0x40) = *(uint *)(DAT_009506fc + 0x40) & 0xfffffff3 | 3;
  FUN_005e4b00(DAT_009506fc);
  DAT_00950700 = FUN_005e4d00(1);
  *(uint *)(DAT_00950700 + 0x40) = *(uint *)(DAT_00950700 + 0x40) | 0xc000;
  *(uint *)(DAT_00950700 + 0x40) = *(uint *)(DAT_00950700 + 0x40) & 0xffffffdf | 0x10;
  *(uint *)(DAT_00950700 + 0x40) = *(uint *)(DAT_00950700 + 0x40) & 0xfffeffff | 0x20000;
  *(uint *)(DAT_00950700 + 0x40) = *(uint *)(DAT_00950700 + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(DAT_00950700 + 0x40) = *(uint *)(DAT_00950700 + 0x40) & 0xfffff7ff | 0x400;
  *(uint *)(DAT_00950700 + 0x40) = *(uint *)(DAT_00950700 + 0x40) | 0x40000;
  *(uint *)(DAT_00950700 + 0x40) = *(uint *)(DAT_00950700 + 0x40) & 0xfffffff1 | 1;
  FUN_005e4b00(DAT_00950700);
  DAT_00950704 = FUN_005e4d00(1);
  *(uint *)(DAT_00950704 + 0x40) = *(uint *)(DAT_00950704 + 0x40) | 0xc000;
  *(uint *)(DAT_00950704 + 0x40) = *(uint *)(DAT_00950704 + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(DAT_00950704 + 0x40) = *(uint *)(DAT_00950704 + 0x40) & 0xfffff7ff | 0x400;
  *(uint *)(DAT_00950704 + 0x40) = *(uint *)(DAT_00950704 + 0x40) & 0xffffffdf | 0x10;
  *(uint *)(DAT_00950704 + 0x40) = *(uint *)(DAT_00950704 + 0x40) & 0xfffeffff | 0x20000;
  *(uint *)(DAT_00950704 + 0x40) = *(uint *)(DAT_00950704 + 0x40) | 0x40000;
  *(undefined4 *)(DAT_00950704 + 0x70) = 0x3f800000;
  *(uint *)(DAT_00950704 + 0x40) = *(uint *)(DAT_00950704 + 0x40) & 0xfffffff1 | 1;
  *(undefined2 *)(DAT_00950704 + 0x74) = 0;
  *(undefined2 *)(DAT_00950704 + 0x76) = 0x7ffe;
  FUN_005e4b00(DAT_00950704);
  return;
}

