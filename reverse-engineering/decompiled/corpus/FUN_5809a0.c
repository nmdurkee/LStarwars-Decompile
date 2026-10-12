/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x5809a0; label: FUN_005809a0
 */

float10 FUN_005809a0(int param_1)

{
  float fVar1;
  int iVar2;
  
  fVar1 = *(float *)(param_1 + 0xb0);
  iVar2 = FUN_0054fa60();
  return (float10)(((fVar1 + fVar1) / 65535.0) * (float)iVar2 - fVar1);
}

