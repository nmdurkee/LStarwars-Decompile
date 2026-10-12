/* Ghidra pseudocode, not original source.
 * ev_eea3a7cf55e62a15d31ae8423a3c3e3cacac13ee26e2c6e4adfc577ce8b80763
 * Entry: 0x745190; label: FUN_00745190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00745190(char *param_1)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = (in_ECX + 4) - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[iVar2] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}

