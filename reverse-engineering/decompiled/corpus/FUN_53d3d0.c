/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53d3d0; label: FUN_0053d3d0
 */

void FUN_0053d3d0(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[1] != 0) {
    FUN_004ef660(in_ECX[3] + in_ECX[1],param_1,2);
    if (*in_ECX != 0) {
      FUN_00621180(in_ECX[3] + in_ECX[1]);
    }
    in_ECX[3] = in_ECX[3] + 2;
  }
  return;
}

