/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x7487e0; label: FUN_007487e0
 */

uint FUN_007487e0(void)

{
  int *in_ECX;
  
  if (in_ECX[3] != 0) {
    return 0;
  }
  return *(uint *)(*in_ECX + 0x1b8) >> 0x19 & 1;
}

