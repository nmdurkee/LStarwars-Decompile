/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d3b30; label: FUN_006d3b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d3b30(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  FUN_004ef660(param_2,param_1,0x3f);
  param_2[0x3f] = '\0';
  cVar1 = *param_2;
  pcVar2 = param_2;
  while (cVar1 != '\0') {
    cVar1 = *param_2;
    if (((('`' < cVar1) && (cVar1 < '{')) || (('@' < cVar1 && (cVar1 < '[')))) ||
       ((('/' < cVar1 && (cVar1 < ':')) || (cVar1 == '_')))) {
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
    }
    param_2 = param_2 + 1;
    cVar1 = *param_2;
  }
  *pcVar2 = '\0';
  return;
}

