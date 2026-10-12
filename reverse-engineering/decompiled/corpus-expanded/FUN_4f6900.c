/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6900; label: FUN_004f6900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f6900(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = PTR_DAT_00800478 + 0xac;
  if (pcVar2 != (char *)0x0) {
    cVar1 = *pcVar2;
    while (cVar1 != '\0') {
      pcVar2 = pcVar2 + 1;
      *param_1 = cVar1;
      param_1 = param_1 + 1;
      cVar1 = *pcVar2;
    }
  }
  *param_1 = '\0';
  return;
}

