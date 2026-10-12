/* Ghidra pseudocode, not original source.
 * ev_291f832bd6f6d010a6248a6acee690ff87721c4cdff92148d1e7c4ba042507e6
 * Entry: 0x4fe310; label: FUN_004fe310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fe310(char *param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = param_1;
  if (*param_1 != '\0') {
    do {
      pcVar1 = pcVar1 + 1;
    } while (*pcVar1 != '\0');
    if (pcVar1 < param_1) goto LAB_004fe33c;
  }
  do {
    if (*pcVar1 == '.') {
      iVar2 = FUN_004f8b10(pcVar1,&DAT_0075ec48);
      if (iVar2 == 0) {
        FUN_004fda90(param_1,param_2,param_3,"LABEL","ENGLISH");
        return;
      }
      break;
    }
    pcVar1 = pcVar1 + -1;
  } while (param_1 <= pcVar1);
LAB_004fe33c:
  FUN_004fdf80(param_1,param_2,param_3);
  return;
}

