/* Ghidra pseudocode, not original source.
 * ev_34bcce3fa22e23c2ab9571957a9a402fab0be6cbc2b7d858acbf9422b22923c6
 * Entry: 0x617d80; label: FUN_00617d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00617d80(int *param_1,int param_2)

{
  int *piVar1;
  
  if (param_1 == (int *)0x0) {
    if (DAT_02912e64 != (int *)0x0) {
      if ((*(code **)((int)DAT_02912e64 + 0x18) != (code *)0x0) && (param_2 != 0)) {
        (**(code **)((int)DAT_02912e64 + 0x18))();
      }
      DAT_02912e64 = (int *)0x0;
      DAT_02912e68 = 0;
    }
  }
  else {
    piVar1 = DAT_02912e60;
    if (DAT_02912e60 != (int *)0x0) {
      do {
        if (piVar1 == param_1) {
          DAT_02912e64 = param_1;
          DAT_02912e68 = 1;
          if (((code *)param_1[5] != (code *)0x0) && (param_2 != 0)) {
            (*(code *)param_1[5])();
          }
          return 1;
        }
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)0x0);
      return 0;
    }
  }
  return 0;
}

