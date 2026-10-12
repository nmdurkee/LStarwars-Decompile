/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748670; label: FUN_00748670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748670(int param_1,void *param_2,size_t param_3)

{
  int *in_ECX;
  
  _memcpy((void *)(*in_ECX + param_1),param_2,param_3);
  return;
}

