/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53d360; label: FUN_0053d360
 */

void FUN_0053d360(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[1] != 0) {
    FUN_004ef660(param_1,in_ECX[2] + in_ECX[1],2);
    if (*in_ECX != 0) {
      FUN_00621180(param_1);
    }
    in_ECX[2] = in_ECX[2] + 2;
  }
  return;
}

