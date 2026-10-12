/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x622b50; label: FUN_00622b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00622b50(char *param_1)

{
  char cVar1;
  
  DAT_029130a4 = 0;
  FUN_004f8de0(param_1);
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    param_1 = (char *)FUN_00622900(param_1,&DAT_029120b8 + DAT_029130a4 * 0xc);
    if ((&DAT_029120b8)[DAT_029130a4 * 0xc] != '\0') {
      DAT_029130a4 = DAT_029130a4 + 1;
    }
    if (*param_1 == '|') {
      param_1 = param_1 + 1;
    }
    cVar1 = *param_1;
  }
  return;
}

