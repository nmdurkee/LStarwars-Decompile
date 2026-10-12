/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f1730; label: FUN_004f1730
 */

undefined4 FUN_004f1730(void)

{
  float *in_ECX;
  float *in_EDX;
  
  if ((((*in_ECX < in_EDX[1]) && (*in_EDX < in_ECX[1])) && (in_ECX[3] < in_EDX[2])) &&
     (in_EDX[3] < in_ECX[2])) {
    return 1;
  }
  return 0;
}

