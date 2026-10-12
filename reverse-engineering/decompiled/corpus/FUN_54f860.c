/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54f860; label: FUN_0054f860
 */

undefined4 FUN_0054f860(int param_1)

{
  float fVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(char *)(param_1 + 0x7b3) == '\x01') {
    *(float *)(param_1 + 0xf18) = (*(float *)(param_1 + 0x748) - *(float *)(param_1 + 400)) * 20.0;
    *(float *)(param_1 + 0xf1c) = (*(float *)(param_1 + 0x74c) - *(float *)(param_1 + 0x194)) * 20.0
    ;
    fVar1 = 20.0;
    local_4 = *(float *)(param_1 + 0x750);
  }
  else {
    FUN_0054f7d0(param_1,&local_c);
    fVar1 = 5.0;
    *(float *)(param_1 + 0xf18) = (local_c - *(float *)(param_1 + 400)) * 5.0;
    *(float *)(param_1 + 0xf1c) = (local_8 - *(float *)(param_1 + 0x194)) * 5.0;
  }
  *(float *)(param_1 + 0xf20) = (local_4 - *(float *)(param_1 + 0x198)) * fVar1;
  return 1;
}

