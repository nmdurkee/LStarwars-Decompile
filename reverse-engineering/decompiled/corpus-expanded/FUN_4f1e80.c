/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1e80; label: FUN_004f1e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f1e80(char *param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  if (param_2 != (char *)0x0) {
    do {
      *param_1 = *param_2;
      cVar1 = *param_2;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
  }
  return;
}

