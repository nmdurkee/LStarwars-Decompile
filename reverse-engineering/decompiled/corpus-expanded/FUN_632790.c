/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x632790; label: FUN_00632790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00632790(int param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *_Dst;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_18;
  
  if (param_4 == 0) {
    local_18 = *(int *)(param_1 + 0x18);
  }
  else {
    local_18 = *(int *)(param_1 + 0x14);
  }
  uVar2 = FUN_00632280();
  uVar3 = FUN_00632280();
  iVar6 = (((param_5 - 1) + param_2) / param_5) * (((param_3 - 1) + param_5) / param_5);
  _Dst = _malloc(iVar6 * 4 + 0x50);
  if (_Dst != (undefined4 *)0x0) {
    _memset(_Dst,0,0x50);
    puVar7 = _Dst + 0x14;
    _Dst[0x12] = puVar7;
    uVar1 = *(undefined4 *)(param_1 + 4);
    _Dst[9] = local_18 * param_2 + 0xf & 0xfffffff0;
    _Dst[4] = local_18;
    _Dst[0xb] = param_2 / param_5;
    *_Dst = uVar1;
    _Dst[0xd] = uVar2;
    _Dst[5] = param_2;
    _Dst[0xe] = uVar3;
    _Dst[6] = param_3;
    _Dst[10] = iVar6;
    _Dst[0xf] = param_2 % param_5;
    _Dst[3] = param_4;
    _Dst[0xc] = param_3 / param_5;
    _Dst[0x10] = param_3 % param_5;
    _Dst[0x11] = param_5;
    if (param_4 == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x20);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
    }
    _Dst[2] = uVar2;
    if (param_4 == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x10);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0xc);
    }
    _Dst[1] = uVar2;
    param_2 = 0;
    if (param_3 / param_5 != 0) {
      do {
        uVar5 = 0;
        if (_Dst[0xb] != 0) {
          do {
            uVar2 = FUN_006322e0(*(undefined4 *)(param_1 + 4),_Dst[1],_Dst[9],_Dst[4],_Dst[0x11],
                                 _Dst[0x11]);
            *puVar7 = uVar2;
            uVar5 = uVar5 + 1;
            puVar7 = puVar7 + 1;
          } while (uVar5 < (uint)_Dst[0xb]);
        }
        if (_Dst[0xd] != 0) {
          uVar2 = FUN_006322e0(*(undefined4 *)(param_1 + 4),_Dst[1],_Dst[9],_Dst[4],_Dst[0xd],
                               _Dst[0x11]);
          *puVar7 = uVar2;
          puVar7 = puVar7 + 1;
        }
        param_2 = param_2 + 1;
      } while (param_2 < (uint)_Dst[0xc]);
    }
    if (_Dst[0xe] != 0) {
      uVar5 = 0;
      if (_Dst[0xb] != 0) {
        do {
          uVar2 = FUN_006322e0(*(undefined4 *)(param_1 + 4),_Dst[1],_Dst[9],_Dst[4],_Dst[0x11],
                               _Dst[0xe]);
          *puVar7 = uVar2;
          uVar5 = uVar5 + 1;
          puVar7 = puVar7 + 1;
        } while (uVar5 < (uint)_Dst[0xb]);
      }
      if (_Dst[0xd] != 0) {
        uVar2 = FUN_006322e0(*(undefined4 *)(param_1 + 4),_Dst[1],_Dst[9],_Dst[4],_Dst[0xd],
                             _Dst[0xe]);
        *puVar7 = uVar2;
      }
    }
    uVar5 = 0;
    if (_Dst[10] != 0) {
      piVar4 = (int *)_Dst[0x12];
      do {
        if (*piVar4 == 0) {
          uVar5 = 0;
          do {
            if (*(int *)(_Dst[0x12] + uVar5 * 4) != 0) {
              piVar4 = *(int **)(_Dst[0x12] + uVar5 * 4);
              (**(code **)(*piVar4 + 8))(piVar4);
              *(undefined4 *)(_Dst[0x12] + uVar5 * 4) = 0;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < (uint)_Dst[10]);
          _free(_Dst);
          return (undefined4 *)0x0;
        }
        uVar5 = uVar5 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar5 < (uint)_Dst[10]);
    }
    _Dst[8] = 0;
    return _Dst;
  }
  return (undefined4 *)0x0;
}

