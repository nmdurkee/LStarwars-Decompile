/* Ghidra analysis pseudocode, not original source.
 * ev_b277bc71922b23f31a72f43f26143bcec8a2b6e78604417b28dcc98660b92d0f
 * Entry: 0x53e870; label: FUN_0053e870
 */

undefined4 FUN_0053e870(int *param_1,int param_2,undefined1 *param_3,float *param_4)

{
  int iVar1;
  float10 fVar2;
  undefined1 local_c [12];
  
  if (((param_2 != 0) && (*(char *)(param_2 + 1) != -1)) && (param_1 != (int *)0x0)) {
    iVar1 = *(char *)(param_2 + 1) * 0x13c + *param_1;
    if ((*(char *)(iVar1 + 0x32) != '\0') && (*(int *)(iVar1 + 0x28) != 0)) {
      if (param_3 == (undefined1 *)0x0) {
        param_3 = local_c;
      }
      FUN_0053e810(param_3,*(undefined4 *)(iVar1 + 0x28),(int)*(short *)(param_2 + 2),
                   (int)*(short *)(param_2 + 0x28),*(undefined4 *)(param_2 + 4));
      if (param_4 != (float *)0x0) {
        fVar2 = (float10)FUN_005becc0(param_3,param_2 + 8,0);
        *param_4 = (float)fVar2;
      }
      return 1;
    }
  }
  return 0;
}

