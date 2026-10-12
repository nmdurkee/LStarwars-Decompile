/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x570c90; label: FUN_00570c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00570c90(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *_Dst;
  float10 fVar4;
  int local_4;
  
  *(undefined4 *)(param_1 + 0x5054) = 0;
  if ((*(int *)(param_1 + 0x13c) != 0) &&
     (iVar1 = FUN_004fc900("specialminikits",param_2,0xffff), iVar1 != 0)) {
    piVar3 = (int *)(*(int *)(param_1 + 0x104) + 3U & 0xfffffffc);
    *(int **)(param_1 + 0x104) = piVar3;
    local_4 = 0;
    iVar2 = FUN_004fc5b0(iVar1);
    _Dst = piVar3;
    while ((iVar2 != 0 && (iVar2 = FUN_004f7fb0(iVar1), iVar2 != 0))) {
      iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"specialminikit");
      if (iVar2 == 0) {
        _memset(_Dst,0,0x3c);
        _Dst[0xe] = _Dst[0xe] | 1;
        iVar2 = FUN_004f7fb0(iVar1);
        while (iVar2 != 0) {
          iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"pickup");
          if (iVar2 == 0) {
            iVar2 = FUN_004f7fb0(iVar1);
            if ((iVar2 != 0) && (iVar2 = FUN_004f1ff0(*(undefined4 *)(iVar1 + 0x510)), iVar2 < 8)) {
              FUN_004f1f10(_Dst + 10,*(undefined4 *)(iVar1 + 0x510));
            }
          }
          else {
            iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"at_object");
            if (iVar2 == 0) {
              iVar2 = FUN_004f7fb0(iVar1);
              if (iVar2 != 0) {
                FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),_Dst,*(undefined4 *)(iVar1 + 0x510),1)
                ;
                _Dst[0xe] = _Dst[0xe] & 0xffffffdf;
              }
            }
            else {
              iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"at_gizmo");
              if (iVar2 == 0) {
                iVar2 = FUN_004f7fb0(iVar1);
                if ((iVar2 != 0) &&
                   (iVar2 = FUN_004f1ff0(*(undefined4 *)(iVar1 + 0x510)), iVar2 < 0x10)) {
                  FUN_004f1f10(_Dst + 6,*(undefined4 *)(iVar1 + 0x510));
                  _Dst[0xe] = _Dst[0xe] | 0x20;
                }
              }
              else {
                iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"draw_at_start");
                if (iVar2 == 0) {
                  _Dst[0xe] = _Dst[0xe] & 0xfffffffeU | 2;
                }
                else {
                  iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"draw_while_animating");
                  if (iVar2 == 0) {
                    _Dst[0xe] = _Dst[0xe] & 0xfffffffeU | 4;
                  }
                  else {
                    iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"draw_at_end");
                    if (iVar2 == 0) {
                      _Dst[0xe] = _Dst[0xe] & 0xfffffffeU | 8;
                    }
                    else {
                      iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"orientate");
                      if (iVar2 == 0) {
                        _Dst[0xe] = _Dst[0xe] | 0x10;
                      }
                    }
                  }
                }
              }
            }
          }
          iVar2 = FUN_004f7fb0(iVar1);
        }
        if ((char)_Dst[10] != '\0') {
          if ((*(byte *)(_Dst + 0xe) & 0x20) == 0) {
            iVar2 = FUN_005cfac0(_Dst);
            if (iVar2 == 0) {
              if ((*(byte *)(_Dst + 0xe) & 0x20) == 0) goto LAB_00570f55;
              goto LAB_00570f0f;
            }
          }
          else {
LAB_00570f0f:
            if ((char)_Dst[6] == '\0') goto LAB_00570f55;
          }
          iVar2 = FUN_005cfac0(_Dst);
          if (iVar2 != 0) {
            iVar2 = FUN_005d0420(_Dst);
            _Dst[3] = iVar2;
            if (iVar2 != 0) {
              iVar2 = *(int *)(*(int *)(*_Dst + 0x54) + (uint)*(ushort *)(iVar2 + 0x5c) * 4);
              _Dst[4] = iVar2;
              fVar4 = (float10)FUN_005ca4b0(iVar2);
              _Dst[5] = (int)(float)fVar4;
            }
          }
          local_4 = local_4 + 1;
          _Dst = _Dst + 0xf;
        }
      }
LAB_00570f55:
      iVar2 = FUN_004fc5b0(iVar1);
    }
    FUN_004fa300(iVar1);
    if (0 < local_4) {
      *(int **)(param_1 + 0x104) = _Dst;
      *(int **)(param_1 + 0x5054) = _Dst;
      *_Dst = (int)piVar3;
      _Dst[1] = local_4;
      *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 0xbU & 0xfffffffc;
    }
  }
  return;
}

