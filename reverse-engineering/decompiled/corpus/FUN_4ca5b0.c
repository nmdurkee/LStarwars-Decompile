/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4ca5b0; label: FUN_004ca5b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ca5b0(void)

{
  float fVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float10 fVar6;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [56];
  undefined4 local_8;
  
  FUN_00548f10(1);
  puVar2 = PTR_DAT_00802c54;
  DAT_007fce84 = 0;
  PTR_DAT_00802c54 = (undefined *)0x0;
  if ((DAT_007fac04 != 0) && (DAT_0087b51c == 0)) {
    _DAT_00925018 = _DAT_0092501c;
    local_6c = 0.2;
    puVar4 = &DAT_00806680;
    puVar5 = DAT_00925164;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    FUN_00603cc0(DAT_00925164);
    FUN_004badd0(DAT_008668d4._3_1_);
    FUN_005d0940(3);
    local_44 = 0x3e000000;
    local_58 = 0;
    local_48 = 0x3e000000;
    local_54 = 0;
    local_4c = 0x3e000000;
    local_50 = 0;
    FUN_005b45a0(local_40,&local_4c);
    local_8 = 0x3f800000;
    local_7c = 3.3;
    if (DAT_009250b0 == 0) {
      DAT_00880578 = 3;
    }
    local_60 = 0.0;
    local_74 = 0.0;
    local_78 = 0.0;
    local_70 = 0.0;
    FUN_004fecf0(FUN_004c9fb0,0,0,0);
    while ((DAT_007fce84 == 0 || (0.0 < local_6c))) {
      FUN_004f3e20();
      FUN_00603cc0(&DAT_009736e8);
      DAT_00926bd0 = 1;
      FUN_0054b090();
      FUN_00495310(&DAT_009253b0,0);
      FUN_00548fe0(&DAT_00925028);
      fVar6 = (float10)FUN_005b7d30(_DAT_00925030,0x3e4ccccd);
      DAT_009213e4 = (uint)(fVar6 < (float10)0.10000000149011612);
      if (DAT_02962034 == 0) {
        FUN_00698e70();
      }
      if ((local_7c < 3.3) && (DAT_00924888 != 0)) {
        if ((local_7c == 0.0) && (iVar3 = FUN_005cfac0(&local_58), iVar3 == 0)) {
          iVar3 = FUN_005cf5b0(DAT_00924888,&local_58,PTR_s_save_icon_007f44fc,1);
          if (iVar3 == 0) {
            local_7c = 3.3;
          }
        }
        else {
          local_7c = _DAT_00925018 + local_7c;
          if (3.3 < local_7c) {
            local_7c = 3.3;
          }
        }
      }
      if (((local_60 < 0.5) && (3.3 <= local_7c)) && (iVar3 = FUN_0054b640(), iVar3 != 0)) {
        if (DAT_00880578 == 0) {
          FUN_00509830(7,0,0xffffffff);
          _DAT_00950780 = 0xbf800000;
          DAT_00880578 = 1;
        }
        if ((DAT_00880578 == 1) && (DAT_00800944 == 0)) {
          DAT_00880578 = 2;
        }
        if ((DAT_00880578 == 2) &&
           (local_60 = _DAT_00925018 + local_60,
           !NAN(local_60) && 0.5 < local_60 != (local_60 == 0.5))) {
          DAT_00880578 = 3;
        }
      }
      if ((((((local_74 < 1.0) && (3.3 <= local_7c)) && (DAT_00880578 == 3)) &&
           ((DAT_0088057c != 0 && (DAT_00924800 == 1)))) && (DAT_00800944 == 0)) &&
         (local_74 = local_74 + _DAT_00925018, 1.0 < local_74 != (local_74 == 1.0))) {
        local_74 = 1.0;
      }
      if (((local_78 < 5.8) && (3.3 <= local_7c)) &&
         ((DAT_00880578 == 3 && ((1.0 < local_74 != (local_74 == 1.0) && (DAT_00880574 != 0)))))) {
        if ((local_78 == 0.0) && (DAT_0088056c == 0)) {
          if ((DAT_00880570 == 0) || (iVar3 = FUN_004c9d10(DAT_00880570), iVar3 == 0)) {
            local_78 = 5.8;
          }
        }
        else {
          local_78 = _DAT_00925018 + local_78;
          if (5.8 < local_78) {
            local_78 = 5.8;
          }
        }
      }
      if ((((((local_70 < 3.8) && (3.3 <= local_7c)) && (DAT_00880578 == 3)) &&
           (((!NAN(local_74) && 1.0 < local_74 != (local_74 == 1.0) &&
             (!NAN(local_78) && 5.8 < local_78 != (local_78 == 5.8))) &&
            ((iVar3 = FUN_0054b640(), iVar3 != 0 && (DAT_0088057c != 0)))))) &&
          ((DAT_007f39e4 == 0 || (DAT_00802368 != -1)))) &&
         (local_70 = _DAT_00925018 + local_70, 3.8 < local_70)) {
        local_70 = 3.8;
      }
      if ((((DAT_007fce84 != 0) && (3.3 <= local_7c)) && (DAT_00880578 == 3)) &&
         (((!NAN(local_74) && 1.0 < local_74 != (local_74 == 1.0) &&
           (!NAN(local_78) && 5.8 < local_78 != (local_78 == 5.8))) &&
          ((3.8 <= local_70 && (local_6c = local_6c - _DAT_00925018, local_6c < 0.0)))))) {
        local_6c = 0.0;
      }
      FUN_005d4290(1);
      FUN_005feab0(0xf00,0x80000000,0x80000000,0x3f800000);
      if (local_6c == 0.2) {
        fVar6 = (float10)FUN_004c9eb0(local_7c,0x40200000);
        if (0.0 < (float)fVar6) {
          FUN_005ff7a0(&local_58,local_40,(float)fVar6);
        }
        FUN_0050fed0(0);
        fVar6 = (float10)FUN_004c9eb0(local_78,0x40a00000);
        if (0.0 < (float)fVar6) {
          switch(DAT_00826494) {
          default:
            fVar1 = 1.3333334;
            break;
          case 1:
            fVar1 = 1.7777778;
            break;
          case 2:
            fVar1 = 1.6;
            break;
          case 3:
            fVar1 = _DAT_02976bf8;
          }
          fVar1 = (1.0 - 1.3333334 / fVar1) * 0.5;
          FUN_005ebd80(0xb00,0,0x3f800000);
          DAT_02854d1c = DAT_02854d1c + 1;
          FUN_00600b20(2);
          FUN_00607d70(0x10,7,DAT_0088056c);
          FUN_006e6b90();
          FUN_004c9a40();
          iVar3 = *DAT_02854d10;
          *(undefined4 *)(iVar3 + 0x10) = 0;
          *(undefined4 *)(iVar3 + 0x14) = 0;
          FUN_006009e0(fVar1 + 0.0,0,0);
          FUN_004c9a40();
          iVar3 = *DAT_02854d10;
          *(undefined4 *)(iVar3 + 0x10) = 0x3f800000;
          *(undefined4 *)(iVar3 + 0x14) = 0x3f800000;
          FUN_006009e0(1.0 - fVar1,0x3f800000,0);
          FUN_006009a0();
          DAT_02854d1c = DAT_02854d1c + -1;
          FUN_00600b20(*(undefined4 *)(&DAT_00981c50 + DAT_02854d1c * 4));
        }
        fVar6 = (float10)FUN_004c9eb0(local_70,0x40400000);
        if ((0.0 < (float)fVar6) && (DAT_007f39e4 != 0)) {
          FUN_0054bf20((float)fVar6);
        }
      }
      FUN_005f3950();
      FUN_0065f4d0();
      fVar6 = (float10)FUN_004fd050();
      _DAT_00925018 = (float)fVar6;
      FUN_0065f4e0();
      if ((_DAT_00925054 < _DAT_00925018) && (DAT_00951be0 == 0)) {
        _DAT_00925018 = _DAT_00925054;
      }
    }
    if (DAT_0088056c != 0) {
      FUN_005e50e0(DAT_0088056c);
      DAT_0088056c = 0;
    }
    PTR_DAT_00802c54 = puVar2;
    return;
  }
  DAT_00880578 = 3;
  FUN_004c9fb0(0);
  if (DAT_0088056c != 0) {
    FUN_005e50e0(DAT_0088056c);
    DAT_0088056c = 0;
  }
  PTR_DAT_00802c54 = puVar2;
  return;
}

