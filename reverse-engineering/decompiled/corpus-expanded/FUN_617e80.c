/* Ghidra pseudocode, not original source.
 * ev_34bcce3fa22e23c2ab9571957a9a402fab0be6cbc2b7d858acbf9422b22923c6
 * Entry: 0x617e80; label: FUN_00617e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00617e80(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_02912a38 != '\0') && (iVar2 = FUN_004fa5f0(&DAT_02912a38,0), iVar2 != 0)) {
    FUN_004fb840(iVar2,0x3032554e);
    iVar3 = FUN_004fb840(iVar2,0);
    while (puVar1 = DAT_02912e60, iVar3 != 0) {
      for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
        if (puVar1[10] == iVar3) {
          if ((code *)puVar1[9] != (code *)0x0) {
            (*(code *)puVar1[9])(iVar2);
          }
          break;
        }
      }
      FUN_004f6ea0(iVar2);
      iVar3 = FUN_004fb840(iVar2,0);
    }
    FUN_004f6ea0(iVar2);
    FUN_004f99e0(iVar2);
  }
  return;
}

