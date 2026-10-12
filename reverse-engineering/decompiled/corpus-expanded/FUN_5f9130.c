/* Ghidra pseudocode, not original source.
 * ev_eb6388f9e6f0da39ba23c58a55c6a14172e207ae27b9d6b4ddcb98efebe4d9b1
 * Entry: 0x5f9130; label: FUN_005f9130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f9130(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  void *_Dst;
  int extraout_ECX;
  size_t _Size;
  void *_Src;
  void *_Src_00;
  undefined4 local_44;
  size_t local_40;
  undefined1 local_36 [10];
  undefined4 local_2c;
  undefined1 local_28 [4];
  undefined4 local_24;
  int local_20;
  undefined2 local_1a;
  
  iVar3 = FUN_004fa5f0(param_1,0);
  if (iVar3 != 0) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      param_3[4] = 0;
      param_3[5] = 0;
      param_3[6] = 0;
      param_3[7] = 0;
      param_3[8] = 0;
      FUN_004f6d10(iVar3);
      FUN_004fb550(iVar3,local_36,0xe);
      FUN_004fb550(iVar3,local_28,0x28);
      switch(local_1a) {
      case 4:
        *param_3 = 4;
        local_40 = 0x40;
        FUN_004fb550(iVar3,&DAT_02856c88,0x40);
        puVar4 = &DAT_02856c88;
        do {
          uVar7 = *puVar4;
          local_44._2_1_ = (undefined1)((uint)uVar7 >> 0x10);
          uVar2 = local_44._2_1_;
          local_44._1_3_ = (undefined3)((uint)uVar7 >> 8);
          local_44 = CONCAT31(local_44._1_3_,uVar2);
          uVar1 = local_44;
          local_44._3_1_ = (undefined1)((uint)uVar7 >> 0x18);
          local_44._0_2_ = (undefined2)uVar1;
          local_44._0_3_ = CONCAT12((char)uVar7,(undefined2)local_44);
          *puVar4 = local_44;
          puVar4 = puVar4 + 1;
        } while ((int)puVar4 < 0x2856cc8);
        break;
      default:
        FUN_005f7490(local_1a,param_1);
        break;
      case 8:
        *param_3 = 5;
        local_40 = 0x400;
        FUN_004fb550(iVar3,&DAT_02856c88,0x400);
        puVar4 = &DAT_02856c88;
        do {
          uVar7 = *puVar4;
          local_44._2_1_ = (undefined1)((uint)uVar7 >> 0x10);
          uVar2 = local_44._2_1_;
          local_44._1_3_ = (undefined3)((uint)uVar7 >> 8);
          local_44 = CONCAT31(local_44._1_3_,uVar2);
          uVar1 = local_44;
          local_44._3_1_ = (undefined1)((uint)uVar7 >> 0x18);
          local_44._0_2_ = (undefined2)uVar1;
          local_44._0_3_ = CONCAT12((char)uVar7,(undefined2)local_44);
          *puVar4 = local_44;
          puVar4 = puVar4 + 1;
        } while ((int)puVar4 < 0x2857088);
        break;
      case 0x18:
        *param_3 = 2;
        local_40 = 0;
        break;
      case 0x20:
        *param_3 = 3;
        local_40 = 0;
      }
      param_3[1] = local_24;
      param_3[2] = local_20;
      param_3[3] = param_2;
      iVar5 = FUN_005f9030(*param_3);
      iVar5 = iVar5 * extraout_ECX + 7;
      _Size = (int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3;
      param_2 = param_2 + 1;
      local_44 = 0;
      iVar5 = extraout_ECX;
      do {
        switch(*param_3) {
        case 0:
        case 1:
          iVar6 = 0x10;
          break;
        case 2:
          iVar6 = 0x18;
          break;
        case 3:
          iVar6 = 0x20;
          break;
        case 4:
          iVar6 = 4;
          break;
        case 5:
        case 0x14:
          iVar6 = 8;
          break;
        default:
          iVar6 = 0;
        }
        iVar6 = iVar6 * local_20 * iVar5;
        local_44 = local_44 + ((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3);
        param_2 = param_2 + -1;
        iVar5 = iVar5 >> 1;
        local_20 = local_20 >> 1;
      } while (param_2 != 0);
      uVar7 = FUN_004eef40(local_44,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nutex_pc.cpp",
                           0x195);
      param_3[4] = uVar7;
      if (local_40 == 0) {
        param_3[5] = 0;
      }
      else {
        uVar7 = FUN_004eef40(local_40,
                             "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nutex_pc.cpp",0x198);
        param_3[5] = uVar7;
      }
      __flushall();
      FUN_004f6de0(iVar3,local_2c,0,0);
      iVar5 = FUN_005f9030(*param_3);
      iVar5 = iVar5 * param_3[2] * param_3[1];
      FUN_004fb550(iVar3,param_3[4],(int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3);
      _Dst = (void *)FUN_004eef40(_Size,
                                  "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nutex_pc.cpp",
                                  0x1a0);
      _Src = (void *)param_3[4];
      iVar5 = FUN_005f9030(*param_3);
      iVar5 = iVar5 * param_3[2] * param_3[1];
      _Src_00 = (void *)((((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) - _Size) + (int)_Src);
      if (_Src < _Src_00) {
        do {
          _memcpy(_Dst,_Src,_Size);
          _memcpy(_Src,_Src_00,_Size);
          _memcpy(_Src_00,_Dst,_Size);
          _Src = (void *)((int)_Src + _Size);
          _Src_00 = (void *)((int)_Src_00 - _Size);
        } while (_Src < _Src_00);
      }
      FUN_004ef280(_Dst,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nutex_pc.cpp",0x1af);
      if (local_40 != 0) {
        _memcpy((void *)param_3[5],&DAT_02856c88,local_40);
      }
    }
    FUN_004f99e0(iVar3);
    return 1;
  }
  _sprintf(&DAT_02856c08,"Cannot open file: %s",param_1);
  return 0;
}

