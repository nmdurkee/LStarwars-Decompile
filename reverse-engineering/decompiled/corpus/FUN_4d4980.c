/* Ghidra analysis pseudocode, not original source.
 * ev_a7e7d672623d9c9895986762e49f541fc5bec923712a30ebf66db24116e2b0d4
 * Entry: 0x4d4980; label: FUN_004d4980
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d4980(int param_1)

{
  int iVar1;
  char cVar2;
  float fVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  float10 fVar9;
  int local_8;
  
  if (param_1 != 0) {
    iVar1 = param_1 + 0x77d8;
    puVar5 = (undefined4 *)FUN_004f1440(iVar1);
    while (puVar4 = puVar5, puVar4 != (undefined4 *)0x0) {
      puVar5 = (undefined4 *)FUN_004f1460(iVar1,puVar4);
      fVar3 = *(float *)(puVar4[2] + 0x14) * _DAT_00925018 * 60.0 + (float)puVar4[3];
      puVar4[3] = fVar3;
      if (*(float *)(puVar4[2] + 0x10) < fVar3) {
        FUN_004f1410(iVar1,puVar4);
        *puVar4 = 0;
        FUN_004f1310(param_1 + 0x77d0,puVar4);
      }
    }
    local_8 = 0;
    if ('\0' < *(char *)(param_1 + 0x77e0)) {
      pcVar8 = (char *)(param_1 + 0x138);
      do {
        fVar3 = *(float *)(pcVar8 + 4) - *(float *)(pcVar8 + -0x124) * _DAT_00925018 * 60.0;
        *(float *)(pcVar8 + 4) = fVar3;
        if (fVar3 <= 0.0) {
          if (*pcVar8 != '\0') {
            iVar6 = FUN_004f1440(param_1 + 0x77d0);
            if (iVar6 != 0) {
              FUN_004f1410(param_1 + 0x77d0,iVar6);
              FUN_004f1310(iVar1,iVar6);
              *(undefined4 *)(iVar6 + 0xc) = 0;
              iVar7 = FUN_0054fa60();
              cVar2 = *pcVar8;
              *(char **)(iVar6 + 8) = pcVar8 + -0x138;
              *(char *)(iVar6 + 0x10) = (char)(iVar7 / ((int)(0xffff / (longlong)(int)cVar2) + 1));
            }
          }
          fVar9 = (float10)FUN_005b9dd0();
          *(float *)(pcVar8 + 4) =
               (float)(((float10)*(float *)(pcVar8 + -0x120) - (float10)*(float *)(pcVar8 + -0x11c))
                      + ((float10)*(float *)(pcVar8 + -0x11c) + (float10)*(float *)(pcVar8 + -0x11c)
                        ) * fVar9);
        }
        local_8 = local_8 + 1;
        pcVar8 = pcVar8 + 0x140;
      } while (local_8 < *(char *)(param_1 + 0x77e0));
    }
  }
  return;
}

