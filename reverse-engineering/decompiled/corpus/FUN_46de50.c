/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46de50; label: FUN_0046de50
 */

int FUN_0046de50(int param_1,undefined4 param_2,int param_3,float *param_4,int param_5)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_18;
  int local_10;
  undefined1 local_c [12];
  
  local_18 = 1e+09;
  iVar6 = 0;
  local_10 = 0;
  if ((param_1 == 0) || (piVar2 = *(int **)(param_1 + 0x5070), piVar2 == (int *)0x0)) {
    return 0;
  }
  iVar4 = 0;
  if (0 < *piVar2) {
    do {
      iVar5 = piVar2[1] + iVar6;
      if (param_3 == 0) {
        fVar7 = (float10)FUN_005b3c50(param_2,iVar5 + 0x50,0);
LAB_0046df0b:
        if ((float)fVar7 < local_18) {
          local_18 = (float)fVar7;
          local_10 = iVar5;
        }
      }
      else {
        bVar1 = *(byte *)(iVar5 + 0x62);
        if (((((bVar1 & 8) != 0) && ((bVar1 & 4) != 0)) && ((bVar1 & 3) == 0)) &&
           ((*(float *)(iVar5 + 0x68) != 2e+06 &&
            ((param_5 == 0 || (iVar3 = FUN_0046dce0(param_3,iVar5), iVar3 != 0)))))) {
          FUN_0046dc10(iVar5,local_c,0);
          fVar7 = (float10)FUN_005b3c50(param_2,local_c,0);
          goto LAB_0046df0b;
        }
      }
      piVar2 = *(int **)(param_1 + 0x5070);
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 0x90;
    } while (iVar4 < *piVar2);
  }
  if (param_4 != (float *)0x0) {
    *param_4 = local_18;
  }
  return local_10;
}

