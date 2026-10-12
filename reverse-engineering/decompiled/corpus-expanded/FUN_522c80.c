/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x522c80; label: FUN_00522c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00522c80(float param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int local_14;
  undefined1 local_c [12];
  
  iVar2 = (int)param_1;
  param_1 = 3.4028235e+38;
  local_14 = -1;
  iVar4 = -1;
  if ((iVar2 != 0) && (iVar5 = 0, *(char *)(iVar2 + 0x10) != '\0')) {
    iVar3 = 0;
    do {
      iVar4 = *(int *)(iVar2 + 0x7c) + iVar3;
      fVar6 = (float10)FUN_005b3cf0(DAT_009238e4 + 0x10,iVar4 + 4,local_c);
      fVar1 = (float)fVar6;
      if ((fVar1 < param_1) && (fVar1 < *(float *)(iVar4 + 0x14))) {
        param_1 = fVar1;
        local_14 = iVar5;
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x5c;
      iVar4 = local_14;
    } while (iVar5 < (int)(uint)*(byte *)(iVar2 + 0x10));
  }
  return iVar4;
}

