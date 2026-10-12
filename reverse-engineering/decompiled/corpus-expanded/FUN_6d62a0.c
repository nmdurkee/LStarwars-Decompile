/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d62a0; label: FUN_006d62a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d62a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char *param_5)

{
  char cVar1;
  char *pcVar2;
  
  FUN_006d61b0(3,param_1);
  FUN_006d61b0(1,param_2);
  FUN_006d61b0(4,param_3);
  FUN_006d61b0(2,param_4);
  DAT_02975148 = 0xff;
  if (param_5 != (char *)0x0) {
    pcVar2 = &DAT_02975148;
    do {
      cVar1 = *param_5;
      *pcVar2 = cVar1;
      param_5 = param_5 + 1;
      pcVar2 = pcVar2 + 1;
    } while (-1 < cVar1);
  }
  return;
}

