/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x580920; label: FUN_00580920
 */

void FUN_00580920(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x80);
  param_2[1] = *(undefined4 *)(param_1 + 0x84);
  param_2[2] = *(undefined4 *)(param_1 + 0x88);
  return;
}

