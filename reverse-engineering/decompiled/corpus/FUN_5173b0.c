/* Ghidra analysis pseudocode, not original source.
 * ev_e9352ae8b4f9815c7bd33078f32d38974dd715693a5fa54abaaf9429a7276350
 * Entry: 0x5173b0; label: FUN_005173b0
 */

undefined4 FUN_005173b0(int param_1,float *param_2)

{
  if ((((*(float *)(param_1 + 0x90) <= *param_2) && (*(float *)(param_1 + 0x94) <= param_2[1])) &&
      (*(float *)(param_1 + 0x98) <= param_2[2])) &&
     (((*param_2 <= *(float *)(param_1 + 0x9c) && (param_2[1] <= *(float *)(param_1 + 0xa0))) &&
      (param_2[2] <= *(float *)(param_1 + 0xa4))))) {
    return 1;
  }
  return 0;
}

