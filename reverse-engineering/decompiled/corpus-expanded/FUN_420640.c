/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x420640; label: FUN_00420640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00420640(int param_1,int param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  
  pcVar1 = (char *)(*(int *)(param_1 + 8) + param_2 * 8);
  cVar2 = *pcVar1;
  bVar3 = pcVar1[3];
  if (((bVar3 & 0x10) == 0) && ((cVar2 == '\0' || (cVar2 == '\x02')))) {
    if (param_3 == 0) {
      bVar3 = bVar3 & 0x20;
    }
    else {
      if (param_3 != 1) {
        return 1;
      }
      bVar3 = bVar3 & 0x40;
    }
    if (bVar3 == 0) {
      return 1;
    }
  }
  return 0;
}

