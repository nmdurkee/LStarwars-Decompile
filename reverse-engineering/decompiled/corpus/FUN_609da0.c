/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x609da0; label: FUN_00609da0
 */

void FUN_00609da0(void)

{
  int *in_ECX;
  
  if (*in_ECX == 0) {
    FUN_006e9fe6();
  }
  if (*(uint *)(*in_ECX + 8) <= (uint)in_ECX[1]) {
    FUN_006e9fe6();
  }
  in_ECX[1] = in_ECX[1] + 8;
  return;
}

