/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d5050; label: FUN_006d5050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d5050(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  DAT_02975148 = 0xff;
  if (param_1 != (char *)0x0) {
    pcVar2 = &DAT_02975148;
    do {
      cVar1 = *param_1;
      *pcVar2 = cVar1;
      param_1 = param_1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (-1 < cVar1);
  }
  return;
}

