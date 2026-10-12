/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x499500; label: FUN_00499500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00499500(int param_1,float *param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  if (param_2 == (float *)0x0) {
    iVar1 = *(int *)(param_1 + 0x790);
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x794) == 0) {
        return 0;
      }
      param_2 = (float *)(*(int *)(param_1 + 0x794) + 0x4c);
    }
    else {
      if ((*(uint *)(iVar1 + 0x1fc) & 1) == 0) {
        return 0;
      }
      if ((*(uint *)(iVar1 + 0x1fc) & 0x1000) == 0) {
        return 0;
      }
      if (*(char *)(iVar1 + 0x28b) != '\0') {
        return 0;
      }
      param_2 = (float *)(iVar1 + 0x5c);
    }
    if (param_2 == (float *)0x0) {
      return 0;
    }
  }
  uVar2 = FUN_005be2d0(*param_2 - *(float *)(param_1 + 0x5c),param_2[2] - *(float *)(param_1 + 100))
  ;
  *(undefined2 *)(param_1 + 0x5a) = uVar2;
  return 1;
}

