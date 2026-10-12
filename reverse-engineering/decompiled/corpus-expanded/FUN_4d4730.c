/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d4730; label: FUN_004d4730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004d4730(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (((param_1 != 0) && (param_2 != 0)) && (*(char *)(param_2 + 0x138) != '\0')) {
    iVar1 = FUN_004f1440(param_1 + 0x77d0);
    if (iVar1 != 0) {
      FUN_004f1410(param_1 + 0x77d0,iVar1);
      FUN_004f1310(param_1 + 0x77d8,iVar1);
      *(undefined4 *)(iVar1 + 0xc) = param_4;
      if ((param_3 < 0) || (0xf < param_3)) {
        param_3 = FUN_0054fa60();
        param_3 = param_3 / ((int)(0xffff / (longlong)(int)*(char *)(param_2 + 0x138)) + 1);
      }
      *(int *)(iVar1 + 8) = param_2;
      *(char *)(iVar1 + 0x10) = (char)param_3;
    }
  }
  return iVar1;
}

