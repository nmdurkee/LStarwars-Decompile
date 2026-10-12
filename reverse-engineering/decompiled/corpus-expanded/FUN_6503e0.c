/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x6503e0; label: FUN_006503e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006503e0(char *param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  cVar1 = *param_1;
  while ((cVar1 != '\0' && (uVar2 < param_2))) {
    uVar2 = uVar2 + 1;
    cVar1 = param_1[uVar2];
  }
  return;
}

