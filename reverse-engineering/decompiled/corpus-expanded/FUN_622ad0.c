/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x622ad0; label: FUN_00622ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00622ad0(char *param_1)

{
  int iVar1;
  int iVar2;
  
  DAT_029130a0 = 0;
  iVar2 = 0;
  FUN_004f8de0(param_1);
  if (*param_1 != '\0') {
    do {
      param_1 = (char *)FUN_00622900(param_1,&DAT_02912b48 + (iVar2 + DAT_029130a0 * 8) * 0xc);
      if (*param_1 == '|') {
        iVar1 = iVar2 + DAT_029130a0 * 8;
        DAT_029130a0 = DAT_029130a0 + 1;
        iVar2 = 0;
        (&DAT_02912b54)[iVar1 * 0xc] = 0;
        param_1 = param_1 + 1;
      }
      else {
        iVar2 = iVar2 + 1;
      }
    } while (*param_1 != '\0');
    if (iVar2 != 0) {
      DAT_029130a0 = DAT_029130a0 + 1;
    }
  }
  return;
}

