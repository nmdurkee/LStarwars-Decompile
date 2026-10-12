/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d8440; label: FUN_005d8440
 */

undefined4 FUN_005d8440(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  float10 fVar3;
  int local_18;
  undefined1 local_10 [8];
  undefined1 local_8 [8];
  
  if (DAT_0097396c == 0) {
    return 0;
  }
  iVar2 = (&DAT_009716a4)[param_1];
  FUN_004f3bd0(local_10);
  FUN_004f3bf0(local_8,local_10,*(int *)(iVar2 + 0x10) + param_2 * 8);
  fVar3 = (float10)FUN_004f3ca0(local_8);
  piVar1 = (int *)(*(int *)(iVar2 + (3 - *(int *)(*(int *)(iVar2 + 0x20) + param_2 * 4)) * 4) +
                  param_2 * 4);
  local_18 = (int)(longlong)ROUND((float)fVar3);
  *piVar1 = *piVar1 + local_18;
  return *(undefined4 *)
          (*(int *)(iVar2 + (3 - *(int *)(*(int *)(iVar2 + 0x20) + param_2 * 4)) * 4) + param_2 * 4)
  ;
}

