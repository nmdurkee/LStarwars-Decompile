/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4b0c80; label: FUN_004b0c80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b0c80(void)

{
  char cVar1;
  short sVar2;
  float fVar3;
  bool bVar4;
  undefined4 uVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float10 fVar12;
  float local_38;
  int aiStack_28 [10];
  
  bVar4 = false;
  if (*(char *)(in_EAX + 0x7b5) == 'A') {
    iVar6 = FUN_0062f150(in_EAX + 8,(int)*(short *)(in_EAX + 0x7aa),1,0);
    if (iVar6 != 0) {
      *(float *)(in_EAX + 0x784) = *(float *)(in_EAX + 0x784) + _DAT_00925018;
      fVar3 = *(float *)(in_EAX + 0x77c) - _DAT_00925018;
      *(float *)(in_EAX + 0x77c) = fVar3;
      if (fVar3 <= 0.0) {
        *(undefined1 *)(in_EAX + 0x7b5) = 0xff;
        return;
      }
    }
  }
  else {
    if ((*(uint *)(*(int *)(in_EAX + 0x54) + 4) & 0x20000000) != 0) {
      piVar8 = &DAT_0093d7f4;
      do {
        iVar6 = piVar8[-1];
        if ((((iVar6 != 0) && (*(char *)(iVar6 + 0x7b5) == 'Q')) && (*(int *)(iVar6 + 0x798) != 0))
           && (*(int *)(*(int *)(iVar6 + 0x798) + 0x6c) == in_EAX)) {
          bVar4 = true;
        }
        iVar6 = *piVar8;
        if (((iVar6 != 0) && (*(char *)(iVar6 + 0x7b5) == 'Q')) &&
           ((*(int *)(iVar6 + 0x798) != 0 && (*(int *)(*(int *)(iVar6 + 0x798) + 0x6c) == in_EAX))))
        {
          bVar4 = true;
        }
        iVar6 = piVar8[1];
        if (((iVar6 != 0) && (*(char *)(iVar6 + 0x7b5) == 'Q')) &&
           ((*(int *)(iVar6 + 0x798) != 0 && (*(int *)(*(int *)(iVar6 + 0x798) + 0x6c) == in_EAX))))
        {
          bVar4 = true;
        }
        iVar6 = piVar8[2];
        if ((((iVar6 != 0) && (*(char *)(iVar6 + 0x7b5) == 'Q')) && (*(int *)(iVar6 + 0x798) != 0))
           && (*(int *)(*(int *)(iVar6 + 0x798) + 0x6c) == in_EAX)) {
          bVar4 = true;
        }
        piVar8 = piVar8 + 4;
      } while ((int)piVar8 < 0x93d814);
      if (((bVar4) || (*(int *)(in_EAX + 0xcd0) != 0)) || ((*(byte *)(in_EAX + 0x1fc) & 0x80) != 0))
      {
        if (*(char *)(in_EAX + 0x7b5) != '\x17') {
          return;
        }
        FUN_004327a0();
      }
      else {
        cVar1 = *(char *)(in_EAX + 0x7b5);
        if ((cVar1 != '>') && (cVar1 != '+')) {
          if (cVar1 == '\x17') {
            *(undefined4 *)(in_EAX + 0x77c) = 0x4e6e6b28;
          }
          else {
            FUN_00432620();
          }
        }
      }
    }
    if (*(char *)(in_EAX + 0x7b5) == '\x17') {
      iVar6 = 0;
      if ((*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + *(short *)(in_EAX + 0x7aa) * 4) == 0)
         || (iVar6 = FUN_0062f150(in_EAX + 8,(int)*(short *)(in_EAX + 0x7aa),1,0), iVar6 != 0)) {
        fVar3 = *(float *)(in_EAX + 0x784) + _DAT_00925018;
        *(float *)(in_EAX + 0x784) = fVar3;
        if (iVar6 != 0) {
          sVar2 = *(short *)(in_EAX + 0x7aa);
          if (sVar2 == 0x81) {
            fVar11 = (float10)FUN_0062e040((int)*(short *)(in_EAX + 0x1064),0x81,0,0,1);
            if (fVar11 < (float10)fVar3 != (fVar11 == (float10)fVar3)) {
              if (*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 0x104) == 0) goto LAB_004b0f2d;
              *(undefined2 *)(in_EAX + 0x7aa) = 0x41;
              if (*(float *)(in_EAX + 0x77c) != 1e+09) {
                *(float *)(in_EAX + 0x77c) = *(float *)(in_EAX + 0x77c) - *(float *)(in_EAX + 0x784)
                ;
              }
              *(undefined4 *)(in_EAX + 0x784) = 0;
            }
          }
          else if (((*(byte *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 8) + sVar2 * 4) + 4) & 2)
                    == 0) &&
                  (fVar11 = (float10)FUN_0062e040((int)*(short *)(in_EAX + 0x1064),(int)sVar2,0,0,1)
                  , fVar11 < (float10)fVar3 != (fVar11 == (float10)fVar3))) {
LAB_004b0f2d:
            FUN_004327a0();
            return;
          }
        }
        fVar11 = (float10)0;
        if ((*(float *)(in_EAX + 0x77c) == 1e+09) ||
           (*(float *)(in_EAX + 0x784) <= *(float *)(in_EAX + 0x77c))) {
          if ((*(byte *)(*(int *)(in_EAX + 0x54) + 4) & 0x20) != 0) {
            fVar11 = (float10)FUN_004aa200();
          }
        }
        else {
          FUN_004327a0();
          fVar11 = (float10)0;
        }
        if ((fVar11 < (float10)*(float *)(in_EAX + 0x778)) &&
           (fVar3 = *(float *)(in_EAX + 0x778) - _DAT_00925018, fVar12 = (float10)fVar3,
           *(float *)(in_EAX + 0x778) = fVar3, fVar12 < fVar11 != (fVar12 == fVar11))) {
          if (*(char *)(in_EAX + 0x7b8) == '\x02') {
            cVar1 = '\x02';
            local_38 = 3.0;
            uVar5 = _DAT_00804b04;
          }
          else {
            if (DAT_0087b90c == 0) {
              return;
            }
            if (*(char *)(in_EAX + 0x7b8) != '\x01') {
              return;
            }
            cVar1 = '\x01';
            local_38 = 1.0;
            uVar5 = 0x40a00000;
          }
          iVar10 = 0;
          iVar9 = 0;
          iVar6 = DAT_0093d504;
          if (0 < DAT_0093d500) {
            do {
              if (9 < iVar10) break;
              if (cVar1 == '\x01') {
                iVar7 = FUN_0049c3f0();
LAB_004b1056:
                if ((iVar7 != 0) &&
                   (fVar11 = (float10)FUN_005b3c50(iVar6 + 0x80,in_EAX + 0x80,0),
                   fVar11 < (float10)(local_38 * local_38))) {
                  aiStack_28[iVar10] = iVar6;
                  iVar10 = iVar10 + 1;
                }
              }
              else if (cVar1 == '\x02') {
                iVar7 = FUN_004b0c10();
                goto LAB_004b1056;
              }
              iVar9 = iVar9 + 1;
              iVar6 = iVar6 + 0x10d8;
            } while (iVar9 < DAT_0093d500);
            if (iVar10 < 2) {
              if (iVar10 != 1) {
                return;
              }
              iVar6 = 0;
            }
            else {
              iVar6 = FUN_0054fa60();
              iVar6 = iVar6 / ((int)(0xffff / (longlong)iVar10) + 1);
              if (iVar6 == -1) {
                return;
              }
            }
            iVar6 = aiStack_28[iVar6];
            iVar9 = FUN_00432620(iVar6,uVar5,0);
            if (iVar9 != 0) {
              *(char *)(iVar6 + 0x7b8) = cVar1;
              *(uint *)(iVar6 + 0x7bc) =
                   *(uint *)(iVar6 + 0x7bc) ^
                   (*(uint *)(in_EAX + 0x7bc) ^ *(uint *)(iVar6 + 0x7bc)) & 0x100;
              if (cVar1 == '\x02') {
                FUN_00681f40("R2Zap",in_EAX + 0x80);
                FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),
                             ~((*(uint *)(iVar6 + 0x7bc) >> 8) * 2) & 2 | 1,iVar6 + 0x80);
                FUN_00549f10();
              }
              iVar9 = FUN_0054fa60();
              *(float *)(iVar6 + 0x778) = (float)iVar9 * 1.5259022e-05 * 0.3 + 0.2;
              if (*(short *)(iVar6 + 0x1064) == DAT_007f197c) {
                FUN_00681f40("Jawa_Dizzy",iVar6 + 0x80);
              }
            }
          }
          return;
        }
      }
    }
  }
  return;
}

