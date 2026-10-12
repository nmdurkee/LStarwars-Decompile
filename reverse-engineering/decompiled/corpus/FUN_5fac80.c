/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5fac80; label: FUN_005fac80
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * FUN_005fac80(undefined4 param_1,int param_2,undefined4 param_3,int param_4,ushort *param_5,
                   undefined4 param_6,undefined4 param_7,uint *param_8)

{
  uint *puVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  size_t sVar6;
  uint uVar7;
  ushort extraout_CX;
  uint uVar8;
  ushort extraout_DX;
  ushort extraout_DX_00;
  void *unaff_EBX;
  size_t _NumOfElements;
  int unaff_ESI;
  int iVar9;
  void *pvVar10;
  undefined6 uVar11;
  int local_2fe4;
  int local_2fe0;
  int local_2fdc;
  int local_2fd8 [2];
  int *local_2fd0;
  int local_2fcc;
  ushort local_2fc8 [64];
  undefined2 local_2f48;
  undefined2 local_2f46;
  ushort auStack_2e44 [1412];
  undefined1 auStack_233c [20];
  int local_2328 [93];
  undefined4 uStack_21b4;
  undefined4 local_21a8;
  undefined4 local_21a4;
  float local_21a0;
  int iStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5fac8a;
  FUN_004f2370(param_5);
  _memset(local_2328,0,9000);
  _memset(local_2fc8,0xff,0xca0);
  piVar4 = (int *)FUN_004eef40(0x24,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nutex_pc.cpp",
                               0x1e1);
  local_2fd0 = piVar4;
  iVar5 = FUN_005f9130(param_1,0,piVar4);
  if (iVar5 == 0) {
    FUN_004ef280(piVar4,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nutex_pc.cpp",0x1e5);
  }
  else if (piVar4 != (int *)0x0) {
    if (*piVar4 == 5) {
      iVar5 = 0;
      do {
        if (iVar5 == param_4) {
          *(undefined1 *)(piVar4[5] + 3 + iVar5 * 4) = 0;
        }
        else {
          puVar1 = (uint *)(piVar4[5] + iVar5 * 4);
          *puVar1 = *puVar1 | 0x7f000000;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x100);
    }
    else if (*piVar4 != 3) {
      FUN_005f7490();
    }
    _DAT_00991da0 = 0;
    DAT_028490e8 = 0;
    uVar2 = *param_5;
    _NumOfElements = 1;
    local_2fd8[0] = 0;
    iVar5 = local_2fd8[0];
    while (local_2fd8[0] = iVar5, uVar2 != 0) {
      if ((_NumOfElements == 0x20) || (_NumOfElements == 0x21)) {
        _NumOfElements = 0x22;
      }
      else if (_NumOfElements == 0x25) {
        _NumOfElements = 0x26;
      }
      else if (_NumOfElements == 0x3f) {
        _NumOfElements = 0x40;
      }
      else if (_NumOfElements == 0x2e) {
        _NumOfElements = 0x2f;
      }
      else if (_NumOfElements == 0x2c) {
        _NumOfElements = 0x2d;
      }
      else if (_NumOfElements == 0x30) {
        _NumOfElements = 0x3a;
      }
      else if (_NumOfElements == 0x41) {
LAB_005faddb:
        _NumOfElements = 0x5c;
      }
      else if (_NumOfElements == 0x61) {
        _NumOfElements = 0x7b;
      }
      else {
        if (_NumOfElements == 0x5b) goto LAB_005faddb;
        if (_NumOfElements == 0x5d) {
          _NumOfElements = 0x5e;
        }
      }
      uVar2 = *param_5;
      if (uVar2 != 0x20) {
        if (((((uVar2 < 0x61) || (0x7a < uVar2)) && ((uVar2 < 0x41 || (0x5a < uVar2)))) &&
            (((((uVar2 < 0x30 || (0x39 < uVar2)) && (uVar2 != 0x21)) &&
              ((uVar2 != 0x3f && (uVar2 != 0x2e)))) && (uVar2 != 0x2c)))) &&
           (((uVar2 != 0x25 && (uVar2 != 0x5b)) && (uVar2 != 0x5d)))) {
          if (*piVar4 == 5) {
            FUN_005fa920(piVar4,param_2,param_4,&local_2fdc,&local_2fe0,&local_2fe4);
          }
          else {
            FUN_005fa9e0(piVar4,param_2,&local_2fdc,&local_2fe0,&local_2fe4);
          }
          local_2328[_NumOfElements * 3] = local_2fdc;
          local_2328[_NumOfElements * 3 + 1] = local_2fe0;
          local_2328[_NumOfElements * 3 + 2] = local_2fe4;
          _NumOfElements = FUN_005faac0(*param_5,_NumOfElements);
          sVar6 = _NumOfElements;
        }
        else {
          if (*piVar4 == 5) {
            FUN_005fa920(piVar4,param_2,param_4,&local_2fdc,&local_2fe0,&local_2fe4);
          }
          else {
            FUN_005fa9e0(piVar4,param_2,&local_2fdc,&local_2fe0,&local_2fe4);
          }
          uVar2 = *param_5;
          uVar8 = (uint)uVar2;
          uVar11 = CONCAT24(uVar2,uVar8);
          local_2328[uVar8 * 3] = local_2fdc;
          local_2328[uVar8 * 3 + 1] = local_2fe0;
          local_2328[uVar8 * 3 + 2] = local_2fe4;
          if (0x328 < uVar8) {
            uVar11 = FUN_005f7490();
            uVar2 = extraout_CX;
          }
          sVar6 = (size_t)uVar11;
          local_2fc8[sVar6 * 2] = (ushort)((uint6)uVar11 >> 0x20);
          local_2fc8[sVar6 * 2 + 1] = uVar2;
        }
        if (local_2fd8[0] <= (int)(sVar6 + 1)) {
          local_2fd8[0] = sVar6 + 1;
        }
      }
      param_5 = param_5 + 1;
      iVar5 = local_2fd8[0];
      uVar2 = *param_5;
    }
    local_21a8 = 0;
    local_2fe4 = param_2 >> 2;
    local_21a4 = 0;
    local_2f48 = 0x20;
    local_2f46 = 0x20;
    local_21a0 = (float)local_2fe4;
    iVar9 = 0x61;
    local_2fcc = iVar5;
    do {
      if (local_2fc8[iVar9 * 2] == 0xffff) {
        uVar2 = FUN_004f2d80(iVar9);
        uVar8 = 0;
        if (0 < iVar5) {
          uVar7 = 0;
          do {
            if (local_2fc8[uVar7 * 2] == (uVar2 & 0xff)) {
              uVar2 = local_2fc8[(uVar8 & 0xffff) * 2 + 1];
              if (uVar2 != 0xffff) {
                if ((0x328 < iVar9) || (iVar9 < 0)) {
                  uVar2 = FUN_005f7490();
                }
                local_2fc8[iVar9 * 2] = (ushort)iVar9;
                local_2fc8[iVar9 * 2 + 1] = uVar2;
                if (local_2fd8[0] <= iVar9) {
                  local_2fd8[0] = iVar9;
                }
              }
              break;
            }
            uVar8 = uVar8 + 1;
            uVar7 = uVar8 & 0xffff;
          } while ((int)uVar7 < iVar5);
        }
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x7b);
    iVar9 = 0xe0;
    do {
      uVar8 = 0;
      if (0 < (int)_NumOfElements) {
        uVar7 = 0;
        do {
          if (local_2fc8[uVar7 * 2] == (ushort)iVar9) {
            if (local_2fc8[(uVar8 & 0xffff) * 2 + 1] != 0xffff) goto LAB_005fb0df;
            break;
          }
          uVar8 = uVar8 + 1;
          uVar7 = uVar8 & 0xffff;
        } while ((int)uVar7 < (int)_NumOfElements);
      }
      uVar2 = FUN_004f2d80(iVar9);
      uVar8 = 0;
      if (0 < iVar5) {
        uVar7 = 0;
        do {
          if (local_2fc8[uVar7 * 2] == (uVar2 & 0xff)) {
            uVar2 = local_2fc8[(uVar8 & 0xffff) * 2 + 1];
            if (uVar2 != 0xffff) {
              if ((0x328 < (int)_NumOfElements) || ((int)_NumOfElements < 0)) {
                uVar2 = FUN_005f7490();
              }
              local_2fc8[_NumOfElements * 2] = (ushort)iVar9;
              local_2fc8[_NumOfElements * 2 + 1] = uVar2;
              _NumOfElements = _NumOfElements + 1;
            }
            break;
          }
          uVar8 = uVar8 + 1;
          uVar7 = uVar8 & 0xffff;
        } while ((int)uVar7 < iVar5);
      }
LAB_005fb0df:
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x100);
    uVar8 = 0;
    uVar2 = 0x91;
    if (0 < (int)_NumOfElements) {
      uVar7 = 0;
      do {
        if (local_2fc8[uVar7 * 2] == 0x91) {
          if (local_2fc8[(uVar8 & 0xffff) * 2 + 1] != 0xffff) goto LAB_005fb16f;
          break;
        }
        uVar8 = uVar8 + 1;
        uVar7 = uVar8 & 0xffff;
      } while ((int)uVar7 < (int)_NumOfElements);
    }
    uVar8 = 0;
    if (0 < iVar5) {
      uVar7 = 0;
      do {
        if (local_2fc8[uVar7 * 2] == 0x27) {
          uVar3 = local_2fc8[(uVar8 & 0xffff) * 2 + 1];
          if (uVar3 != 0xffff) {
            if ((0x328 < (int)_NumOfElements) || ((int)_NumOfElements < 0)) {
              uVar3 = FUN_005f7490();
              uVar2 = extraout_DX;
            }
            local_2fc8[_NumOfElements * 2] = uVar2;
            local_2fc8[_NumOfElements * 2 + 1] = uVar3;
            _NumOfElements = _NumOfElements + 1;
          }
          break;
        }
        uVar8 = uVar8 + 1;
        uVar7 = uVar8 & 0xffff;
      } while ((int)uVar7 < iVar5);
    }
LAB_005fb16f:
    uVar8 = 0;
    uVar2 = 0x92;
    if (0 < (int)_NumOfElements) {
      uVar7 = 0;
      do {
        if (local_2fc8[uVar7 * 2] == 0x92) {
          if (local_2fc8[(uVar8 & 0xffff) * 2 + 1] != 0xffff) goto LAB_005fb1ef;
          break;
        }
        uVar8 = uVar8 + 1;
        uVar7 = uVar8 & 0xffff;
      } while ((int)uVar7 < (int)_NumOfElements);
    }
    uVar8 = 0;
    if (0 < iVar5) {
      uVar7 = 0;
      do {
        if (local_2fc8[uVar7 * 2] == 0x27) {
          uVar3 = local_2fc8[(uVar8 & 0xffff) * 2 + 1];
          if (uVar3 != 0xffff) {
            if ((0x328 < (int)_NumOfElements) || ((int)_NumOfElements < 0)) {
              uVar3 = FUN_005f7490();
              uVar2 = extraout_DX_00;
            }
            local_2fc8[_NumOfElements * 2] = uVar2;
            local_2fc8[_NumOfElements * 2 + 1] = uVar3;
            _NumOfElements = _NumOfElements + 1;
          }
          break;
        }
        uVar8 = uVar8 + 1;
        uVar7 = uVar8 & 0xffff;
      } while ((int)uVar7 < iVar5);
    }
LAB_005fb1ef:
    if ((int)_NumOfElements < 0x7b) {
      _NumOfElements = 0x7b;
    }
    _qsort(local_2fc8,_NumOfElements,4,(_PtFuncCompare *)&LAB_005fac50);
    piVar4 = (int *)*param_8;
    *param_8 = (uint)(piVar4 + 10);
    *piVar4 = 0;
    piVar4[1] = 0;
    piVar4[2] = 0;
    piVar4[3] = 0;
    piVar4[4] = 0;
    piVar4[5] = 0;
    piVar4[6] = 0;
    piVar4[7] = 0;
    piVar4[8] = 0;
    piVar4[9] = 0;
    *piVar4 = local_2fd0[1];
    piVar4[1] = local_2fd0[2];
    FUN_006e47d0(local_2fd0[1],local_2fd0[2],local_2fd0[3],0,0x15,1,piVar4 + 9);
    iVar5 = FUN_005e5210(piVar4);
    if (iVar5 == 0) {
      FUN_005f7490();
    }
    iVar9 = FUN_005e5310(iVar5);
    iVar9 = (**(code **)(**(int **)(iVar9 + 0x24) + 0x4c))(*(int **)(iVar9 + 0x24),0,local_2fd8,0,0)
    ;
    if (-1 < iVar9) {
      pvVar10 = *(void **)(local_2fe4 + 0x10);
      sVar6 = *(int *)(local_2fe4 + 4) * 4;
      iVar9 = 0;
      if (0 < *(int *)(local_2fe4 + 8)) {
        do {
          _memcpy(unaff_EBX,pvVar10,sVar6);
          unaff_EBX = (void *)((int)unaff_EBX + unaff_ESI);
          pvVar10 = (void *)((int)pvVar10 + sVar6);
          iVar9 = iVar9 + 1;
        } while (iVar9 < *(int *)(local_2fe4 + 8));
      }
      iVar9 = FUN_005e5310(iVar5);
      (**(code **)(**(int **)(iVar9 + 0x24) + 0x50))(*(int **)(iVar9 + 0x24),0);
    }
    iVar9 = local_2fe4;
    FUN_004ef280(*(undefined4 *)(local_2fe4 + 0x10),
                 "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nuqfnt_PC.cpp",0x264);
    FUN_004ef280(iVar9,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nuqfnt_PC.cpp",0x265);
    FUN_005e52d0(iVar5);
    FUN_005e52f0(iVar5);
    pvVar10 = (void *)(*param_8 + 0xf & 0xfffffff0);
    *param_8 = (*param_8 + 0xf & 0xfffffff0) + 0x4c;
    _memset(pvVar10,0,0x4c);
    *(int *)((int)pvVar10 + 0xc) = local_2fe0;
    *(float *)((int)pvVar10 + 0x14) = (float)iStack_c;
    *(size_t *)((int)pvVar10 + 0x10) = _NumOfElements;
    *(undefined4 *)((int)pvVar10 + 0x28) = 0;
    *(float *)((int)pvVar10 + 0x18) = (float)iStack_8;
    *(undefined4 *)((int)pvVar10 + 0x24) = 0;
    *(undefined4 *)((int)pvVar10 + 0x1c) = uStack_21b4;
    uVar8 = *param_8 + 0xf & 0xfffffff0;
    *param_8 = uVar8;
    *(uint *)((int)pvVar10 + 0x34) = uVar8;
    *param_8 = *param_8 + *(int *)((int)pvVar10 + 0xc) * 0xc;
    _memcpy(*(void **)((int)pvVar10 + 0x34),auStack_233c,*(int *)((int)pvVar10 + 0xc) * 0xc);
    for (uVar8 = *(int *)((int)pvVar10 + 0xc) * 0xc; (uVar8 & 0xf) != 0; uVar8 = uVar8 + 4) {
      *(undefined4 *)*param_8 = 0;
      *param_8 = *param_8 + 4;
    }
    uVar8 = *param_8 + 0xf & 0xfffffff0;
    *param_8 = uVar8;
    *(uint *)((int)pvVar10 + 0x38) = uVar8;
    *param_8 = *param_8 + *(int *)((int)pvVar10 + 0x10) * 4;
    _memcpy(*(void **)((int)pvVar10 + 0x38),&local_2fdc,*(int *)((int)pvVar10 + 0x10) * 4);
    uVar8 = *param_8 + 0xf & 0xfffffff0;
    *param_8 = uVar8;
    *(uint *)((int)pvVar10 + 8) = uVar8 - (int)pvVar10;
    FUN_005faaf0(iVar5,param_1,param_2,param_4);
    return pvVar10;
  }
  return (void *)0x0;
}

