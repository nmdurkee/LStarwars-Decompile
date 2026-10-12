/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x507750; label: FUN_00507750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00507750(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = DAT_009213d8;
  iVar1 = FUN_004f8b80(param_2,&DAT_0075ee90,2);
  if (iVar1 == 0) {
    if (piVar2 != (int *)0x0) {
      while (*piVar2 != 0) {
        iVar1 = FUN_004f8b10(param_2 + 2,*piVar2);
        if (iVar1 == 0) {
          FUN_004fff10(param_2);
          if ((code *)piVar2[1] == (code *)0x0) {
            return 0;
          }
          (*(code *)piVar2[1])(0);
          return 0;
        }
        piVar2 = piVar2 + 2;
        if (piVar2 == (int *)0x0) {
          return 0;
        }
      }
    }
  }
  else {
    for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)*param_1) {
      iVar1 = FUN_004f8b10(param_1[1],param_2);
      if (iVar1 == 0) {
        FUN_004fff10(param_2);
        FUN_00507390(param_1[2],param_3,param_4);
        return 0;
      }
    }
    FUN_004fff10(param_2);
  }
  return 0;
}

