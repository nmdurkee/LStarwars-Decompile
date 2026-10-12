/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x514ec0; label: FUN_00514ec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00514ec0(int param_1)

{
  int in_stack_00000014;
  
  if (((param_1 != 0) && (in_stack_00000014 != 0)) &&
     (((*(int *)(param_1 + 0x138c) != 0 &&
       ((int)*(short *)(*(int *)(*(int *)(param_1 + 0x138c) + 4) + 0x124) ==
        (in_stack_00000014 - *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 8) + 0x7c)) / 0x5c)) ||
      ((*(int *)(param_1 + 0x1390) != 0 &&
       ((int)*(short *)(*(int *)(*(int *)(param_1 + 0x1390) + 4) + 0x124) ==
        (in_stack_00000014 - *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 8) + 0x7c)) / 0x5c)))))) {
    return (float10)1;
  }
  return (float10)0;
}

