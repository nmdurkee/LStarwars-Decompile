/* Ghidra pseudocode, not original source.
 * ev_9f880a640db7021abf6bd9453b6c2d9d41a7c75291a178dd1542c0e98d960678
 * Entry: 0x6b9200; label: FUN_006b9200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b9200(undefined4 *param_1,void *param_2,size_t param_3)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    _memcpy((void *)*param_1,param_2,param_3);
    return;
  }
  *param_1 = param_2;
  return;
}

