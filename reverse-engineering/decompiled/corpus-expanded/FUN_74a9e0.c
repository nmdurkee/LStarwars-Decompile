/* Ghidra pseudocode, not original source.
 * ev_e0447f8e73d2150c5385a8aa294440164da99c01f5f62ba5bd70b4e5b4546b39
 * Entry: 0x74a9e0; label: FUN_0074a9e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_0074a9e0(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined4 *in_ECX;
  char *pcVar3;
  
  pcVar3 = (char *)*in_ECX;
  cVar1 = *param_1;
  while( true ) {
    if (cVar1 == '\0') {
      return 1;
    }
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    param_1 = param_1 + 1;
    if (cVar1 != cVar2) break;
    cVar1 = *param_1;
  }
  return 0;
}

