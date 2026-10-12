/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50d680; label: FUN_0050d680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050d680(void)

{
  DAT_009213f0 = FUN_005e4d00(1);
  *(uint *)(DAT_009213f0 + 0x40) = *(uint *)(DAT_009213f0 + 0x40) | 0xc000;
  *(uint *)(DAT_009213f0 + 0x40) = *(uint *)(DAT_009213f0 + 0x40) & 0xffffffdf | 0x10;
  *(uint *)(DAT_009213f0 + 0x40) = *(uint *)(DAT_009213f0 + 0x40) & 0xfffeffff | 0x20000;
  *(uint *)(DAT_009213f0 + 0x40) = *(uint *)(DAT_009213f0 + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(DAT_009213f0 + 0x40) = *(uint *)(DAT_009213f0 + 0x40) & 0xfffff7ff | 0x400;
  *(uint *)(DAT_009213f0 + 0x40) = *(uint *)(DAT_009213f0 + 0x40) | 0x40000;
  *(uint *)(DAT_009213f0 + 0x40) = *(uint *)(DAT_009213f0 + 0x40) & 0xfffffff1 | 1;
  FUN_005e4b00(DAT_009213f0);
  _DAT_00921ecc = 1;
  return;
}

