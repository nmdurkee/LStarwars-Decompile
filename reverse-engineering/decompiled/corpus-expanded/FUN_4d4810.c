/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d4810; label: FUN_004d4810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d4810(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  void *_Dst;
  float *pfVar4;
  int iVar5;
  float10 fVar6;
  float local_8;
  int local_4;
  
  if (param_1 != 0) {
    puVar1 = (undefined4 *)(param_1 + 0x77d0);
    *puVar1 = 0;
    *(undefined4 *)(param_1 + 0x77d4) = 0;
    _Dst = (void *)(param_1 + 0x50c0);
    *(undefined4 *)(param_1 + 0x77d8) = 0;
    *(undefined4 *)(param_1 + 0x77dc) = 0;
    _memset(_Dst,0,10000);
    iVar5 = 500;
    do {
      FUN_004f1310(puVar1,_Dst);
      _Dst = (void *)((int)_Dst + 0x14);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if ('\0' < *(char *)(param_1 + 0x77e0)) {
      local_4 = 0;
      pfVar4 = (float *)(param_1 + 0x10);
      do {
        local_8 = 0.0;
        if (0.0 < *pfVar4) {
          do {
            if ((*(char *)(pfVar4 + 0x4a) == '\0') || (iVar5 = FUN_004f1440(puVar1), iVar5 == 0))
            break;
            FUN_004f1410(puVar1,iVar5);
            FUN_004f1310(param_1 + 0x77d8,iVar5);
            *(float *)(iVar5 + 0xc) = local_8;
            iVar3 = FUN_0054fa60();
            cVar2 = *(char *)(pfVar4 + 0x4a);
            *(float **)(iVar5 + 8) = pfVar4 + -4;
            *(char *)(iVar5 + 0x10) = (char)(iVar3 / ((int)(0xffff / (longlong)(int)cVar2) + 1));
            fVar6 = (float10)FUN_005b9dd0();
            local_8 = (float)(((float10)pfVar4[2] - (float10)pfVar4[3]) +
                              ((float10)pfVar4[3] + (float10)pfVar4[3]) * fVar6 + (float10)local_8);
          } while (local_8 < *pfVar4);
        }
        fVar6 = (float10)FUN_005b9dd0();
        local_4 = local_4 + 1;
        pfVar4[0x4b] = (float)(((float10)pfVar4[2] - (float10)pfVar4[3]) +
                              ((float10)pfVar4[3] + (float10)pfVar4[3]) * fVar6);
        pfVar4 = pfVar4 + 0x50;
      } while (local_4 < *(char *)(param_1 + 0x77e0));
    }
  }
  return;
}

