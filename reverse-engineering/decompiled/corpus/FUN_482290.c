/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x482290; label: FUN_00482290
 */

void FUN_00482290(int param_1)

{
  undefined4 *in_ECX;
  ushort in_DX;
  
  *(ushort *)(param_1 + 0x5a) = in_DX;
  *(undefined4 *)(param_1 + 0x748) = *in_ECX;
  *(undefined4 *)(param_1 + 0x74c) = in_ECX[1];
  *(undefined4 *)(param_1 + 0x750) = in_ECX[2];
  *(float *)(param_1 + 0x754) =
       *(float *)(param_1 + 0x748) -
       (float)(&DAT_029899a0)[in_DX >> 1] * *(float *)(param_1 + 0x1dc);
  *(undefined4 *)(param_1 + 0x758) = *(undefined4 *)(param_1 + 0x74c);
  *(float *)(param_1 + 0x75c) =
       *(float *)(param_1 + 0x750) -
       (float)(&DAT_029899a0)[(int)(in_DX + 0x4000) >> 1 & 0x7fff] * *(float *)(param_1 + 0x1dc);
  return;
}

