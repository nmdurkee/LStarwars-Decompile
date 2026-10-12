/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x621cc0; label: FUN_00621cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621cc0(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar5 = DAT_02913054;
  puVar6 = PTR_DAT_0080facc;
  do {
    if (param_1 < 1) {
      return;
    }
    iVar3 = 0;
    if (puVar6 == &DAT_02900c88) {
      iVar3 = 0;
    }
    else {
      pcVar2 = puVar6 + -2;
      cVar1 = puVar6[-2];
      while (cVar1 != '\0') {
        if (pcVar2 == &DAT_02900c88) {
          iVar3 = iVar3 + 2;
          goto LAB_00621d15;
        }
        pcVar2 = pcVar2 + -1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      }
      iVar3 = iVar3 + 1;
    }
LAB_00621d15:
    iVar4 = 0;
    if (PTR_DAT_0080fad0 == &DAT_02900c88) {
      iVar4 = 0;
    }
    else {
      pcVar2 = PTR_DAT_0080fad0 + -2;
      cVar1 = PTR_DAT_0080fad0[-2];
      while (cVar1 != '\0') {
        if (pcVar2 == &DAT_02900c88) {
          iVar4 = iVar4 + 2;
          goto LAB_00621d46;
        }
        pcVar2 = pcVar2 + -1;
        iVar4 = iVar4 + 1;
        cVar1 = *pcVar2;
      }
      iVar4 = iVar4 + 1;
    }
LAB_00621d46:
    if (PTR_DAT_0080fad0 == puVar6) {
      puVar6 = puVar6 + -iVar3;
      PTR_DAT_0080facc = puVar6;
      if (iVar5 != 0) {
        iVar5 = iVar5 + -1;
        DAT_02913054 = iVar5;
      }
    }
    else {
      DAT_02913050 = DAT_02913050 + -1;
    }
    PTR_DAT_0080fad0 = PTR_DAT_0080fad0 + -iVar4;
    param_1 = param_1 + -1;
  } while( true );
}

