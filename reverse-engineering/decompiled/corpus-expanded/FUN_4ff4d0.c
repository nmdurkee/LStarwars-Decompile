/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ff4d0; label: FUN_004ff4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ff4d0(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = &DAT_0091f0a8;
  do {
    cVar1 = *pcVar2;
    pcVar2[param_1 + -0x91f0a8] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return;
}

