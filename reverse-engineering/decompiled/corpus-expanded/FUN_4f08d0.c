/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f08d0; label: FUN_004f08d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

size_t FUN_004f08d0(char *param_1,char *param_2)

{
  char *pcVar1;
  size_t _Count;
  char *_Source;
  
  pcVar1 = _strrchr(param_2,0x5c);
  _Source = param_2;
  if (pcVar1 != (char *)0x0) {
    _Source = pcVar1 + 1;
  }
  pcVar1 = _strrchr(param_2,0x2e);
  if (pcVar1 == (char *)0x0) {
    do {
      pcVar1 = param_2;
      param_2 = pcVar1 + 1;
    } while (*pcVar1 != '\0');
  }
  _Count = (int)pcVar1 - (int)_Source;
  _strncpy(param_1,_Source,_Count);
  param_1[_Count] = '\0';
  return _Count;
}

