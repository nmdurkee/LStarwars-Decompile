/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x603ad0; label: FUN_00603ad0
 */

void FUN_00603ad0(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  
  fVar1 = 0.0;
  if ((0.0 <= param_3) && (fVar1 = param_3, 1.0 < param_3)) {
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x3c) = 0x3f800000;
    return;
  }
  *(float *)(*(int *)(param_1 + 4) + 0x3c) = fVar1;
  return;
}

