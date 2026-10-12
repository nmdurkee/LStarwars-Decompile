/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x609ce0; label: FUN_00609ce0
 */

undefined4 FUN_00609ce0(int *param_1)

{
  int *in_ECX;
  
  if ((*in_ECX == 0) || (*in_ECX != *param_1)) {
    FUN_006e9fe6();
  }
  return CONCAT31((int3)((uint)in_ECX[1] >> 8),in_ECX[1] != param_1[1]);
}

