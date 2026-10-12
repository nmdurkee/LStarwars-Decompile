/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x5618e0; label: FUN_005618e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005618e0(int param_1,int param_2,int param_3,char *param_4)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar1 = 0;
  pcVar2 = &DAT_00947cb8;
  iVar3 = 0x80;
  do {
    if ((((*pcVar2 != '\0') && (pcVar2[6] == param_1)) && (pcVar2 + -0xf8 != param_4)) &&
       (((param_3 == -1 || (pcVar2[5] == param_3)) && (iVar1 = iVar1 + 1, param_2 != 0)))) {
      *pcVar2 = '\0';
    }
    pcVar2 = pcVar2 + 0x114;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar1;
}

