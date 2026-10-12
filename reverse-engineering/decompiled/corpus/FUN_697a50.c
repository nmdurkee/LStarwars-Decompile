/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x697a50; label: FUN_00697a50
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00697a50(int param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_1008;
  undefined1 local_1004 [2048];
  char local_804 [2048];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_1008;
  if (DAT_02972bc8 == 0) {
    FUN_00696d00(0,0,1);
  }
  else {
    FUN_006973c0();
  }
  iVar3 = 0;
  iVar4 = *(int *)(param_1 + 0xc);
  piVar2 = (int *)(param_1 + 0xc);
  DAT_02972bc8 = param_1;
  do {
    DAT_02972be4 = iVar3;
    if (iVar4 == -1) {
LAB_00697ad2:
      local_1008 = 0.0;
      do {
        fVar1 = local_1008;
        if (local_1008 == 0.0) {
          DAT_02962bb0 = 0xc61c4000;
        }
        else {
          local_1008 = (float)(int)local_1008 / 16383.0;
          fVar5 = (float10)FUN_006e9190();
          (&DAT_02962bb0)[(int)fVar1] = (float)fVar5 * 2000.0;
        }
        local_1008 = (float)((int)fVar1 + 1);
      } while ((int)local_1008 < 0x4000);
      iVar4 = 0;
      if (0 < iVar3) {
        iVar3 = 0;
        do {
          FUN_004f1ff0(*(undefined4 *)(iVar3 + DAT_02972bc8));
          FUN_004f6900(local_1004);
          _sprintf(local_804,"%s%s",local_1004,*(undefined4 *)(iVar3 + DAT_02972bc8));
          if (*(int *)(iVar3 + 0xc + DAT_02972bc8) < 0x1000) {
            FUN_00696f10(local_804,iVar4);
          }
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 0x1c;
        } while (iVar4 < DAT_02972be4);
      }
      __security_check_cookie(local_4 ^ (uint)&local_1008);
      return;
    }
    if (DAT_02972bfc <= iVar3) {
      FUN_00696ab0();
      goto LAB_00697ad2;
    }
    piVar2 = piVar2 + 7;
    iVar3 = iVar3 + 1;
    iVar4 = *piVar2;
  } while( true );
}

