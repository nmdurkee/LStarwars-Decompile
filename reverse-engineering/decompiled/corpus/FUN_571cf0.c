/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x571cf0; label: FUN_00571cf0
 */

int FUN_00571cf0(int param_1,undefined4 param_2,float param_3,uint param_4,float param_5)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_1c;
  int local_18;
  undefined1 local_c [12];
  
  local_18 = 0;
  if (param_5 <= 0.0) {
    local_1c = 100.0;
  }
  else {
    local_1c = param_5;
  }
  iVar3 = 0;
  iVar4 = DAT_0291f664;
  if (0 < DAT_0081020c) {
    do {
      if ((((*(byte *)(iVar4 + 0x144) & 1) != 0) && (*(int *)(iVar4 + 0xd4) != param_1)) &&
         ((*(uint *)(iVar4 + 0x108) & param_4) == param_4)) {
        if (param_5 <= 0.0) {
          fVar5 = (float10)FUN_005bec80(iVar4 + 0x80);
          fVar1 = (float)fVar5;
          if (fVar1 != 0.0) {
            FUN_005b3830(local_c,iVar4 + 0x80,1.0 / fVar1);
            fVar5 = (float10)FUN_005b3c50(iVar4 + 0x30,param_2,0);
            if (((float)fVar5 < fVar1 * 0.5 * fVar1 * 0.5) &&
               (iVar2 = FUN_00551730(iVar4 + 0x30,local_c,param_2,param_3 * param_3,0), iVar2 != 0))
            {
              local_1c = (float)fVar5;
              local_18 = iVar4;
            }
          }
        }
        else {
          fVar5 = (float10)FUN_005b3c50(iVar4 + 0x30,param_2,0);
          if ((float)fVar5 < local_1c) {
            local_1c = (float)fVar5;
            local_18 = iVar4;
          }
        }
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x220;
    } while (iVar3 < DAT_0081020c);
    return local_18;
  }
  return 0;
}

