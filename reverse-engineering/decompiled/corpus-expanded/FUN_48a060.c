/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x48a060; label: FUN_0048a060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0048a060(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = FUN_004f1ff0(param_2);
    if (iVar1 < 0x10) {
      iVar4 = 0;
      iVar1 = param_1 + 0x2d68;
      do {
        iVar2 = FUN_004f8b10(iVar1,param_2);
        if (iVar2 == 0) {
          if (iVar4 < 0xc) {
            if (param_3 != 0) {
              *(undefined1 *)(iVar4 * 0x10 + 0x2d68 + param_1) = 0;
              return 2;
            }
            return 3;
          }
          break;
        }
        iVar4 = iVar4 + 1;
        iVar1 = iVar1 + 0x10;
      } while (iVar4 < 0xc);
      if (param_3 == 0) {
        iVar1 = 0;
        pcVar3 = (char *)(param_1 + 0x2d78);
        do {
          if (pcVar3[-0x10] == '\0') {
LAB_0048a13c:
            if (iVar1 < 0xc) {
              FUN_004f1f10(iVar1 * 0x10 + 0x2d68 + param_1,param_2);
            }
            return 1;
          }
          if (*pcVar3 == '\0') {
            iVar1 = iVar1 + 1;
            goto LAB_0048a13c;
          }
          if (pcVar3[0x10] == '\0') {
            iVar1 = iVar1 + 2;
            goto LAB_0048a13c;
          }
          if (pcVar3[0x20] == '\0') {
            iVar1 = iVar1 + 3;
            goto LAB_0048a13c;
          }
          if (pcVar3[0x30] == '\0') {
            iVar1 = iVar1 + 4;
            goto LAB_0048a13c;
          }
          if (pcVar3[0x40] == '\0') {
            iVar1 = iVar1 + 5;
            goto LAB_0048a13c;
          }
          iVar1 = iVar1 + 6;
          pcVar3 = pcVar3 + 0x60;
          if (0xb < iVar1) {
            return 1;
          }
        } while( true );
      }
    }
  }
  return 0;
}

