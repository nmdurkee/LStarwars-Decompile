/* Ghidra analysis pseudocode, not original source.
 * ev_eecf13eba2be62f78d2c2fac028dc2e8e01e29bc459957490b66b8c35bfd6df7
 * Entry: 0x6e8318; label: FUN_006e8318
 */

void FUN_006e8318(uint param_1)

{
  if ((0x82958f < param_1) && (param_1 < 0x8297f1)) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffff7fff;
    FUN_006f179a(((int)(param_1 - 0x829590) >> 5) + 0x10);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}

