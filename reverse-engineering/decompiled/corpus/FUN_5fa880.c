/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5fa880; label: FUN_005fa880
 */

undefined4 FUN_005fa880(int *param_1,int *param_2)

{
  int iVar1;
  char *pcVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  do {
    pcVar2 = (char *)(*(int *)(unaff_EDI + 0x10) + 3 +
                     (*(int *)(unaff_EDI + 4) * *param_2 + *param_1) * 4);
    iVar1 = 0;
    if (unaff_ESI < 1) {
      return 1;
    }
    while( true ) {
      if (*(int *)(unaff_EDI + 8) <= *param_2 + iVar1) {
        return 1;
      }
      if (*pcVar2 != '\0') break;
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar2 + *(int *)(unaff_EDI + 4) * 4;
      if (unaff_ESI <= iVar1) {
        return 1;
      }
    }
    iVar1 = *param_1;
    *param_1 = iVar1 + 1;
    if (*(int *)(unaff_EDI + 4) <= iVar1 + 1) {
      *param_1 = 0;
      *param_2 = *param_2 + unaff_ESI;
      if (*(int *)(unaff_EDI + 8) <= *param_2 + unaff_ESI) {
        return 0;
      }
    }
  } while( true );
}

