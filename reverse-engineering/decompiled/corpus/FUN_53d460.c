/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53d460; label: FUN_0053d460
 */

void FUN_0053d460(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  *in_ECX = *param_1;
  if (in_ECX[1] != 0) {
    piVar1 = (int *)(in_ECX[1] + 0x4b0);
    *piVar1 = *piVar1 + 1;
    return;
  }
  FUN_0060f2d0();
  return;
}

