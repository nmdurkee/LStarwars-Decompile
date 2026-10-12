/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ff4b0; label: FUN_004ff4b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ff4b0(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (int)&DAT_0091f0a8 - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[iVar2] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}

