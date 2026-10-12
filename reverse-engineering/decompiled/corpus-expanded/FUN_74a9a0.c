/* Ghidra pseudocode, not original source.
 * ev_e0447f8e73d2150c5385a8aa294440164da99c01f5f62ba5bd70b4e5b4546b39
 * Entry: 0x74a9a0; label: FUN_0074a9a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0074a9a0(char *param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  char *pcVar2;
  
  pcVar2 = (char *)*in_ECX;
  uVar1 = 0;
  if (0 < (int)in_ECX[1]) {
    do {
      if (*pcVar2 != *param_1) {
        return uVar1 & 0xffffff00;
      }
      uVar1 = uVar1 + 1;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + 1;
    } while ((int)uVar1 < (int)in_ECX[1]);
  }
  return (uint)(*param_1 == '\0');
}

