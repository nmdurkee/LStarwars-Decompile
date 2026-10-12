/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x4212e0; label: FUN_004212e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004212e0(int *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)param_1[2];
  iVar3 = *param_1;
  iVar1 = 0;
  if (0 < iVar3) {
    do {
      if (((*pcVar2 == '\x02') || (*pcVar2 == '\0')) &&
         (((pcVar2[3] & 0x20U) == 0 || ((pcVar2[3] & 0x40U) == 0)))) {
        iVar1 = iVar1 + 1;
      }
      pcVar2 = pcVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1;
}

