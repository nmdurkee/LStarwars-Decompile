/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x52dc60; label: FUN_0052dc60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052dc60(int param_1,int *param_2,uint *param_3,size_t param_4,float param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  char *pcVar2;
  undefined1 uVar3;
  char cVar4;
  undefined2 uVar5;
  short sVar6;
  uint uVar7;
  void *pvVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  float fVar14;
  size_t sVar15;
  undefined4 in_EDX;
  int iVar16;
  undefined4 *_Dst;
  int iVar17;
  float *pfVar18;
  float10 fVar19;
  int local_27c;
  int local_278;
  int local_274;
  float local_270;
  uint *local_26c;
  undefined4 local_268;
  int local_264;
  int *local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined1 auStack_254 [16];
  undefined1 local_244 [32];
  char local_224 [32];
  char local_204 [128];
  char local_184 [128];
  undefined1 auStack_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_27c;
  local_264 = param_1;
  local_270 = param_5;
  local_260 = param_2;
  local_26c = param_3;
  local_258 = param_6;
  local_25c = in_EDX;
  _sprintf(local_204,"%sLevels\\%s\\%s\\%s.ai2",PTR_DAT_00801c70,param_7,param_6,param_5);
  if (((param_2 == (int *)0x0) || (param_3 == (uint *)0x0)) || (*param_3 <= *param_2 + 0x1398U)) {
    FUN_00512850();
    __security_check_cookie(local_4 ^ (uint)&local_27c);
    return;
  }
  uVar7 = *param_2 + 0xf;
  _Dst = (undefined4 *)(uVar7 & 0xfffffff0);
  *param_2 = (uVar7 & 0xfffffff0) + 0x1398;
  _memset(_Dst,0,0x1398);
  if (_Dst == (undefined4 *)0x0) goto LAB_0052e7ff;
  _memset(_Dst,0,0x1398);
  _Dst[3] = param_4;
  pvVar8 = (void *)FUN_00517160(param_2,local_26c,param_4);
  *_Dst = pvVar8;
  piVar1 = _Dst + 1;
  *piVar1 = *param_2;
  _memset(pvVar8,0,param_4);
  _Dst[2] = *_Dst;
  FUN_006211c0(1);
  if (local_264 == 0) {
LAB_0052dda6:
    FUN_006211d0(0);
    iVar9 = FUN_00621270(local_204,0);
    if (iVar9 != 0) goto LAB_0052ddc7;
  }
  else {
    _sprintf(local_224,"%s.ai2",local_270);
    FUN_006211d0(local_264);
    iVar9 = FUN_00621270(local_224,0);
    if (iVar9 == 0) goto LAB_0052dda6;
LAB_0052ddc7:
    iVar9 = FUN_006217e0();
    _Dst[0x4e5] = local_268;
    local_278 = iVar9;
    uVar10 = FUN_00517430(iVar9,local_268,piVar1);
    _Dst[4] = uVar10;
    if (3 < iVar9) {
      iVar11 = FUN_006217e0();
      _Dst[0xd] = iVar11;
      if (iVar11 != 0) {
        uVar10 = FUN_00517160(_Dst + 2,piVar1,iVar11 << 6);
        _Dst[0xe] = uVar10;
        local_274 = 0;
        if (0 < (int)_Dst[0xd]) {
          iVar11 = 0;
          do {
            iVar16 = _Dst[0xe] + iVar11;
            FUN_006216f0(iVar16,0x10);
            fVar19 = (float10)FUN_006217a0();
            *(float *)(iVar16 + 0x10) = (float)fVar19;
            fVar19 = (float10)FUN_006217a0();
            *(float *)(iVar16 + 0x14) = (float)fVar19;
            fVar19 = (float10)FUN_006217a0();
            *(float *)(iVar16 + 0x18) = (float)fVar19;
            fVar19 = (float10)FUN_006217a0();
            *(float *)(iVar16 + 0x1c) = (float)fVar19;
            fVar19 = (float10)FUN_006217a0();
            *(float *)(iVar16 + 0x20) = (float)fVar19;
            fVar19 = (float10)FUN_006217a0();
            *(float *)(iVar16 + 0x24) = (float)fVar19;
            uVar5 = FUN_00621860();
            *(undefined2 *)(iVar16 + 0x28) = uVar5;
            *(undefined4 **)(iVar16 + 0x38) = _Dst;
            if (iVar9 < 0x14) {
              FUN_006218c0();
            }
            else {
              uVar3 = FUN_006218c0();
              *(undefined1 *)(iVar16 + 0x2b) = uVar3;
            }
            FUN_006218c0();
            local_274 = local_274 + 1;
            iVar11 = iVar11 + 0x40;
          } while (local_274 < (int)_Dst[0xd]);
        }
      }
    }
    if (_Dst[4] != 0) {
      if (5 < local_278) {
        iVar9 = FUN_006217e0();
        _Dst[9] = iVar9;
        if (iVar9 != 0) {
          uVar10 = FUN_00517160(_Dst + 2,_Dst + 1,iVar9 * 0x3c);
          iVar9 = 0;
          _Dst[10] = uVar10;
          if (0 < (int)_Dst[9]) {
            iVar11 = 0;
            do {
              iVar16 = _Dst[10] + iVar11;
              FUN_006216f0(iVar16,0x10);
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar16 + 0x10) = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar16 + 0x14) = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar16 + 0x18) = (float)fVar19;
              sVar6 = FUN_00621860();
              *(int *)(iVar16 + 0x1c) = (int)sVar6;
              uVar7 = FUN_006218c0();
              *(undefined4 *)(iVar16 + 0x20) =
                   *(undefined4 *)(*(int *)(_Dst[4] + 4) + (uVar7 & 0xff) * 4);
              uVar3 = FUN_006218c0();
              *(undefined1 *)(iVar16 + 0x28) = uVar3;
              uVar7 = FUN_00621860();
              *(uint *)(iVar16 + 0x24) =
                   *(int *)(*(int *)(iVar16 + 0x20) + 0x80) + (uVar7 & 0xffff) * 0x24;
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar16 + 0x30) = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar16 + 0x34) = (float)fVar19;
              if (0xe < local_278) {
                uVar10 = FUN_006217e0();
                *(undefined4 *)(iVar16 + 0x38) = uVar10;
              }
              iVar9 = iVar9 + 1;
              iVar11 = iVar11 + 0x3c;
            } while (iVar9 < (int)_Dst[9]);
          }
        }
        if (0x11 < local_278) {
          iVar9 = FUN_006217e0();
          _Dst[0xb] = iVar9;
          if (iVar9 != 0) {
            uVar10 = FUN_00517160(_Dst + 2,_Dst + 1,iVar9 * 0x1c);
            _Dst[0xc] = uVar10;
            local_274 = 0;
            if (0 < (int)_Dst[0xb]) {
              local_27c = 0;
              do {
                iVar9 = _Dst[0xc] + local_27c;
                FUN_006216f0(iVar9,0x10);
                cVar4 = FUN_006217e0();
                *(char *)(iVar9 + 0x10) = cVar4;
                uVar10 = FUN_00517160(_Dst + 2,_Dst + 1,cVar4 * 0x1c);
                iVar11 = 0;
                *(undefined4 *)(iVar9 + 0x14) = uVar10;
                if ('\0' < *(char *)(iVar9 + 0x10)) {
                  do {
                    uVar3 = FUN_006218c0();
                    *(undefined1 *)(iVar11 + *(int *)(iVar9 + 0x14)) = uVar3;
                    iVar11 = iVar11 + 1;
                  } while (iVar11 < *(char *)(iVar9 + 0x10));
                }
                sVar15 = (size_t)*(char *)(iVar9 + 0x10);
                piVar1 = _Dst + 2;
                pvVar8 = (void *)0x0;
                if (((piVar1 == (int *)0x0) || (_Dst + 1 == (uint *)0x0)) ||
                   ((uint)_Dst[1] <= *piVar1 + sVar15)) {
                  FUN_00512850();
                }
                else {
                  pvVar8 = (void *)(*piVar1 + 0xfU & 0xfffffff0);
                  *piVar1 = (*piVar1 + 0xfU & 0xfffffff0) + sVar15;
                  _memset(pvVar8,0,sVar15);
                }
                *(void **)(iVar9 + 0x18) = pvVar8;
                _memset(pvVar8,0,(int)*(char *)(iVar9 + 0x10));
                local_27c = local_27c + 0x1c;
                local_274 = local_274 + 1;
              } while (local_274 < (int)_Dst[0xb]);
            }
          }
        }
      }
      iVar9 = FUN_006217e0();
      _Dst[5] = iVar9;
      if (iVar9 != 0) {
        uVar10 = FUN_00517160(_Dst + 2,_Dst + 1,iVar9 * 0xa4);
        _Dst[6] = uVar10;
        local_274 = 0;
        if (0 < (int)_Dst[5]) {
          local_270 = 0.0;
          do {
            iVar11 = _Dst[6] + (int)local_270;
            FUN_006216f0(iVar11,0x10);
            pcVar2 = (char *)(iVar11 + 0x10);
            FUN_006216f0(pcVar2,0x10);
            iVar9 = local_278;
            pcVar12 = pcVar2;
            do {
              cVar4 = *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (cVar4 != '\0');
            if (pcVar12 == (char *)(iVar11 + 0x11)) {
              builtin_strncpy(pcVar2,"defa",4);
              builtin_strncpy((char *)(iVar11 + 0x14),"ult",4);
            }
            if (local_278 < 0xe) {
              uVar10 = 0x10;
            }
            else {
              uVar10 = 0x20;
            }
            FUN_006216f0(local_244,uVar10);
            iVar16 = 0;
            if (DAT_00923898 != (code *)0x0) {
              uVar5 = (*DAT_00923898)(local_244);
              *(undefined2 *)(iVar11 + 0x4e) = uVar5;
            }
            fVar19 = (float10)FUN_006217a0();
            *(float *)(iVar11 + 0x20) = (float)fVar19;
            fVar19 = (float10)FUN_006217a0();
            *(float *)(iVar11 + 0x24) = (float)fVar19;
            fVar19 = (float10)FUN_006217a0();
            *(float *)(iVar11 + 0x28) = (float)fVar19;
            sVar6 = FUN_00621860();
            *(int *)(iVar11 + 0x2c) = (int)sVar6;
            if (0xf < iVar9) {
              uVar3 = FUN_006218c0();
              *(undefined1 *)(iVar11 + 0x4c) = uVar3;
            }
            uVar3 = FUN_006218c0();
            *(undefined1 *)(iVar11 + 0x50) = uVar3;
            uVar3 = FUN_006218c0();
            *(undefined1 *)(iVar11 + 0x51) = uVar3;
            uVar10 = FUN_006217e0();
            *(undefined4 *)(iVar11 + 0x58) = uVar10;
            fVar19 = (float10)FUN_006217a0();
            *(float *)(iVar11 + 0x5c) = (float)fVar19;
            fVar19 = (float10)FUN_006217a0();
            *(float *)(iVar11 + 0x60) = (float)fVar19;
            uVar10 = FUN_006217e0();
            *(undefined4 *)(iVar11 + 0x48) = uVar10;
            uVar7 = FUN_006218c0();
            *(undefined4 *)(iVar11 + 0x30) =
                 *(undefined4 *)(*(int *)(_Dst[4] + 4) + (uVar7 & 0xff) * 4);
            uVar3 = FUN_006218c0();
            *(undefined1 *)(iVar11 + 0x38) = uVar3;
            uVar7 = FUN_00621860();
            *(uint *)(iVar11 + 0x34) =
                 *(int *)(*(int *)(iVar11 + 0x30) + 0x80) + (uVar7 & 0xffff) * 0x24;
            if (2 < iVar9) {
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar11 + 100) = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar11 + 0x68) = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar11 + 0x6c) = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar11 + 0x70) = (float)fVar19;
            }
            if (((3 < iVar9) && (iVar13 = FUN_006217e0(), iVar13 != 0)) &&
               (FUN_006216f0(auStack_254,0x10), 0 < (int)_Dst[0xd])) {
              local_27c = 0;
              do {
                iVar17 = _Dst[0xe] + local_27c;
                iVar13 = FUN_004f8b10(auStack_254,iVar17);
                iVar9 = local_278;
                if (iVar13 == 0) {
                  *(int *)(iVar11 + 0x78) = iVar17;
                  break;
                }
                local_27c = local_27c + 0x40;
                iVar16 = iVar16 + 1;
              } while (iVar16 < (int)_Dst[0xd]);
            }
            if ((5 < iVar9) && (iVar9 = FUN_006217e0(), iVar9 != 0)) {
              FUN_006216f0(auStack_254,0x10);
              iVar9 = 0;
              if (0 < (int)_Dst[9]) {
                local_27c = 0;
                do {
                  iVar13 = _Dst[10] + local_27c;
                  iVar16 = FUN_004f8b10(auStack_254,iVar13);
                  if (iVar16 == 0) {
                    *(int *)(iVar11 + 0x7c) = iVar13;
                    break;
                  }
                  local_27c = local_27c + 0x3c;
                  iVar9 = iVar9 + 1;
                } while (iVar9 < (int)_Dst[9]);
              }
            }
            if ((0x10 < local_278) && (iVar9 = FUN_006217e0(), iVar9 != 0)) {
              FUN_006216f0(auStack_254,0x10);
              iVar9 = 0;
              if (0 < (int)_Dst[9]) {
                local_27c = 0;
                do {
                  iVar13 = _Dst[10] + local_27c;
                  iVar16 = FUN_004f8b10(auStack_254,iVar13);
                  if (iVar16 == 0) {
                    *(int *)(iVar11 + 0x80) = iVar13;
                    break;
                  }
                  local_27c = local_27c + 0x3c;
                  iVar9 = iVar9 + 1;
                } while (iVar9 < (int)_Dst[9]);
              }
            }
            iVar9 = local_278;
            if (local_278 < 8) {
              *(undefined1 *)(iVar11 + 0x84) = DAT_00801c5c;
              *(undefined1 *)(iVar11 + 0x85) = DAT_00922264;
              *(undefined1 *)(iVar11 + 0x86) = DAT_00922265;
              *(undefined4 *)(iVar11 + 0x88) = _DAT_00923868;
              fVar19 = (float10)_DAT_0092386c;
            }
            else {
              uVar3 = FUN_006218c0();
              *(undefined1 *)(iVar11 + 0x84) = uVar3;
              uVar3 = FUN_006218c0();
              *(undefined1 *)(iVar11 + 0x85) = uVar3;
              uVar3 = FUN_006218c0();
              *(undefined1 *)(iVar11 + 0x86) = uVar3;
              uVar3 = FUN_006218c0();
              *(undefined1 *)(iVar11 + 0x87) = uVar3;
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar11 + 0x88) = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
            }
            *(float *)(iVar11 + 0x8c) = (float)fVar19;
            if (iVar9 < 10) {
              fVar19 = (float10)_DAT_00923870;
            }
            else {
              fVar19 = (float10)FUN_006217a0();
            }
            *(float *)(iVar11 + 0x90) = (float)fVar19;
            if (*(char *)(iVar11 + 0x87) == '\x01') {
              FUN_006216f0(auStack_254,0x10);
              iVar9 = 0;
              if (0 < (int)_Dst[0xd]) {
                local_27c = 0;
                do {
                  iVar13 = _Dst[0xe] + local_27c;
                  iVar16 = FUN_004f8b10(auStack_254,iVar13);
                  if (iVar16 == 0) {
                    *(int *)(iVar11 + 0x74) = iVar13;
                    break;
                  }
                  local_27c = local_27c + 0x40;
                  iVar9 = iVar9 + 1;
                } while (iVar9 < (int)_Dst[0xd]);
              }
            }
            if (local_278 < 0xb) {
              if (DAT_009238c8 == (code *)0x0) {
                fVar19 = (float10)1;
              }
              else {
                fVar19 = (float10)(*DAT_009238c8)((int)*(short *)(iVar11 + 0x4e));
              }
              *(float *)(iVar11 + 0x94) = (float)fVar19;
              if (DAT_009238cc == (code *)0x0) {
                fVar19 = (float10)1;
              }
              else {
                fVar19 = (float10)(*DAT_009238cc)((int)*(short *)(iVar11 + 0x4e));
              }
              *(float *)(iVar11 + 0x98) = (float)fVar19;
              if (DAT_009238d0 == (code *)0x0) {
                fVar19 = (float10)1;
              }
              else {
                fVar19 = (float10)(*DAT_009238d0)((int)*(short *)(iVar11 + 0x4e));
              }
              *(float *)(iVar11 + 0x9c) = (float)fVar19;
              if (DAT_009238d4 == (code *)0x0) {
                fVar19 = (float10)1;
              }
              else {
                fVar19 = (float10)(*DAT_009238d4)((int)*(short *)(iVar11 + 0x4e));
              }
LAB_0052e5ac:
              *(float *)(iVar11 + 0xa0) = (float)fVar19;
            }
            else {
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar11 + 0x94) = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar11 + 0x98) = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar11 + 0x9c) = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              *(float *)(iVar11 + 0xa0) = (float)fVar19;
              FUN_006217e0();
              if ((DAT_009238c8 != (code *)0x0) && (*(float *)(iVar11 + 0x94) == 0.0)) {
                fVar19 = (float10)(*DAT_009238c8)((int)*(short *)(iVar11 + 0x4e));
                *(float *)(iVar11 + 0x94) = (float)fVar19;
              }
              if ((DAT_009238cc != (code *)0x0) && (*(float *)(iVar11 + 0x98) == 0.0)) {
                fVar19 = (float10)(*DAT_009238cc)((int)*(short *)(iVar11 + 0x4e));
                *(float *)(iVar11 + 0x98) = (float)fVar19;
              }
              if ((DAT_009238d0 != (code *)0x0) && (*(float *)(iVar11 + 0x9c) == 0.0)) {
                fVar19 = (float10)(*DAT_009238d0)((int)*(short *)(iVar11 + 0x4e));
                *(float *)(iVar11 + 0x9c) = (float)fVar19;
              }
              if ((DAT_009238d4 != (code *)0x0) && (*(float *)(iVar11 + 0xa0) == 0.0)) {
                fVar19 = (float10)(*DAT_009238d4)((int)*(short *)(iVar11 + 0x4e));
                goto LAB_0052e5ac;
              }
            }
            local_270 = (float)((int)local_270 + 0xa4);
            local_274 = local_274 + 1;
          } while (local_274 < (int)_Dst[5]);
        }
      }
      iVar9 = local_278;
      if (0xc < local_278) {
        iVar11 = FUN_006217e0();
        _Dst[0x4df] = iVar11;
        if (iVar11 != 0) {
          sVar15 = iVar11 * 0x58;
          piVar1 = _Dst + 2;
          pvVar8 = (void *)0x0;
          if ((piVar1 == (int *)0x0) || (_Dst + 1 == (uint *)0x0)) {
            FUN_00512850();
          }
          else if (sVar15 + *piVar1 < (uint)_Dst[1]) {
            uVar7 = *piVar1 + 0xf;
            pvVar8 = (void *)(uVar7 & 0xfffffff0);
            *piVar1 = (uVar7 & 0xfffffff0) + sVar15;
            _memset(pvVar8,0,sVar15);
            iVar9 = local_278;
          }
          else {
            FUN_00512850();
            iVar9 = local_278;
          }
          _Dst[0x4e0] = pvVar8;
          local_274 = 0;
          if (0 < (int)_Dst[0x4df]) {
            iVar11 = 0;
            do {
              pfVar18 = (float *)(_Dst[0x4e0] + iVar11);
              *(undefined1 *)(pfVar18 + 0x12) = 1;
              fVar19 = (float10)FUN_006217a0();
              *pfVar18 = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              pfVar18[1] = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              pfVar18[2] = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              local_270 = (float)fVar19;
              pfVar18[3] = local_270;
              pfVar18[0x10] = local_270;
              pfVar18[0x11] = local_270;
              fVar19 = (float10)FUN_006217a0();
              pfVar18[4] = (float)fVar19;
              fVar19 = (float10)FUN_006217a0();
              local_270 = (float)fVar19;
              pfVar18[6] = local_270;
              pfVar18[5] = pfVar18[4] - pfVar18[1];
              pfVar18[7] = local_270 - pfVar18[1];
              if (iVar9 < 0xf) {
                FUN_006218c0();
              }
              else {
                fVar14 = (float)FUN_006217e0();
                pfVar18[0xe] = fVar14;
                fVar19 = (float10)FUN_006217a0();
                pfVar18[0x10] = (float)fVar19;
                fVar19 = (float10)FUN_006217a0();
                pfVar18[0x11] = (float)fVar19;
                uVar3 = FUN_006218c0();
                *(undefined1 *)((int)pfVar18 + 0x4a) = uVar3;
              }
              FUN_006218c0();
              FUN_006218c0();
              uVar3 = FUN_006218c0();
              *(undefined1 *)((int)pfVar18 + 0x49) = uVar3;
              cVar4 = FUN_006218c0();
              if (cVar4 != 0) {
                FUN_006216f0(auStack_104,(int)cVar4);
                iVar16 = FUN_005cf5b0(local_268,pfVar18 + 8,auStack_104,1);
                *(bool *)((int)pfVar18 + 0x4b) = iVar16 != 0;
                fVar19 = (float10)FUN_006217a0();
                pfVar18[0xb] = (float)fVar19;
                fVar19 = (float10)FUN_006217a0();
                pfVar18[0xc] = (float)fVar19;
                fVar19 = (float10)FUN_006217a0();
                pfVar18[0xd] = (float)fVar19;
                if (0xe < iVar9) {
                  fVar14 = (float)FUN_006217e0();
                  pfVar18[0xf] = fVar14;
                }
              }
              local_274 = local_274 + 1;
              iVar11 = iVar11 + 0x58;
            } while (local_274 < (int)_Dst[0x4df]);
          }
        }
      }
      if ((6 < iVar9) && (DAT_009238bc != (code *)0x0)) {
        (*DAT_009238bc)(_Dst,iVar9,local_268,local_260,local_26c);
      }
    }
    FUN_006213e0();
    param_2 = local_260;
  }
  _sprintf(local_184,"%sLevels\\%s\\%s",PTR_DAT_00801c70,local_25c,local_258);
  FUN_0052c470(local_264,local_184,param_2,local_26c,_Dst);
  iVar9 = _Dst[4];
  if (((iVar9 != 0) && (iVar11 = **(int **)(iVar9 + 4), iVar11 != 0)) &&
     (iVar11 != *(int *)(iVar9 + 8))) {
    *(int *)(iVar9 + 8) = iVar11;
  }
LAB_0052e7ff:
  __security_check_cookie(local_4 ^ (uint)&local_27c);
  return;
}

