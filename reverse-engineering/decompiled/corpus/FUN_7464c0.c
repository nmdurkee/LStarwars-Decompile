/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x7464c0; label: FUN_007464c0
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

