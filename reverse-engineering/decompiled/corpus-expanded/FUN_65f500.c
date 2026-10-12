/* Ghidra pseudocode, not original source.
 * ev_3c91a6b80548833a29ecc2d389e89e55b74ab0261b3e94a742c4850371a9aab1
 * Entry: 0x65f500; label: FUN_0065f500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0065f500(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  if (0 < DAT_02962a08) {
    piVar2 = (int *)(DAT_02962a14 + 4);
    iVar3 = DAT_02962a08;
    do {
      if (*piVar2 != 0) {
        iVar1 = iVar1 + *piVar2;
      }
      piVar2 = piVar2 + 0x14;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1 * 0x4c + 0x10;
}

