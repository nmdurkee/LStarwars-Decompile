/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6af0; label: FUN_004f6af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f6af0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = *param_1;
  if (cVar1 != '\0') {
    pcVar2 = PTR_DAT_00800478 + 0x1ac;
    do {
      param_1 = param_1 + 1;
      *pcVar2 = cVar1;
      cVar1 = *param_1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    *pcVar2 = '\0';
    FUN_004f1e80(PTR_DAT_00800478 + 0x1ac,&DAT_0075a204);
    return;
  }
  PTR_DAT_00800478[0x1ac] = 0;
  return;
}

