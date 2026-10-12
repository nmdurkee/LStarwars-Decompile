/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62d500; label: FUN_0062d500
 */

void FUN_0062d500(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  if (0 < *DAT_029130e4) {
    iVar3 = 0;
    piVar2 = DAT_029130e4;
    do {
      if ((*(byte *)(piVar2[8] + 4 + iVar3) & 2) == 0) {
        *(undefined2 *)(piVar2[7] + iVar1 * 2) = 0xffff;
        piVar2 = DAT_029130e4;
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x4c;
    } while (iVar1 < *piVar2);
  }
  return;
}

