/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x5618e0; label: FUN_005618e0
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

