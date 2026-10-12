/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x7464c0; label: FUN_007464c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_007464c0(char *param_1,int param_2)

{
  char cVar1;
  void *_Dst;
  char *pcVar2;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  _Dst = *(void **)(param_2 + 4);
  *(char **)(param_2 + 4) = pcVar2 + (int)_Dst + (1 - (int)(param_1 + 1));
  _memcpy(_Dst,param_1,(size_t)(pcVar2 + (1 - (int)(param_1 + 1))));
  return _Dst;
}

